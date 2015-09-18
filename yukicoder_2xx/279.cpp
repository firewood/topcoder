#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	int ans = min(cnt['t'], min(cnt['r'], cnt['e'] / 2));
	cout << ans << endl;
	return 0;
}
