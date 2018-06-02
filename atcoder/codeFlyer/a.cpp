// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	int ans = a - (a % b);
	cout << ans << endl;
	return 0;
}
