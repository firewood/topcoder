#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 9;
LL tbl[10][100000];

LL ways(LL types, LL amount) {
	if (types <= 0) {
		return 1;
	}
	LL &r = tbl[types][amount];
	if (r >= 0) {
		return r;
	}
	LL a = ways(types - 1, amount);
	if (amount >= types) {
		a = (a + ways(types, amount - types)) % MOD;
	}
	return r = a;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	LL N = atoi(s.c_str());
	memset(tbl, -1, sizeof(tbl));
	for (LL i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		LL m;
		ss >> m;
		cout << ways(9, m / 111111) << endl;
	}
	return 0;
}
