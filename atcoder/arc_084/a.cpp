// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string a, b;
	cin >> a >> b;
	reverse(b.begin(), b.end());
	cout << (a == b ? "YES" : "NO") << endl;
	return 0;
}
