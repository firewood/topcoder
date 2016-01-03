// B.

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		int a[100001];
		int b[100001];
		bool f = true;
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			int x;
			cin >> x;
			a[i] = x - 1;
			b[x - 1] = i;
			int d = a[i] - i;
			if (d > 2) {
				f = false;
			}
		}
		for (int i = N - 1; i >= 0; --i) {
			int pos = b[i];
			while (pos < i) {
				++ans;
				int x = a[pos + 1];
				a[pos] = x;
				a[pos + 1] = i;
				b[i] = pos + 1;
				b[x] = pos;
				++pos;
			}
		}
		for (int i = 0; f && i < N; ++i) {
			if (a[i] != i) {
				f = false;
			}
		}
		if (f) {
			cout << ans << endl;
		} else {
			cout << "Too chaotic" << endl;
		}
	}
	return 0;
}
