// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<vector<int>> f(n, vector<int>(10));
	vector<vector<int>> p(n, vector<int>(11));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> f[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 11; ++j) {
			cin >> p[i][j];
		}
	}
	int ans = -(1 << 30);
	for (int b = 1; b < (1 << 10); ++b) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int c = 0;
			for (int j = 0; j < 10; ++j) {
				c += f[i][j] && ((1 << j) & b);
			}
			sum += p[i][c];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
