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

string solve(int64_t K) {
	string ans;
	while (K > 0) {
		ans += K & 1 ? '2' : '0';
		K >>= 1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	int64_t K;
	std::cin >> K;
	cout << solve(K) << endl;
	return 0;
}
