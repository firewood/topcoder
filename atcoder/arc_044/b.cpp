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

static const long long MOD = 1000000007;

map<pair<int, int>, int> memo;

struct modll {
	long long x;
	modll() { }
	modll(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(int y) { return (x + y + MOD) % MOD; }
	modll operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modll operator-(int y) { return (x - y + MOD) % MOD; }
	modll operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modll operator*(int y) { return (x * y) % MOD; }
	modll operator*=(int y) { x = (x * y) % MOD; return *this; }
	modll operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modll operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
        pair<int, int> key = make_pair(a, b);
        if (memo.find(key) != memo.end()) return memo[key];
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
        return memo[key] = r;
	}
};

LL solve(long long N, std::vector<int> &A) {
    int mx = *max_element(A.begin(), A.end());
    if (mx >= N) {
        return 0;
    }
    vector<int> count(N);
    for (int i = 0; i < N; i++) {
        count[A[i]] += 1;
    }
    if (A[0] != 0 || count[0] > 1) {
        return 0;
    }
    modll ans = 1;
    for (int i = 1; i <= mx; ++i) {
        int c = count[i];
        ans *= modll::modpow(2, (((LL)c * (c - 1)) / 2) % (MOD - 1));
        ans *= modll::modpow(modll::modpow(2, count[i - 1]) - 1, c);
    }
    return ans;
}

int main() {
#if DEBUG
    freopen("in_1.txt", "r", stdin);
#endif

    long long N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i]; // A[i]--;
    }
    cout << solve(N, A) << endl;
	return 0;
}
