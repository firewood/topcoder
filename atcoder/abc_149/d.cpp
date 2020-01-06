// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, k, r, s, p, score[256] = {}, ans = 0;
	string t;
	cin >> n >> k >> r >> s >> p >> t;
	score['r'] = p;
	score['s'] = r;
	score['p'] = s;
	for (int i = 0; i < n; ++i) {
		if (i >= k && t[i] == t[i - k]) {
			t[i] = 0;
		} else {
			ans += score[t[i]];
		}
	}
	cout << ans << endl;
	return 0;
}
