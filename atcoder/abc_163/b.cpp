// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m, a;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		n -= a;
	}
	cout << max(-1, n) << endl;
	return 0;
}
