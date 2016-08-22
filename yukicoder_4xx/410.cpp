#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(20);
	int px, py, qx, qy;
	cin >> px >> py >> qx >> qy;
	double ans = (abs(qx - px) + abs(qy - py)) * 0.5;
	cout << ans << endl;
	return 0;
}
