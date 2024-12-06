#include "book.h"

// 생성자
Book::Book( string genre, string title, string author) {
    this->title = title;
    this->author = author;
    this->genre = genre;
    isBorrowed = false;
}