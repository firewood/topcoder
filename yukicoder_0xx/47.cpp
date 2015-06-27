#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N;
	int ans = 0;
	while (N > 1) {
		ans += 1;
		N -= N / 2;
	}
	cout << ans << endl;
	return 0;
}
