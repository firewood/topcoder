#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<int> solve(int64_t N, string S) {
	vector<int> ans(N, N);
	int xc = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'x') {
			ans[xc++] = i + 1;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	cin >> N;
	string S;
	cin >> S;
	auto answers = solve(N, S);
	for (const auto ans : answers) {
		cout << ans << endl;
	}
}
