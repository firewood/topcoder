class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        age = initialAge;
        if (age < 0) {
            cout << "Age is not valid, setting age to 0." << endl;
            age = 0;
        }
    }

    void Person::amIOld(){
        if (age < 13) {
            cout << "You are young." << endl;
        } else if (age < 18) {
            cout << "You are a teenager." << endl;
        } else {
            cout << "You are old." << endl;
        }
    }

    void Person::yearPasses(){
        ++age;
    }
}
