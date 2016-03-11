#include <iostream>
#include <sstream>
#include <map>
#include <cstdint>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	map<string, int> m;
	bool possible = true;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		m[s] += 1;
		if (m[s] > (N + 1) / 2) {
			possible = false;
		}
	}
	cout << (possible ? "YES" : "NO") << endl;
	return 0;
}
