// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int m[4] = {};
	for (int i = 0; i < n; ++i) {
		cin >> m[i];
	}
	sort(m, m + n);
	int ans = min({
		max(m[0] + m[1] + m[2], m[3]),
		max(m[0] + m[3], m[1] + m[2]),
		max(m[0] + m[2], m[1] + m[3])
	});
	cout << ans << endl;
	return 0;
}
