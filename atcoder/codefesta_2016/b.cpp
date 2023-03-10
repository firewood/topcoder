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

set<int> solve(int64_t N) {
	set<int> ans;
	int sum = 0;
	for (int i = 1; sum < N; ++i) {
		sum += i;
		ans.insert(i);
	}
	ans.erase(sum - N);
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	set<int> ans = solve(N);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
