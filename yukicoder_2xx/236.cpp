#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(10);
	double A, B, X, Y, ans;
	cin >> A >> B >> X >> Y;
	if (A * Y > B * X) {
		ans = X * (A + B) / A;
	} else {
		ans = Y * (A + B) / B;
	}
	cout << ans << endl;
	return 0;
}
