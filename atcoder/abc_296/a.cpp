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

bool solve(int64_t N, std::string S) {
	char prev = 0;
	for (char c : S) {
		if (c == prev) {
			return false;
		}
		prev = c;
	}
	return true;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << (solve(N, S) ? "Yes" : "No") << endl;
	return 0;
}
