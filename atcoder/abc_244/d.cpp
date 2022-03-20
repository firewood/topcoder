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

bool solve(std::vector<std::string> S, std::vector<std::string> T) {
	for (int t = 0; t < 100; ++t) {
		vector<string> x = S;
		for (int i = 0; i < 4; ++i) {
			int a = 0, b = 0;
			while (a == b) {
				a = rand() % 3, b = rand() % 3;
			}
			swap(x[a], x[b]);
		}
		if (x == T) {
			return true;
		}
	}
	return false;
}

int main() {
	std::vector<std::string> S(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> S[i];
	}
	std::vector<std::string> T(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> T[i];
	}
	cout << (solve(S, T) ? "Yes" : "No") << endl;
	return 0;
}
