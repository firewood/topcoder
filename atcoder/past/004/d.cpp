#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t(n, '#');
	int mn = 1 << 30, ax, ay;
	for (int x = 0; x < n; ++x) {
		string prev = s;
		for (int y = 0; y < n; ++y) {
			if (s == t && (x + y) < mn) {
				mn = x + y;
				ax = x;
				ay = y;
			}
			string prev = s;
			for (int i = 0; i < n - 1; ++i) {
				if (prev[i] == '#') {
					s[i + 1] = '#';
				}
			}
		}
		s = prev;
		for (int i = 1; i < n; ++i) {
			if (prev[i] == '#') {
				s[i - 1] = '#';
			}
		}
	}
	cout << ax << " " << ay << endl;
	return 0;
}
