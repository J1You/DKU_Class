/* mycp program, by Choi JiYun(32194747), 2020-10-06 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#define MAX_BUF 64
int main(int argc, char *argv[]){
	int fd1, fd2, read_size, write_size;;
	char buf[MAX_BUF];
	struct stat st;

	if(argc!=3){
		printf("USAGE: %s <FILE_NAME> <COPYFILE_NAME>\n",argv[0]);
		exit(-1);
	}
	stat(argv[1],&st);

	fd1 = open(argv[1],O_RDONLY);
	if(fd1 < 0){
		printf("errno:%d . Can't open file <%s>\n", errno, argv[1]);
        	exit(-1);

	}
	fd2 = open(argv[2], O_RDWR|O_CREAT|O_EXCL, st.st_mode); 
	if(fd2 < 0){
		printf("errno:%d . Can't open file <%s>\n", errno, argv[2]);
        	exit(-1);

	}
	
	while(1){
		read_size = read(fd1, buf, MAX_BUF);
		if(read_size==0) break;
		write_size = write(fd2, buf, read_size);
	}
	close(fd1);
	close(fd2);
	return 0;
}
