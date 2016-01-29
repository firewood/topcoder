#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N, P;
	cin >> N >> P;
	string ans = (P == N * P) ? "=" : "!=";
	cout << ans << endl;
	return 0;
}
