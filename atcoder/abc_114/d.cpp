// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	map<int, int> m;
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int x = i;
		for (int k = 2; k <= x; ++k) {
			while ((x % k) == 0) {
				m[k] += 1;
				x /= k;
			}
		}
	}
	vector<int> v;
	for (auto kv : m) {
		v.push_back(kv.second);
	}
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for (int i = 0; i < (int)v.size(); ++i) {
		ans += v[i] >= 74;
		for (int j = i + 1; j < (int)v.size(); ++j) {
			ans += v[i] >= 24 && v[j] >= 2;
			ans += v[i] >= 2 && v[j] >= 24;
			ans += v[i] >= 4 && v[j] >= 14;
			ans += v[i] >= 14 && v[j] >= 4;
			for (int k = j + 1; k < (int)v.size(); ++k) {
				ans += v[i] >= 2 && v[j] >= 4 && v[k] >= 4;
				ans += v[i] >= 4 && v[j] >= 2 && v[k] >= 4;
				ans += v[i] >= 4 && v[j] >= 4 && v[k] >= 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
