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

int64_t solve(int64_t N, int64_t A, int64_t B, int64_t C) {
    int64_t ans = 1LL << 60;
    for (int a = 0; a < 10000; ++a) {
        for (int b = 0; a + b < 10000; ++b) {
            int64_t c = N - A * a - B * b;
            if (c < 0) break;
            if (c % C == 0) {
                ans = min(ans, a + b + c / C);
            }
        }
    }
	return ans;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N, A, B, C;
	std::cin >> N >> A >> B >> C;
	cout << solve(N, A, B, C) << endl;
	return 0;
}
