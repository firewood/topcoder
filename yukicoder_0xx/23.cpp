#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int H, A, D;
	stringstream ss(s);
	ss >> H >> A >> D;
	double dp[10001];
	for (int i = 0; i <= H; ++i) {
		dp[i] = 1e9;
	}
	dp[0] = 0;
	for (int h = 0; h < H; ++h) {
		if (dp[h] < 1e9) {
			int n = min(H, h + A);
			dp[n] = min(dp[n], dp[h] + 1);
			n = min(H, h + D);
			dp[n] = min(dp[n], dp[h] + 1.5);
		}
	}
	cout << dp[H] << endl;
	return 0;
}
