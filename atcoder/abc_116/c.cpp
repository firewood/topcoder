// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	int n, ans = 0;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	while (true) {
		int s, e;
		for (s = 0; s < n; ++s) {
			if (h[s]) {
				break;
			}
		}
		if (s >= n) {
			break;
		}
		++ans;
		for (int i = s; i < n; ++i) {
			if (!h[i]) {
				break;
			}
			--h[i];
		}
	}
	cout << ans << endl;
	return 0;
}
