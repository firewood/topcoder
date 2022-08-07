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

int solve(int N, std::vector<int> P) {
	int ans = 0, x = N - 1;
	while (x > 0) {
		++ans;
		x = P[x];
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> P(N);
	for (int i = 1; i < N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	cout << solve(N, P) << endl;
	return 0;
}
