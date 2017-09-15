// A.

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int x, a, b;
	cin >> x >> a >> b;
	int d = -a + b;
	if (d <= 0) {
		cout << "delicious" << endl;
	} else if (d <= x) {
		cout << "safe" << endl;
	} else {
		cout << "dangerous" << endl;
	}
	return 0;
}
