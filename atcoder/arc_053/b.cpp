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

int solve(std::string S) {
	int cnt[256] = {};
	for (char c : S) {
		cnt[c] += 1;
	}
	int oc = 0;
	for (auto x : cnt) {
		oc += x % 2;
	}
	if (!oc) {
		return S.length();
	} else {
		return 2 * ((S.length() - oc) / (oc * 2)) + 1;
	}
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
