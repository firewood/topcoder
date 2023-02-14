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

int solve(int N, int M, std::string name, std::string kit) {
	char cnt[256] = {}, req[256] = {};
	for (char c : kit) {
		cnt[c] += 1;
	}
	for (char c : name) {
		req[c] += 1;
	}
	int ans = 0;
	for (char c = 'A'; c <= 'Z'; ++c) {
		if (req[c] > 0) {
			if (!cnt[c]) {
				return -1;
			}
			ans = max(ans, (req[c] + cnt[c] - 1) / cnt[c]);
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::string name, kit;
	std::cin >> N >> M >> name >> kit;
	cout << solve(N, M, name, kit) << endl;
	return 0;
}
