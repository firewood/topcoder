// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> LLLL;

LLLL solve(LL x) {
	map<LL, LL> m;
	for (LL i = -2000; i < 2000; ++i) {
		m[i * i * i * i * i] = i;
	}
	for (auto kv : m) {
		LL y = kv.first - x;
		if (m.find(y) != m.end()) {
			return LLLL(-m[y], -kv.second);
		}
	}
	return { 0,0 };
}

int main(int argc, char* argv[]) {
	LL x = -1;
	cin >> x;
	LLLL ans = solve(x);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
