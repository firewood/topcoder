#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	int N, A[201] = {};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = 1 << 30;
	int sum = accumulate(A, A + N, 0);
	int max_n = (int)sqrt(sum);
	for (int len = 1; len <= max_n; ++len) {
		int in = 0;
		int out = accumulate(A + len * 2 - 1, A + 201, 0);
		for (int j = 0; j < len - 1; ++j) {
			int a = A[j], b = A[len * 2 - 2 - j];
			int d = j + 1 - a;
			if (d > 0) {
				in += d;
			} else {
				out -= d;
			}
			d = j + 1 - b;
			if (d > 0) {
				in += d;
			} else {
				out -= d;
			}
		}
		int d = len - A[len - 1];
		if (d > 0) {
			in += d;
		} else {
			out -= d;
		}
		in -= min(in, out);
		ans = min(ans, in + out);
	}
	cout << ans << endl;
	return 0;
}
