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

vector<int> solve(int N) {
	vector<int> ans;
	ans.emplace_back(3 * 5 * 7);
	for (int i = 2; ans.size() < N; i += 2) {
		if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
			ans.emplace_back(i);
		}
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	vector<int> ans = solve(N);
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;return 0;
}
