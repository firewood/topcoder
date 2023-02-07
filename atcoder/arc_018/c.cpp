#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, M, x0, a, p, ans = 0;
	cin >> N >> M;
	cin >> x0 >> a >> p;
	vector<vector<int>> b(N, vector<int>(M));
	int prev = x0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			b[i][j] = prev;
			prev = (prev + a) % p;
		}
	}
	if (prev != x0) {
		vector<pair<int, pair<int, int>>> v;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				v.push_back({ b[i][j],{ i, j} });
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < N; ++i) {
			vector<pair<int, int>> w;
			for (int j = 0; j < M; ++j) {
				w.emplace_back(v[i * M + j].second.second, v[i * M + j].second.first);
			}
			sort(w.begin(), w.end());
			for (int j = 0; j < M; ++j) {
				ans += abs(j - w[j].first) + abs(i - w[j].second);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
