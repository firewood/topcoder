// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int k;
	cin >> k;
	vector<string> v;
	int len = (int)s.length();
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j <= 6; ++j) {
			if ((i + j) <= len) {
				string x = s.substr(i, j);
				v.push_back(x);
			}
		}
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	string prev;
	for (string x : v) {
		if (x != prev) {
			prev = x;
			if (++cnt == k) {
				cout << x << endl;
				break;
			}
		}
	}
	return 0;
}
