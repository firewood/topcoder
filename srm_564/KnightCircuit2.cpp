// BEGIN CUT HERE
/*
// SRM 564 Div1 Easy (250)

問題
w×hのサイズのチェス盤がある
左上からナイトが到達可能な升目の総数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class KnightCircuit2 {

public:
	int maxSize(int w, int h) {
		int a = min(w, h);
		int b = max(w, h);
		if (a <= 1) {
			return a;
		}
		if (a == 2) {
			return (b+1)/2;
		}
		return w*h - (w==3 && h==3);
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 2;
			int Arg2 = 8;

			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 10000;

			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 14;
			int Arg1 = 2;
			int Arg2 = 7;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			int Arg1 = 2;
			int Arg2 = 7;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 2;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 8;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

void dfs(int &count, int (&visited)[256][256], const int &w, const int &h, int x, int y) {
	if (x >= 0 && x < w && y >= 0 && y < h && !visited[y][x]) {
		++count;
		visited[y][x] = 1;
		const int dx[] = {1,1,-1,-1,2,2,-2,-2};
		const int dy[] = {2,-2,2,-2,1,-1,1,-1};
		for (int n = 0; n < 8; ++n) {
			dfs(count, visited, w, h, x+dx[n], y+dy[n]);
		}
	}
}

// BEGIN CUT HERE
int main() {
	KnightCircuit2 ___test;
	___test.run_test(-1);

	int w, h;
	for (w = 1; w <= 80; ++w) {
		cout << "w=" << w;
		for (h = 1; h <= 80; ++h) {
			int visited[256][256] = {};
			int count = 0;
			dfs(count, visited, w, h, 0, 0);
			int s = ___test.maxSize(w, h);
			if (count == s) {
				cout << ".";
			} else {
				cout << "FAILED,h=" << h << "," << count << "," << s;
				break;
			}
		}
		cout << endl;
	}

	return 0;
}
// END CUT HERE
