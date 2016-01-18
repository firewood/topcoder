// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N, L;
	cin >> N >> L;
	string s;
	cin >> s;
	int ans = 0, tabs = 1;
	for (int i = 0; i < N; ++i) {
		if (s[i] == '+') {
			if (++tabs > L) {
				++ans;
				tabs = 1;
			}
		} else {
			tabs = max(0, tabs - 1);
		}
	}
	cout << ans << endl;
	return 0;
}
