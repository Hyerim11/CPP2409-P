#include <string>
using namespace std;

class Book {
   public:
    string title;
    string author;
    bool isBorrowed;  // 대출:true, 도서관에 있으면 false

    // 생성자, 저자가 없을경우 unknown
    Book(string title, string author = "unknown");
};
