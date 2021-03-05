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

LL solve(long long N, long long K) {
	LL x = N;
	for (LL i = 0; i < K; ++i) {
		string a = to_string(x);
		string b = a;
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		x = stoll(b) - stoll(a);
	}
	return x;
}

int main() {
	long long N, K;
	std::cin >> N >> K;
	cout << solve(N, K) << endl;
	return 0;
}
