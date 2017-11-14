// B.

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	int x, y, z;
	cin >> x >> y >> z;
	int ans = (x - z) / (y + z);
	cout << ans << endl;
	return 0;
}
