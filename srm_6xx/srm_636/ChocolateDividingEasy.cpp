// BEGIN CUT HERE
/*
SRM 636 Div1 Easy (250)

PROBLEM STATEMENT
Mirosz adores sweets.
He has just bought a rectangular bar of chocolate.
The bar is divided into a grid of square cells.
Different cells may have a different quality.
You are given the description of the bar in a vector <string> chocolate.
Each character in chocolate is a digit between '0' and '9', inclusive: the quality of one of the cells.

Mirosz is now going to divide the chocolate into 9 parts: one for him and one for each of his 8 friends.
He will do the division by making four cuts: two horizontal and two vertical ones.
Each cut must go between two rows or columns of cells.
Each of the 9 parts must be non-empty.
The quality of a part is the sum of the qualities of all cells it contains.

Mirosz is well-mannered and he will let his friends choose their pieces first.
His friends are even more addicted to chocolate than he is.
Therefore, they will certainly choose the pieces with higher quality first, and Mirosz will be left with the worst of the nine pieces.

You are given the vector <string> chocolate.
Find the optimal places for the four cuts.
More precisely, compute and return the largest possible quality of Mirosz's part of the chocolate bar.


DEFINITION
Class:ChocolateDividingEasy
Method:findBest
Parameters:vector <string>
Returns:int
Method signature:int findBest(vector <string> chocolate)


CONSTRAINTS
-chocolate will contain between 3 and 50 elements, inclusive. 
-All elements in chocolate will contain between 3 and 50 characters, inclusive. 
-All elements in chocolate will contain the same number of characters. 
-All elements in chocolate will contain only digits ('0'-'9').


EXAMPLES

0)
{
"9768",
"6767",
"5313"
}

Returns: 3

There are three valid ways to cut this chocolate.
One of the optimal ones is shown below. 

9 | 7 | 6 8 
--|---|----- 
6 | 7 | 6 7 
--|---|----- 
5 | 3 | 1 3 

This way of cutting produces parts with the following qualities:
9, 7, 14, 6, 7, 13, 5, 3, and 4.
The quality of the worst part (the one that Mirosz will get) is 3. 

Here is another way of cutting the same chocolate: 


9 7 | 6 | 8 
----|---|--- 
6 7 | 6 | 7 
----|---|--- 
5 3 | 1 | 3 


If Mirosz cuts the chocolate in this way, the quality of his part will be 1, which is worse than 3.


1)
{
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
}

Returns: 15

There is only one optimal way to divide the chocolate:  


3 6 7 5 | 3 5 | 6 2 
9 1 2 7 | 0 9 | 3 6 
--------|-----|----- 
0 6 2 6 | 1 8 | 7 9 
2 0 2 3 | 7 5 | 9 2 
--------|-----|----- 
2 8 9 7 | 3 6 | 1 2 
9 3 1 9 | 4 7 | 8 4  

The three parts on the top have qualities 3+6+7+5+9+1+2+7 = 40, 3+5+0+9 = 17 and 6+2+3+6 = 17 
The worst part is the one in the bottom right corner. Its quality is only 1+2+4+8 = 15.


2)
{
"012",
"345",
"678"
}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class ChocolateDividingEasy {

	int hsum[64][64];

	int calc(int sx, int sy, int ex, int ey) {
		int sum = 0;
		for (int i = sy; i <= ey; ++i) {
			sum += hsum[i][ex + 1] - hsum[i][sx];
		}
		return sum;
	}

public:
	int findBest(vector <string> chocolate) {
		memset(hsum, 0, sizeof(hsum));
		int W = chocolate[0].length(), H = chocolate.size();
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				hsum[i][j + 1] = hsum[i][j] + chocolate[i][j] - '0';
			}
		}
		int ans = 0;
		for (int i = 1; i < H; ++i) {
			for (int j = i + 1; j < H; ++j) {
				for (int k = 1; k < W; ++k) {
					for (int l = k + 1; l < W; ++l) {
						int m[9] = {
							calc(0, 0, k - 1, i - 1), calc(k, 0, l - 1, i - 1), calc(l, 0, W - 1, i - 1),
							calc(0, i, k - 1, j - 1), calc(k, i, l - 1, j - 1), calc(l, i, W - 1, j - 1),
							calc(0, j, k - 1, H - 1), calc(k, j, l - 1, H - 1), calc(l, j, W - 1, H - 1)
						};
						ans = max(ans, *min_element(m, m + 9));
					}
				}
			}
		}
		return ans;

// BEGIN CUT HERE
/*
struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; }
		else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};
*/

// 問題文をよく読む
// サンプルの説明を読む
// 制約の数値 -> コピペする
// 負数のチェック
// ケースの列挙 -1,0,1,2,3...
// 空文字列、空配列
// 赤い人のコードを読む
// long long
// {0}
// END CUT HERE
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"9768",
"6767",
"5313"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
};
			int Arg1 = 15;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"012",
"345",
"678"
};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChocolateDividingEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
