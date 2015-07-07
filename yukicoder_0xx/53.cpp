#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(12);
	int N;
	cin >> N;
	long double ans = 4.0L * powl(0.75, N);
	cout << ans << endl;
	return 0;
}
