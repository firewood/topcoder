#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	N /= 4;
	int ans = 0;
	int M = (int)sqrt(N);
	for (int n = 1; n <= M; ++n) {
		for (int m = n + 1; m <= M; ++m) {
			if (((m - n) % 2) == 0 || gcd(n, m) != 1) {
				continue;
			}
			int a = m * m - n * n;
			int b = 2 * m * n;
			int c = m * m + n * n;
			if (a + b + c > N) {
				break;
			}
			++ans;
		}
	}
	cout << (ans % 1000003) << endl;
	return 0;
}
