// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a == c || a == d || b == c || b == d ? "YES" : "NO") << endl;
	return 0;
}
