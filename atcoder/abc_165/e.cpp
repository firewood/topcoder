// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, m;
		cin >> n >> m;
		if (n < 0) return 0;
		int r = m;
		if ((n % 2) == 0) {
			for (int i = 0; i < m / 2; ++i) {
				--r;
				cout << (n / 2 - i) << " " << (n / 2 + i + 2) << endl;
			}
		}
		for (int i = 0; i < r; ++i) {
			cout << (i + 1) << " " << (n - i) << endl;
		}
	}
	return 0;
}
