// D.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

LL a;
LL b;

bool possible(LLVec &v, LL x) {
	LL r = x;
	for (int i = 0; i != v.size(); ++i) {
		LL c = max(0LL, v[i] - b * x);
		r -= (c + (a - b) - 1) / (a - b);
	}
	return r >= 0;
}

int main(int argc, char *argv[]) {
	LL n, low = 0, high = 0;
	cin >> n >> a >> b;
	LLVec v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		high += (v[i] + a - 1) / a;
	}
	while (high - low > 1) {
		LL mid = (high + low) / 2;
		if (possible(v, mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	cout << high << endl;
	return 0;
}
