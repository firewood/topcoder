// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int a[1000] = {};
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	sort(a, a + N);
	int ans = 1 << 30;
	for (int b = 1; b <= a[0]; ++b) {
		int sum = 0;
		int c;
		for (c = 0; c < N; ++c) {
			int d = a[c] / b;
			if (d <= 0 || a[c] / d > b) {
				break;
			}
			while (d > 1 && a[c] / (d - 1) == b) {
				--d;
			}
			sum += d;
		}
		if (c >= N) {
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}
