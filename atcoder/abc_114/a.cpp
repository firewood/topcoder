// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int x;
	cin >> x;
	bool ans = x == 3 || x == 5 || x == 7;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
