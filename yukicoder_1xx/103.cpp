#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	int g = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		ss >> a;
		for (int b = 2; a >= b; ++b) {
			int c = 0;
			while ((a % b) == 0) {
				++c;
				a /= b;
			}
			g ^= (c % 3);
		}
	}
	cout << ((g != 0) ? "Alice" : "Bob") << endl;
	return 0;
}
