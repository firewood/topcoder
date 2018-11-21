// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int h, m;
	cin >> h >> m;
	int ans = 18 * 60 - (h * 60 + m);
	cout << ans << endl;
	return 0;
}
