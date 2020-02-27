// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, r, ans;
	cin >> n >> r;
	ans = n < 10 ? r + 100 * (10 - n) : r;
	cout << ans << endl;
	return 0;
}
