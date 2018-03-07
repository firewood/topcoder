// C.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int c[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> c[i][j];
		}
	}
	bool ans = true;
	for (int i = 1; i < 3; ++i) {
		for (int j = 1; j < 3; ++j) {
			if ((c[i][0] - c[i-1][0]) != (c[i][j] - c[i-1][j])) {
				ans = false;
			}
			if ((c[0][j] - c[0][j-1]) != (c[i][j] - c[i][j-1])) {
				ans = false;
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
