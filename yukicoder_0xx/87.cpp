#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

typedef long long LL;

bool is_uruu(LL year) {
	return (year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0);
}

LL solve(LL N)
{
	LL ans = 0;
	LL year;
	int w = 0;
	for (year = 2015; year <= N && year < 400 * 7; ++year) {
		int days = 365 + is_uruu(year);
		w = (w + days) % 7;
		ans += w == 0;
	}
	if (N > 400 * 7 * 2) {
		LL t = 0;
		for (; year < 400 * 7 * 2; ++year) {
			int days = 365 + is_uruu(year);
			w = (w + days) % 7;
			t += w == 0;
		}
		LL a = ((N - year) / (400 * 7));
		ans += (a + 1) * t;
		year += a * 400 * 7;
	}
	for (; year <= N; ++year) {
		int days = 365 + is_uruu(year);
		w = (w + days) % 7;
		ans += w == 0;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	LL N;
	sscanf(s.c_str(), "%lld", &N);
	cout << solve(N) << endl;
	return 0;
}
