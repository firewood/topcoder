// A.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int ans = (n % 2) ? n * 2 : n;
	cout << ans << endl;
	return 0;
}
