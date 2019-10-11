// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m, a, b;
	cin >> n >> m;
	vector<int> r(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		r[a - 1] += 1;
		r[b - 1] += 1;
	}
	for (int i = 0; i < n; ++i) {
		cout << r[i] << endl;
	}
	return 0;
}
