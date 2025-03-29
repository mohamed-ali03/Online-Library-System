#include "main.h"


User_t *headUser = new User_t;
Book_t *headBook = new Book_t;
Book_t *highestRate_ = new Book_t;
int main()
{
    int choice;
    bool Exit = false;
    while(!Exit){
        cout<<start_menu;
        if (!(cin >> choice) || choice <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }
        cout<<endl;
        switch(choice){
            case 1 :
                Book_Menu();
                break;
            case 2 :
                User_Menu();
                break;
            case 3 :
                Exit = true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
    }
    freeHeapUser(headUser);
    freeHeapBook(headBook);
    return 0;
}



void Book_Menu(){
    int choiceBook ;
    bool ExitBook = false;
    while(!ExitBook){
        cout<<book_menu;
        if (!(cin >> choiceBook) || choiceBook <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }
        cout<<endl;

        switch(choiceBook){
            case 1 :{
                User_t *Author = SearchForUser(headUser,search_menu_author);
                if(Author && !Author->user.getName().empty())
                    CreateBook(headBook,Author);
                else
                    cout<<"Author not Found"<<endl;
                break;
            }
            case 2 :
                SearchBook(headBook,search_menu_book);
                break;
            case 3 :
                DisplayBooks(headBook);
                break;
            case 4 :
                highestRate_ = GetHighestRate(headBook);
                break;
            case 5 :
                GetBooksOfUser(headBook,DefineUserNameOrId);
                break;
            case 6 :
                ExitBook = true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
    }
}

void User_Menu(){
    int choiceUser ;
    bool ExitUser = false;
    while(!ExitUser){
        cout<<user_menu;
        if (!(cin >> choiceUser) || choiceUser <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }
        cout<<endl;

        switch(choiceUser){
            case 1 :
                CreateNewUser(headUser);
                break;
            case 2 :
                SearchForUser(headUser,search_menu_user);
                break;
            case 3 :
                DisplayAllUsers(headUser);
                break;
            case 4 :
                ExitUser = true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
    }
}

void freeHeapUser(User_t* head) {
    User_t* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp; // Use delete instead of free
    }
}

void freeHeapBook(Book_t* head) {
    Book_t* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp; // Use delete instead of free
    }
}

