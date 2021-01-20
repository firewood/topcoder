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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

void solve(std::string S, std::string T, long long q, std::vector<long long> &a, std::vector<long long> &b, std::vector<long long> &c, std::vector<long long> &d) {
	vector<int> ssum(S.length() + 1);
	vector<int> tsum(S.length() + 1);
	for (int i = 0; i < S.length(); ++i) {
		ssum[i + 1] = ssum[i] + (S[i] == 'A' ? 1 : 2);
	}
	for (int i = 0; i < T.length(); ++i) {
		tsum[i + 1] = tsum[i] + (T[i] == 'A' ? 1 : 2);
	}
	for (int i = 0; i < q; ++i) {
		int s = ssum[b[i] + 1] - ssum[a[i]];
		int t = tsum[d[i] + 1] - tsum[c[i]];
		bool ans = (s % 3) == (t % 3);
		cout << (ans ? "YES" : "NO") << endl;
	}
}

int main() {
    std::string S;
	std::cin >> S;
	std::string T;
	std::cin >> T;
	long long q;
	std::cin >> q;
	std::vector<long long> a(q);
	std::vector<long long> b(q);
	std::vector<long long> c(q);
	std::vector<long long> d(q);
	for (int i = 0; i < q; i++) {
		std::cin >> a[i]; a[i]--;
		std::cin >> b[i]; b[i]--;
		std::cin >> c[i]; c[i]--;
		std::cin >> d[i]; d[i]--;
	}
	solve(S, T, q, a, b, c, d);
	return 0;
}
