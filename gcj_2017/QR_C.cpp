// Google Code Jam 2017 Qualification Round
// Problem C. Bathroom Stalls

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

typedef pair<LL, LL> LLLL;

LLLL solve1(LL N, LL K) {
	priority_queue<LL> q;
	q.push(N);
	LLLL ans;
	for (int i = 0; i < K; ++i) {
		LL t = q.top() - 1;
		q.pop();
		ans = { (t / 2) + (t % 2), t / 2 };
		q.push(ans.first);
		q.push(ans.second);
	}
	return ans;
}

LLLL solve2(LL N, LL K) {
	LL r = N, d = 1;
	while (K > d) {
		K -= d;
		r -= d;
		d *= 2;
	}
	LL sz = r / d + (K <= (r % d)) - 1;
	return { sz / 2 + (sz % 2), sz / 2 };
}

int main(int argc, char *argv[]) {
	LL T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		LL N, K;
		cin >> N >> K;
		LLLL ans = solve2(N, K);
		cout << "Case #" << t << ": " << ans.first << " " << ans.second << endl;
	}

//#ifdef _DEBUG
#if 1
	for (int n = 1; n <= 100; ++n) {
		for (int k = 1; k <= n; ++k) {
			LLLL a = solve1(n, k);
			LLLL b = solve2(n, k);
			if (a.first != b.first || a.second != b.second) {
				printf("ERROR: %d, %d\n", n, k);
				break;
			}
		}
	}
#endif

	return 0;
}
