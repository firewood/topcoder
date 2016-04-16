// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int K, a = 1, b = 1;
	cin >> K;
	for (int k = 1; k < K; ++k) {
		int c = a + b;
		a = b;
		b = c;
	}
	cout << a << " " << b << endl;
	return 0;
}
