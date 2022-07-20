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

int64_t solve(int64_t N, int64_t X, int64_t Y) {
    int64_t red = 1, blue = 0;
    for (int64_t i = N; i >= 2; --i) {
        blue += red * X;
        red += blue;
        blue *= Y;
    }
    return blue;
}

int main() {
    int64_t N, X, Y;
    std::cin >> N >> X >> Y;
    cout << solve(N, X, Y) << endl;
    return 0;
}
