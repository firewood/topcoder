// BEGIN CUT HERE 
/*
// SRM 504 Div2 Middle 500
// PROBLEM STATEMENT
// The most famous math contest is going to start soon. As usual in math contests, there is going to be a problem that involves an abstract machine of sorts and predicting how will it process a sequence of colored balls. This time, the machine will use the balls as a special language that works as follows: The process begins when the machine is given a stack of balls that are colored either white or black. The next steps are as follows:
Take the top ball out of the stack, show it to the audience and discard it.
If the taken ball was white, the contents of the stack will be dumped into a new stack and the new stack will be used in the next step. In other words, the order of the balls in the stack will be reversed.
If the taken ball was black, the balls inside the stack will get their colors inverted. Every originally-white ball will turn black and every originally-black ball will turn white.
The process is repeated until there are no balls left in the stack.

You have been hired to make a program to grade the answers to this contest question. Given the contents of the stack, return the number of black balls that will be shown to the audience. Due to limitations in the input size, the contents of the stack are given by string ballSequence, and int repetitions. To form the sequence of balls, repeat ballSequence repetitions times. The final sequence will contain 'B' and 'W' characters denoting a black or a white ball respectively from the top of the stack to the bottom.

DEFINITION
Class:MathContest
Method:countBlack
Parameters:string, int
Returns:int
Method signature:int countBlack(string ballSequence, int repetitions)


CONSTRAINTS
-ballSequence will contain between 1 and 50 characters, inclusive.
-Each character in ballSequence will be 'B' or 'W'.
-repetitions will be between 1 and 3500, inclusive.
-The total number of balls after generating the sequence will be between 1 and 100000, inclusive.


EXAMPLES

0)
"BBWWB"
1

Returns: 2

The starting contents of the stack from top to bottom are: BBWWB. The process can be simulated as follows:

(Stack contents: BBWWB). Take a black ball, change the contents from BWWB to WBBW.
(Stack contents: WBBW). Take a white ball, change the contents from BBW to WBB.
(Stack contents: WBB). Take a white ball, change the contents from BB to BB.
(Stack contents: BB). Take a black ball, change the contents from B to W.
(Stack contents: W). Take a white ball.



1)
"BBB"
10

Returns: 1

There are initially 30 black balls in the stack. After the first one is processed, all the remaining balls become white. A white ball cannot change the color of the remaining balls.

2)
"BW"
10

Returns: 20

A series of alternating black and white balls which begins with a black ball. Initially, a black ball inverts the colors of the remaining balls, making them a new alternation of black and white balls that begins with a black ball. The process will repeat for each ball and each ball will be black when picked.

3)
"WWWWWWWBWWWWWWWWWWWWWW"
1

Returns: 2

Eventually, the black ball will be reached after reversing the order 14 times. It will turn all of the remaining balls black. But the next black ball that is processed will turn all the remaining balls white once again.


*/
// END CUT HERE
#line 73 "MathContest.cpp"
#include <string>
#include <vector>

using namespace std;

class MathContest {
	public:
	int countBlack(string ballSequence, int repetitions) {
		char *buffer = new char[100000 + 4];
		char *dst = buffer;
		int chunk_size = (int)ballSequence.length();
		int remain = chunk_size * repetitions;
		while (--repetitions >= 0) {
			memcpy(dst, ballSequence.c_str(), chunk_size);
			dst += chunk_size;
		}
		const char *head = buffer;
		const char *tail = buffer + remain - 1;
		char target = 'B';
		bool is_head = true;
		int black = 0;
		while (--remain >= 0) {
			char c;
			if (is_head) {
				c = *head++;
			} else {
				c = *tail--;
			}
			if (c == target) {
				++black;
				target ^= ('B' ^ 'W');
			} else {
				is_head = !is_head;
			}
		}
		delete [] buffer;
		return black;
	}
};

// BEGIN CUT HERE 
static void Test(const char *seq, int repeat, int expected)
{
	MathContest ___test;
	int result = ___test.countBlack(seq, repeat);
	printf("result: %s, seq:%s, ret:%d\n", result == expected ? "OK" : "FAILED", seq, result);
}

int main() {
	Test("BBWWB", 1, 2);
	Test("BBB", 10, 1);
	Test("BW", 10, 20);
	Test("WWWWWWWBWWWWWWWWWWWWWW", 1, 2);
	return 0;
}
// END CUT HERE
