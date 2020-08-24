#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <queue>

#pragma GCC diagnostic ignored "-Wunused-result"

using namespace std;

typedef long long LL;

void solve(long long n, long long m, std::string s) {
	LL goal = n, prev = -1;
	vector<LL> ans(1, n);
	for (LL i = n - 1; i >= 0; --i) {
		if (i + m < goal) {
			if (prev < 0) {
				cout << -1 << endl;
				return;
			}
			goal = prev;
			prev = -1;
			ans.push_back(goal);
		}
		if (s[i] == '0') {
			prev = i;
		}
	}
	ans.push_back(0);
	reverse(ans.begin(), ans.end());
	for (LL i = 1; i < (LL)ans.size(); ++i) {
		if (i > 1) {
			cout << " ";
		}
		cout << (ans[i] - ans[i - 1]);
	}
	cout << endl;
}

int main() {
    long long N;
	scanf("%lld", &N);
	long long M;
	scanf("%lld", &M);
	std::string S;
	std::cin >> S;
	solve(N, M, S);
	return 0;
}
