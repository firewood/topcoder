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
	int x = 0;
	char temp[64];
	for (int i = 0; i < N; ++i) {
		while (true) {
			sprintf(temp, "%d", ++x);
			int a = strlen(temp);
			int c = 0;
			for (int j = 0; j < a; ++j) {
				c += temp[0] == temp[j];
			}
			if (a == c) {
				break;
			}
		}
	}
	cout << temp << endl;
	return 0;
}
