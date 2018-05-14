// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m, x;
	cin >> n >> m >> x;
	int sum[2] = {};
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		if (a < x) {
			sum[0] += 1;
		} else if (a > x) {
			sum[1] += 1;
		}
	}
	cout << min(sum[0], sum[1]) << endl;
	return 0;
}
