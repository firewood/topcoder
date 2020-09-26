#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(std::string S) {
	string ans = S;
	ans += S.back() == 's' ? "es" : "s";
	cout << ans << endl;
}

int main() {
    std::string S;
	std::cin >> S;
	solve(S);
	return 0;
}
