/* program:MyShell, by Choi JiYun (32194747), 2020-10-30 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/wait.h>
#define MAX_SYS 128
bool cmd_help(int argc, char* argv[]);
bool cmd_quit(int argc, char* argv[]);
bool cmd_exit(int argc, char* argv[]);
bool cmd_cd(int argc, char*argv[]);
int check(char *line[]);
int tokenize(char *buf, char *delims, char *tokens[], int max);
bool run(char *line);

struct shell {  //명령어 sturcture
	char *key; 
	char *key_ex; bool (*intr_func)(int argc, char *argv[]);
};
struct shell cmd[] = {
	{"help", "Show this help ", cmd_help},
	{"quit", "Quit this Shell", cmd_quit},
	{"exit", "Exit this shell", cmd_exit},
	{"cd", "Change directory", cmd_cd},
	{">", "Redirection"},
	{"|", "Pipe"},
	{"&", "Run task on background"}
};

int main(){ // 명령어 입력 메인함수 
	char line[1024], usr[MAX_SYS], cwd[MAX_SYS];
	getlogin_r(usr, MAX_SYS); 
	getcwd(cwd, MAX_SYS); 
	while(1){
		printf("%s@%s $ ", usr, cwd);
		fgets(line, sizeof(line) - 1, stdin);
		if(run(line) == false) break;
	}
	return 0;
}

bool cmd_help(int argc, char* argv[]) {  // 도움말 출력 함수
	int i;
	printf("-----------------JiYun's Shell -----------------\n");
	printf("| These shell commands are defined internally. |\n");
	printf("------------------------------------------------\n");

	printf("CMD\t FUNCTION\n------------------------------------------------\n");
	for (i = 0; i < 4; i++) printf("%s\t %s\n", cmd[i].key, cmd[i].key_ex);
	printf("------------------------------------------------\n");
	printf("KEY\t FUNCTION\n------------------------------------------------\n");
	for (i = 4; i < 8; i++) printf("%s\t %s\n", cmd[i].key, cmd[i].key_ex);
	return true;
}

bool cmd_quit(int argc, char*argv[]){return 0;}  // myshell 종료 quit 함수

bool cmd_exit(int argc, char* argv[]) { return 0; }  // myshell 종료 exit 함수

bool cmd_cd(int argc, char*argv[]){  // 디렉토리 변경 함수
	if(argc == 1); 
	else if(argc == 2) {
		if(chdir(argv[1])) printf("type correct directory\n");
	}
	else printf("USAGE: %s [dir_name]\n", argv[0]);
	return true;
}

void cmd_redirection(int argc, char *argv[]){  // 출력 재지정 함수
	int fd;
	if (argc != 4) { printf("USAGE: %s input > output\n", argv[0]); return; }
	if((fd = open(argv[3], O_WRONLY | O_CREAT, 0664)) < 0) {
		printf("Can't open %s file with errno %d\n", argv[3], errno);
		return;
	}
	dup2(fd, STDOUT_FILENO);
	argv[2] = NULL;
	close(fd);
}

void cmd_pipe(int argc, char *argv[]){  // 파이프 함수
	int i, read_size, stat, fd[2];
	pid_t pid;
	char bufc[MAX_SYS], bufp[MAX_SYS];
	if(argc != 4){
		printf("USAGE: %s file_name | file_name\n", argv[0]);
		return;
	}
	if(pipe(fd) < 0){
		printf("pipe error\n"); return;
	}
	if((pid = fork()) == 0){
		close(fd[0]);
		dup2(fd[1], 1);
		execlp(argv[0], argv[0], argv[1], (char*)0);
	}
	else {
		wait(&stat);
		close(fd[1]);
		dup2(fd[0], 0);
		execlp(argv[3], argv[3], 0, (char*)0);
		
	}
	return;
}

int check(char *line[]){  // 명령어 체크
	int i;
	for(i=0; line[i] != NULL; i++){
		if(!strcmp(line[i], ">")) return 1; 
		if(!strcmp(line[i], "|")) {line[i] = NULL; return 2;} 
		if(!strcmp(line[i], "&")) {line[i] = NULL; return 3;}
	}
	return 0;
}
int tokenize(char *buf, char *delims, char *tokens[], int max){  // 명령어 토큰화 함수
	int token_count = 0;
	char *token = strtok(buf, delims);
	while(token != NULL && token_count < max){
		tokens[token_count] = token; token_count++;
		token = strtok(NULL, delims);
	}
	tokens[token_count] = NULL; 
	return token_count;
}

bool run(char *line){  // 수행 함수
    char delims[] = " \n";
    char *tokens[MAX_SYS];
    pid_t pid;
    int i, stat, chk;
	int token_count = tokenize(line, delims, tokens, sizeof(tokens) / sizeof(char*));
	if(token_count == 0) return true; 
	chk = check(tokens); 
	for(i = 0; i < 4; i++) { 
        if(strcmp(cmd[i].key, tokens[0]) == 0)
        	return cmd[i].intr_func(token_count, tokens);
    }
	if((pid=fork()) < 0) {
		perror("fork error caused\n"); 
		exit(-1);
	}
	else if(pid == 0) {
		if(chk == 1){  // redirection 명령어 실행
		cmd_redirection(token_count, tokens);
		execvp(tokens[0], tokens);
		}
		else if(chk == 2) cmd_pipe(token_count, tokens);  // pipe 명령어 실행
		else{  // 기본 명령어 실행
			execvp(tokens[0], tokens);
			printf("execute failed\n"); 
			exit(-1);
		}
	}
	else {
		if(chk == 3) {  // background 수행
			waitpid(pid, &stat, WNOHANG); 
			sleep(1);
		}
		else waitpid(pid, &stat, 0);
	}
	return true;
}
