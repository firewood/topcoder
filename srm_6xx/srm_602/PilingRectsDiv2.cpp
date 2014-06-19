// BEGIN CUT HERE
/*
SRM 602 Div2 Medium (500)

問題
-N枚の四角い紙がある
-面積がlimit以上重なる枚数の最大値を求める

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 

using namespace std; 

class PilingRectsDiv2 {
	public:
	int getmax(vector <int> X, vector <int> Y, int limit) {
		int ans = -1;
		int N = (int)X.size();
		for (int y = 1; y <= 200; ++y) {
			for (int x = y; x <= 200; ++x) {
				if (x*y >= limit) {
					int c = 0;
					for (int i = 0; i < N; ++i) {
						int a = min(X[i], Y[i]);
						int b = max(X[i], Y[i]);
						c += a >= y && b >= x;
					}
					if (c > 0) {
						ans = max(ans, c);
					}
				}
			}
		}
		return ans;
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
			int Arr0[] = {1,2,3,1};
			int Arr1[] = {3,2,4,4};
			int Arg2 = 3;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,7};
			int Arr1[] = {7,4};
			int Arg2 = 25;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			int Arr1[] = {10};
			int Arg2 = 9999;
			int Arg3 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			int Arr1[] = {3};
			int Arg2 = 30;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,6,5,8,2,9,14};
			int Arr1[] = {14,6,13,8,15,6,3};
			int Arg2 = 27;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149};
			int Arr1[] = {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146};
			int Arg2 = 5345;
			int Arg3 = 24;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	PilingRectsDiv2 ___test;
	___test.run_test(-1);

}
// END CUT HERE

