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

string solve(int64_t K) {
    string ans;
    for (int i = 0; i < K; ++i) {
        ans += char('A' + i);
    }
    return ans;
}

int main() {
    int64_t K;
    std::cin >> K;
    cout << solve(K) << endl;
    return 0;
}
