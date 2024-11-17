#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
using namespace std;

class Library {
   public:
    vector<Book> books;

    // 책 추가, 저자가 없을경우 unknown
    void addBook(const string& title, const string& author = "unknown");

    // 책 대출
    void borrowBook(const string& title);

    // 책 반납
    void returnBook(const string& title);
};
