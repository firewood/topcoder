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

int64_t g(int64_t x) {
	int64_t a = sqrt(2 * x);
	while (a > 0 && ((a + 1) * a) / 2 > x) {
		--a;
	}
	return a;
}

string solve(int64_t N) {
	string ans;
	int ch = 1;
	while (N > 0) {
		if (!ans.empty()) {
			ans += char('0' + ch);
		}
		int64_t a = g(N);
		ans += string(a, '7');
		N -= ((a + 1) * a) / 2;
		for (int i = 0; i < a; ++i) {
			ch = (ch * 10) % 7;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	string ans = solve(N);
	cout << ans << endl;
	return 0;
}
