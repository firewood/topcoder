// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	string op;
	cin >> a >> op >> b;
	int ans = op == "+" ? (a + b) : (a - b);
	cout << ans << endl;
	return 0;
}
