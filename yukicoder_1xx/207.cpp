#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	int A, B;
	ss >> A >> B;
	for (int n = A; n <= B; ++n) {
		char w[16];
		sprintf(w, "%d", n);
		if ((n % 3) == 0 || (strchr(w, '3') != NULL)) {
			cout << n << endl;
		}
	}
	return 0;
}
