#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N, L;
	cin >> N >> L;
	int prev = 0;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int x, w, t;
		cin >> x >> w >> t;
		ans += (x - prev);
		prev = x + w;
		int r = t - (ans % (t * 2));
		if (r < w) {
			ans += r + t;
		}
		ans += w;
	}
	ans += (L - prev);
	cout << ans << endl;
	return 0;
}
