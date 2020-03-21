// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, m = -1, ans = 0;
		cin >> n >> m;
		if (n < 0) return 0;
		vector<int> x(n);
		vector<vector<int>> mods(m);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
			mods[x[i] % m].push_back(x[i]);
		}
		for (int i = 0; i <= m / 2; ++i) {
			if (i == 0 || i * 2 == m) {
				ans += (int)mods[i].size() / 2;
			} else {
				vector<int> a = mods[i];
				vector<int> b = mods[m - i];
				if (a.size() < b.size()) {
					swap(a, b);
				}
				int remain = (int)(a.size() - b.size());
				sort(a.begin(), a.end());
				for (int j = 1; j < (int)a.size() && remain >= 2; ++j) {
					if (a[j - 1] == a[j]) {
						remain -= 2;
						++ans;
						++j;
					}
				}
				ans += (int)b.size();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
