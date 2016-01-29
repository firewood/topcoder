#include <iostream>
#include <sstream>
#include <numeric>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int N, A[100], G, ans = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		G = (i == 0) ? A[i] : gcd(A[i], G);
	}
	for (int i = 0; i < N; ++i) {
		ans += A[i] / G;
	}
	cout << ans << endl;
	return 0;
}
