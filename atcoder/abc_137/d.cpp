// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, LL> IL;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<IL> v;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back(IL(a, b));
	}
	sort(v.begin(), v.end());
	priority_queue<LL, vector<LL> > q;
	int pos = 0;
	LL ans = 0;
	for (int i = 0; i <= m; ++i) {
		while (pos < n && v[pos].first <= i) {
			q.push(v[pos].second);
			++pos;
		}
		if (q.size()) {
			LL t = q.top();
			q.pop();
			ans += t;
		}
	}
	cout << ans << endl;
	return 0;
}
