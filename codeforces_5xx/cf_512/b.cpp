// B. 

#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int d, n, m, x, y;
	cin >> n >> d >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		bool ans = (y - x) <= d && (y - x) >= -d && (x + y) >= d && (x + y) <= (n * 2 - d);
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
