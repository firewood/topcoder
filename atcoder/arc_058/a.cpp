// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	bool ans = a[0] == 5 && a[1] == 5 && a[2] == 7;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
