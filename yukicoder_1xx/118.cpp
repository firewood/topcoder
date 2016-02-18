#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

#define MOD 1000000007LL

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	LL cnt[102] = {};
	int t = 0;
	for (LL i = 0; i < N; ++i) {
		int n;
		ss >> n;
		cnt[n] += 1;
	}

	LL ans = 0;
	for (LL i = 1; i <= 100; ++i) {
		for (LL j = i + 1; j <= 100; ++j) {
			for (LL k = j + 1; k <= 100; ++k) {
				ans = (ans + cnt[i] * cnt[j] * cnt[k]) % MOD;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
