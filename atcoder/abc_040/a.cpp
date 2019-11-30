// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, x;
	cin >> n >> x;
	int ans = min(x - 1, n - x);
	cout << ans << endl;
	return 0;
}
