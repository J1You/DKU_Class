#include <iostream>
#include <cstring>
using namespace std;

class B_class {
protected:
	char author[80];
public:
	void put_author(const char* s) {
		strcpy_s(author, s);
	}
	virtual void show_author() {
		cout << author << "\n";
	}
};

class D_class :public B_class {
private:
	char title[80];
public:
	void show_author() {
		cout << "Author: " << author << "\n";
		cout << "Title: " << title << "\n";
	}
	void put_title(const char* num) {
		strcpy_s(title, num);
	}
	void show_title() {
		cout << "Title: ";
		cout << title << "\n";
	}
};

int main()
{
	D_class* p;
	D_class D_ob;
	p = &D_ob;
	p->put_author("William Shakespeare");
	p->put_title("The Tempest");
	p->show_author();
	return 0;
}
