#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	cout << s.substr(0, 4) << " " << s.substr(4) << endl;
	return 0;
}
