#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	long long n, ans = 1;
	cin >> n;
	for (long long i = 2; i < n * 2; i += 2) {
		long long j = ((i + 1) * (i + 2)) / 2;
		ans = (ans * (j % 1000000007)) % 1000000007;
	}
	cout << ans << endl;
	return 0;
}
