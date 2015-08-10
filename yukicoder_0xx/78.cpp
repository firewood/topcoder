#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N, K;
	string S;
	cin >> N >> K >> S;
	int p[64] = {};
	int b = 0, e = 0;
	int r = 0;
	for (int i = 0; i < 3 * N; ++i) {
		if (r <= 0) {
			++b, ++e;
			if (p[i % N] > 0) {
				int m = (K - e) / N - 1;
				if (m > 0) {
					int t = b - p[i % N];
					b += t * m;
					e += N * m;
				}
			}
			p[i % N] = b;
			r += S[i % N] - '0';
		} else {
			--r;
			++e;
			r += S[i % N] - '0';
		}
		if (e >= K) {
			break;
		}
	}
	cout << b << endl;
	return 0;
}
