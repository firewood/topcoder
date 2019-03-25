// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> sum(n + 1, 0);
	for (int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1];
		sum[i] += (s[i - 1] == 'A' && s[i] == 'C');
	}
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << (sum[r - 1] - sum[l - 1]) << endl;
	}
	return 0;
}
