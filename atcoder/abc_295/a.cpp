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

bool solve(int64_t N, std::vector<std::string> W) {
	const string words[] = { "and", "not", "that", "the", "you" };
	for (auto w : W) {
		for (auto preset_word : words) {
			if (w == preset_word) return true;
		}
	}
	return false;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> W(N);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
	}
	cout << (solve(N, W) ? "Yes" : "No") << endl;
	return 0;
}
