// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> f(n + 1);
	vector<int> q;
	q.push_back(n);
	int ans = -1;
	while (q.size()) {
		++ans;
		vector<int> next;
		for (int x : q) {
			if (!x) {
				next.clear();
				break;
			}
			int y = x - 1;
			if (!f[y]) {
				f[y] = 1;
				next.push_back(y);
			}
			for (int a = 6; a <= x; a *= 6) {
				y = x - a;
				if (!f[y]) {
					f[y] = 1;
					next.push_back(y);
				}
			}
			for (int a = 9; a <= x; a *= 9) {
				y = x - a;
				if (!f[y]) {
					f[y] = 1;
					next.push_back(y);
				}
			}
		}
		q = next;
	}
	cout << ans << endl;
	return 0;
}
