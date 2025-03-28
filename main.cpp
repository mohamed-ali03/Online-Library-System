#include "main.h"

int choice;
bool Exit = false;
User_t head ;

int main()
{
    while(!Exit){
        cout<<start_menu;
        cin>>choice;
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
        cin>>choiceUser;

        switch(choiceUser){
            case 1 :
                CreateNewUser(&head);
                break;
            case 2 :
                SearchForUser(&head);
                break;
            case 3 :
                DisplayAllUsers(&head);
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



