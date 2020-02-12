// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		string s;
		int len, k = -1;
		cin >> s >> k;
		if (k <= 0) return 0;
		len = (int)s.length();
		vector<int> r(len), w(len);
		for (int i = 0; i < len; ++i) {
			r[i] = s[i] - '0';
		}
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			for (int a = 1; a <= 9; ++a) {
				if (i == 0 && a > r[0]) break;
				bool x = i == 0 && a == r[0];
				w[i] = a;
				if (k >= 2) {
					for (int j = i + 1; j < len; ++j) {
						for (int b = 1; b <= 9; ++b) {
							if (x) w[j] = b;
							if (k >= 3) {
								for (int k = j + 1; k < len; ++k) {
									for (int c = 1; c <= 9; ++c) {
										if (x) {
											w[k] = c;
											ans += w <= r;
										} else {
											++ans;
										}
									}
									if (x) w[k] = 0;
								}
							} else {
								ans += w <= r;
							}
						}
						if (x) w[j] = 0;
					}
				} else {
					ans += w <= r;
				}
				w[i] = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
