// A. 

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	long long w, h, a, b;
	cin >> w >> h;
	a = w * 3, b = h * 4;
	cout << (a == b ? "4:3" : "16:9") << endl;
	return 0;
}
