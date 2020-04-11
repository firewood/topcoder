// Google Code Jam 2020 Round 1A
// Problem A.

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> II;

string solve(int n, vector<string> w) {
	vector<string> l(n), r(n);
	vector<II> v, rv;
	vector<int> pos(n);
	for (int i = 0; i < n; ++i) {
		int p;
		while ((p = w[i].find("**")) > 0) {
			w[i] = w[i].substr(0, p) + w[i].substr(p + 1);
		}
		p = w[i].find("*");
		l[i] = w[i].substr(0, p);
		r[i] = w[i].substr(p + 1);
		v.push_back(II(l[i].length(), i));
		rv.push_back(II(r[i].length(), i));
	}
	string ans;
	sort(v.rbegin(), v.rend());
	sort(rv.rbegin(), rv.rend());
	string x = l[v[0].second];
	string y = r[rv[0].second];
	for (int j = 0; j <= (int)y.length(); ++j) {
		string z = x + y.substr(y.length() - j);
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (z.length() < l[i].length() + r[i].length()) {
				ok = false;
				break;
			}
			if (z.substr(0, l[i].length()) == l[i] && z.substr(z.length() - r[i].length()) == r[i]) {
				;
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans = z;
			break;
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<string> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		string ans = solve(n, w);
		cout << "Case #" << t << ": " << (ans.empty() ? "*" : ans) << endl;
	}
	return 0;
}
