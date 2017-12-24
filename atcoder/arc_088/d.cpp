// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int len = s.length();
	int ans = len / 2, left = (len - 1) / 2, right = len - (len + 1) / 2, center = left;
	while (left >= 0) {
		if (s[center] != s[left] || s[center] != s[right]) {
			break;
		}
		++ans;
		--left, ++right;
	}
	cout << ans << endl;
	return 0;
}
