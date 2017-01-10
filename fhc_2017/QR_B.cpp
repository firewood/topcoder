//
// Facebook Hacker Cup 2017 Qualification Round
// B. Lazy Loading
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<int> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		sort(w.rbegin(), w.rend());
		int ans = 0, r = n, pos = 0;
		while (r > 0) {
			int top = w[pos++], tot = top;
			--r;
			while (r > 0 && tot < 50) {
				tot += top;
				--r;
			}
			ans += tot >= 50;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
