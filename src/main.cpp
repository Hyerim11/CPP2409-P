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

    library.AddBook("Human Acts", "Han Kang");
    library.AddBook("Justice", "Michael J. Sandel");
    library.AddBook("Chunhyangjeon");

    UserMenu(library);

    return 0;
}

void UserMenu(Library& library) {
    int choice;
    string title;

    while (true) {
        cout << "도서관리 시스템" << endl;
        cout << "0. 관리자 메뉴" << endl;
        cout << "1. 도서 대출" << endl;
        cout << "2. 도서 반납" << endl;
        cout << "3. 시스템 종료" << endl;

        cin >> choice;

        if (choice == 0) {
            AdminMenu(library);
        } else if (choice == 1) {
            cout << "대출할 도서 제목: ";
            cin >> title;
            library.BorrowBook(title);
        } else if (choice == 2) {
            cout << "반납할 도서 제목: ";
            cin >> title;
            library.ReturnBook(title);
        } else if (choice == 3) {
            break;
            ;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
        }
    }
    return;
}
void AdminMenu(Library& library) {
    int choice;
    string title, author;
    while (true) {
        cout << "관리자 메뉴" << endl;
        cout << "0. 이전으로 돌아가기" << endl;
        cout << "1. 도서 추가" << endl;
        cout << "2. 도서 삭제" << endl;
        cout << "3. 시스템 종료" << endl;

        cin >> choice;

        if (choice == 0) {
            return;
        } else if (choice == 1) {
            cout << "추가할 도서 제목: ";
            cin >> title;
            cout << "도서의 저자: ";
            cin >> author;
            library.AddBook(title, author);
        } else if (choice == 2) {
            cout << "삭제할 도서 제목: ";
            cin >> title;
            library.RemoveBook(title);
        } else if (choice == 3) {
            exit(0);  // 프로그램의 즉시 종료
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
        }
    }
}