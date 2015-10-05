#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int K, S;
	cin >> K >> S;
	int ans = (S * 100) / (100 - K);
	cout << ans << endl;
	return 0;
}
