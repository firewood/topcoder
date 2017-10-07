// B.

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	bool ans = false;
	for (int i = a; i < 1000000; i += a) {
		if ((i % b) == c) {
			ans = true;
			break;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
