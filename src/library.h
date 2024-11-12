#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
using namespace std;

class Library {
   public:
    vector<Book> books;

    // 책 추가, 저자가 없을경우 unknown
    void addBook(string title, string author = "unknown");

    // 책 대출
    void borrowBook(string title);
    
    // 책 반납
    void returnBook(string title);
};
