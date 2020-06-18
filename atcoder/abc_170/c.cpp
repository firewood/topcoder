// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	int x, n, p, ans = -1;
	cin >> x >> n;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		s.insert(p);
	}
	for (int i = 0; i <= 101; ++i) {
		if (s.find(i) == s.end()) {
			if (abs(x - i) < abs(ans - x)) {
				ans = i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
