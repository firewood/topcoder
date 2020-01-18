// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n = 0, k, s;
	cin >> n >> k >> s;
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		if (i < k) {
			ans[i] = s;
		} else {
			ans[i] = (s < 1e8) ? 1e9 : 1;
		}
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
