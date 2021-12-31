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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t R, int64_t G, int64_t B) {
    int64_t ans = INF;
    for (int64_t gleft = -300; gleft <= 300; ++gleft) {
        int64_t gcost = 0, gright = gleft + G - 1;
        if (gleft < 0) {
            int64_t a = abs(gleft), b = max(int64_t(0), a - G);
            gcost += ((a + 1) * a) / 2 - ((b + 1) * b) / 2;
            int64_t r = max(int64_t(0), G - a - 1);
            gcost += ((r + 1) * r) / 2;
        } else {
            int64_t a = gright, b = max(int64_t(0), a - G);
            gcost += ((a + 1) * a) / 2 - ((b + 1) * b) / 2;
        }

        int64_t rcost = INF, rr, rl;
        for (int64_t rright = min(int64_t(-100 + 150), gleft - 1); rright >= -100 - 500; --rright) {
            int64_t cost = 0, rleft = rright - R + 1;
            if (rright > -100) {
                int64_t a = abs(rright + 100), b = max(int64_t(0), a - R);
                cost += ((a + 1) * a) / 2 - ((b + 1) * b) / 2;
                int64_t r = max(int64_t(0), R - a - 1);
                cost += ((r + 1) * r) / 2;
            } else {
                int64_t a = abs(rleft + 100), b = max(int64_t(0), a - R);
                cost += ((a + 1) * a) / 2 - ((b + 1) * b) / 2;
            }
            rcost = min(rcost, cost);
        }

        int64_t bcost = INF, bb;
        for (int64_t bleft = max(int64_t(100 - 150), gright + 1); bleft <= 100 + 500; ++bleft) {
            int64_t cost = 0, bright = bleft + B - 1;
            if (bleft < 100) {
                int64_t a = abs(bleft - 100), b = max(int64_t(0), a - B);
                cost += ((a + 1) * a) / 2 - ((b + 1) * b) / 2;
                int64_t r = max(int64_t(0), B - a - 1);
                cost += ((r + 1) * r) / 2;
            } else {
                int64_t a = abs(bright - 100), b = max(int64_t(0), a - B);
                cost += ((a + 1) * a) / 2 - ((b + 1) * b) / 2;
            }
            bcost = min(bcost, cost);
        }
        ans = min(ans, rcost + gcost + bcost);
    }
    return ans;
}

int main() {
    int64_t R, G, B;
    std::cin >> R >> G >> B;
    cout << solve(R, G, B) << endl;
    return 0;
}
