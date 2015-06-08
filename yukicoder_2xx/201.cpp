#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string sa, sb, pa, pb, xa, xb;
	string s;
	getline(cin, s);
	stringstream ssa(s);
	ssa >> sa >> pa >> xa;
	getline(cin, s);
	stringstream ssb(s);
	ssb >> sb >> pb >> xb;
	int winner = 0;
	if (pa.length() > pb.length()) {
		winner = 1;
	} else if (pa.length() < pb.length()) {
		winner = 2;
	} else {
		int cmp = pa.compare(pb);
		if (cmp > 0) {
			winner = 1;
		} else if (cmp < 0) {
			winner = 2;
		}
	}
	string names[3] = { "-1", sa, sb };
	cout << names[winner] << endl;
	return 0;
}
