// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m, x, y, a;
	cin >> n >> m >> x >> y;
	int max_x = x, min_y = y;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		max_x = max(max_x, a);
	}
	for (int i = 0; i < m; ++i) {
		cin >> a;
		min_y = min(min_y, a);
	}
	cout << (max_x < min_y ? "No War" : "War") << endl;
	return 0;
}
