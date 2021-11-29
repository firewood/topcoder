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

vector<int> solve(int64_t N, int64_t M) {
	vector<int> ans(3, -1);
	if (N * 2 <= M && M <= N * 4) {
		M -= N * 2;
		int64_t a = M / 2;
		ans[2] = a;
		N -= a;
		M -= a * 2;
		ans[1] = M;
		N -= M;
		ans[0] = N;
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	vector<int> ans = solve(N, M);
	for (int i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
