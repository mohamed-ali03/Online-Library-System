#include "Book.h"

int Book::count = 1 ;
string modify_menu = "1- Update author\n2- Update Title\n3- Update Category\n4- Delete Book\n5- rate book\n6- Get back to books menu\n";
Book::Book(){
}
Book::Book(string title, string isbn, string category,User *user){
    if(title.empty())
        throw invalid_argument ("Invalid title! title cannot be empty.");
    this->title = title;
    if(isbn.empty())
        throw invalid_argument ("Invalid isbn! isbn cannot be empty.");
    this->isbn = isbn;
    if(category.empty())
        throw invalid_argument ("Invalid category! category cannot be empty.");
    this->category = category;
    this->id = count++;
    this->author = user;
}

Book::Book(const Book& book){
    this->title = book.title;
    this->isbn = book.isbn;
    this->category = book.category;
    this->id = count++;
    this->author = book.author;
}


void Book::setTitle(string title){
    if(title.empty())
        throw invalid_argument("Invalid title! title cannot be empty.");
    this->title = title;
}
string Book::getTitle() const {
    return this->title;
 }

void Book::setIsbn(string isbn){
    if(isbn.empty())
        throw  invalid_argument("Invalid isbn! isbn cannot be empty.");
    this->isbn = isbn;
}
string Book::getIsbn() const{
    return this->isbn;
}

void Book::setId(int id){
    if (id <= 0) {
        throw invalid_argument("Invalid id! id must be a positive number.");
    }
    this->id = id;
}
int Book::getId() const{
    return this->id;
}

void Book::setCategory(string category){
    if(category.empty())
        throw  invalid_argument("Invalid category! category cannot be empty.");
    this->category = category;
}
string Book::getCategory()const{
    return this->category;
}
void Book::setAuthor(User_t * author){
    this->author = &(author->user);
}
User* Book::getAuthor() const{
    return this->author;
}


void Book::rateBook(double rate) {
    if (rate <= 0) {
        throw invalid_argument("Invalid rate! Rate must be a positive number.");
    }

    // Update the average rating correctly
    this->totalRatings += 1;
    this->averageRating = ((this->averageRating * (this->totalRatings - 1)) + rate) / this->totalRatings;
}

double Book::getAverageRating () const{
    return this->averageRating;
}

bool Book::operator==(const Book &book){
    if(title != book.title || author != book.author || category != book.category)
        return false;
    return true;
}


ostream &operator<<(ostream &out, const Book &book){
    if(book.author){
        out << "Title : " << book.title;
        out << "  ||  Author Name : " << book.author->getName();
        out << "  ||  ID : " << book.id;
        out << "  ||  category : " << book.category;
        out << "  ||  Average Rate : " << book.averageRating << endl;
    }
    return out;
}
istream &operator>>( istream &in, Book &book){
    cout<<"Enter Book Title : ";
    in.ignore();
    getline(in,book.title);
    cout<<"Enter Book Category : ";
    in >> book.category;
    if (book.category.empty()) {
        throw invalid_argument("Invalid Category! Category must not be empty.");
    }
    if (book.author == nullptr) {
        book.author = new User;
    }
    book.id = Book::count;
    Book::count++;
    cout<<endl;
    return in;
}



void CreateBook(Book_t *head, User_t *author) {
    Book_t *newBook = new Book_t;
    cin >> newBook->book;
    newBook->book.setAuthor(author);
    newBook->next = NULL;

    if (Book::count == 1) {
        head = newBook;
    } else {
        Book_t *trav = head;
        while (trav->next) {
            trav = trav->next;
        }
        trav->next = newBook;
    }
}


void SearchBook(Book_t *head,string msg){
    int choiceSearch ;
    bool ExitSearch= false;
    Book_t *desiredBook = new Book_t;
    while(!ExitSearch){
        cout<<msg;
        if (!(cin >> choiceSearch) || choiceSearch <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }

        switch(choiceSearch){
            case 1 :{
                string title;
                cout<<"Enter title : ";
                cin>>title;
                desiredBook = SearchTitle(title,head);
                break;
            }
            case 2 :{
                int id ;
                cout<<"Enter ID : ";
                if (!(cin >> id) || id <= 0) {
                    throw invalid_argument("Invalid id! id must be a positive number.");
                }
                desiredBook = SearchID(id,head);
                break;
            }
            case 3 :
                ExitSearch = true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
        if(desiredBook && !ExitSearch)
            ModifyBookData(head,desiredBook);

        cout<<endl;
    }
}

Book_t* SearchTitle(string title,Book_t *head){
    Book_t *trav = head;
    while(trav){
        if(trav->book.getTitle() == title){
            cout<<trav->book;
            return trav;
        }
        trav = trav->next;
    }
    cout<<"Book not Exit"<<endl;
    return NULL;
}

Book_t* SearchID(int id,Book_t *head){
    Book_t *trav = head;
    while(trav){
        if(trav->book.getId() == id){
            cout<<trav->book;
            return trav;
        }
        trav = trav->next;
    }
    cout<<"Book not Exit"<<endl;
    return NULL;
}

void ModifyBookData(Book_t *head ,Book_t* book){
    int choiceModify ;
    bool ExitModify= false;
    bool deleteflag = false;
    while(!ExitModify){
        cout<<modify_menu;
        if (!(cin >> choiceModify) || choiceModify <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }
        cout<<endl;
        switch(choiceModify){
            case 1 :{

            }
            case 2 :{
                string title;
                cout<<"Enter the Modified Title : ";
                cin>>title;
                book->book.setTitle(title);
                break;
            }
            case 3 :{
                string Cat;
                cout<<"Enter the Modified Category : ";
                cin>>Cat;
                book->book.setCategory(Cat);
                break;
            }
            case 4 :
                DeleteBook(head,book->book.getId());
                deleteflag = true;
                ExitModify =true;
                break;
            case 5 :
                double rate;
                cout<<"Enter the Rate : ";
                cin>>rate;
                book->book.rateBook(rate);
                break;
            case 6 :
                ExitModify =true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
        if(!deleteflag || !ExitModify)
            cout<<book->book<<endl;
    }
}

void DeleteBook(Book_t *head, int id) {
    if (!head) {
        cout << "Book list is empty!" << endl;
        return;
    }

    Book_t *trav = head, *prev = nullptr;

    // If head itself is the book to delete
    if (head->book.getId() == id) {
        Book_t *temp = head;
        head = head->next; // Update head
        delete temp;
        cout << "Book " << id << " is deleted" << endl;
        return;
    }

    // Traverse the list
    while (trav && trav->book.getId() != id) {
        prev = trav;
        trav = trav->next;
    }

    if (!trav) {
        cout << "Book not found!" << endl;
        return;
    }

    // Remove the node
    prev->next = trav->next;
    delete trav;
    cout << "Book " << id << " is deleted\n" << endl;
}


void DisplayBooks(Book_t *head) {
    if (head == nullptr) {
        cout << "Book list is empty" << endl;
        return;
    }

    Book_t *trav = head;
    while (trav) {
        cout << trav->book;
        trav = trav->next;
    }
    cout<<endl;
}

Book_t* GetHighestRate(Book_t *head){
    Book_t *highestRate = new Book_t();
    Book_t *trav = head;
    highestRate->book.rateBook(0.0);
    while(trav){
        if(trav->book.getAverageRating() > highestRate->book.getAverageRating()){
            highestRate = trav;
        }
        trav = trav->next;
    }
    cout<<highestRate->book;
    return highestRate;
}


void GetBooksOfUser(Book_t *head,string msg){
    int choiceuserbook ;
    bool exituserbook = false;
    while(!exituserbook){
        cout<<msg;
        if(!(cin >> choiceuserbook) || choiceuserbook <0){
            throw invalid_argument ("Invaild Choice, Choice must be positive number\n");
        }


        switch(choiceuserbook){
            case 1 :{
                string name ;
                cout<<"Enter the Author Name : ";
                cin>>name;
                if(name.empty()){
                    throw invalid_argument("Invaild Name, Name must not be Empty");
                }
                GetBooksOfUserName(head,name);
                break;
            }
            case 2 :{
                int id;
                cout<<"Enter the Author Id : ";
                if (!(cin >> id) || id <= 0) {
                    throw invalid_argument("Invalid id! ID must be a positive number.");
                }
                GetBooksOfUserId(head,id);
                break;
            }
            case 3 :
                exituserbook = true;
                break;
            default:
                cout<<"Invaild input, Please try again"<<endl;
                break;
        }
        cout<<endl;
    }
}

void GetBooksOfUserName(Book_t *head ,string name){
    if (head == nullptr) {
        cout << "Book list is empty" << endl;
        return;
    }

    Book_t *trav = head;
    bool found = false;

    while (trav) {
        User* author = trav->book.getAuthor(); // Store result to avoid multiple calls

        if (author && author->getName() == name) {  // Check if author is not nullptr
            cout << trav->book;
            found = true;
        }

        trav = trav->next;
    }

    if (!found) {
        cout << "No books found for the given user ID." << endl;
    }
}
void GetBooksOfUserId(Book_t *head, int id) {
    if (head == nullptr) {
        cout << "Book list is empty" << endl;
        return;
    }

    Book_t *trav = head;
    bool found = false;

    while (trav) {
        User* author = trav->book.getAuthor(); // Store result to avoid multiple calls

        if (author && author->getId() == id) {  // Check if author is not nullptr
            cout << trav->book;
            found = true;
        }

        trav = trav->next;
    }

    if (!found) {
        cout << "No books found for the given user ID." << endl;
    }
}



