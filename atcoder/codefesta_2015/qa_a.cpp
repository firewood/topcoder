#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	s[s.length() - 1] = '5';
	cout << s << endl;
	return 0;
}
