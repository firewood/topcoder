#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	int T = atoi(s.c_str());

	static int dp[51][100001];
	memset(dp, 0, sizeof(dp));

	vector<int> A(N);
	getline(cin, s);
	stringstream ss(s);
	for (int i = 0; i < N; ++i) {
		ss >> A[i];
	}
	dp[N][T] = 1;
	for (int i = N-1; i >= 0; --i) {
		for (int j = 0; j <= T; ++j) {
			if (A[i] + j <= T && dp[i+1][A[i] + j]) {
				dp[i][j] = 1;
			}
			if (A[i] * j <= T && dp[i+1][A[i] * j]) {
				dp[i][j] = 1;
			}
		}
	}
	int sum = A[0];
	for (int i = 1; i < N; ++i) {
		if (dp[i+1][sum + A[i]]) {
			cout << "+";
			sum += A[i];
		} else {
			cout << "*";
			sum *= A[i];
		}
	}
	cout << endl;
	return 0;
}
