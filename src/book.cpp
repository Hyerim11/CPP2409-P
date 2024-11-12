#include "book.h"

// 생성자
Book::Book(string title, string author) {
    this->title = title;
    this->author = author;
    isBorrowed = false;
}