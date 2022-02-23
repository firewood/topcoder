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

vector<int> gen_primes(int m) {
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= m; i += 2) {
        for (int prime : primes) {
            if (i < prime * prime) {
                primes.push_back(i);
                break;
            }
            if ((i % prime) == 0) {
                break;
            }
        }
    }
    return primes;
}

bool solve(int A, int B, int C, int D) {
    vector<int> primes = gen_primes(1000);
    set<int> p(primes.begin(), primes.end());
    for (int i = A; i <= B; ++i) {
        bool w = false;
        for (int j = C; j <= D; ++j) {
            if (p.find(i + j) != p.end()) {
                w = true;
            }
        }
        if (!w) {
            return true;
        }
    }
    return false;
}

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    cout << (solve(A, B, C, D) ? "Takahashi" : "Aoki") << endl;
    return 0;
}
