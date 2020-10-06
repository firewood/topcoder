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


void solve(long long N, std::vector<long long> &A, std::vector<long long> &B) {
	vector<int> ac(N + 1), bc(N + 1);
	for (int i = 0; i < N; i++) {
		ac[A[i]] += 1;
		bc[B[i]] += 1;
	}
	bool possible = true;
	int shift = 0;
	for (int i = 1; i <= N; i++) {
		ac[i] += ac[i - 1];
		bc[i] += bc[i - 1];
		if (ac[i] + bc[i] > N) {
			possible = false;
			break;
		}
		shift = max(shift, ac[i] - bc[i - 1]);
	}
	cout << (possible ? "Yes" : "No") << endl;
	if (possible) {
		for (int i = 0; i < N; i++) {
			if (i) cout << " ";
			cout << B[(i + shift) % N];
		}
		cout << endl;
	}
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i]; // A[i]--;
	}
	std::vector<long long> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i]; // B[i]--;
	}
	solve(N, A, B);
	return 0;
}
