#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;

static const long long MOD = 1000000007;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		long long c, d;
		ss >> c >> d;
		c = ((c + 1) / 2) % MOD;
		ans += c * (d % MOD);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
