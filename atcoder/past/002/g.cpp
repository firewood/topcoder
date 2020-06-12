// G.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char* argv[]) {
	int q, t, d;
	cin >> q;
	deque<II> v;
	for (int i = 0; i < q; ++i) {
		char c;
		cin >> t;
		if (t == 1) {
			cin >> c >> d;
			v.emplace_back(II(d, c));
		} else {
			cin >> d;
			long long sum = 0;
			map<int, long long> m;
			while (d > 0 && !v.empty()) {
				int p = min(d, v.front().first);
				d -= p;
				m[v.front().second] += p;
				v.front().first -= p;
				if (v.front().first <= 0) {
					v.pop_front();
				}
			}
			for (auto kv : m) {
				sum += kv.second * kv.second;
			}
			cout << sum << endl;
		}
	}
	return 0;
}
