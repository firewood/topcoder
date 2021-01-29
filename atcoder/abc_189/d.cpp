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

LL solve(int N, std::vector<std::string> &S) {
    LL ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        ans |= (S[i] == "OR");
        ans <<= 1;
    }
    return ans | 1;
}

int main() {
#if DEBUG
    freopen("in_1.txt", "r", stdin);
#endif
    int N;
    std::cin >> N;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    cout << solve(N, S) << endl;
    return 0;
}
