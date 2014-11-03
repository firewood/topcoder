// BEGIN CUT HERE
/*
SRM 638 Div1 Easy (300)

PROBLEM STATEMENT
A shadow sculpture is a 3D object that seems amorphous but casts a beautiful shadow.

You want to create a simple shadow sculpture that will consist of unit cubes.
More precisely, imagine an n*n*n cube that is aligned with the coordinate axes and divided into unit cubes.
Your sculpture will consist of some of those unit cubes (possibly none or all of them).
The unit cubes have coordinates (x,y,z) where 0 <= x,y,z < n.

You have already determined three shadows your sculpture should cast: its orthogonal projections onto the XY, YZ, and ZX plane.
You are given their description in three vector <string>s: XY, YZ, and ZX.

Their meaning is as follows:
For each i and j, the character XY[i][j] is either 'Y' or 'N'.
The character 'Y' means that the unit square (i,j) of the projection is dark.
In other words, if XY[i][j] is 'Y', at least one of the cubes with coordinates (i,j,k) has to be a part of your sculpture.
On the other hand, if XY[i][j] is 'N', none of the cubes with coordinates (i,j,k) may belong into your sculpture.
YZ and ZX describe the other two projections in the same way.
E.g., if ZX[i][j] is 'Y', you have to use at least one of the cubes (j,k,i).

Finally, there is one last constraint:
Your entire sculpture has to be 6-connected.
(Formally: Your sculpture must form one connected component, given that two cubes are adjacent iff they share a common face.)

Return "Possible" if it is possible to construct a sculpture that matches all the given constraints.
Otherwise, return "Impossible".


DEFINITION
Class:ShadowSculpture
Method:possible
Parameters:vector <string>, vector <string>, vector <string>
Returns:string
Method signature:string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)


CONSTRAINTS
-n will be between 1 and 10, inclusive.
-XY, YZ and ZX will contain exactly n elements.
-Each element of XY, YZ and ZX will contain exactly n characters.
-Each element of XY, YZ and ZX will contain only 'Y' and 'N'.


EXAMPLES

0)
{"YN","NN"}
{"YN","NN"}
{"YN","NN"}

Returns: "Possible"

It is possible: we only have one solid cell at (0, 0, 0).


1)
{"YN","NY"}
{"YN","NY"}
{"YN","NY"}

Returns: "Impossible"

Here it is impossible to make a valid sculpture.
Note that you can make all three projections look right by using exactly two cubes: (0,0,0) and (1,1,1).
However, this sculpture is not 6-connected.


2)
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}

Returns: "Possible"


3)
{"YYY","YNY","YYY"}
{"NYY","YNY","YYY"}
{"YYY","YNY","YYN"}

Returns: "Impossible"


4)
{"N"}
{"N"}
{"N"}

Returns: "Possible"

A sculpture that consists of no cubes is connected.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class ShadowSculpture {
	int N;
	vector <string> xy;
	vector <string> yz;
	vector <string> zx;
	vector <string> xy2;
	vector <string> yz2;
	vector <string> zx2;
	int visited[10][10][10];

	void dfs(int x, int y, int z) {
		if (x < 0 || x >= N || y < 0 || y >= N || z < 0 || z >= N) {
			return;
		}
		if (visited[x][y][z]) {
			return;
		}
		visited[x][y][z] = 1;
		if (xy[x][y] == 'N' || yz[y][z] == 'N' || zx[z][x] == 'N') {
			return;
		}
		xy2[x][y] = 'Y', yz2[y][z] = 'Y', zx2[z][x] = 'Y';
		dfs(x - 1, y, z);
		dfs(x + 1, y, z);
		dfs(x, y - 1, z);
		dfs(x, y + 1, z);
		dfs(x, y, z - 1);
		dfs(x, y, z + 1);
	}

	bool check(void) {
		vector <string> e = xy;
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {
				e[x][y] = 'N';
			}
		}

		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {
				for (int z = 0; z < N; ++z) {
					xy2 = e, yz2 = e, zx2 = e;
					memset(visited, 0, sizeof(visited));
					dfs(x, y, z);
					if (xy == xy2 && yz == yz2 && zx == zx2) {
						return true;
					}
				}
			}
		}

		return false;
	}

public:
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		N = (int)XY.size();
		xy = XY, yz = YZ, zx = ZX;
		return check() ? "Possible" : "Impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YN","NN"};
			string Arr1[] = {"YN","NN"};
			string Arr2[] = {"YN","NN"};
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YN","NY"};
			string Arr1[] = {"YN","NY"};
			string Arr2[] = {"YN","NY"};
			string Arg3 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYY","YNY","YYY"};
			string Arr1[] = {"YYY","YNY","YYY"};
			string Arr2[] = {"YYY","YNY","YYY"};
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYY","YNY","YYY"};
			string Arr1[] = {"NYY","YNY","YYY"};
			string Arr2[] = {"YYY","YNY","YYN"};
			string Arg3 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"N"};
			string Arr1[] = {"N"};
			string Arr2[] = {"N"};
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "NN", "NN" };
			string Arr1[] = { "NN", "NN" };
			string Arr2[] = { "NN", "NN" };
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "N" };
			string Arr1[] = { "N" };
			string Arr2[] = { "Y" };
			string Arg3 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "YYY", "YYY", "YNY" };
			string Arr1[] = { "YYY", "YYY", "YNY" };
			string Arr2[] = { "YNY", "YYY", "YYY" };
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "NNN", "NNN", "NYN" };
			string Arr1[] = { "NNN", "YNN", "NNN" };
			string Arr2[] = { "NNY", "NNN", "NNN" };
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};


// BEGIN CUT HERE
int main() {
	ShadowSculpture ___test;
	___test.run_test(-1);
}
// END CUT HERE
