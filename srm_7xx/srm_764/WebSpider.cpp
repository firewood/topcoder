// BEGIN CUT HERE
/*
SRM 764 Level 3 (400)

PROBLEM STATEMENT
You are writing software that will spider a web site (that is, it visits all links on the homepage, then visits all links on those pages, etc.), and travels three levels deep.  You have a list of all the links found in the first pass, in the second pass, and in the third pass.

You are given a vector <string>, firstPass, containing a list of all the links visited from the home page.  They will all be in the form "page", "subfolder/page", "subfolder/subfolder/page", etc.  There may be any level of depth to the subfolders.

You are given a vector <string>, secondPass, containing a list of all the links found in the second pass (by visiting the links found on the home page).  Each element is of the form "pageNumber address", where pageNumber is the index (from 0) of the page from firstPass on which the link was found.  address is formatted similarly to the elements of firstPass, with the added possibility of a subfolder named "..", which means "go to the parent folder".  However, ".." can only appear as the first subfolder, or if all the previous subfolders are also "..".  So, if the homepage contains a link to "reports/sales.htm", sales.htm is in the reports folder.  If that page then contains a link to "products.htm", then products.htm is also in the reports folder.  However, if that page contains a link to "../home.htm", then that is a link back to a page in the root folder.

You are finally given a vector <string>, thirdPass, indicating all of the links found in the third pass.  It is formatted exactly as in secondPass, but the page numbers here refer to the index of the page from secondPass.  In all cases, the links reference will be relative paths.  In particular, they will never begin with a '/' character.

You are to return an int indicating the number of distinct pages (not including the initial homepage) visited during this crawl of the web site.


DEFINITION
Class:WebSpider
Method:countPages
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int countPages(vector <string> firstPass, vector <string> secondPass, vector <string> thirdPass)


NOTES
-The links are all case sensitive, so "home.htm" is different from "home.HTM".
-Links may point at directories (see example 1).


CONSTRAINTS
-firstPass will contain between 1 and 50 elements, inclusive.
-secondPass and thirdPass will contain between 0 and 50 elements, inclusive.
-A link will be formatted as a sequence of letters, numbers, periods and slashes.  
-No link will contain leading, trailing or double slashes, and the file name will contain at least one letter or number.  
-Each element of firstPass will be formatted as a single link.
-Each element of secondPass and thirdPass will be formatted as an integer with no extra leading zeros, followed by a space and a link.
-The integers in secondPass and thirdPass will reference valid pages in firstPass and secondPass, respectively.
-None of the links will go above the root directory.
-A subfolder containing only periods will only be ".." and is only allowed in secondPass or thirdPass.  Furthermore, it must be either the first subfolder or else all the preceding subfolders must also be "..".  Hence, links like "reports/../home.htm" and ".../abc.htm" are not allowed.


EXAMPLES

0)
{"home.htm", "sitemap.htm", "contact.htm", "support/login.jsp"}
{"2 locations.htm", "3 ../home.htm"}
{"0 contact.htm"}

Returns: 5

On the home page, the first pass finds that there are four links: "home.htm", "sitemap.htm", "contact.htm", and "login.jsp".  Notice that the login page is in the "support" folder.
On the second pass, we find that the contact page has a link to "locations.htm", and the login page has a link back to the home page (which we have already visited).
On the third (and final) pass, we find that the locations page has a link back to the contact page (which we have already seen).
So, we take account of all pages found on the site: home, sitemap, contact, login, and locations.  Thus, there are five pages.


1)
{"index.html","products/all/INDEX.HTML","images/products/A101.GIF"}
{"1 ../../index.html","1 ../../products"}
{}

Returns: 4

Note that the second link in secondPass is to products, which is the same as a directory name.  This is allowed, and should be counted separately.


2)
{".rc"}
{}
{}

Returns: 1


3)
{"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"}
{"0 a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"}
{"0 ../a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a",
 "0 ..a/a",
 "0 a../a.."}

Returns: 5


4)
{"abc/ccba","ab/cba","..a"}
{"0 cba","1 ccba"}
{"0 cba","1 ccba"}

Returns: 5


5)
{"a","ab/ab","ab/ab/abc","abc/abc"}
{"0 ab/ab","1 ab","1 ../ab/ab","2 ../../ab/abc"}
{"0 ../ab/ab","2 ../abc/abc","1 ab/ab"}

Returns: 6


6)
{"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"}
{"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"}
{"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"}

Returns: 1


7)
{"index.asp", "contact.asp", "about/index.asp", "users/support.asp",
 "company/executiveteam.asp", "products/catalog.asp"}
{"1 index.asp", "1 requestinfo.asp", "2 ../index.asp", "2 history.asp",
"3 ../index.asp", "3 helpdesk.asp", "4 ../index.asp", "4 boardofdirectors.asp",
"4 location.asp", "5 ../index.asp", "5 new/index.asp",  "5 ../index.asp", "5 sale.asp"}
{"10 ../../index.asp", "11 products/index.asp", "11 products/catalog.asp"}

Returns: 14

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class WebSpider {
public:
	int countPages(vector <string> firstPass, vector <string> secondPass, vector <string> thirdPass) {
		set<string> all_paths;
		vector<vector<string>> passes({ firstPass, secondPass, thirdPass });
		vector<string> prev;
		for (int i = 0; i < (int)passes.size(); ++i) {
			vector<string> next;
			for (string s : passes[i]) {
				if (i > 0) {
					string src = prev[stoi(s)];
					src = src.substr(0, max(0, (int)src.rfind('/')));
					s = s.substr(s.find(' ') + 1);
					while (s.substr(0, 3) == "../") {
						src = src.substr(0, max(0, (int)src.rfind('/')));
						s = s.substr(3);
					}
					if (!src.empty()) {
						s = src + "/" + s;
					}
				}
				all_paths.insert(s);
				next.push_back(s);
			}
			prev = next;
		}
		return (int)all_paths.size();
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
			string Arr0[] = {"home.htm", "sitemap.htm", "contact.htm", "support/login.jsp"};
			string Arr1[] = {"2 locations.htm", "3 ../home.htm"};
			string Arr2[] = {"0 contact.htm"};
			int Arg3 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"index.html","products/all/INDEX.HTML","images/products/A101.GIF"};
			string Arr1[] = {"1 ../../index.html","1 ../../products"};
			// string Arr2[] = {};
			int Arg3 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2;
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".rc"};
			// string Arr1[] = {};
			// string Arr2[] = {};
			int Arg3 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			vector <string> Arg2;
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
			string Arr1[] = {"0 a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
			string Arr2[] = {"0 ../a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a",
 "0 ..a/a",
 "0 a../a.."};
			int Arg3 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abc/ccba","ab/cba","..a"};
			string Arr1[] = {"0 cba","1 ccba"};
			string Arr2[] = {"0 cba","1 ccba"};
			int Arg3 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a","ab/ab","ab/ab/abc","abc/abc"};
			string Arr1[] = {"0 ab/ab","1 ab","1 ../ab/ab","2 ../../ab/abc"};
			string Arr2[] = {"0 ../ab/ab","2 ../abc/abc","1 ab/ab"};
			int Arg3 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
			string Arr1[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"};
			string Arr2[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"};
			int Arg3 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"index.asp", "contact.asp", "about/index.asp", "users/support.asp",
 "company/executiveteam.asp", "products/catalog.asp"};
			string Arr1[] = {"1 index.asp", "1 requestinfo.asp", "2 ../index.asp", "2 history.asp",
"3 ../index.asp", "3 helpdesk.asp", "4 ../index.asp", "4 boardofdirectors.asp",
"4 location.asp", "5 ../index.asp", "5 new/index.asp",  "5 ../index.asp", "5 sale.asp"};
			string Arr2[] = {"10 ../../index.asp", "11 products/index.asp", "11 products/catalog.asp"};
			int Arg3 = 14;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countPages(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WebSpider ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(7);
	___test.run_test(-1);
}
// END CUT HERE
