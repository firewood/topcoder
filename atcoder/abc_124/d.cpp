// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, k = -1;
		cin >> n >> k;
		if (n <= 0 || k <= 0) break;
		string s;
		cin >> s;
		vector<int> st(1, 0), ed;
		char prev = '1';
		for (int i = 0; i < (int)s.length(); ++i) {
			if (prev != s[i]) {
				if (s[i] == '0') {
					ed.push_back(i);
				} else {
					st.push_back(i);
				}
			}
			prev = s[i];
		}
		if (prev == '0') {
			st.push_back(s.length());
		}
		ed.push_back(s.length());
		int ans = 0;
		if (st.size() <= k) {
			ans = s.length();
		} else {
			for (int i = 0; i + k < st.size(); ++i) {
				ans = max(ans, ed[i + k] - st[i]);
			}
		}
   		cout << ans << endl;
	}
	return 0;
}
