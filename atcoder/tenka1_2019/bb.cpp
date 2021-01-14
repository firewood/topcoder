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

string solve(long long N, std::string S, long long K) {
    string ans;
    for (char c : S) {
        ans += c == S[K - 1] ? c : '*';
    }
    return ans;
}

int main() {
#if DEBUG
    freopen("in_1.txt", "r", stdin);
#endif

    int N, K;
    std::string S;
    std::cin >> N >> S >> K;
    cout << solve(N, S, K) << endl;
	return 0;
}
