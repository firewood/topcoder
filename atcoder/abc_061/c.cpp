// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		LL n = -1, k = -1;
		cin >> n >> k;
		if (n <= 0) break;
		vector<pair<LL, LL>> v(n);
		for (LL i = 0; i < n; ++i) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());
		for (LL i = 0; i < n; ++i) {
			if (k <= v[i].second) {
				cout << v[i].first << endl;
				break;
			}
			k -= v[i].second;
		}
	}
	return 0;
}
