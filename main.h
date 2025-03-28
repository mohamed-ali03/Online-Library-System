#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
//===============================Includies===========================
#include "User.h"

//===============================Variable Declaration===========================
string start_menu = "Select one of the following choices\n1- Book Menu\n2- User Menu\n3- Exit\n";
string user_menu = "USERS MENU\n1- Create a USER and add it to the list\n2- Search for a user\n3- Display all users\n4- Back to the main\n";

//===============================Function Declaration===========================
void Book_Menu();
void User_Menu();
void freeHeap(User_t *head);

#endif // MAIN_H_INCLUDED
