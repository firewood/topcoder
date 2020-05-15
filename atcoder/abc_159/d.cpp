// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<int> a(n);
		map<int, LL> m;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			m[a[i]] += 1;
		}
		LL tot = 0;
		for (auto kv : m) {
			tot += (kv.second * (kv.second - 1)) / 2;
		}
		for (int i = 0; i < n; ++i) {
			LL cnt = tot;
			LL c = m[a[i]];
			if (c > 1) {
				cnt -= (c * (c - 1)) / 2;
				--c;
				cnt += (c * (c - 1)) / 2;
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
