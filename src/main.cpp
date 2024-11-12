#include <iostream>
#include <string>
#include <vector>

#include "Library.h"
using namespace std;

int main() {
    Library library;
    int choice;
    string title;

    library.addBook("Human Acts", "Han Kang");
    library.addBook("Justice", "Michael J. Sandel");
    library.addBook("Chunhyangjeon");

    // library.borrowBook("Justice");  // 대출 기능 테스트

    while (true) {
        cout << "도서관리 시스템" << endl;
        cout << "1. 도서 대출" << endl;
        cout << "2. 도서 반납" << endl;
        cout << "3. 시스템 종료" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "대출할 도서 제목: ";
                cin >> title;
                library.borrowBook(title);
                break;
            case 2:
                cout << "반납할 도서 제목: ";
                cin >> title;
                library.returnBook(title);
                break;
            case 3:
                cout << "시스템을 종료합니다" << endl;
                return 0;
            default:
                return 0;
                break;
        }
    }

    return 0;
}