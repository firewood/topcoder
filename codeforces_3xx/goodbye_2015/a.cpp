// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	string a, b;
	cin >> n >> a >> b;

	tm t = {};
	t.tm_year = 2016 - 1900;
	t.tm_mday = 1;
	t.tm_hour = 12;
	time_t x = mktime(&t);
	int ans = 0;
	while (true) {
		tm *y = localtime(&x);
		if (y->tm_year > t.tm_year) {
			break;
		}
		int mon = y->tm_mon + 1;
		int day = y->tm_mday;

		if (b.compare("week") == 0) {
			ans += (n % 7) == y->tm_wday;
		}

		if (b.compare("month") == 0) {
			ans += n == day;
		}

		x += 24 * 60 * 60;
	}

	cout << ans << endl;

	return 0;
}
