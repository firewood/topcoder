// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int a;
	cin >> a;
	int ans = a + a * a + a * a * a;
	cout << ans << endl;
	return 0;
}
