#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int W, D;
	cin >> W >> D;
	for (int d = D; d >= 2; --d) {
		double dd = (double)d * d;
		int w = floor((double)W / dd);
		W -= w;
	}
	cout << W << endl;
	return 0;
}
