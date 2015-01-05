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
	int n[100];
	for (int i = 0; i < N; ++i) {
		ss >> n[i];
	}
	int ans = 0;
	for (int i = 2; i < N; ++i) {
		if (n[i - 2] != n[i]) {
			ans += n[i - 2] < n[i - 1] && n[i - 1] > n[i] || n[i - 2] > n[i - 1] && n[i - 1] < n[i];
		}
	}
	cout << ans << endl;
	return 0;
}
