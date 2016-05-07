// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N, Q;
	cin >> N >> Q;
	int a[100] = {};
	for (int i = 0; i < Q; ++i) {
		int L, R, T;
		cin >> L >> R >> T;
		fill(a + L - 1, a + R, T);
	}
	for (int i = 0; i < N; ++i) {
		cout << a[i] << endl;
	}
	return 0;
}
