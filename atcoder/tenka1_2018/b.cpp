// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int c[2], k;
	cin >> c[0] >> c[1] >> k;
	for (int i = 0; i < k; ++i) {
		c[(i & 1) ^ 1] += c[i & 1] / 2;
		c[i & 1] /= 2;
	}
	cout << c[0] << " " << c[1] << endl;
	return 0;
}
