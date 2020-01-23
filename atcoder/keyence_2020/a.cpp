// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int h, w, n;
	cin >> h >> w >> n;
	int x = max(h, w);
	int ans = (n + x - 1) / x;
	cout << ans << endl;
	return 0;
}
