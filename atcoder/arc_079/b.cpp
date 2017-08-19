// B.

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int ans = 1;
	while (ans <= n) {
		ans *= 2;
	}
	ans /= 2;
	cout << ans << endl;
	return 0;
}
