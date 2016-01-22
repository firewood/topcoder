//
// Facebook Hacker Cup 2016 Round 1
// B. Laundro, Matt
//

/*
Constraints

1 <= T <= 50
1 <= L <= 1,000,000
1 <= N <= 100,000
1 <= M <= 1,000,000,000
1 <= D <= 1,000,000,000
1 <= Wi <= 1,000,000,000

*/

#include <cstdint>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int64_t> LLVec;

struct RingBuffer {
	int N;
	int cnt;
	int rp;
	int wp;
	LLVec buff;

	RingBuffer(int n) {
		N = n;
		cnt = rp = wp = 0;
		buff.resize(N);
	}

	int count(void) const {
		return cnt;
	}

	void push(int64_t t) {
		++cnt;
		buff[wp] = t;
		wp = (wp + 1) % N;
	}

	void pop(void) {
		--cnt;
		rp = (rp + 1) % N;
	}

	int64_t top(void) const {
		return buff[rp];
	}
};

int64_t solve2(int64_t L, int64_t N, int64_t M, int64_t D, LLVec &W) {
	int64_t low = 1;
	int64_t high = W.back() * L;
	while (high - low > 1) {
		int64_t t = (low + high) / 2;
		int64_t c = 0;
		for (int i = 0; i < N; ++i) {
			c += t / W[i];
		}
		((c >= L) ? high : low) = t;
	}

	LLVec tv;
	tv.reserve(L + N);
	for (int i = 0; i < N; ++i) {
		int64_t m = high / W[i];
		for (int j = 1; j <= m; ++j) {
			tv.push_back(W[i] * j);
		}
	}
	sort(tv.begin(), tv.end());

	int dr_size = (int)min(L, M);
	RingBuffer dr(dr_size);

	int stocks = 0;
	int64_t d;
	for (int i = 0; i < L; ++i) {
		int64_t t = tv[i];
		while (dr.count() > 0) {
			d = dr.top();
			if (d > t) {
				break;
			}
			dr.pop();
			if (stocks > 0) {
				--stocks;
				dr.push(d + D);
			}
		}
		if (dr.count() < dr_size) {
			dr.push(t + D);
		} else {
			++stocks;
		}
	}
	while (stocks > 0 || dr.count() > 0) {
		d = dr.top();
		dr.pop();
		if (stocks > 0) {
			--stocks;
			dr.push(d + D);
		}
	}
	return d;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int64_t L, N, M, D;
		cin >> L >> N >> M >> D;
		LLVec W(N);
		for (int i = 0; i < N; ++i) {
			cin >> W[i];
		}
		sort(W.begin(), W.end());
		int64_t ans = solve2(L, N, M, D, W);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
