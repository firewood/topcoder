// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, x;
	cin >> n >> x;
	vector<int> l(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		l[i + 1] = l[i] + a;
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans += l[i] <= x;
	}
	cout << ans << endl;
	return 0;
}
