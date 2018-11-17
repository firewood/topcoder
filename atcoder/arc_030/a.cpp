// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	bool ans = k <= n / 2;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
