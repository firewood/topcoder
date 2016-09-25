//Write MyBook class
class MyBook : public Book {
        int _price;
    public:
        MyBook(string title, string author, int price)
            : Book(title, author), _price(price) { }
        void display() {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: " << _price << endl;
        }
};
