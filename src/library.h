#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
using namespace std;

class Library {
   public:
    vector<Book> books;

    // 책 추가, 저자가 없을경우 unknown
    void AddBook(const string& title, const string& author = "unknown");

    // 책 삭제
    void RemoveBook(const string& title);

    // 책 대출
    void BorrowBook(const string& title);

    // 책 반납
    void ReturnBook(const string& title);

    // 책 목록
    void BookList();
};
