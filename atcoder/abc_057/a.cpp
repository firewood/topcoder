// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b;
	cin >> a >> b;
	int ans = (a + b) % 24;
	cout << ans << endl;
	return 0;
}
