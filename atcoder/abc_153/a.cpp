// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int h, a;
	cin >> h >> a;
	int ans = (h + a - 1) / a;
	cout << ans << endl;
	return 0;
}
