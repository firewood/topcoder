/*

Google Code Jam 2011 Round 1A

Problem C. Pseudominion

Small input 15 points
Large input 35 points

You are playing a game with a fancy deck of cards. Each card has three
bonus numbers: a card bonus c, a score bonus s, and a turn bonus t.
Some of the cards start in your hand, while the rest are in a deck
on the table. You start with one turn.

On each turn, you can choose any card from your hand and play it.
If it has bonus numbers c, s, t, then the following happens:

The card is discarded from your hand, and it can never be used again.
You draw the first c cards from the deck into your hand. If the deck
has fewer than c cards in it, you draw all of them.
Your total score increases by s.
Your number of remaining turns increases by t.
If you do not have any cards in your hand at the start of a turn,
then nothing happens on that turn. Your goal is to get as high a score
as possible before running out of turns.
For example, suppose your hand and deck contain the following cards:

         +---+---+---+            +---+---+---+
   HAND: | c | s | t |      DECK: | c | s | t |
         +---+---+---+            +---+---+---+
Card #1: | 0 | 0 | 2 |   Card #4: | 1 | 1 | 0 |
Card #2: | 0 | 5 | 0 |   Card #5: | 0 | 1 | 1 |
Card #3: | 2 | 1 | 1 |   Card #6: | 2 | 2 | 0 |
         +---+---+---+            +---+---+---+
The following table shows how you can get a score of 8 from these cards.
The first three columns show your hand, the number of turns left, and
your score before playing each card, and the final column shows which
card to play.
+---------+------------+-------+------+
| Hand    | Turns left | Score | Play |
+---------+------------+-------+------+
| 1, 2, 3 |      1     |   0   |   1  |
| 2, 3    |      2     |   0   |   3  |
| 2, 4, 5 |      2     |   1   |   2  |
| 4, 5    |      1     |   6   |   5  |
| 4       |      1     |   7   |   4  |
| 6       |      0     |   8   |   -  |
+---------+------------+-------+------+
As you can see, the card bonuses and turn bonuses allow you to chain
together a long sequence of cards before you have to stop.


Input

The first line of the input gives the number of test cases, T.
T test cases follow.

Each test case begins with a single line containing N, the number of
cards in your hand. The next N lines each contain three integers, c, s, and t,
representing the bonus numbers for a single card in your hand.

This is followed by a single line containing M, the number of cards
in the deck. The next M lines each contain three integers, c, s, and t,
representing the bonus numbers for a single card in the deck. These cards
are listed in the same order in which you draw them.


Output

For each test case, output one line containing "Case #x: S", where S is the
largest score you can obtain before running out of turns.


Limits

1 <= T <= 100.
1 <= N.
0 <= M.
N + M <= 80.

Small dataset

0 <= c <= 1.
0 <= s <= 20.
0 <= t <= 20.

Large dataset

0 <= c <= 2.
0 <= s <= 50.
0 <= t <= 50.


Sample (Small dataset)

Input 

2
4
1 0 0
1 1 1
0 5 0
1 2 0
0
2
1 1 1
0 6 0
1
0 1 3

Output 

Case #1: 6
Case #2: 8


Sample (Large dataset)

Input 

1
3
0 0 2
0 5 0
2 1 1
3
1 1 0
0 1 1
2 2 0

Output 

Case #1: 8

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <list>

using namespace std;

struct Card {
	int c;
	int s;
	int t;
	bool operator <(const Card &c) const { return s < c.s; }
};
typedef list<Card> CardList;
typedef priority_queue<Card> CardQueue;

ostream &operator <<(ostream &s, const Card &c) {
	return s << c.c << "," << c.s << "," << c.t;
}

// pass by value
int sum_c0(CardQueue c0, int turns) {
	int score = 0;
	while (--turns >= 0 && !c0.empty()) {
		score += c0.top().s;
		c0.pop();
	}
	return score;
}

static void classify(const Card &c, CardList &deck, CardQueue &c0, CardQueue &c1, int &score, int &turns) {
	if (c.t > 0) {
		score += c.s;
		turns += (c.t - 1);
		int draws = c.c;
		while (draws-- > 0 && !deck.empty()) {
			Card d = deck.front();
			deck.pop_front();
			classify(d, deck, c0, c1, score, turns);
		}
	} else if (c.c > 0) {
		c1.push(c);
	} else {
		c0.push(c);
	}
}

static int solve(CardList hand, CardList deck) {
	int score = 0;
	int turns = 1;
	CardQueue c0, c1;

	while (!hand.empty()) {
		classify(hand.front(), deck, c0, c1, score, turns);
		hand.pop_front();
	}

	int Max = score + sum_c0(c0, turns);
	while (c1.size() > 0 && turns > 0) {
		Card c = c1.top();
		c1.pop();
		score += c.s;
		turns += (c.t - 1);
		if (!deck.empty() && turns > 0) {
			Card d = deck.front();
			deck.pop_front();
			classify(d, deck, c0, c1, score, turns);
		}
		Max = max(Max, score + sum_c0(c0, turns));
	}
	return Max;
}

int main()
{
	int i, T;
	cin >> T;
	for (i = 0; i < T; ++i) {
		int n;
		Card c;
		CardList hand, deck;
		cin >> n;
		while (--n >= 0) {
			cin >> c.c >> c.s >> c.t;
			hand.push_back(c);
		}
		cin >> n;
		while (--n >= 0) {
			cin >> c.c >> c.s >> c.t;
			deck.push_back(c);
		}
		int r = solve(hand, deck);
		cout << "Case #" << (i+1) << ": " << r << endl;
	}
	return 0;
}

