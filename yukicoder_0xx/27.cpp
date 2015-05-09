#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	int v[4];
	ss >> v[0] >> v[1] >> v[2] >> v[3];
	sort(v, v + 4);
	int ans = 1 << 20;
	for (int i = 1; i <= v[3]; ++i) {
		int ti[32];
		for (int j = 0; j <= v[3]; ++j) {
			ti[j] = ((j % i) == 0) ? (j / i) : (1 << 20);
		}
		for (int j = i; j <= v[3]; ++j) {
			int tj[32];
			for (int k = v[3]; k >= 0; --k) {
				tj[k] = ti[k];
				for (int l = j; l <= k; l += j) {
					tj[k] = min(tj[k], ti[k - l] + l / j);
				}
			}
			for (int k = j; k <= v[3]; ++k) {
				int tk[32];
				for (int l = v[3]; l >= 0; --l) {
					tk[l] = tj[l];
					for (int m = k; m <= l; m += k) {
						tk[l] = min(tk[l], tj[l - m] + m / k);
					}
				}
				ans = min(ans, tk[v[0]] + tk[v[1]] + tk[v[2]] + tk[v[3]]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
