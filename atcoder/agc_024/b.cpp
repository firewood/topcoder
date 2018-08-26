// B. Backfront

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, mx = 0;
	cin >> n;
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cnt[a] = cnt[a - 1] + 1;
		mx = max(mx, cnt[a]);
	}
	int ans = n - mx;
	cout << ans << endl;
	return 0;
}
