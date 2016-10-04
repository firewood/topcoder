// B. 

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	string s;
	cin >> N >> s;
	int cnt = 0, len = 0, w = 0;
	bool p = false;
	for (char c : s) {
		switch (c) {
		case '(':
			p = true;
			cnt = 0;
			break;
		case ')':
			p = false;
			cnt = 0;
			break;
		case '_':
			cnt = 0;
			break;
		default:
			++cnt;
			if (p) {
				w += cnt == 1;
			} else {
				len = max(len, cnt);
			}
			break;
		}
	}
	cout << len << " " << w << endl;
	return 0;
}
