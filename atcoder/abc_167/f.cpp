// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

bool solve(vector<string> ss) {
	vector<II> v;
	for (string s : ss) {
		int cnt = 0, mn = 0;
		for (char c : s) {
			if (c == '(') {
				++cnt;
			} else {
				--cnt;
				mn = min(mn, cnt);
			}
		}
		v.emplace_back(II(mn, cnt));
	}
	int cnt = 0;
	vector<II> mp;
	vector<pair<int, II>> mm;
	for (auto kv : v) {
		if (kv.first >= 0) {
			cnt += kv.second;
		} else if (kv.second >= 0) {
			mp.emplace_back(kv);
		} else {
			mm.emplace_back(make_pair(kv.second - kv.first, kv));
		}
	}
	sort(mp.rbegin(), mp.rend());
	for (auto kv : mp) {
		if (cnt + kv.first < 0) {
			return false;
		}
		cnt += kv.second;
	}
	sort(mm.rbegin(), mm.rend());
	for (auto kv : mm) {
		if (cnt + kv.second.first < 0) {
			return false;
		}
		cnt += kv.second.second;
	}
	return cnt == 0;
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<string> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		bool ans = solve(v);
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
