// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	cout << "1";
	for (int i = 1; i < N; ++i) {
		cout << "0";
	}
	cout << "7" << endl;
	cout.precision(10);
	return 0;
}
