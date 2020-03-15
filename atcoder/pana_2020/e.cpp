// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		string a, b, c;
		getline(cin, a);
		getline(cin, b);
		getline(cin, c);
		if (a.empty() || b.empty() || c.empty()) return 0;
		vector<bool> ab(20000), bc(20000), ca(20000);
		auto fill = [](const string& a, const string& b, vector<bool> &f) {
			for (size_t i = 0; i < a.length(); ++i) {
				for (size_t j = 0; j < b.length(); ++j) {
					if (!(a[i] == '?' || b[j] == '?' || a[i] == b[j])) {
						f[10000 + i - j] = true;
					}
				}
			}
		};
		fill(a, b, ab);
		fill(b, c, bc);
		fill(c, a, ca);
		int ans = 1 << 30;
		for (int i = -4000; i <= 4000; ++i) {
			for (int j = -4000; j <= 4000; ++j) {
				if (!ab[10000 + i] && !bc[10000 - i + j] && !ca[10000 - j]) {
					int left = min({ 0, i, j });
					int right = max({ (int)a.length(), i + (int)b.length(), j + (int)c.length() });
					ans = min(ans, right - left);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
