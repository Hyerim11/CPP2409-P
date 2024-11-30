#include "Library.h"

// 책을 추가하는 함수
void Library::AddBook(const string& title, const string& author) {
    books.emplace_back(title, author);
    // push_back은 객체를 복사해서 벡터에 추가, 객체가 미리 있을 때 유용
    // emplace_back은 객체를 즉시 생성
    cout << title << " 이/가 도서관에 추가되었습니다." << endl;
}

// 책 삭제
void Library::RemoveBook(const string& title) {
    for (auto i = books.begin(); i != books.end(); ++i) {
        if (i->title == title) {
            books.erase(i);
            cout << title << " 이/가 삭제되었습니다." << endl;
            return;
        }
    }
    cout << title << " 은/는 도서관에 없습니다." << endl;
}

// 책을 대출하는 함수
void Library::BorrowBook(const string& title) {
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

// 책을 반납하는함수
void Library::ReturnBook(const string& title) {
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

// 도서관의 책 목록을 볼 수 있는 함수
void Library::BookList() {
    if (books.empty()) {
        cout << "도서관에 책이 없습니다. " << endl;
        return;
    }

    else {
        cout << "현재 도서 목록" << endl;
        for (const auto& book : books) {
            cout << "제목: " << book.title;
            cout << ", 저자: " << book.author;
            cout << ", 상태: ";
            if (book.isBorrowed == true) {
                cout << "대출 중" << endl;
            } else {
                cout << "대출 가능" << endl;
            }
        }
    }
    cout << endl;
}