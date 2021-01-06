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
//typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

void solve(int N, std::vector<long long> &a) {
    vector<LL> max_sum(a.size() + 1), min_sum(a.size() + 1);
    {
        priority_queue<LL, vector<LL>, greater<>> q;
        for (int i = 0; i < a.size(); ++i) {
            q.push(a[i]);
            max_sum[i + 1] = max_sum[i] + a[i];
            if (i >= N) {
                max_sum[i + 1] -= q.top();
                q.pop();
            }
        }
    }
    {
        priority_queue<LL> q;
        for (int i = (int)a.size() - 1; i >= 0; --i) {
            q.push(a[i]);
            min_sum[i] = min_sum[i + 1] + a[i];
            if (i < N * 2) {
                min_sum[i] -= q.top();
                q.pop();
            }
        }
    }
    LL ans = -(1LL << 60);
    for (int i = N; i <= 2 * N; ++i) {
        ans = max(ans, max_sum[i] - min_sum[i]);
    }
	cout << ans << endl;
}

int main() {
#if DEBUG
    freopen("in_1.txt", "r", stdin);
#endif

    int N;
    std::cin >> N;
    std::vector<long long> a(3*N);
    for (int i = 0; i < 3*N; i++) {
        std::cin >> a[i]; // a[i]--;
    }
	solve(N, a);
	return 0;
}
