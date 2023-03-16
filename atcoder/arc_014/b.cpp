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

string solve(int64_t N, std::vector<std::string> W) {
	set<string> s;
	char prev = W.front().front();
	for (int i = 0; i < N; ++i) {
		if (s.find(W[i]) != s.end() || W[i].front() != prev) {
			return i % 2 ? "WIN" : "LOSE";
		}
		s.insert(W[i]);
		prev = W[i].back();
	}
	return "DRAW";
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> W(N);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
	}
	cout << solve(N, W) << endl;
	return 0;
}
