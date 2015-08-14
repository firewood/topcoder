#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int D;
	cin >> D;
	D /= 2;
	int ans = (D / 2) * (D - D / 2);
	cout << ans << endl;
	return 0;
}
