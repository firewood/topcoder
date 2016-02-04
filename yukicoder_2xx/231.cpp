#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int C = 3000000;
	int N;
	cin >> N;
	int chosen = -1, mx = 0;
	for (int i = 0; i < N; ++i) {
		int G, D;
		cin >> G >> D;
		G -= D * 30000;
		if (G > mx) {
			chosen = i + 1;
			mx = G;
		}
	}
	if (mx * 6 >= C) {
		cout << "YES" << endl;
		for (int i = 0; i < 6; ++i) {
			cout << chosen << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
