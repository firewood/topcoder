// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	bool ans = cnt['R'] > cnt['B'];
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
