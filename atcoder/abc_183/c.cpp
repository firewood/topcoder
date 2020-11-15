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

void solve(long long N, long long K, std::vector<std::vector<long long>> &T) {
	int ans = 0;
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	do {
		LL cost = 0;
		for (int i = 1; i < N; i++) {
			cost += T[seq[i - 1]][seq[i]];
		}
		cost += T[seq[N - 1]][seq[0]];
		ans += cost == K;
	} while (next_permutation(seq.begin() + 1, seq.end()));
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	long long K;
	std::cin >> K;
	std::vector<std::vector<long long>> T(N, std::vector<long long>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> T[i][j]; // T[i][j]--;
		}
	}
	solve(N, K, T);
	return 0;
}
