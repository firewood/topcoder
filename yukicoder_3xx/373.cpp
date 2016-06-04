#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long A, B, C, D, ans;
	cin >> A >> B >> C >> D;
	ans = (((A * B) % D) * C) % D;
	cout << ans << endl;
	return 0;
}
