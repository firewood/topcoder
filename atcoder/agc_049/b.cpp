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

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

LL solve(int N, std::string S, std::string T) {
//	int a1 = count(S.begin(), S.end(), '1');
//	int b1 = count(T.begin(), T.end(), '1');
//	if (b1 > a1) return -1;
//	if ((a1 - b1) % 2) return -1;

	LL ans = 0, op = 0;
	for (op = 0; op < N; ++op) {
		if (S[op] == '1') {
			break;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (T[i] == '0') {
			if (S[i] == '0') continue;
			for (; op < N; ++op) {
				if (S[op] == '1') {
					break;
				}
			}
			if (op >= N) return -1;
			ans += op - i;
			S[op] = '0';
			++op;
			for (; op < N; ++op) {
				if (S[op] == '1') {
					break;
				}
			}
			if (op >= N) return -1;
			ans += op - i;
			S[op] = '0';
			++op;
		} else {
			for (; op < N; ++op) {
				if (S[op] == '1') {
					break;
				}
			}
			if (op >= N) return -1;
			ans += op - i;
			S[op] = '0';
			S[i] = '1';
			++op;
		}
	}
//	if (S != T)return -1;
	return ans;
}


int solve2(int N, std::string S, std::string T) {
	if (S == T)return 0;
	set<string> m;
	vector<string> q;
	q.emplace_back(S);
	int tt = 0;
	while (!q.empty()) {
		++tt;
		vector<string> nq;
		for (string s : q) {
			for (int i = 1; i < N; ++i) {
				if (s[i] == '1') {
					string t = s;
					t[i] = '0';
					t[i - 1] ^= 1;
					if (t == T) {
						return tt;
					}
					if (m.find(t) == m.end()) {
						nq.emplace_back(t);
						m.insert(t);
					}
				}
			}
		}
		q = nq;
	}
	return -1;
}

int main() {
    int N;
	std::cin >> N;
	std::string S;
	std::cin >> S;
	std::string T;
	std::cin >> T;
	LL ans = solve(N, S, T);
	cout << ans << endl;
//	ans = solve2(N, S, T);
//	cout << ans << endl;

#if defined(_WIN32) && defined(NDEBUG)
	for (int tt = 0; tt < 100000; ++tt) {
		int n = 18;
//		int n = 1 + (rand() % 15);
		string s(n, '0'), t(n, '0');
		for (int i = 0; i < n; ++i) {
			if ((rand() % 5) <= 1)s[i] ^= 1;
			if ((rand() % 10) <= 1)t[i] ^= 1;
		}
		int a = solve(n, s, t);
		int b = solve2(n, s, t);
		if (a != b) {
			cout << s << endl;
			cout << t << endl;
			++n;
			--n;
			break;
		}
	}
	cout << "DONE" << endl;
#endif

	return 0;
}
