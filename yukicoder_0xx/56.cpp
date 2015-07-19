#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int D, P;
	cin >> D >> P;
	int ans = D + (D * P / 100);
	cout << ans << endl;
	return 0;
}
