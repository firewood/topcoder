// B.

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

typedef long long LL;
typedef map<LL, LL> LLMap;
const LL MOD = 1000000007;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	LLMap m;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		LL n;
		ss >> n;
		m[n] += 1;
	}
	LLMap::const_iterator it;
	LL ans = 1;
	LL p = 0;
	LL t = 0;
	for (it = m.begin(); it != m.end(); ++it) {
		for (LL i = 1; i <= it->second; ++i) {
			ans = (ans * i) % MOD;
			t += it->first;
			p += t;
		}
	}
	cout << p << endl;
	cout << ans << endl;
	return 0;
}
