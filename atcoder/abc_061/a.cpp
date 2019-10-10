// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b, c;
	cin >> a >> b >> c;
	bool ans = a <= c && c <= b;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
