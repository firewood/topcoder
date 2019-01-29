// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a, b;
	cin >> n >> a >> b;
	int x = min(a, b);
	int y = max(0, a + b - n);
	cout << x << " " << y << endl;
	return 0;
}
