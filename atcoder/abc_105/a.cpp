// A.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	int ans = (n % k) > 0;
	cout << ans << endl;
	return 0;
}
