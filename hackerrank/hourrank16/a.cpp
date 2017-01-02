// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int c[100000];
	for (int i = 0; i < N; ++i) {
		cin >> c[i];
	}
	sort(c, c + N);
	int h = c[0] * 2, w = 1;
	if (N > 1) {
		if (c[0] == c[1]) {
			h = c[0], w = N;
		} else {
			h = min(h, c[1]);
		}
	}
	cout << h << " " << w << endl;
	return 0;
}
