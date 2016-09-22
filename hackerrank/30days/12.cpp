#include <algorithm>

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        Student(string firstName, string lastName, int identification, vector<int> scores)
            : Person(firstName, lastName, identification), testScores(scores) { }

        char calculate() {
            int ave = accumulate(testScores.begin(), testScores.end(), 0) / testScores.size();
            if (ave < 40) {
                return 'T';
            }
            if (ave < 55) {
                return 'D';
            }
            if (ave < 70) {
                return 'P';
            }
            if (ave < 80) {
                return 'A';
            }
            if (ave < 90) {
                return 'E';
            }
            return 'O';
        }
};
