// A.

#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	char w[64];
	sprintf(w, "ABC%03d", n);
	cout << w << endl;
	return 0;
}
