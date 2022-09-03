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

bool solve(std::string S) {
	bool ans = false;
	if (S[0] != '0') {
		return false;
	}
	int c[] = { S[6] != '0', S[3] != '0', S[1] != '0' || S[7] != '0', S[4] != '0', S[2] != '0' || S[8] != '0', S[5] != '0', S[9] != '0' };
	for (int i = 0; i < 7; ++i) {
		for (int j = i + 2; j < 7; ++j) {
			if (c[i] > 0 && c[j] > 0) {
				for (int k = i + 1; k < j; ++k) {
					if (c[k] == 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << (solve(S) ? "Yes" : "No") << endl;
	return 0;
}
