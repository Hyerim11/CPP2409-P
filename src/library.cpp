#include "Library.h"

#include <iomanip>
#include <iostream>

// 책을 추가하는 함수
void Library::AddBook(const string& genre, const string& title, const string& author) {
    books.emplace_back(genre, title, author);
    // push_back은 객체를 복사해서 벡터에 추가, 객체가 미리 있을 때 유용
    // emplace_back은 객체를 즉시 생성
    cout << author << " 의 " << title << " 이/가 도서관에 추가되었습니다." << endl;
    cout << endl;
}

// 책 삭제
void Library::RemoveBook(const string& title) {
    for (auto i = books.begin(); i != books.end(); ++i) {
        if (i->title == title) {
            if (i->isBorrowed == true) {
                cout << title << "이/가 대출 중이라 삭제가 불가능합니다." << endl;
                cout << endl;
                return;
            }

            books.erase(i);
            cout << title << " 이/가 삭제되었습니다." << endl;
            cout << endl;
            return;
        }
    }
    cout << title << " 은/는 도서관에 없습니다." << endl;
    cout << endl;
}

// 책을 대출하는 함수
void Library::BorrowBook(const string& title) {
    for (auto& book : books) {
        if (book.title == title) {
            // 책이 이미 대출되어있는 경우
            if (book.isBorrowed == true) {
                cout << title << " 은/는 이미 대출 중입니다." << endl;
                cout << endl;
            } else {
                book.isBorrowed = true;
                cout << title << " 이/가 대출되었습니다." << endl;
                cout << endl;
            }
            return;
        }
    }
    // 책이 존재하지 않는경우
    cout << title << " 을/를 대츨할 수 없습니다." << endl;
    cout << endl;
}

// 책을 반납하는함수
void Library::ReturnBook(const string& title) {
    for (auto& book : books) {
        if (book.title == title) {
            // 책이 대출되어있지 않는 경우
            if (book.isBorrowed == false) {
                cout << title << " 은/는 대출 되어있지 않습니다." << endl;
                cout << endl;
            } else {
                book.isBorrowed = false;
                cout << title << " 이/가 반납되었습니다." << endl;
                cout << endl;
            }
            return;
        }
    }
    // 책이 존재하지 않는 경우
    cout << title << " 을/를 반납할 수 없습니다." << endl;
    cout << endl;
}

// 도서관의 책 목록을 볼 수 있는 함수
void Library::BookList() {
    if (books.empty()) {
        cout << "도서관에 책이 없습니다. " << endl;
        cout << endl;
        return;
    }

    cout << "- 현재 도서 목록 -" << endl;
    cout << left << setw(20) << "Genre" << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "Status" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (const auto& book : books) {
        cout << left << setw(20) << book.genre;
        cout << setw(20) << book.title;
        cout << setw(20) << book.author;
        cout << setw(10);
        if (book.isBorrowed == true) {
            cout << "대출 중" << endl;
        } else {
            cout << "대출 가능" << endl;
        }
    }

    cout << endl;
}

// 장르별로 책을 추천해줌
void Library::RecommendBook(const string& genre) {
    bool book_found = false;

    if (books.empty()) {
        cout << "도서관에 책이 없습니다. " << endl;
        cout << endl;
        return;
    }

    cout << "도서 목록: " << genre << endl;
    cout << left << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "Status" << endl;
    cout << "----------------------------------------------------" << endl;

    for (const auto& book : books) {
        if (book.genre == genre) {
            book_found = true;
            cout << left << setw(20) << book.title;
            cout << setw(20) << book.author;
            cout << setw(10);
            if (book.isBorrowed == true) {
                cout << "대출 중" << endl;
            } else {
                cout << "대출 가능" << endl;
            }
        }
    }

    if (book_found == false) {
        cout << genre << " 장르의 책이 도서관에 없습니다." << endl;
    }

    cout << endl;
}

// 장르 선택
string Library::SelectGenre() {
    int choice_genre;
    string genre;

    cout << "도서의 장르 목록" << endl;
    cout << "1. General(총류)" << endl;
    cout << "2. Literature(문학)" << endl;
    cout << "3. Technology(기술과학)" << endl;
    cout << "4. Social Science(사화과학)" << endl;
    cout << "5. Science(순수과학)" << endl;
    cout << "6. Art(예술)" << endl;
    cout << "7. Language(언어)" << endl;
    cout << "8. History(역사)" << endl;
    cout << "9. Religion(종교)" << endl;
    cout << "장르 번호: ";
    cin >> choice_genre;
    cout << endl;

    switch (choice_genre) {
        case 1:
            genre = "General";
            break;
        case 2:
            genre = "Literature";
            break;
        case 3:
            genre = "Technology";
            break;
        case 4:
            genre = "Social Science";
            break;
        case 5:
            genre = "Science";
            break;
        case 6:
            genre = "Art";
            break;
        case 7:
            genre = "Language";
            break;
        case 8:
            genre = "History";
            break;
        case 9:
            genre = "Religion";
            break;

        default:
            cout << "1에서 9 사이의 숫자를 선택해주세요." << endl;
            return SelectGenre();
    }

    return genre;
}