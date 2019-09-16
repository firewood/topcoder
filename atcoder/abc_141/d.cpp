// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, m = -1;
		cin >> n >> m;
		if (n <= 0 || m <= 0) break;
		priority_queue<int> q;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			q.push(a);
		}
		for (int i = 0; i < m; ++i) {
			int x = q.top();
			q.pop();
			q.push(x / 2);
		}
		LL ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += q.top();
			q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
