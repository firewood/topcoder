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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

int main() {
#if DEBUG
    freopen("in_1.txt", "r", stdin);
#endif

    LL N, Q, t, x;
    cin >> N >> Q;
    LL ans = (N - 2) * (N - 2);
    map<LL, LL> h_y, v_x;
    h_y[0] = N;
    v_x[0] = N;
    LL w = N, h = N;
    for (int q = 0; q < Q; ++q) {
        cin >> t >> x;
        if (t == 1) {
            auto it = h_y.lower_bound(x);
            --it;
            LL y = it->second;
            h_y[x] = y;
            ans -= y - 2;
            if (x < w) {
                w = x;
                v_x[0] = x;
            }
        } else {
            auto it = v_x.lower_bound(x);
            --it;
            LL y = it->second;
            v_x[x] = y;
            ans -= y - 2;
            if (x < h) {
                h = x;
                h_y[0] = h;
            }
        }
    }
	cout << ans << endl;
	return 0;
}
