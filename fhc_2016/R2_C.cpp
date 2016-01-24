//
// Facebook Hacker Cup 2016 Round 2
// C. Snakes and Ladders
//

/*
Constraints

1 <= T <= 50 
1 <= N <= 200,000 
0 <= Xi, Hi <= 1,000,000,000

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;
typedef vector<II> IIVec;
typedef set<int> IntSet;
typedef map<int, IntSet> IntSetMap;

#define MOD 1000000007

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
};

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		modll ans = 0;
		IntSetMap m;
		IIVec v(N);
		for (int n = 0; n < N; ++n) {
			int x, h;
			cin >> x >> h;
			v[n] = II(x, h);
		}
		sort(v.begin(), v.end());

		for (int n = 0; n < N; ++n) {
			int x = v[n].first, h = v[n].second;
			IntSetMap::iterator it = m.begin();
			while (it != m.end() && it->first < h) {
				it = m.erase(it);
			}
			IntSet &s = m[h];
			if (s.size() > 0) {
				IntSet::const_iterator p;
				for (p = s.begin(); p != s.end(); ++p) {
					LL d = x - *p;
					ans += d * d;
				}
			}
			s.insert(x);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
