// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> IntVec;
typedef set<int> IntSet;

int main(int argc, char *argv[])
{
	cout.precision(16);
	string s;
	int NA, NB;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> NA >> NB;
	}
	IntVec A(NA), B(NB);
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < NA; ++i) {
			ss >> A[i];
		}
	}
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < NB; ++i) {
			ss >> B[i];
		}
	}
	IntSet SA(A.begin(), A.end());
	IntSet SB(B.begin(), B.end());
	IntSet SC;
	for (int i = 0; i < NA; ++i) {
		if (SB.find(A[i]) != SB.end()) {
			SC.insert(A[i]);
		}
	}
	for (int i = 0; i < NB; ++i) {
		SA.insert(B[i]);
	}
	double ans = (double)SC.size() / (double)SA.size();
	cout << ans << endl;
}
