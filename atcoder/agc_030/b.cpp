// B. 

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL ans = 0;
	LL l, n;
	cin >> l >> n;
	vector<LL> pos(n + 2);
	for (LL i = 1; i <= n; ++i) {
		cin >> pos[i];
	}
	for (LL s = 1; s <= n; ++s) {
		for (int i = 0; i < 2; ++i) {
			LL left = s, right = s, last = s, t = 0;
			int f = i;
			while (left > 1 || right < n) {
				LL a = 0, b = 0;
				if (left > 1) {
					if (last == right) {
						a = l - pos[last] + pos[left - 1];
					} else {
						a = pos[left] - pos[left - 1];
					}
				}
				if (right < n) {
					if (last == left) {
						b = pos[left] + l - pos[right + 1];
					} else {
						b = pos[right + 1] - pos[right];
					}
				}
				if ((a > 0 && f) || !b) {
					t += a;
					--left;
					last = left;
				} else {
					t += b;
					++right;
					last = right;
				}
				f = !f;
			}
			if (last == left) {
				t += pos[left];
			} else {
				t += l - pos[right];
			}
			ans = max(ans, t);
		}
	}
	cout << ans << endl;
	return 0;
}
