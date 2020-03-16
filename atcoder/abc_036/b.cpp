// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<string> s(n), r;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	r = s;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			r[j][n - 1 - i] = s[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << r[i] << endl;
	}
	return 0;
}
