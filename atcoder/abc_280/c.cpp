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

int64_t solve(std::string S, std::string T) {
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] != T[i]) {
            return i + 1;
        }
    }
    return S.length() + 1;
}

int main() {
    std::string S, T;
    std::cin >> S >> T;
    cout << solve(S, T) << endl;
    return 0;
}
