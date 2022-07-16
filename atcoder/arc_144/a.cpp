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

void solve(int N) {
	int ans = N * 2;
	cout << ans << endl;
	string s;
	while (N > 0) {
		int c = min(4, N);
		s += char('0' + c);
		N -= c;
	}
	sort(s.begin(), s.end());
	cout << s << endl;
}

int main() {
	int N;
	std::cin >> N;
	solve(N);
	return 0;
}
