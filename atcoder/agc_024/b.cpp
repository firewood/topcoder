// B. Backfront

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> pos(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pos[a] = i;
	}
	pos[0] = 1<<30;
	int cnt = 0, mx = 0;
	for (int i = 1; i <= n; ++i) {
		if (pos[i - 1] > pos[i]) {
			cnt = 0;
		}
		++cnt;
		mx = max(mx, cnt);
	}
	int ans = n - mx;
	cout << ans << endl;
	return 0;
}
