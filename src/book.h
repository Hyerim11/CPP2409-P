#include <string>
using namespace std;

class Book {
   public:
    string title;
    string author;
    string genre;
    bool isBorrowed;  // 대출:true, 도서관에 있으면 false

    // 생성자, 저자가 없을경우 unknown
    Book(string genre, string title, string author = "unknown");
};

// General, Literature, Technology, Social Science, Science, Art, Language, History, Religion)
// 총류, 문학, 기술과학, 사화과학, 순수과학, 예술, 언어, 역사, 종교