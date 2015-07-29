#include <iostream>

using namespace std;

typedef long long LL;

LL calc_l(LL n) {
	LL cnt = 0;
	for (LL a = 2; a < n; ++a) {
		LL t = (a * (a - 1) / 2) * (n - a);
		cnt = max(cnt, t);
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	LL cnt[256] = {};
	for (int i = 'a'; i <= 'z'; ++i) {
		cin >> cnt[i];
	}
	LL ans = cnt['h'] * cnt['e'] * calc_l(cnt['l']);
	LL o = cnt['o'];
	ans *= (o / 2) * (o - o / 2);
	ans *= cnt['r'] * cnt['w'] * cnt['d'];
	cout << ans << endl;
	return 0;
}
