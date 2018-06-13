// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	cin >> a >> b;
	int d = b - a;
	int t = (d * (d + 1)) / 2;
	cout << (t - b) << endl;
	return 0;
}
