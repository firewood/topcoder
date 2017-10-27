// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int s = max(a, c);
	int e = min(b, d);
	int ans = max(0, e - s);
	cout << ans << endl;
	return 0;
}
