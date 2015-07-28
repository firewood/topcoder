#include <iostream>

using namespace std;

static const long long MOD = 1000007;

int main(int argc, char *argv[])
{
	long long N;
	cin >> N;
	long long a = N / 2;
	long long total = ((a + 1) % MOD) * ((N - a + 1) % MOD);
	long long ans = (total - 1 + MOD) % MOD;
	cout << ans << endl;
	return 0;
}
