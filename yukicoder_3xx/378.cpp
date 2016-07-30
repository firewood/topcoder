#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long N, a, b, ans;
	cin >> N;
	for (a = N, b = 0; a > 0; a /= 2) {
		b += a;
	}
	ans = N * 2 - b;
	cout << ans << endl;
	return 0;
}
