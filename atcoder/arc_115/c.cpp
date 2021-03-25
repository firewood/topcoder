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

typedef long long LL;

static const LL INF = 1LL << 60;

vector<int> solve(long long N) {
	vector<int> ans(N, 1);
	for (LL i = 2; i <= N; ++i) {
		if (ans[i - 1] == 1) {
			for (LL k = i; k <= N; k *= i) {
				for (LL j = k; j <= N; j += k) {
					ans[j - 1] += 1;
				}
			}
		}
	}
	return ans;
}

int main() {
	long long N;
	std::cin >> N;
	vector<int> ans = solve(N);
	for (int i = 0; i < (int)ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
