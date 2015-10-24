#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	vector<LL> v;
	for (int i = 0; i < N; ++i) {
		LL a, b;
		cin >> a >> b;
		v.push_back(a + 4 * b);
	}
	LL high = *max_element(v.begin(), v.end());
	LL ans = 0;
	for (LL a : v) {
		LL d = high - a;
		if (d % 2) {
			ans = -1;
			break;
		}
		ans += d / 2;
	}
	cout << ans << endl;
	return 0;
}
