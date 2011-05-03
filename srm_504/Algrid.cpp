// BEGIN CUT HERE 
/*
// PROBLEM STATEMENT
// Algrid is a program that uses a single grid with cells colored white or black as input and returns a new one as output. The grid has H rows and W columns. The topmost row is row 0, the bottommost row is row H-1, the leftmost column is column 0 and the rightmost column is column W-1. The cell at row i, column j can be denoted as (i,j). The program works by evaluating pairs of contiguous cells and making decisions depending on their contents. The following pseudo-code describes how the program works:


For i = 0 to H-2:
    For j = 0 to W-2:
        //Get the current colors of cells (i,j) and (i,j+1)
        A = Color(i,j) , B = Color(i,j+1)

        If (A,B) == (White, White) Then:
             Do nothing.
        EndIf
        If (A,B) == (Black, White) Then: 
             Repaint cells (i+1,j) and (i+1,j+1) Black.
        EndIf
        If (A,B) == (White, Black) Then:
             Repaint cells (i+1,j) and (i+1,j+1) White.
        EndIf
        if (A,B) == (Black, Black) Then:
             Swap the colors in cells (i+1,j) and (i+1,j+1).
        EndIf
    EndFor
EndFor


You will be given a possible output for the program as a vector <string> output. The j-th character in the i-th element of output represents the color of cell (i,j) where 'W' represents white and 'B' represents black. Find an input grid that would yield output as a result. If there is more than one possible result, find the lexicographically smallest one. Return the found grid as a vector <string> following the same format as the input. If there are no grids that would generate the wanted output, return an empty vector <string> instead.

DEFINITION
Class:Algrid
Method:makeProgram
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> makeProgram(vector <string> output)


NOTES
-To compare two vector <string>s A and B, find the smallest index i such that A[i] and B[i] differ. If A[i] is lexicographically smaller than B[i], we say that A is lexicographically smaller than B, and vice versa.
-To compare two strings C and D, find the smallest index i such that the characters C[i] and D[i] differ. If C[i] is smaller in ASCII ordering than D[i], we say that C is lexicographically smaller than D, and vice versa.


CONSTRAINTS
-output will contain between 2 and 16 elements, inclusive.
-Each element of output will contain between 2 and 16 characters, inclusive.
-All elements of output will have the same length.
-Each element of output will only contain 'W' or 'B' characters.


EXAMPLES

0)
{"WWWWWWW",
 "WWWWWWB",
 "BBBBBWW"}

Returns: {"WWWWWWW", "WWWWWWB", "BBBBBBB" }

The following is another input grid that would yield the same output but is not the wanted result as it is not the lexicographically smallest:

WWWWWWW
WWWWWWB
BBBBBWB


1)
{"BBBBB",
 "WBWBW"}

Returns: {"BBBBB", "WWBWB" }



2)
{"BBBB",
 "BBBB",
 "BBWB",
 "WWBB",
 "BWBB"}

Returns: { }

There is no possible input that would generate this output.

3)
{"WWBBBBW",
 "BWBBWBB",
 "BWBBWBW",
 "BWWBWBB"}

Returns: {"WWBBBBW", "BBBBBWB", "BBBBBBB", "BBBWBBB" }



*/
// END CUT HERE
#line 98 "Algrid.cpp"
#include <string>
#include <vector>

using namespace std;
typedef vector<string>VS;

class Algrid {
	public:
	vector <string> makeProgram(vector <string> output) {
		VS e;
		int H = output.size();
		if (H <= 1) {
			return e;
		}
		int W = output[0].length();

		char buffer[16][20];
		int x, y;
		for (y = 0; y < H; ++y) {
			strcpy(buffer[y], output[y].c_str());
		}

		VS r;
		r.push_back(output[0]);
		for (y = 0; y <= (H - 2); ++y) {
			char dst[20] = { 0 };
			for (x = 0; x < W; ++x) {
				dst[x] = x;
			}

			for (x = 0; x <= (W - 2); ++x) {
				if (buffer[y][x] == 'W' && buffer[y][x + 1] == 'W') {
					// nothing to do
				} else if (buffer[y][x] == 'B' && buffer[y][x + 1] == 'W') {
					// BW: fill with black
					dst[x] = 'B';
					dst[x + 1] = 'B';
				} else if (buffer[y][x] == 'W' && buffer[y][x + 1] == 'B') {
					// WB: fill with white
					dst[x] = 'W';
					dst[x + 1] = 'W';
				} else if (buffer[y][x] == 'B' && buffer[y][x + 1] == 'B') {
					// BB: swap
					char c = dst[x + 1];
					dst[x + 1] = dst[x];
					dst[x] = c;
				} else {
					return e;
				}
			}

			char src[20] = { 0 };
			memset(src, 'B', W);
			for (x = 0; x < W; ++x) {
				if (dst[x] == 'W' || dst[x] == 'B') {
					if (dst[x] != buffer[y + 1][x]) {
						return e;
					}
				} else {
					src[dst[x]] = buffer[y + 1][x];
				}
			}

			r.push_back(src);
		}

		return r;
	}
};

// BEGIN CUT HERE



static void Test(const char *seq)
{
	char buffer[1000];
	strcpy(buffer, seq);
	vector <string> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(p);
		p = strtok(NULL, " ,");
	}
	Algrid ___test;
	v = ___test.makeProgram(v);
	printf("result: %d\n", v.size());
	size_t i;
	for (i = 0; i < v.size(); ++i) {
		printf("%s\n", v[i].c_str());
	}
}

int main() {
	Test("WWWWWWW WWWWWWB BBBBBWW");	// Returns: {"WWWWWWW", "WWWWWWB", "BBBBBBB" }
	Test("BBBBB WBWBW");	// Returns: {"BBBBB", "WWBWB" }
	Test("BBBB BBBB BBWB WWBB BWBB");	// Returns: { }
	Test("WWBBBBW BWBBWBB BWBBWBW BWWBWBB");	// Returns: {"WWBBBBW", "BBBBBWB", "BBBBBBB", "BBBWBBB" }

	return 0;
}
// END CUT HERE
