// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		const int INF = 1 << 30;
		int n = -1, ans = INF;
		cin >> n;
		if (n < 0) return 0;
		string s;
		cin >> s;
		vector<int> r(n + 1), w(n + 1);
		for (int i = 0; i < n; ++i) {
			r[i + 1] = r[i] + (s[i] == 'R');
			w[i + 1] = w[i] + (s[i] == 'W');
		}
		for (int i = 0; i <= n; ++i) {
			int right = r[n] - r[i];
			int cost = w[i] + right - min(w[i], right);
			ans = min(ans, cost);
		}
		cout << ans << endl;
	}
	return 0;
}
