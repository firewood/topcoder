// C.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool ok(set<int> &kw, vector<string> &sv, string t) {
	for (int i = 0; i != sv.size(); ++i) {
		string &s = sv[i];
		bool x = kw.find(i) != kw.end();
		if ((s.substr(0, t.length()) == t) != x) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	int N, K;
	cin >> N >> K;
	set<int> kw;
	for (int i = 0; i < K; ++i) {
		int a;
		cin >> a;
		kw.insert(a - 1);
	}
	string ans, tail;
	if (K < N) {
		map<string, int> sm;
		vector<string> sv;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			sm[s] = i;
			sv.push_back(s);
			if (kw.find(i) != kw.end()) {
				if (ans.empty() || s.length() < ans.length()) {
					ans = s;
				}
				if (tail < s) {
					tail = s;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			string s = sv[i];
			if (kw.find(i) != kw.end()) {
				while (ans.length() > 1 && ans != s.substr(0, ans.length())) {
					ans = ans.substr(0, ans.length() - 1);
				}
			}
		}
		if (!ok(kw, sv, ans)) {
			ans = "-1";
		} else {
			map<string, int>::const_iterator it = sm.upper_bound(ans);
			while (it != sm.end() && kw.find(it->second) != kw.end()) {
				++it;
			}
			while (ans.length() > 1) {
				string t = ans.substr(0, ans.length() - 1);
				if (kw.find((sm.lower_bound(t))->second) == kw.end()) {
					break;
				}
				if (it != sm.end()) {
					if ((it->first).substr(0, t.length()) == t) {
						break;
					}
				}
				ans = t;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
