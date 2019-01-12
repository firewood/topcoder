// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, h, w;
	cin >> n >> h >> w;
	int ans = (n - h + 1) * (n - w + 1);
	cout << ans << endl;
	return 0;
}
