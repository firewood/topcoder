// Google Code Jam 2019 
// Problem C. Alien Rhyme

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

struct W {
	int count;
	W *next[256];
	W() {
		count = 0;
		memset(next, 0, sizeof(next));
	}
};

W *pool;

typedef pair<int, string> IS;

int solve(vector<string> w) {
	pool = new W[100000];
	W *avail = pool;
	W *top = avail++;
	for (string s : w) {
		string r = s;
		reverse(r.begin(), r.end());
		W *cur = top;
		cur->count += 1;
		int level = 0;
		for (char c : r) {
			if (!cur->next[c]) {
				cur->next[c] = avail++;
			}
			W *next = cur->next[c];
			next->count += 1;
			cur = next;
			++level;
		}
	}
	vector<IS> v;
	for (string s : w) {
		string r = s;
		reverse(r.begin(), r.end());
		W *cur = top;
		int level = 0, ml = 0;
		for (char c : r) {
			W *next = cur->next[c];
			if (next->count >= 2) {
				ml = level;
			}
			cur = next;
			++level;
		}
		v.push_back(IS(-ml, r));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	set<string> used;
	for (int i = 1; i < (int)v.size(); ++i) {
		const string &x = v[i - 1].second;
		const string &y = v[i].second;
		if (x[0] == y[0]) {
			string p = x.substr(0, 1 - v[i - 1].first);
			string q = y.substr(0, 1 - v[i].first);
			int a = p.length();
			int b = q.length();
			int c = min(a, b);
			p = p.substr(0, c);
			q = q.substr(0, c);
			while (c > 0) {
				if (p == q && used.find(p) == used.end()) {
					used.insert(p);
					ans += 2;
					++i;
					break;
				}
				--c;
				p.resize(c);
				q.resize(c);
			}
		}
	}
	delete pool;
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<string> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		int ans = solve(w);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
