#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

void solve(std::string W) {
	string aiueo = "aiueo";
	string ans;
	for (char c : W) {
		if (aiueo.find(c) == string::npos) {
			ans += c;
		}
	}
	cout << ans << endl;
}

int main() {
    std::string W;
	std::cin >> W;
	solve(W);
	return 0;
}
