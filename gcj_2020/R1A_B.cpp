// Google Code Jam 2020 Round 1A
// Problem B. Pascal Walk

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;

vector<II> solve(int n) {
	const size_t M = 33;
	vector<vector<int>> p(M);
	p[0] = { 1 };
	int sum = 1, i;
	set<II> s;
	for (i = 1; i < M; ++i) {
		vector<int>& prev = p[i - 1];
		vector<int>& curr = p[i];
		curr.resize(i + 1);
		for (int j = 0; j <= i; ++j) {
			int a = j > 0 ? prev[j - 1] : 0;
			int b = j < i ? prev[j] : 0;
			if (a < 0 || b < 0 || a + b > 1e9) {
				a = 0, b = -1;
			}
			curr[j] = a + b;
		}
		if (sum + curr[i / 2] > n) {
			--i;
			break;
		}
		sum += curr[i / 2];
		s.emplace(II(i, i / 2));
	}
	for (; i > 0; --i) {
		int dir = i % 2 ? 1 : -1;
		if (sum + p[i][i / 2 + dir] <= n) {
			sum += p[i][i / 2 + dir];
			s.emplace(II(i, i / 2 + dir));
		}
	}
	vector<II> ans;
	ans.emplace_back(II(0, 0));
	for (int i = 1; i < M; ++i) {
		for (int j = 1; j >= 0; --j) {
			int dir = i % 2 ? 1 : -1;
			II key(i, i / 2 + dir * j);
			if (s.find(key) != s.end()) {
				ans.push_back(key);
			}
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
		vector<II> ans = solve(n);
		cout << "Case #" << t << ":" << endl;
		for (auto kv : ans) {
			cout << (kv.first + 1) << " " << (kv.second + 1) << endl;
		}
	}
	return 0;
}
