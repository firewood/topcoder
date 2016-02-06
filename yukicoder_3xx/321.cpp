#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int P, Q, N;
	cin >> P >> Q >> N;
	int g;
	if (P == 0) {
		g = Q;
	} else if (Q == 0) {
		g = P;
	} else {
		g = gcd(P, Q);
	}
	int ans = 0;
	if (g == 0) {
		for (int i = 0; i < N; ++i) {
			int X, Y;
			cin >> X >> Y;
			ans += (X == 0 && Y == 0);
		}
	} else {
		int r = abs((P - Q) / g) % 2;
		for (int i = 0; i < N; ++i) {
			int X, Y;
			cin >> X >> Y;
			X = abs(X), Y = abs(Y);
			if ((X % g) == 0 && (Y % g) == 0) {
				if (r || (((X + Y) / g) % 2) == 0) {
					++ans;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
