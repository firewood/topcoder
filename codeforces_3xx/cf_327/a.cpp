// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	long double L, P, Q;
	cin >> L >> P >> Q;
	long double ans = (P * L) / (P + Q);
	cout << ans << endl;
	return 0;
}
