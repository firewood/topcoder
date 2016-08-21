// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	bool ans = (cnt['N'] > 0 == cnt['S'] > 0) && (cnt['W'] > 0 == cnt['E'] > 0);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
