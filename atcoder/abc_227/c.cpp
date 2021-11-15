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

int64_t solve(int64_t N) {
    int64_t ans = 0;
    for (int64_t a = 1; a * a * a <= N; ++a) {
        for (int64_t b = a; a * b * b <= N; ++b) {
            ans += N / a / b - b + 1;
        }
    }
    return ans;
}

int main() {
    int64_t N;
    std::cin >> N;
    cout << solve(N) << endl;
    return 0;
}
