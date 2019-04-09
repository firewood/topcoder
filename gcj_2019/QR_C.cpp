// Google Code Jam 2019 Qualification Round
// Problem C. Cryptopangrams

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int n, int l, vector<int> &v) {
	if (n < 101 || n > 10000) {
		return "";
	}
	set<int> s;
	for (int x : v) {
		for (int i = 2; i <= n; ++i) {
			if ((x % i) == 0) {
				s.insert(i);
				s.insert(x / i);
				break;
			}
		}
	}
	vector<int> p(s.begin(), s.end());
	for (int i = 0; i < (int)p.size(); ++i) {
		if ((v[0] % p[i]) == 0) {
			bool ok = true;
			int prev = p[i];
			string res = string(1, char('A' + i));
			for (int j = 0; ok && j < l; ++j) {
				ok = false;
				for (int k = 0; k < (int)p.size(); ++k) {
					int x = v[j] / prev;
					if (x == p[k] && x * prev == v[j]) {
						ok = true;
						res += char('A' + k);
						prev = x;
						break;
					}
				}
			}
			if (ok) {
				return res;
			}
		}
	}
	return "";
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n, l;
		cin >> n >> l;
		vector<int> v(l);
		for (int i = 0; i < l; ++i) {
			cin >> v[i];
		}
		string ans = solve(n, l, v);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
