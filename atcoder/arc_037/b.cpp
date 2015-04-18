// B.

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int N, M;
int e[128][128];
int vis[128];

bool dfs(int n) {
	vis[n] = 1;
	bool r = true;
	for (int i = 0; i < N; ++i) {
		if (e[i][n]) {
			e[i][n] = 0, e[n][i] = 0;
			if (vis[i]) {
				r = false;
			} else if (!dfs(i)) {
				r = false;
			}
		}
	}
	return r;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N >> M;
	for (int i = 0; i < M; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int a, b;
		ss >> a >> b;
		e[a - 1][b - 1] = 1;
		e[b - 1][a - 1] = 1;
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (!vis[i] && dfs(i)) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
