// D.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(10);
	int n, elapsed = 0, speed = 0, x;
	double ans = 0;
	cin >> n;
	vector<int> t(n), v(n);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		elapsed += x;
		t[i] = elapsed;
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	t.push_back(t.back());
	v.push_back(0);
	elapsed = 0;
	for (int i = 0; i <= n; ++i) {
		for (; elapsed < t[i]; ++elapsed) {
			int next = min(speed + 1, v[i]);
			for (int k = i + 1; k <= n; ++k) {
				next = min(next, v[k] + t[k - 1] - elapsed - 1);
			}
			ans += speed + (next - speed) * 0.125;
			if (speed == next && speed < v[i]) {
				ans += 0.25;
			}
			speed = next;
		}
	}
	cout << ans << endl;
	return 0;
}
