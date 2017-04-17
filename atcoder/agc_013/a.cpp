// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N, dir = 0, prev, ans = 1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (i) {
			if (a > prev) {
				if (!dir) {
					dir = 1;
				} else if (dir < 0) {
					++ans;
					dir = 0;
				}
			} else if (a < prev) {
				if (!dir) {
					dir = -1;
				} else if (dir > 0) {
					++ans;
					dir = 0;
				}
			}
		}
		prev = a;
	}
	cout << ans << endl;
	return 0;
}
