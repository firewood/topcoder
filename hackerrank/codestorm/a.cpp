// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	LL ans = -1;
	for (int i = N + 1; i > 0; i -= 2) {
		ans += i;
	}
	cout << ans << endl;
	return 0;
}
