#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	cout << s << (s == "0" ? "" : "0") << endl;
	return 0;
}
