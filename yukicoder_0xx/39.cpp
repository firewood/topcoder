#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int len = (int)s.length();
	string ans = s;
	for (int i = 0; i < len; ++i) {
		for (int j = i + 1; j < len; ++j) {
			string a = s;
			swap(a[i], a[j]);
			if (a > ans) {
				ans = a;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
