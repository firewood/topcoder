// BEGIN CUT HERE
/*
// SRM 534 Div2 Easy (250)

問題
ディレクトリのファイルのリストがある。
リストの最後がカレントディレクトリとルートディレクトリでないとき、
最初に見つかったディレクトリを末尾と交換する。
それでもリストの最後がカレントディレクトリとルートディレクトリでないとき、
最初に見つかったディレクトリを末尾のひとつ前と交換する。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class EllysDirectoryListing {

	bool IsDir(const string &s) {
		return strcmp(s.c_str(), ".") == 0 || strcmp(s.c_str(), "..") == 0;
	}

	bool Done(const StrVec &v) {
		int len = v.size();
		return IsDir(v[len-1]) && IsDir(v[len-2]);
	}

public:
	vector <string> getFiles(vector <string> files) {
		int len = files.size();
		while (files.size() >= 2) {
			if (Done(files)) {
				break;
			}
			int i;
			for (i = 0; i < len; ++i) {
				if (IsDir(files[i])) {
					break;
				}
			}
			swap(files[i], files[len-1]);
			if (Done(files)) {
				break;
			}
			for (i = 0; i < len; ++i) {
				if (IsDir(files[i])) {
					break;
				}
			}
			swap(files[i], files[len-2]);
		}
		return files;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ContestApplet.jnlp", ".", "Image.jpg", "..", "Book.pdf", "Movie.avi"};
			string Arr1[] = {"ContestApplet.jnlp", "Movie.avi", "Image.jpg", "Book.pdf", "..", "." };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getFiles(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Image.jpg", "..", "."};
			string Arr1[] = {"Image.jpg", "..", "." };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getFiles(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..", ".", "Image.jpg"};
			string Arr1[] = {"Image.jpg", ".", ".." };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getFiles(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"No", "..", "Zaphod", ".", "Just", "very", "very...", "Improbable"};
			string Arr1[] = {"No", "Improbable", "Zaphod", "very...", "Just", "very", ".", ".." };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getFiles(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"www.topcoder.com", "Ever.tried", ".", "Ever.failed", "..", "No", "Matter.", "Try", "Again.", "Fail", "Again..", "Fail.Better"};
			string Arr1[] = {"www.topcoder.com", "Ever.tried", "Fail.Better", "Ever.failed", "Again..", "No", "Matter.", "Try", "Again.", "Fail", "..", "." };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getFiles(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"This", ".", "is", "tricky", "test", ".."};
			string Arr1[] = {"This", "test", "is", "tricky", "..", "." };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getFiles(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysDirectoryListing ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
