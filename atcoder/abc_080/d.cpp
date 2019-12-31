// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, c;
		int edt[30] = {}, ch[30] = {};
		int ans = 0;
		cin >> n >> c;
		if (n < 0) return 0;
		vector<pair<pair<int, int>, int>> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first.first >> v[i].first.second >> v[i].second;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 30; ++j) {
				if (edt[j] < v[i].first.first || (edt[j] == v[i].first.first && ch[j] == v[i].second)) {
					edt[j] = v[i].first.second;
					ch[j] = v[i].second;
					ans = max(ans, j + 1);
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
