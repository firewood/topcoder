#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<string> w[2];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			string s;
			cin >> s;
			w[i].push_back(s);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (w[0][i] != w[1][i]) {
			cout << (i + 1) << endl;
			cout << w[0][i] << endl;
			cout << w[1][i] << endl;
			break;
		}
	}
	return 0;
}
