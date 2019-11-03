// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	const LL INF = 1LL << 60;
#ifdef _MSC_VER
	while (true)
#endif
	{
		string s;
		cin >> s;
		int n = s.length() + 1;
		if (n <= 1) return 0;
		vector<int> v(n, -1);
		char prev = -1;
		int m = 0;
		for (int i = 1; i < n; ++i) {
			char c = s[i - 1];
			if (c == '<') {
				v[i] = ++m;
				if (prev != '<') {
					v[i - 1] = 0;
				}
			} else {
				m = 0;
			}
			prev = c;
		}
		prev = -1;
		for (int i = n - 2; i >= 0; --i) {
			char c = s[i];
			if (c == '>') {
				++m;
				v[i] = max(v[i], m);
				if (prev != '>') {
					v[i + 1] = 0;
				}
			} else {
				m = 0;
			}
			prev = c;
		}
		//for (int i = 0; i < n; ++i) {
		//	cout << " " << v[i];
		//}
		//cout << endl;
		long long ans = accumulate(v.begin(), v.end(), 0LL);
		cout << ans << endl;
	}
	return 0;
}
