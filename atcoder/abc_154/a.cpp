// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s, t, u;
	int a, b;
	cin >> s >> t >> a >> b >> u;
	if (s == u) {
		--a;
	} else if (t == u) {
		--b;
	}
	cout << a << " " << b << endl;
	return 0;
}
