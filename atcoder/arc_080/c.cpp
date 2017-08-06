// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, t = 0, f = 0, o = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if ((a % 4) == 0) {
			++f;
		} else if ((a % 2) == 0) {
			++t;
		} else {
			++o;
		}
	}
	bool ans = true;
	if (f < o) {
		ans = f == o - 1 && t == 0;
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
