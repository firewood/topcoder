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

typedef pair<int64_t, int64_t> II;

set<int64_t> solve(int64_t N, int64_t X, int64_t Y, int64_t Z, std::vector<int64_t> A, std::vector<int64_t> B) {
    set<int64_t> ans;
    set<II> s;
    for (int64_t i = 0; i < N; ++i) {
        s.insert(II(-A[i], i));
    }
    for (int64_t i = 0; i < X && !s.empty(); ++i) {
        ans.insert(s.begin()->second);
        s.erase(s.begin());
    }
    set<II> s2;
    for (auto kv : s) {
        int64_t i = kv.second;
        s2.insert(II(-B[i], i));
    }
    for (int64_t i = 0; i < Y && !s2.empty(); ++i) {
        ans.insert(s2.begin()->second);
        s2.erase(s2.begin());
    }
    set<II> s3;
    for (auto kv : s2) {
        int64_t i = kv.second;
        s3.insert(II(-(A[i] + B[i]), i));
    }
    for (int64_t i = 0; i < Z && !s3.empty(); ++i) {
        ans.insert(s3.begin()->second);
        s3.erase(s3.begin());
    }
	return ans;
}

int main() {
    int64_t N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::vector<int64_t> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    set<int64_t> ans = solve(N, X, Y, Z, A, B);
    for (auto x : ans) {
        cout << x + 1 << endl;
    }
	return 0;
}
