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

bool validate(string a, string x) {
	if (a.length() + 1 != x.length()) {
		return false;
	}
	a += a;
	int i = 0, j = 0;
	while (i < a.length() && j < x.length()) {
		while (i < a.length() && a[i] != x[j]) {
			++i;
		}
		if (i >= a.length()) {
			break;
		}
		++i;
		++j;
	}
	return j >= x.length();
}

int main() {
	int T, N;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		string a, b, c;
		cin >> a >> b >> c;
		string ans = string(N, '0') + string(N, '1') + "0";
		cout << ans << endl;
	}
	return 0;
}
