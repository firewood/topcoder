// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	int r, g, b;
	cin >> r >> g >> b;
	int n = r * 100 + g * 10 + b;
	cout << (n % 4 ? "NO" : "YES") << endl;
	return 0;
}
