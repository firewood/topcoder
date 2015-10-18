#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += s[i] != t[i];
	}
	cout << ans << endl;
	return 0;
}
