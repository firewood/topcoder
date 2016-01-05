// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int ans = 0;
	for (int i = 1; i <= 5; ++i) {
		int d;
		cin >> d;
		ans += max(0, 10 - (d - i)) * 10;
	}
	cout << ans << endl;
	return 0;
}
