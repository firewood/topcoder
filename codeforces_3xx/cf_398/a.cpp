// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int ex[100002] = {}, right = N;
	for (int i = 0; i < N; ++i) {
		int sz;
		cin >> sz;
		ex[sz] = 1;
		if (sz == right) {
			string delim = "";
			for (; ex[right]; --right) {
				cout << delim << right;
				delim = " ";
			}
		}
		cout << endl;
	}
	return 0;
}
