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

string solve(int64_t N) {
	string ans;
	for (int i = 60; i >= 0; --i) {
		if (!ans.empty()) {
			ans += "B";
		}
		if ((1LL << i) & N) {
			ans += "A";
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
