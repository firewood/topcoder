// Google Code Jam 2016 Qualification Round
// Problem C. Coin Jam

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
typedef set<LL> LLSet;
typedef vector<LL> LLVec;

LLVec primes;

void gen_primes() {
	int f[65537] = {};
	primes.clear();
	primes.push_back(2);
	for (LL i = 3; i <= 65536; i += 2) {
		if (!f[i]) {
			primes.push_back(i);
			for (LL j = i * 2; j <= 65536; j += i) {
				f[j] = 1;
			}
		}
	}
}

LL check(int N, int *a, LL *d, LLSet &u) {
	LL n;
	for (int j = 2; j <= 10; ++j) {
		n = 1;
		for (int k = 1; k < N; ++k) {
			n = n * j + a[k];
		}
		for (LL p : primes) {
			if (p >= n) {
				break;
			}
			if ((n % p) == 0) {
				d[j] = p;
				break;
			}
		}
		if (!d[j]) {
			return -1;
		}
	}
	return u.find(n) == u.end() ? n : -1;
}

void solve(int N, int J) {
	LLSet u;
	for (int i = 0; i < J; ++i) {
		while (true) {
			int a[32] = {};
			LL d[11] = {};
			a[0] = 1, a[N - 1] = 1;
			for (int j = 1; j < N - 1; ++j) {
				a[j] = rand() % 2;
			}
			LL n = check(N, a, d, u);
			if (n > 0) {
				u.insert(n);
				cout << n;
				for (int j = 2; j <= 10; ++j) {
					cout << " " << d[j];
				}
				cout << endl;
				break;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	gen_primes();
	LL T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, J;
		cin >> N >> J;
		cout << "Case #" << t << ":" << endl;
		solve(N, J);
	}
	return 0;
}
