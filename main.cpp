#include "main.h"


User_t *head = new User_t;

int main()
{
    int choice;
    bool Exit = false;
    while(!Exit){
        cout<<start_menu;
        if (!(cin >> choice) || choice <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }
        if(choice)
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
    freeHeap(head);
    return 0;
}



void Book_Menu(){
    cout<< "you are in book menu"<<endl;
}

void User_Menu(){
    int choiceUser ;
    bool ExitUser = false;
    while(!ExitUser){
        cout<<user_menu;
        if (!(cin >> choiceUser) || choiceUser <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }

        switch(choiceUser){
            case 1 :
                CreateNewUser(head);
                break;
            case 2 :
                SearchForUser(head);
                break;
            case 3 :
                DisplayAllUsers(head);
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

void freeHeap(User_t* head) {
    User_t* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp; // Use delete instead of free
    }
}

