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

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
    int N, K, v;
    cin >> N >> K;
    set<int> s;
    s.insert(0);
    for (int i = 0; i < N; ++i) {
        set<int> ns;
        for (int j = 0; j < K; ++j) {
            cin >> v;
            for (auto x : s) {
                ns.insert(x ^ v);
            }
        }
        s = ns;
    }
    bool ans = s.find(0) != s.end();
    cout << (ans ? "Found" : "Nothing") << endl;
	return 0;
}
