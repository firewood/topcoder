#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		int a, b, c, d;
		sscanf(s.c_str(), "%d:%d %d:%d", &a, &b, &c, &d);
		sum += ((c + 24) * 60 + d - (a * 60 + b)) % (24 * 60);
	}
	cout << sum << endl;
	return 0;
}
