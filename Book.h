#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
//======================================Includies=====================================
#include "User.h"

//======================================Class Declaration =====================================
class Book
{
private:
 string title;
 string isbn;
 int id;
 string category;
 double averageRating;
 int totalRatings;
 User *author;
public:
static int count;
 Book();
 Book(string , string , string ,User *);
 Book(const Book& );
 void setTitle(string );
 string getTitle() const ;
 void setIsbn(string );
 string getIsbn() const;
 void setId(int);
 int getId() const;
 void setCategory(string );
 string getCategory()const;
 void setAuthor(User_t * );
 User* getAuthor() const;
 void rateBook(double );
 double getAverageRating () const;
 bool operator==(const Book&);
 friend ostream &operator<<(ostream &, const Book &);
 friend istream &operator>>( istream &, Book &);
};

typedef struct node{
    Book book;
    struct node *next;
}Book_t;

void CreateBook(Book_t *,User_t *);
void SearchBook(Book_t *,string);
    Book_t* SearchTitle(string ,Book_t *);
    Book_t* SearchID(int ,Book_t *);
void ModifyBookData(Book_t*,Book_t*);
void DeleteBook(Book_t * ,int );
void DisplayBooks(Book_t *);
Book_t* GetHighestRate(Book_t *);
void GetBooksOfUser(Book_t *,string);
    void GetBooksOfUserName(Book_t * ,string);
    void GetBooksOfUserId(Book_t * ,int);

#endif // BOOK_H_INCLUDED
