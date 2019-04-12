// B.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef pair<int, int> II;

void solve(int n) {
	vector<II> ans;
	int sum = (n * (n + 1)) / 2 - n - ((n % 2) ? 0 : 1);
	for (int i = 1; i <= n; ++i) {
		int ex = (n * (n + 1)) / 2 - i - sum;
		for (int j = 1; j <= n; ++j) {
			if (j != i && j != ex && j > i) {
				ans.push_back(II(i, j));
			}
		}
	}
	cout << ans.size() << endl;
	for (auto kv : ans) {
		cout << kv.first << " " << kv.second << endl;
	}
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	solve(n);
	return 0;
}
