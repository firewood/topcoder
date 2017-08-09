// A.

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	bool ans = (a % 3) == 0 || (b % 3) == 0 || ((a + b) % 3) == 0;
	cout << (ans ? "Possible" : "Impossible") << endl;
	return 0;
}
