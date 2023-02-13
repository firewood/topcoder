#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

bool is_uruu(int year) {
	return (year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0);
}

bool is_fine(int year, int month, int day) {
	return year % (month * day) == 0;
}

string solve(int year, int month, int day) {
	while (!is_fine(year, month, day)) {
		vector<int> days = { 31, is_uruu(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (++day > days[month - 1]) {
			day = 1;
			if (++month > 12) {
				month = 1;
				++year;
			}
		}
	}
	char ans[16];
	sprintf(ans, "%04d/%02d/%02d", year, month, day);
	return ans;
}

int main() {
	string s;
	getline(cin, s);
	int year = stoi(s.substr(0, 4)), month = stoi(s.substr(5, 2)), day = stoi(s.substr(8, 2));
	cout << solve(year, month, day) << endl;
	return 0;
}
