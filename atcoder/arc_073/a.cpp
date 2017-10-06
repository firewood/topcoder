// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string a, b, c;
	cin >> a >> b >> c;
	bool ans = (a.back() == b.front() && b.back() == c.front());
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
