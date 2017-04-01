// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> g[100000];
vector<int> v, d, c;
int vis[100000];
int dist[100000];

int main(int argc, char *argv[])
{
	int N, M, Q;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> Q;
	v.resize(Q);
	d.resize(Q);
	c.resize(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> v[i] >> d[i] >> c[i];
		--v[i];
	}
	for (int i = 0; i < N; ++i) {
		int ans = 0;
		if (N <= 2000) {
			memset(vis, 0, sizeof(vis));
			memset(dist, 0x3f, sizeof(dist));
			vector<int> q;
			q.push_back(i);
			int dd = 0;
			while (q.size()) {
				vector<int> next;
				for (int n : q) {
					if (!vis[n]) {
						vis[n] = 1;
						dist[n] = dd;
						for (int a : g[n]) {
							next.push_back(a);
						}
					}
				}
				++dd;
				q = next;
			}
			for (int j = Q - 1; j >= 0; --j) {
				if (dist[v[j]] <= d[j]) {
					ans = c[j];
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
