// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> dists;
	for (int i = 1; i < m; ++i) {
		dists.push_back(a[i] - a[i - 1]);
	}
	sort(dists.rbegin(), dists.rend());
 	long long ans = accumulate(dists.begin() + min(m - 1, n - 1), dists.end(), 0LL);
	cout << ans << endl;
	return 0;
}
