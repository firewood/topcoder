#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(16);
	long double D;
	cin >> D;
	D *= 1.08;
	int d = (int)((D - floor(D) + 0.0001) * 100);
	cout << floor(D) << "." << (d / 10) << (d % 10) << endl;
	return 0;
}
