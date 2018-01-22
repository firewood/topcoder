// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	long long a, b;
	cin >> a >> b;
	cout << (((a * b) % 2) ? "Odd" : "Even") << endl;
	return 0;
}
