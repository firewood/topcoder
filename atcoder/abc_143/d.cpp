// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		LL n = -1, ans = 0;
		cin >> n;
		if (n <= 0) break;
		vector<LL> l(n);
		for (int i = 0; i < n; ++i) {
			cin >> l[i];
		}
		sort(l.begin(), l.end());
		l.push_back(1LL << 60);
		for (LL a = 0; a < n; ++a) {
			for (LL b = a + 1, c = a + 1; b < n; ++b) {
				while (l[c + 1] < l[a] + l[b]) {
					++c;
				}
				ans += c - b;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
