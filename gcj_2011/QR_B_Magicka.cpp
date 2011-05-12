/*

Qualification Round 2011
Problem B. Magicka


Introduction

Magicka(TM) is an action-adventure game developed by Arrowhead Game Studios.
In Magicka you play a wizard, invoking and combining elements to create Magicks.
This problem has a similar idea, but it does not assume that you have played Magicka.

Note: "invoke" means "call on." For this problem, it is a technical term and
you don't need to know its normal English meaning.


Problem

As a wizard, you can invoke eight elements, which are the "base" elements.
Each base element is a single character from {Q, W, E, R, A, S, D, F}.
When you invoke an element, it gets appended to your element list.
For example: if you invoke W and then invoke A, 
(we'll call that "invoking WA" for short) then your element list will be [W, A].

We will specify pairs of base elements that combine to form non-base elements
(the other 18 capital letters). For example, Q and F might combine to form T.
If the two elements from a pair appear at the end of the element list,
then both elements of the pair will be immediately removed,
and they will be replaced by the element they form. In the example above,
if the element list looks like [A, Q, F] or [A, F, Q] at any point,
it will become [A, T].

We will specify pairs of base elements that are opposed to each other.
After you invoke an element, if it isn't immediately combined to form another element,
and it is opposed to something in your element list, then your element list will be cleared.

For example, suppose Q and F combine to make T. R and F are opposed to each other.
Then invoking the following things (in order, from left to right) will have the following results:

・QF → [T] (Q and F combine to form T)
・QEF → [Q, E, F] (Q and F can't combine because they were never at the end of the element list together)
・RFE → [E] (F and R are opposed, so the list is cleared; then E is invoked)
・REF → [] (F and R are opposed, so the list is cleared)
・RQF → [R, T] (QF combine to make T, so the list is not cleared)
・RFQ → [Q] (F and R are opposed, so the list is cleared)

Given a list of elements to invoke, what will be in the element list when you're done?


Input

The first line of the input gives the number of test cases, T. T test cases follow.
Each test case consists of a single line, containing the following space-separated elements in order:

First an integer C, followed by C strings, each containing three characters:
two base elements followed by a non-base element. This indicates that
the two base elements combine to form the non-base element. Next will come an integer D,
followed by D strings, each containing two characters: two base elements
that are opposed to each other. Finally there will be an integer N,
followed by a single string containing N characters: the series of base elements you are to invoke.
You will invoke them in the order they appear in the string (leftmost character first, and so on).


Output

For each test case, output one line containing "Case #x: y", where x is the case number
(starting from 1) and y is a list in the format "[e0, e1, ...]" where ei is the ith element
of the final element list. Please see the sample output for examples.


Limits

1 <= T <= 100.
Each pair of base elements may only appear together in one combination,
though they may appear in a combination and also be opposed to each other.
No base element may be opposed to itself.
Unlike in the computer game Magicka, there is no limit to the length of the element list.


Small dataset

0 <= C <= 1.
0 <= D <= 1.
1 <= N <= 10.
Large dataset

0 <= C <= 36.
0 <= D <= 28.
1 <= N <= 100.


Sample


Input

5
0 0 2 EA
1 QRI 0 4 RRQR
1 QFT 1 QF 7 FAQFDFQ
1 EEZ 1 QE 7 QEEEERA
0 1 QW 2 QW


Output 

Case #1: [E, A]
Case #2: [R, I, R]
Case #3: [F, D, T]
Case #4: [Z, E, R, A]
Case #5: []


Magicka(TM) is a trademark of Paradox Interactive AB.
Paradox Interactive AB does not endorse and has no involvement with Google Code Jam.

*/


#include <stdio.h>
#include <string.h>
#include <list>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef __int64 __ll;
typedef list<int> LI;

typedef list<char> CharList;
typedef set<char> CharSet;
typedef map<int, int> IntMap;
typedef map<char, CharSet> OpposedMap;

class GCJ {
	static const size_t BufferSize = 1024000;
	FILE *m_Source;
	size_t m_BufferSize;
	char *m_Buffer;

public:
	GCJ(FILE *source, size_t buffer_size = BufferSize) {
		m_Source = source;
		m_BufferSize = buffer_size;
		m_Buffer = new char[m_BufferSize];
	}

	~GCJ() {
		delete [] m_Buffer;
	}

	bool solve(void) {
		int cases;
		if (!getInt(cases) || cases < 1) {
			return false;
		}

		int solved = 0;
		int i;
		for (i = 0; i < cases; ++i) {
			if (solve(i)) {
				++solved;
			}
		}
		return solved >= cases;
	}

private:
	bool solve(int case_index) {
		char *p = getSingleLine();
		if (!p) return false;

		const char *delim = "\t ";
		p = strtok(p, delim);
		if (!p) return false;
		IntMap combine_map;
		int transforms = atoi(p);
		while (--transforms >= 0) {
			p = strtok(NULL, delim);
			if (strlen(p) != 3) return false;
			unsigned char a = *p++;
			unsigned char b = *p++;
			char c = *p;
			combine_map[((unsigned int)a << 8) | (unsigned int)b] = c;
			combine_map[((unsigned int)b << 8) | (unsigned int)a] = c;
		}

		p = strtok(NULL, delim);
		if (!p) return false;
		OpposedMap opposed_map;
		transforms = atoi(p);
		while (--transforms >= 0) {
			p = strtok(NULL, delim);
			if (strlen(p) != 2) return false;
			char a = *p++;
			char b = *p;

			OpposedMap::iterator it = opposed_map.find(a);
			if (it == opposed_map.end()) {
				CharSet s;
				opposed_map[a] = s;
			}
			(opposed_map[a]).insert(b);

			it = opposed_map.find(b);
			if (it == opposed_map.end()) {
				CharSet s;
				opposed_map[b] = s;
			}
			(opposed_map[b]).insert(a);
		}

		p = strtok(NULL, delim);
		if (!p) return false;
		int length = atoi(p);

		p = strtok(NULL, delim);
		if (!p) return false;

		CharList char_queue;
		IntMap char_count;
		int i;
		for (i = 0; i < 256; ++i) {
			char_count[i] = 0;
		}

		unsigned char c;
		while ((c = *p++) != 0) {
			char_queue.push_back(c);
			char_count[c] += 1;

			// combine
			while (char_queue.size() >= 2) {
				CharList::const_reverse_iterator r = char_queue.rbegin();
				unsigned char a = *r++;
				unsigned char b = *r;
				int combined = ((int)a << 8) | (int)b;
				IntMap::const_iterator it = combine_map.find(combined);
				if (it == combine_map.end()) {
					break;
				}
				char_count[a] -= 1;
				char_count[b] -= 1;
				char_queue.pop_back();
				char_queue.pop_back();
				char c = (char)(it->second);
				char_queue.push_back(c);
				char_count[c] += 1;
			}

			if (char_queue.size() < 2) {
				continue;
			}

			// opposed
			c = *(char_queue.rbegin());
			{
				OpposedMap::const_iterator it = opposed_map.find(c);
				if (it == opposed_map.end()) {
					continue;
				}
				CharSet::const_iterator x;
				for (x = it->second.begin(); x != it->second.end(); ++x) {
					unsigned char t = *x;
					IntMap::const_iterator s = char_count.find(t);
					if (s == char_count.end()) {
						continue;
					}
					int req_count = 1 + (c == t);
					if (s->second >= req_count) {
						char_queue.clear();
						for (i = 0; i < 256; ++i) {
							char_count[i] = 0;
						}
						break;
					}
				}
			}
		}

		string result;
		{
			CharList::const_iterator it;
			for (it = char_queue.begin(); it != char_queue.end(); ++it) {
				if (!result.empty()) {
					result += ", ";
				}
				result += (char)(*it);
			}
		}

		printf("Case #%d: [%s]\n", case_index + 1, result.c_str());
		return true;
	}

	int getCases(void) {
		int cases;
		char *p = getSingleLine();
		if (p != NULL && sscanf(p, "%d", &cases) >= 1) {
			return cases;
		}
		return -1;
	}

	bool getInt(int &i) {
		char *p = getSingleLine();
		return p != NULL && sscanf(p, "%d", &i) >= 1;
	}

	char *getSingleLine(void) {
		char *p = fgets(m_Buffer, m_BufferSize, m_Source);
		if (!p) {
			return NULL;
		}
		char *term = p + strlen(p) - 1;
		if (term > p && *term == '\n') {
			*term = 0;
		}
		return p;
	}

};


int main()
{
	GCJ gcj(stdin);
	return gcj.solve() ? 0 : -1;
}

