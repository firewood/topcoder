// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a;
	cin >> n;
	bool ans = true;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a) {
			ans = false;
		}
	}
	cout << (ans ? "EASY" : "HARD") << endl;
	return 0;
}
