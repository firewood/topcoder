#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	LL L, N, M;
	string s;
	getline(cin, s);
	stringstream sa(s);
	sa >> L;
	getline(cin, s);
	stringstream sb(s);
	sb >> M;
	getline(cin, s);
	stringstream sc(s);
	sc >> N;
	M += N / 25;
	N %= 25;
	L += M / 4;
	M %= 4;
	L %= 10;
	cout << (L + M + N) << endl;
	return 0;
}
