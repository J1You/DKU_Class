#include <iostream>
using namespace std;

class queue {
private:
	int* q;
	int size;
	int sloc, rloc;
public:
	queue(int n);
	~queue();
	void qput(int i);
	int qget();
	int max();
	void reverse_print(int num);

};

queue::queue(int n = 100)
{
	sloc = rloc = -1;
	size = n;
	q = new int[size];
	cout << "Queue initialized." << endl;
}

queue::~queue()
{
	cout << "Queue destroyed." << endl;
}

void queue::qput(int i)
{
	if (sloc == (size - 1)) {
		cout << "Queue is full." << endl;
		return;
	}
	sloc++;
	q[sloc] = i;
}

int queue::qget()
{
	if (rloc == sloc) {
		cout << "Queue Underflow." << endl;
		return 0;
	}
	rloc++;
	return q[rloc];
}

int queue::max()
{
	if (rloc == sloc) return -999;
	int max = q[rloc + 1];
	for (int i = rloc + 2; i <= sloc; i++) {
		if (q[i] > max) max = q[i];
	}
	return max;
}

void queue::reverse_print(int num)
{
	if (rloc == sloc) {
		cout << "¾øÀ½" << endl;
		return;
	}
	for (int i = sloc; i > sloc - 4; i--) cout << q[i] << " ";
	cout << "\n";
}

int main()
{
	int n;
	queue a(20);
	for (int i = 0; i < 6; i++) {
		cin >> n;
		a.qput(n);
	}
	cout << a.max() << endl;
	a.reverse_print(4);
	return 0;
}

