/*

Google Code Jam 2011 Round 1A

Problem B. The Killer Word


Problem

You are playing Hangman with your friend Sean. And while you have heard that
Sean is very good at taking candy from a baby, he is not as good at this game.
Can you take advantage of Sean's imperfect strategy, and make him lose
as badly as possible?

 +--+
 |  O
 | /|\       Mystery word: _ a _ a _ a _
 | / \
 |
+-+---+
Hangman is played as follows:

There is a dictionary D of all valid words, which both you and Sean know. A
word consists only of the characters a - z. In particular, there are no spaces.
You begin by choosing any word from D, and writing it down on a blackboard
with each letter replaced by a blank: _.
On his turn, Sean can choose any letter and ask you if it is in the word. If
it is, you reveal all locations of that letter. Otherwise, Sean loses a point.
Once all letters in the word have been revealed, the round ends.
The round never ends early, no matter how many points Sean loses.
Sean uses a very simple strategy. He makes a list L of the 26 letters in some
order, and goes through the list one letter at a time. If there is at least
one word in D that (a) has the letter he is thinking of, and (b) is consistent
with what you have written down so far and the result of all of Sean's
previous guesses, then Sean guesses that letter. Otherwise, he skips it.
No matter what, Sean then moves on to the next letter in his list.

Given Sean's list, what word should you choose to make Sean lose as many as
points as possible? If several choices are equally good, you should choose
the one that appears first in D.


Example

Suppose Sean decides to guess the letters in alphabetical order
(i.e., L = "abcdefghijklmnopqrstuvwxyz"), and D contains the words banana,
caravan, and pajamas. If you choose pajamas, the game would play out as follows:

You begin by writing 7 blanks _ _ _ _ _ _ _ on the blackboard. Based on the
number of blanks, Sean knows immediately that the word is either caravan or pajamas.
Sean begins by guessing a since it is first in L, and you reveal all locations
of the letter a on the blackboard: _ a _ a _ a _.
Sean skips b even though it is used in banana. Sean already knows that is not
your word.
He then guesses c because it appears in caravan. It does not appear in the word
you actually chose though, so Sean loses a point and nothing more is revealed.
By process of elimination, Sean now knows your word has to be pajamas, so he
proceeds to guess j, m, p, and s in order, without losing any more points.
So Sean loses one point if you choose pajamas. He would have gotten either of
the other words without losing any points.


Input

The first line of the input gives the number of test cases, T. T test cases follow.
Each test case begins with a line containing integers N and M, representing the
number of words in the dictionary and the number of lists to consider.

The next N lines contain the words in the dictionary, one per line: D1, D2, ..., DN.
Each word is an arbitrary sequence of characters a - z.

The final M lines contain all of the lists Sean will use, one per line: L1, L2, ..., LM.
Each list is exactly 26 letters long, containing each letter exactly once.
Sean will use these lists to guess letters as described above.


Output

For each test case, output one line containing "Case #x: w1 w2 ... wM", where
x is the case number (starting from 1) and wi is the word you should choose
if Sean guesses the letters in order Li. If multiple words cause Sean to lose
the same number of points, you should choose the option that appears first
in the dictionary.


Limits

1 <= T <= 10.
Each word in D will have between 1 and 10 characters inclusive.
No two words in D will be the same within a single test case.
Small dataset

1 <= N <= 100.
1 <= M <= 10.

Large dataset

1 <= N <= 10000.
1 <= M <= 100.


Sample


Input 

2
3 2
banana
caravan
pajamas
abcdefghijklmnopqrstuvwxyz
etaoisnhrdlcumwfgypbvkjxqz
4 1
potato
tomato
garlic
pepper
zyxwvutsrqponmlkjihgfedcba


Output 

Case #1: pajamas caravan
Case #2: garlic

*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> IntVec;
typedef vector<string> StrVec;
typedef map<string, IntVec> IntVecMap;

#define DIC_LEN 10
#define MAX_N 10000

char w[MAX_N][DIC_LEN+1];
IntVec p[MAX_N][26];
int s[MAX_N];

static void classify(const IntVec &dicidx, const string &sean, int n);

static void solve(const IntVec &dicidx, const string &sean, int n) {
	if (n >= (int)sean.length()) {
		return;
	}
	int i, j;
	int c = sean[n] - 'a';
	bool f = false;
	for (i = 0; i < (int)dicidx.size(); ++i) {
		IntVec &v = p[dicidx[i]][c];
		if (v.size() >= 1) {
			f = true;
			break;
		}
	}
	if (!f) {
		// not found; ignore this character
		solve(dicidx, sean, n+1);
	} else {
		for (i = 0; i < (int)dicidx.size(); ++i) {
			IntVec &v = p[dicidx[i]][c];
			if (v.size() >= 1) {
				for (j = 0; j < (int)v.size(); ++j) {
					w[dicidx[i]][v[j]] = c + 'a';
				}
			} else {
				++s[dicidx[i]];
			}
		}
		classify(dicidx, sean, n+1);
	}
}

static void classify(const IntVec &dicidx, const string &sean, int n) {
	int i;
	IntVecMap m;
	for (i = 0; i < (int)dicidx.size(); ++i) {
		m[w[dicidx[i]]].push_back(dicidx[i]);
	}
	IntVecMap::const_iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		if (it->second.size() >= 2) {
			solve(it->second, sean, n);
		}
	}
}

static void prepare(const StrVec &dic) {
	int i, j;
	for (i = 0; i < MAX_N; ++i) {
		for (j = 0; j < 26; ++j) {
			if (p[i][j].size()) {
				p[i][j].clear();
			}
		}
	}

	for (i = 0; i < (int)dic.size(); ++i) {
		for (j = 0; j < (int)dic[i].length(); ++j) {
			w[i][j] = '_';
			p[i][dic[i][j] - 'a'].push_back(j);
		}
		w[i][j] = 0;
		s[i] = 0;
	}
}

int main()
{
	int i, t, T;
	cin >> T;
	for (t = 0; t < T; ++t) {
		int n, m;
		cin >> n >> m;
		StrVec dic;
		IntVec dicidx;
		while (n-- > 0) {
			string s;
			cin >> s;
			dicidx.push_back(dic.size());		// 0,1,2,...
			dic.push_back(s);
		}

		cout << "Case #" << (t+1) << ":";

		while (m-- > 0) {
			string sean;
			cin >> sean;
			prepare(dic);
			classify(dicidx, sean, 0);
			int mi = 0, ms = 0;
			for (i = 0; i < (int)dic.size(); ++i) {
				if (s[i] > ms) {
					mi = i, ms = s[i];
				}
			}
			cout << " " << dic[mi];
		}
		cout << endl;
	}

	return 0;
}

