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

typedef long long LL;

char solve(std::string S, long long X) {
	vector<LL> q;
	LL cnt = 0;
	for (char c : S) {
		if (c <= '9') {
			cnt *= (c - '0' + 1);
		} else {
			++cnt;
		}
		q.emplace_back(cnt);
		if (cnt > X) break;
	}
	for (LL i = q.size() - 1; i >= 0; --i) {
		if (S[i] <= '9') {
			while (X > q[i - 1]) {
				X -= q[i - 1];
			}
		} else if (X >= q[i]) {
			return S[i];
		}
	}
}

int main() {
    std::string S;
	std::cin >> S;
	long long X;
	std::cin >> X;
	cout << solve(S, X) << endl;
	return 0;
}
