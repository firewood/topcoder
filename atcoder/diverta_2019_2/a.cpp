// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <locale>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	int ans = k <= 1 ? 0 : (n - k);
	cout << ans << endl;
	return 0;
}
