// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	int ans = 1 << 30;
	sort(x.begin(), x.end());
	for (int i = x[0]; i <= x.back(); ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			int d = i - x[j];
			sum += d * d;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
