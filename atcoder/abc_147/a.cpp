// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b + c >= 22 ? "bust" : "win") << endl;
	return 0;
}
