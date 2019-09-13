// BEGIN CUT HERE
/*
SRM 766 Div2 Easy (300)

PROBLEM STATEMENT

Dr. Black was just killed somewhere in his mansion.
You are investigating the murder.

There are six suspects: "White", "Green", "Peacock", "Plum", "Scarlett", and "Mustard".

There are eight rooms: "Hall", "Kitchen", "Ballroom", "Conservatory", "Cellar", "Library", "Lounge", and "Study".

Initially (at time 0) all suspects were in the Hall.

Dr. Black was staying in the room murderRoom for the whole time, and that is also where he was killed. An autopsy of his body has shown that the time of the murder was murderTime.

You have collected a chronologically ordered sequence of events. For each valid index i, there is an event of the following form: "At time eventTime[i], the suspect eventPerson[i] moved to the room eventRoom[i]."

Find the murderer!
That is, if there is a single suspect who was in the murder room at the time of the murder, return their name.
Otherwise, return an empty string.


DEFINITION
Class:Alibi
Method:findMurderer
Parameters:string, int, vector <int>, vector <string>, vector <string>
Returns:string
Method signature:string findMurderer(string murderRoom, int murderTime, vector <int> eventTime, vector <string> eventPerson, vector <string> eventRoom)


NOTES
-You can determine the number of events by looking at the length of the vector <int> eventTime.


CONSTRAINTS
-murderRoom will be one of the rooms listed in the statement.
-murderTime will be between 1 and 1000, inclusive.
-eventTime will contain between 0 and 50 elements, inclusive.
-eventTime, eventPerson and eventRoom will each contain the same number of elements.
-Each element of eventTime will be between 1 and 1000, inclusive.
-Elements of eventTime will be sorted in a strictly increasing order.
-Elements of eventTime will all be distinct from murderTime.
-Each element of eventPerson will be one of the suspects listed in the statement.
-Each element of eventRoom will be one of the rooms listed in the statement.


EXAMPLES

0)
"Library"
10
{ 5, 7, 9 }
{ "Plum", "Scarlett", "Plum" }
{ "Library", "Library", "Cellar" }

Returns: "Scarlett"

Mr. Black was killed in the Library at time 10. At that time, Miss Scarlett was the only suspect in the library -- professor Plum was there earlier but at time 10 he was already in the Cellar. Thus, Scarlett must be the murderer.


1)
"Library"
10
{}
{}
{}

Returns: ""

According to our data, everybody was still in the Hall at the time of the murder, so there is no clear murderer.


2)
"Library"
8
{ 5, 7, 9 }
{ "Plum", "Scarlett", "Plum" }
{ "Library", "Library", "Cellar" }

Returns: ""

At time 8 there were two suspects in the Library so we do not know who's the murderer.


3)
"Hall"
11
{ 2, 4, 6, 8, 10, 12 }
{ "White", "Green", "Peacock", "Plum", "Scarlett", "Mustard" }
{ "Kitchen", "Ballroom", "Conservatory", "Library", "Lounge", "Study" }

Returns: "Mustard"

At time 11 the only suspect still in the Hall was colonel Mustard.


4)
"Library"
10
{3, 7}
{"Plum", "Plum"}
{"Library", "Library"}

Returns: "Plum"

The new room for a person can be the same as their old room. In that case, they just stay where they are. In this case, professor Plum went from the Hall to the Library at time 3 and then nothing changed at time 7.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Alibi {
public:
	string findMurderer(string murderRoom, int murderTime, vector <int> eventTime, vector <string> eventPerson, vector <string> eventRoom) {
		vector<string> suspects({ "White", "Green", "Peacock", "Plum", "Scarlett", "Mustard" });
		vector<string> rooms({ "Hall", "Kitchen", "Ballroom", "Conservatory", "Cellar", "Library", "Lounge", "Study" });
		map<string, int> si, ri;
		for (int i = 0; i < suspects.size(); ++i) {
			si[suspects[i]] = i;
		}
		for (int i = 0; i < rooms.size(); ++i) {
			ri[rooms[i]] = i;
		}
		int w[6] = {};
		int d = ri[murderRoom];
		for (int i = 0; i < eventTime.size(); ++i) {
			w[si[eventPerson[i]]] = ri[eventRoom[i]];
			if (eventTime[i] > murderTime) {
				break;
			}
			if (i < eventTime.size() - 1 && eventTime[i + 1] <= murderTime) {
				continue;
			}
			int cnt = 0, m = -1;
			for (int i = 0; i < 6; ++i) {
				if (w[i] == d) {
					++cnt;
					m = i;
				}
			}
			if (cnt == 1) {
				return suspects[m];
			}
		}
		return "";
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
			string Arg0 = "Library";
			int Arg1 = 10;
			int Arr2[] = { 5, 7, 9 };
			string Arr3[] = { "Plum", "Scarlett", "Plum" };
			string Arr4[] = { "Library", "Library", "Cellar" };
			string Arg5 = "Scarlett";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Library";
			int Arg1 = 10;
			// int Arr2[] = {};
			// string Arr3[] = {};
			// string Arr4[] = {};
			string Arg5 = "";

			vector <int> Arg2;
			vector <string> Arg3;
			vector <string> Arg4;
			verify_case(n, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Library";
			int Arg1 = 8;
			int Arr2[] = { 5, 7, 9 };
			string Arr3[] = { "Plum", "Scarlett", "Plum" };
			string Arr4[] = { "Library", "Library", "Cellar" };
			string Arg5 = "";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Hall";
			int Arg1 = 11;
			int Arr2[] = { 2, 4, 6, 8, 10, 12 };
			string Arr3[] = { "White", "Green", "Peacock", "Plum", "Scarlett", "Mustard" };
			string Arr4[] = { "Kitchen", "Ballroom", "Conservatory", "Library", "Lounge", "Study" };
			string Arg5 = "Mustard";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Library";
			int Arg1 = 10;
			int Arr2[] = {3, 7};
			string Arr3[] = {"Plum", "Plum"};
			string Arr4[] = {"Library", "Library"};
			string Arg5 = "Plum";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "Lounge";
			int Arg1 = 972;
			int Arr2[] = { 10, 60, 61, 67, 72, 131, 133, 140, 148, 152, 160, 180, 281, 283, 332, 398, 412, 419, 446, 488, 489, 518, 525, 531, 553, 560, 625, 635, 639, 645, 674, 683, 692, 697, 721, 735, 737, 749, 753, 766, 791, 834, 846, 881, 956, 958 };
			string Arr3[] = { "Scarlett", "White", "Scarlett", "Mustard", "White", "Peacock", "Green", "White", "Scarlett", "White", "Scarlett", "Mustard", "Scarlett", "Green", "Mustard", "Scarlett", "Scarlett", "Green", "Mustard", "Peacock", "Mustard", "Scarlett", "Peacock", "Scarlett", "Plum", "Peacock", "White", "Peacock", "Peacock", "Peacock", "Mustard", "Scarlett", "Mustard", "Green", "White", "Plum", "White", "Peacock", "Plum", "Mustard", "White", "White", "Peacock", "Green", "White", "Scarlett" };
			string Arr4[] = { "Ballroom", "Kitchen", "Hall", "Cellar", "Library", "Lounge", "Library", "Lounge", "Library", "Ballroom", "Study", "Cellar", "Conservatory", "Kitchen", "Lounge", "Kitchen", "Cellar", "Cellar", "Kitchen", "Library", "Hall", "Kitchen", "Study", "Library", "Study", "Study", "Library", "Lounge", "Study", "Ballroom", "Ballroom", "Lounge", "Cellar", "Cellar", "Kitchen", "Study", "Study", "Lounge", "Study", "Conservatory", "Study", "Library", "Conservatory", "Hall", "Cellar", "Kitchen" };
			string Arg5 = "";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Alibi ___test;
	___test.run_test(5);
}
// END CUT HERE
