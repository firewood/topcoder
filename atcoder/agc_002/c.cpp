// C.

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N, L, prev;
	cin >> N >> L >> prev;
	for (int i = 1; i < N; ++i) {
		int a;
		cin >> a;
		if (prev + a >= L) {
			cout << "Possible" << endl;
			for (int j = 0; j < i - 1; ++j) {
				cout << (j + 1) << endl;
			}
			for (int j = N - 2; j >= i; --j) {
				cout << (j + 1) << endl;
			}
			cout << i << endl;
			return 0;
		}
		prev = a;
	}
	cout << "Impossible" << endl;
	return 0;
}
