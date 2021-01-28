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
typedef pair<LL, LL> II;
static const LL INF = 1LL << 60;

void solve(long long N, long long X, std::vector<long long> &T, std::vector<long long> &A) {
    LL left = 0, right = N + 1;
    vector<II> v;
    for (int i = 0; i < N; i++) {
        v.emplace_back(II(A[i], T[i] - 1));
    }
    sort(v.rbegin(), v.rend());
    auto possible = [&](LL t) -> bool {
        LL sum = 0;
        set<LL> s;
        for (int i = 0; i < t; i++) {
            s.insert(-i);
        }
        for (int i = 0; i < N; i++) {
            auto x = s.lower_bound(-v[i].second);
            if (x != s.end()) {
                sum += v[i].first;
                s.erase(x);
            }
        }
        return sum >= X;
    };
    while (right - left > 1) {
        LL mid = (left + right) / 2;
        if (possible(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    LL ans = right > N ? -1 : left + 1;
    cout << ans << endl;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif

	long long N, X;
	std::cin >> N >> X;
	std::vector<long long> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	solve(N, X, T, A);
	return 0;
}
