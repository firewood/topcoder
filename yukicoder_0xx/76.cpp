#include <iostream>
#include <sstream>

using namespace std;

double p[7] = { 0, 1.0 / 12, 2.0 / 12, 3.0 / 12, 1.0 / 12, 3.0 / 12, 2.0 / 12 };
double dp[1000007];

int main(int argc, char *argv[])
{
	cout.precision(12);
	for (int i = 6; i <= 1000006; ++i) {
		dp[i] = 1 + dp[i - 1] * p[1] + dp[i - 2] * p[2] + dp[i - 3] * p[3] + dp[i - 4] * p[4] + dp[i - 5] * p[5] + dp[i - 6] * p[6];
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int n;
		cin >> n;
		cout << dp[5 + n] << endl;
	}
	return 0;
}
