#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Library.h"
using namespace std;

void UserMenu(Library& library);
void AdminMenu(Library& library);

int main() {
    Library library;
    string title;

    library.AddBook("Literature", "book1", "author1");
    library.AddBook("Literature", "book2", "author2");
    library.AddBook("Literature", "book3");
    library.AddBook("Technology", "book4", "author4");

    UserMenu(library);

    return 0;
}

void UserMenu(Library& library) {
    int choice;
    string title, genre;

    while (true) {
        cout << "도서관리 시스템" << endl;
        cout << "0. 시스템 종료" << endl;
        cout << "1. 도서 대출" << endl;
        cout << "2. 도서 반납" << endl;
        cout << "3. 도서 목록" << endl;
        cout << "4. 장르별 도서 추천" << endl;
        cout << "5. 관리자 메뉴" << endl;
        cin >> choice;
        cout << endl;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            cout << "대출할 도서 제목: ";
            cin >> title;
            library.BorrowBook(title);
        } else if (choice == 2) {
            cout << "반납할 도서 제목: ";
            cin >> title;
            library.ReturnBook(title);
        } else if (choice == 3) {
            library.BookList();

        } else if (choice == 4) {
            genre = library.SelectGenre();
            library.RecommendBook(genre);

        } else if (choice == 5) {
            AdminMenu(library);
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
        }
    }
    return;
}

void AdminMenu(Library& library) {
    int choice, choice_genre;
    string title, author, genre;
    while (true) {
        cout << "관리자 메뉴" << endl;
        cout << "0. 시스템 종료" << endl;
        cout << "1. 도서 추가" << endl;
        cout << "2. 도서 삭제" << endl;
        cout << "3. 이전으로 돌아가기" << endl;

        cin >> choice;
        cout << endl;

        if (choice == 0) {
            exit(0);  // 프로그램의 즉시 종료
        } else if (choice == 1) {
            cout << "추가할 도서 제목: ";
            cin >> title;

            cout << "도서의 저자: ";
            cin >> author;

            genre = library.SelectGenre();

            library.AddBook(genre, title, author);

        } else if (choice == 2) {
            cout << "삭제할 도서 제목: ";
            cin >> title;
            library.RemoveBook(title);
        } else if (choice == 3) {
            return;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
        }
    }
}