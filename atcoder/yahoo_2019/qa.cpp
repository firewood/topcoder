// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	bool ans = (n + 1) / 2 >= k;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
