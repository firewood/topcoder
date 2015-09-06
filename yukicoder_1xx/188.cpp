#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
	tm t = {};
	t.tm_year = 2015 - 1900;
	t.tm_mday = 1;
	time_t a = mktime(&t);
	int cnt = 0;
	while (true) {
		tm *b = localtime(&a);
		if (b->tm_year > t.tm_year) {
			break;
		}
		int mon = b->tm_mon + 1;
		int day = b->tm_mday;
		int c = 0;
		while (day) {
			c += day % 10;
			day /= 10;
		}
		cnt += mon == c;
		a += 24 * 60 * 60;
	}
	cout << cnt << endl;
	return 0;
}
