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

void solve(int N) {
	string s;
	int left = 0, right = N;
	cout << left << endl;
	fflush(stdout);
	getline(cin, s);
	if (s == "Vacant") {
		return;
	}
	bool a = s == "Male";
	while (right - left > 3) {
		int mid = ((left + right) / 2 + 1) / 2 * 2;
		if (mid >= N) {
			break;
		}
		cout << mid << endl;
		fflush(stdout);
		getline(cin, s);
		if (s == "Vacant") {
			return;
		}
		bool b = s == "Male";
		if (a == b) {
			left = mid;
		} else {
			right = mid;
		}
	}
	while (true) {
		++left;
		cout << left << endl;
		fflush(stdout);
		getline(cin, s);
		if (s == "Vacant") {
			return;
		}
	}
}

int main() {
	string s;
	getline(cin, s);
	int N = stoi(s);
	solve(N);
	return 0;
}
