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

string solve(std::string S) {
    map<int, int> m;
    for (auto c : S) {
        m[c] += 1;
    }
    for (auto kv : m) {
        if (kv.second == 1) {
            return string(1, char(kv.first));
        }
    }
    return "-1";
}

int main() {
    std::string S;
    std::cin >> S;
    cout << solve(S) << endl;
    return 0;
}
