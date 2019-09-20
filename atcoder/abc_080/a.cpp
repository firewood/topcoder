// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	int n, a, b;
	cin >> n >> a >> b;
	int ans = min(a * n, b);
	cout << ans << endl;
	return 0;
}
