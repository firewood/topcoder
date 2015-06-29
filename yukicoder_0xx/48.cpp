#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int X, Y, L;
	cin >> X >> Y >> L;
	int ans = 0;
	if (Y > 0) {
		ans += (Y + L - 1) / L;
		Y = 0;
	}
	if (X || Y) {
		++ans;
		ans += (abs(X) + L - 1) / L;
	}
	if (Y) {
 		++ans;
		ans += (-Y + L - 1) / L;
	}
	cout << ans << endl;
	return 0;
}
