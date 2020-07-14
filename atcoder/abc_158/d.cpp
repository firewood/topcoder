// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		string s, r;
		int q = -1, t, f, m = 0;
		cin >> s >> q;
		if (q < 0) return 0;
		for (int i = 0; i < q; ++i) {
			cin >> t;
			if (t == 1) {
				m = !m;
			} else {
				char c;
				cin >> f;
				cin >> c;
				if ((m == 0 && f == 2) || (m == 1 && f == 1)) {
					s += c;
				} else {
					r += c;
				}
			}
		}
		reverse(r.begin(), r.end());
		string ans = r + s;
		if (m) {
			reverse(ans.begin(), ans.end());
		}
		cout << ans << endl;
	}
	return 0;
}
