// A.
 
#include <iostream>
#include <algorithm>

using namespace std;
 
int main(int argc, char *argv[])
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = max(a * b, c * d);
	cout << ans << endl;
	return 0;
}
