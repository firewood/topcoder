// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b;
	cin >> a >> b;
	int ans = a <= 9 && b <= 9 ? a * b : -1;
	cout << ans << endl;
	return 0;
}
