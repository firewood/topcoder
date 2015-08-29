#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main(int argc, char *argv[])
{
	int N, K;
	int x[1000] = {}, y[1000] = {}, z[1000];
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < N; ++i) {
		int n = i + 1;
		for (int j = 0; j < K; ++j) {
			if (n == x[j]) {
				++n;
			} else if (n == y[j]) {
				--n;
			}
		}
		z[i] = n - 1;
	}
	int ans = 1;
	for (int i = 0; i < N; ++i) {
		int c;
		int n = z[i];
		for (c = 1; i != n; ++c) {
			n = z[n];
		}
		ans = lcm(ans, c);
	}
	cout << ans << endl;
	return 0;
}
