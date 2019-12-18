// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = (a * b + b * c + c * a) * 2;
	cout << ans << endl;
	return 0;
}
