#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long N, ans;
	cin >> N;
	ans = 316 + (N - 1) * 52;
	cout << ans << endl;
	return 0;
}
