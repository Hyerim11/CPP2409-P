#include "Library.h"

// 책을 추가하는 함수
void Library::addBook(string title, string author) {
    books.emplace_back(title, author);
    // push_back은 객체를 복사해서 벡터에 추가, 객체가 미리 있을 때 유용
    // emplace_back은 객체를 즉시 생성
    cout << title << " 이/가 도서관에 추가되었습니다." << endl;
}

// 책을 대출하는 함수
void Library::borrowBook(string title) {
    for (auto& book : books) {
        if (book.title == title) {
            // 책이 이미 대출되어있는 경우
            if (book.isBorrowed == true) {
                cout << title << " 은/는 이미 대출 중입니다." << endl;
            } else {
                book.isBorrowed = true;
                cout << title << " 이/가 대출되었습니다." << endl;
            }
            return;
        }
    }
    // 책이 존재하지 않는경우
    cout << title << " 을/를 대츨할 수 없습니다." << endl;
}

// 책을 반남하는함수
void Library::returnBook(string title) {
    for (auto& book : books) {
        if (book.title == title) {
            // 책이 대출되어있지 않는 경우
            if (book.isBorrowed == false) {
                cout << title << " 은/는 대출 되어있지 않습니다." << endl;
            } else {
                book.isBorrowed = false;
                cout << title << " 이/가 반납되었습니다." << endl;
            }
            return;
        }
    }
    // 책이 존재하지 않는 경우
    cout << title << " 을/를 반납할 수 없습니다." << endl;
}