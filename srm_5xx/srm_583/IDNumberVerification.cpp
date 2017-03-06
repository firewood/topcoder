// BEGIN CUT HERE
/*
SRM 583 Div2 Medium (550)

問題
-中国では国民に18桁のIDが与えられる
-IDは17桁の数値と、1桁の数値または文字Xからなる
-最初の6桁は地域コードであり、有効な地域コードが配列で与えられる
-次の8桁は誕生日である(うるう年を考慮すること)
-続く3桁は通し番号であり、000は無効である
-通し番号が奇数なら男性、偶数なら女性である
-最後の1桁はチェックディジットである
-IDが有効かどうかと、性別を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool is_uruu(int year) {
	return (year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0);
}

class IDNumberVerification {

	bool check(string id, vector <string> regionCodes, bool &s) {
		bool r = false;
		for (string s : regionCodes) {
			if (s.compare(id.substr(0, 6)) == 0) {
				r = true;
				break;
			}
		}
		if (!r) {
			return false;
		}

		int year = atoi(id.substr(6, 4).c_str());
		int month = atoi(id.substr(10, 2).c_str());
		int day = atoi(id.substr(12, 2).c_str());
		if (year < 1900 || year > 2011) {
			return false;
		}
		int mdays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month < 1 || month > 12) {
			return false;
		}
		if (day < 1 || day > mdays[month - 1]) {
			return false;
		}
		if (month == 2 && day == 29 && !is_uruu(year)) {
			return false;
		}

		int seq = atoi(id.substr(14, 3).c_str());
		if (seq == 0) {
			return false;
		}
		s = (seq % 2) != 0;

		int sum = 0;
		for (int i = 0; i < 17; ++i) {
			sum += (id[i] - '0') * (1 << (17 - i));
		}
		sum = (12 - sum % 11) % 11;
		if (sum == 10 && id[17] == 'X') {
			return true;
		}
		return sum == (id[17] - '0');
	}

public:
	string verify(string id, vector <string> regionCodes) {
		bool s;
		if (!check(id, regionCodes, s)) {
			return "Invalid";
		}
		return s ? "Male" : "Female";
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
			string Arg0 = "441323200312060636";
			string Arr1[] = {"441323"};
			string Arg2 = "Male";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "62012319240507058X";
			string Arr1[] = {"620123"};
			string Arg2 = "Female";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "321669197204300886";
			string Arr1[] = {"610111","659004"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "230231198306900162";
			string Arr1[] = {"230231"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "341400198407260005";
			string Arr1[] = {"341400"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "520381193206090891";
			string Arr1[] = {"532922","520381"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IDNumberVerification ___test;
	___test.run_test(-1);
}
// END CUT HERE
