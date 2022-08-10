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

bool solve(int64_t N, std::vector<std::string> A) {
	char table[256];
	table['-'] = '-';
	table['D'] = 'D';
	table['L'] = 'W';
	table['W'] = 'L';
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] != table[A[j][i]]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << (solve(N, A) ? "correct" : "incorrect") << endl;
	return 0;
}
