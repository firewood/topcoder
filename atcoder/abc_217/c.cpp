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

vector<int> solve(int N, std::vector<int> p) {
	vector<int> ans(N);
	for (int i = 0; i < N; ++i) {
		ans[p[i]] = i;
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> p(N);
	for (int i = 0; i < N; i++) {
		std::cin >> p[i];
		--p[i];
	}
	vector<int> ans = solve(N, p);
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << (ans[i] + 1);
	}
	cout << endl;
	return 0;
}
