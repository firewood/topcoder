// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s, t;
	cin >> s >> t;
	int n = (int)s.length();
	vector<int> a(n), b(n), p(256, -1), q(256, -1);
	int si = 0, pi = 0;
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (p[c] < 0) {
			p[c] = si++;
		}
		a[i] = p[c];
		c = t[i];
		if (q[c] < 0) {
			q[c] = pi++;
		}
		b[i] = q[c];
	}
	bool ans = a == b;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
