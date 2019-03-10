// B.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m, c, ans = 0;
	cin >> n >> m >> c;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		int a, sum = c;
		for (int j = 0; j < m; ++j) {
			cin >> a;
			sum += a * b[j];
		}
		ans += sum > 0;
	}
	cout << ans << endl;
	return 0;
}
