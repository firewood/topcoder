// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	cin >> a >> b;
	if (a == 0 || b == 0 || a < 0 && b > 0) {
		cout << "Zero" << endl;
	} else if (a < 0 && ((b - a) % 2) == 0) {
		cout << "Negative" << endl;
	} else {
		cout << "Positive" << endl;
	}
	return 0;
}
