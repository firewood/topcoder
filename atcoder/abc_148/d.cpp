// D.

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
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int ans = 0, nx = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] == nx) {
				++nx;
			} else {
				++ans;
			}
		}
		cout << (ans < n ? ans : -1) << endl;
	}
	return 0;
}
