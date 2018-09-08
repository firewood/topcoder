// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	string ans = (a * b % 2) ? "Yes" : "No";
	cout << ans << endl;
	return 0;
}
