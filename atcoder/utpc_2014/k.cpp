// K.
 
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
 
using namespace std;
 
typedef long long LL;
 
LL check(LL A, LL B, LL X) {
	if (A >= 1024 || B >= 1024 || X >= 1024) {
		return -1;
	}
	const LL m = 500000000;
	LL t;
	for (t = 0; A != X && t < m; ++t) {
		A = (A >> 1) ^ ((A & 1) ? B : 0);
	}
	return t < m ? t : -1;
}
 
int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	LL A, B, X;
	ss >> A >> B >> X;
	cout << check(A, B, X) << endl;
	return 0;
}
