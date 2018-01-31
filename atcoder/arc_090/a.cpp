// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int x, a, b;
	cin >> x >> a >> b;
	int ans = (x - a) % b;
	cout << ans << endl;
	return 0;
}
