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

int solve(int N, std::vector<int> A) {
	int ans = 0;
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		map<int, int> nm;
		m[0] += 1;
		for (auto kv : m) {
			int next = kv.first + A[i];
			if (next >= 4) {
				ans += kv.second;
			} else {
				nm[next] = kv.second;
			}
		}
		m = nm;
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
