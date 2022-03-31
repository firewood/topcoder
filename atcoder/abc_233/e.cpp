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

string solve(std::string X) {
	int N = X.length();
	vector<int64_t> sum(N + 1);
	for (int i = 0; i < N; ++i) {
		sum[i + 1] = sum[i] + X[i] - '0';
	}
	string ans;
	int64_t c = 0;
	for (int i = N - 1; i >= 0; --i) {
		int64_t a = sum[i + 1] + c;
		ans += char('0' + (a % 10));
		c = a / 10;
	}
	reverse(ans.begin(), ans.end());
	if (c > 0) {
		string x = to_string(c);
		ans = x + ans;
	}
	return ans;
}

int main() {
	std::string X;
	std::cin >> X;
	cout << solve(X) << endl;
	return 0;
}
