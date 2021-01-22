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

void solve(long long N, long long C, std::vector<long long> &a, std::vector<long long> &b, std::vector<long long> &c) {
	vector<int> aseq(N), bseq(N);
	iota(aseq.begin(), aseq.end(), 0);
	iota(bseq.begin(), bseq.end(), 0);
	sort(aseq.begin(), aseq.end(), [&](int lhs, int rhs) {
		return a[lhs] < a[rhs];
	});
	sort(bseq.begin(), bseq.end(), [&](int lhs, int rhs) {
		return b[lhs] < b[rhs];
	});
	set<LL> days;
	for (int i = 0; i < N; i++) {
		days.insert(a[i]);
		days.insert(++b[i]);
	}
	LL ans = 0, sum = 0, last_day = 0, ai = 0, bi = 0;
	for (LL day : days) {
		ans += min(sum, C) * (day - last_day);
		last_day = day;
		while (ai < N && a[aseq[ai]] == day) {
			sum += c[aseq[ai++]];
		}
		while (bi < N && b[bseq[bi]] == day) {
			sum -= c[bseq[bi++]];
		}
	}
	cout << ans << endl;
}

int main() {
	long long N, C;
	std::cin >> N >> C;
	std::vector<long long> a(N), b(N), c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
	}
	solve(N, C, a, b, c);
	return 0;
}
