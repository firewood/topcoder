#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

int getmin(int b, IntVec &a) {
	if (b <= 0) {
		return 0;
	}
	IntVec c[2];
	for (int n : a) {
		if (n & b) {
			c[1].push_back(n ^ b);
		} else {
			c[0].push_back(n);
		}
	}
	if (c[0].size() == 0) {
		return getmin(b >> 1, c[1]);
	}
	if (c[1].size() == 0) {
		return getmin(b >> 1, c[0]);
	}
	return b | min(getmin(b >> 1, c[0]), getmin(b >> 1, c[1]));
}

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	IntVec A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	int ans = getmin(1 << 29, A);

	cout << ans << endl;
	return 0;
}
