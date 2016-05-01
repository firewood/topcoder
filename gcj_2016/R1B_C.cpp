// Google Code Jam 2016 Round 1B
// Problem C. Technobabble

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> G[2000];
int match[2000];
bool used[2000];

static void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

static bool dfs(int v) {
	used[v] = true;
	int i;
	for (i = 0; i < (int)G[v].size(); ++i) {
		int u = G[v][i];
		int w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

vector<int> str2int(const vector<string> &w) {
	vector<int> v;
	int index = 0;
	map<string, int> dic;
	for (const string &s : w) {
		if (dic.find(s) == dic.end()) {
			dic[s] = index++;
		}
		v.push_back(dic[s]);
	}
	return v;
}

int solve1(const vector<int> &a, const vector<int> &b) {
	int N = (int)a.size();
	int af = 0, bf = 0;
	for (int i = 0; i < N; ++i) {
		af |= 1 << a[i];
		bf |= 1 << b[i];
	}
	int ans = 0;
	int mx = 1 << N;
	for (int i = 1; i < mx; ++i) {
		int x = 0, y = 0;
		for (int j = 0; j < N; ++j) {
			if ((1 << j) & i) {
				x |= 1 << a[j];
				y |= 1 << b[j];
			}
		}
		if (x == af && y == bf) {
			ans = max(ans, N - popcount(i));
		}
	}
	return ans;
}

int solve2(const vector<int> &a, const vector<int> &b) {
	int N = (int)a.size();
	for (int i = 0; i < 2000; ++i) {
		G[i].clear();
	}
	for (int i = 0; i < N; ++i) {
		add_edge(a[i], 1000 + b[i]);
	}
	int cnt = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < 1000; ++i) {
		if (match[i] < 0) {
			memset(used, 0, sizeof(used));
			cnt += dfs(i);
		}
	}
	int cover = *max_element(a.begin(), a.end()) + 1 + *max_element(b.begin(), b.end()) + 1 - cnt;
	return N - cover;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<string> sa, sb;
		for (int i = 0; i < N; ++i) {
			string p, q;
			cin >> p >> q;
			sa.push_back(p);
			sb.push_back(q);
		}
		vector<int> ia = str2int(sa);
		vector<int> ib = str2int(sb);
		int ans = solve2(ia, ib);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
