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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

string check(int64_t N, const set<string>& ss, const vector<string>& S, const vector<int>& seq, string s, int index, int rlen) {
    s += S[seq[index++]];
    if (index == S.size()) {
        return s.length() >= 3 && s.length() <= 16 && ss.find(s) == ss.end() ? s : "";
    }
    while (rlen >= 0) {
        s += "_";
        string r = check(N, ss, S, seq, s, index, rlen--);
        if (!r.empty()) {
            return r;
        }
    }
    return "";
}

string solve(int64_t N, int64_t M, std::vector<std::string> S, std::vector<std::string> T) {
    set<string> ss;
    for (int i = 0; i < M; ++i) {
        ss.insert(T[i]);
    }

    int rlen = 16 - (N - 1);
    for (int i = 0; i < N; ++i) {
        rlen -= S[i].length();
    }
    if (rlen >= 0) {
        vector<int> seq(N);
        iota(seq.begin(), seq.end(), 0);
        do {
            string r = check(N, ss, S, seq, "", 0, rlen);
            if (!r.empty()) {
                return r;
            }
        } while (next_permutation(seq.begin(), seq.end()));
    }
    return "-1";
}

int main() {
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    std::vector<std::string> T(M);
    for (int i = 0; i < M; i++) {
        std::cin >> T[i];
    }
    cout << solve(N, M, S, T) << endl;
    return 0;
}
