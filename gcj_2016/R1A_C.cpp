// Google Code Jam 2016 Round 1A
// Problem C. BFFs

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int dfs(vector<int> &f, vector<int> &v, int n, int &ed) {
	if (v[n]) {
		ed = n;
		return 0;
	} else {
		v[n] = 1;
		return 1 + dfs(f, v, f[n], ed);
	}
}

int dfs2(vector< set<int> > &rev, int n) {
	int len = 0;
	for (int nx : rev[n]) {
		len = max(len, 1 + dfs2(rev, nx));
	}
	return len;
}

int solve(vector<int> &f) {
	int N = (int)f.size();
	vector< set<int> > r(N);
	for (int i = 0; i != N; ++i) {
		r[f[i]].insert(i);
	}
	vector<int> u(N);
	int a = 0, b = 0;
	for (int i = 0; i != N; ++i) {
		if (!u[i]) {
			vector<int> v = u;
			int ed;
			int len = dfs(f, v, i, ed);
			if (i == ed) {
				u = v;
				if (len == 2) {
					r[i].erase(f[i]);
					r[f[i]].erase(i);
					b += 2 + dfs2(r, i) + dfs2(r, f[i]);
				} else {
					a = max(a, len);
				}
			}
		}
	}
	return max(a, b);
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<int> f(N);
		for (int i = 0; i < N; ++i) {
			cin >> f[i];
			--f[i];
		}
		cout << "Case #" << t << ": " << solve(f) << endl;
	}
	return 0;
}
