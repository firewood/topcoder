#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(10);
	int L, K;
	cin >> L >> K;
	int ans = ((L - 1) / (K * 2)) * K;
	cout << ans << endl;
	return 0;
}
