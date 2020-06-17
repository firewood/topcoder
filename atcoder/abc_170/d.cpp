// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAX_N = 1000000;

int main(int argc, char* argv[]) {
	int n, ans = 0;
	cin >> n;
	vector<int> a(n), ng(MAX_N + 1);
	map<int, int> count;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		count[a[i]] += 1;
		if (count[a[i]] == 1) {
			for (int j = a[i] * 2; j <= MAX_N; j += a[i]) {
				ng[j] = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		ans += count[a[i]] == 1 && ng[a[i]] == 0;
	}
	cout << ans << endl;
	return 0;
}
