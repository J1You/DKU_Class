/*#include <iostream>
#include <string>
using namespace std;

class mystring {
private:
	char str[80];
public:
	mystring(char* s);
	int strlength();
	int numchar(char ch);
};

mystring::mystring(char* s)
{
	strcpy_s(str, s);
}

int mystring::strlength()
{
	return strlen(str);
}

int mystring::numchar(char ch)
{
	int count = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == ch) count++;
	}
	return count;
}

int main()
{
	char str[] = "I am studing C++ language.";
	mystring my(str);
	cout << "문자열 길이: " << my.strlength() << endl;
	cout << "문자 a의 개수: " << my.numchar('a') << endl;
	return 0;
}*/