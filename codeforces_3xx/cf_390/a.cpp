// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int a[100];
	int zc = 0, j = -1, sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		zc += a[i] == 0;
		if (j < 0 && a[i] != 0) {
			j = i;
		}
		sum += a[i];
	}
	if (zc == N) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		if (sum) {
			cout << "1" << endl;
			cout << "1 " << N << endl;
		} else {
			cout << "2" << endl;
			cout << "1 " << (j + 1) << endl;
			cout << (j + 2) << " " << N << endl;
		}
	}
	return 0;
}
