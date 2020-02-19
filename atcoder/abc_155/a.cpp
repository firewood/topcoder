// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	bool ans = (a[0] == a[1] && a[1] != a[2]) || (a[0] != a[1] && a[1] == a[2]);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
