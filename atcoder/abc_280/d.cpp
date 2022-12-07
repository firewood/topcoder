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

int64_t solve(int64_t K) {
    int64_t ans = 1;
    int64_t r = K;
    vector<int> p(1000002);
    for (int64_t x = 2; x <= 1000000; ++x) {
        if (!p[x]) {
            for (int64_t j = x; j <= 10000000; j += x) {
                if ((r % x) == 0) {
                    int64_t rr = j;
                    while ((rr % x) == 0 && (r % x) == 0) {
                        r /= x;
                        rr /= x;
                    }
                    ans = max(ans, j);
                }
                if (j <= 1000000) {
                    p[j] = 1;
                }
            }
        }
    }
    return max(ans, r);
}

int main() {
    int64_t K;
    std::cin >> K;
    cout << solve(K) << endl;
    return 0;
}
