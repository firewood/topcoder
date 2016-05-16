#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int N, M;
	cin >> N >> M;
	vector<int> a, b;
	for (int i = 0; i < M; ++i) {
		int d;
		cin >> d;
		(d < 0 ? a : b).push_back(abs(d));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 1 << 30;
	if (b.size() >= N) {
		ans = min(ans, b[N - 1]);
	}
	for (int i = 1; i <= min((int)a.size(), N); ++i) {
		if ((i + b.size()) >= N) {
			int p = a[i - 1], q = i >= N ? 0 : b[N - 1 - i];
			ans = min(ans, min(p, q) * 2 + max(p, q));
		}
	}
	cout << ans << endl;
	return 0;
}
