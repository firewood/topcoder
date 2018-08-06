// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string ans = n < 1200 ? "ABC" : (n < 2800 ? "ARC" : "AGC");
	cout << ans << endl;
	return 0;
}
