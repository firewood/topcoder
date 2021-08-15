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

bool solve(int N, vector<int> L, vector<int> R) {
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(make_pair(L[i], R[i]));
	}
	v.emplace_back(make_pair(1 << 30, 1 << 30));
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<>> q;
	int pos = 1;
	for (auto [l, r] : v) {
		while (!q.empty() && pos < l) {
			if (pos > q.top()) {
				return false;
			}
			q.pop();
			++pos;
		}
		pos = l;
		q.emplace(r);
	}
	return true;
}

int main() {
	int T, N;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		vector<int> L(N), R(N);
		for (int i = 0; i < N; ++i) {
			cin >> L[i] >> R[i];
		}
		cout << (solve(N, L, R) ? "Yes" : "No") << endl;
	}
	return 0;
}
