#include <iostream>
#include <sstream>

using namespace std;

double dp[256];
double p[256];

int main(int argc, char *argv[])
{
	int K;
	cin >> K;
	cout.precision(12);
	p[5] = 1;
	for (int i = 1; i <= K; ++i) {
		dp[5 + i] = 1;
		p[5 + i] = 0;
		for (int j = 1; j <= 6; ++j) {
			dp[5 + i] += dp[5 + i - j] / 6.0;
			p[5 + i] += p[5 + i - j] / 6.0;
		}
	}
	double success = dp[5 + K];
	double fail_rate = 1.0 - p[5 + K];
	double ans = 0, r = 1.0;
	for (int i = 0; i < 100; ++i) {
		ans += r * success;
		r *= fail_rate;
	}
	cout << ans << endl;
	return 0;
}
