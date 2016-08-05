#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	const char *b[] = { "XII", "I", "II", "III", "IIII", "V", "VI", "VII", "VIII", "IX", "X", "XI" };
	string s;
	int t;
	cin >> s >> t;
	for (int i = 0; i < 12; ++i) {
		if (s.compare(b[i]) == 0) {
			break;
		}
		++t;
	}
	cout << b[(t % 12 + 12) % 12] << endl;
	return 0;
}
