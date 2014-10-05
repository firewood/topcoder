
// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N;

	string a, b, c;
	for (int i = 1; i < 34; i += 3) {
		if (i <= 3) {
			a += N > 0 ? "O." : "#.";
			b += N > 1 ? "O." : "#.";
			c += N > 3 ? "O." : "#.";
		} else {
			a += N >= i + 1 ? "O." : "#.";
			b += N >= i + 2 ? "O." : "#.";
			c += N >= i + 3 ? "O." : "#.";
		}
	}

	printf("+------------------------+\n");
	printf("|%s|D|)\n", a.c_str());
	printf("|%s|.|\n", b.c_str());
	printf("|%c.......................|\n", N >= 3 ? 'O' : '#');
	printf("|%s|.|)\n", c.c_str());
	printf("+------------------------+\n");

	return 0;
}

