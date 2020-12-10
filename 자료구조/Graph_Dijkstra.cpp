#include<iostream>
#include <iomanip>
using namespace std;
#define MAX 999999 //간선이 없는 경우 MAX값을 인접행렬에 넣음

class Graph
{
private:
	int** length;            // 이차원 배열
	int* dist;               // 일차원 배열
	bool* s;                  // 일차원 배열
	int* path;  // 일차원 배열 경로저장
	int n;                    // 정점의 수
	int* stack; // 경로역순을 바꾸기 위한 배열
public:
	Graph(const int vertices = 0) :n(vertices)
	{
		length = new int* [n];   // 이차원 배열의 동적 생성
		dist = new int[n];
		s = new bool[n];
		path = new int[n];
		for (int i = 0; i < n; i++) {
			length[i] = new int[n];
			for (int j = 0; j < n; j++) {
				if (i == j) length[i][j] = 0;
				else
					length[i][j] = MAX;
			}
		}
	};
	void input(int a, int b);
	int choose(const int);
	void ShortestPath(const int);
	void output(int start);
	int path_printf(int v, int c);
};

void Graph::input(int a, int b)	//간선 입력
{
	int x, y, c;
	for (int i = 0; i < b; i++)
	{
		cout << i + 1 << "번째 간선과 가충치 입력 :";
		cin >> x >> y >> c;

		length[x][y] = c;
	}
}

int Graph::choose(const int n)
{
	int min = MAX;
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (!s[i])
			if (min > dist[i])
			{
				min = dist[i];
				pos = i;
			}
	}
	return pos;
}

void Graph::ShortestPath(const int v)
// dist[j],0<=j<n은 n개의 정점을 가진 방향 그래프 G에서 정점 v로부터 정점 j
// 까지의 최단 경로 길이로 설정됨. 간선의 길이는 length[j][j]로 주어짐.
{
	for (int i = 0; i < n; i++) { s[i] = false; dist[i] = length[v][i]; path[i] = v; }// 초기화
	s[v] = true;
	dist[v] = 0;
	for (int i = 0; i < n - 2; i++) { // 정점 v로부터 n-1개 경로를 결정
		int u = choose(n); // choose는 dist[u] = minimum dist[w]인 u를 반환
						   // (여기서 s[w]=FALSE) 
		s[u] = true;
		for (int w = 0; w < n; w++) {
			if (!s[w])
				if (dist[u] + length[u][w] < dist[w])
				{
					dist[w] = dist[u] + length[u][w];
					path[w] = u;
				}
		}

	}
	//dist값 출력
	cout << "최종 dist값:";
	for (int j = 0; j < n; j++)
		cout << dist[j] << " ";
	cout << "\n\n";
}

void Graph::output(int start) //인접행렬 및 경로 출력
{
	cout << "\n<<<<<인접행렬>>>>>" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (length[i][j] == MAX)
				cout << setw(3) << "∞";
			else cout << setw(3) << length[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	ShortestPath(start);//다익스트라 시작

	cout << "<<<<<경로출력>>>>>" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "0";
		if (path[i] == 0)
			cout << "->" << i;
		else
		{
			int c;
			stack = new int[n * n]; // 경로를 배열에 넣기위해 동적 메모리할당
			c = path_printf(i, 0);
			for (int j = c; j >= 0; j--)
				cout << "->" << stack[j];
			delete stack; //초기화하기 위해 메모리 반환
		}
		cout << "\n";
	}
}

int Graph::path_printf(int v, int c)//경로역추적 함수
{
	if (path[v] == 0) {
		stack[c] = v;
		return c;
	}
	else {
		stack[c] = v;
		path_printf(path[v], c + 1); //재귀함수로 계속해서 역추적
	}
}

int main()
{
	int n, m, start;
	cout << "정점수와 간선 수 입력 : ";

	cin >> n >> m;
	Graph A(n);
	A.input(n, m);
	cout << "시작 정점 입력: ";
	cin >> start;
	A.output(start);
	return 0;
}