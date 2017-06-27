// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	cout << (s.rfind('Z') - s.find('A') + 1) << endl;
	return 0;
}
