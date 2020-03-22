// D.

#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> N;
	}
	static int v[1 << 18];
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		ss >> v[i];
	}

	static int cnt[1 << 18];
	for (int i = 0; i < N; ++i) {
		int h = v[i];
		for (int j = i - 1; j >= 0; --j) {
			if (v[j] >= h) {
				++cnt[j];
			}
			h = max(h, v[j]);
		}
		h = v[i];
		for (int j = i + 1; j < N; ++j) {
			if (v[j] >= h) {
				++cnt[j];
			}
			h = max(h, v[j]);
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << cnt[i] << endl;
	}

	return 0;
}
