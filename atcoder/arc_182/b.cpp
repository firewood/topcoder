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

vector<int> solve(int N, int K) {
	vector<int> ans;
	map<int, int> v;
	v[1] = N;
	for (int kk = 1; kk < K; ++kk) {
		map<int, int> nv;
		for (auto kv : v) {
			int x = kv.first * 2;
			for (int k = 0; k < kv.second; ++k) {
				int ac = 0, bc = 0;
				{
					auto it = nv.find(x);
					if (it != nv.end()) {
						ac = it->second;
					}
				}
				{
					auto it = nv.find(x + 1);
					if (it != nv.end()) {
						bc = it->second;
					}
				}
				if (ac <= bc) {
					nv[x] += 1;
				} else {
					nv[x + 1] += 1;
				}
			}
		}
		v = nv;
	}
	for (auto kv : v) {
		for (int k = 0; k < kv.second; ++k) {
			ans.emplace_back(kv.first);
		}
	}
	return ans;
}

int main() {
	int T, N, K;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N >> K;
		vector<int> ans = solve(N, K);
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
