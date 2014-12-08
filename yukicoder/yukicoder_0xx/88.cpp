#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string f;
	getline(cin, f);
	string s;
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		getline(cin, s);
		cnt += count_if(s.begin(), s.end(), [](char c){ return c != '.'; });
	}

	s = f.compare("oda") == 0 ? "yukiko" : "oda";
	cout << ((cnt % 2) ? s : f) << endl;

	return 0;
}
