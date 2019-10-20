// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b;
	cin >> a >> b;
	int ans = max(0, a - b * 2);
	cout << ans << endl;
	return 0;
}
