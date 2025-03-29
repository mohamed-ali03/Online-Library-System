#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
//===============================Includies===========================
#include "Book.h"

//===============================Variable Declaration===========================
string start_menu = "Select one of the following choices\n1- Book Menu\n2- User Menu\n3- Exit\n> ";
string user_menu = "USERS MENU\n1- Create a USER and add it to the list\n2- Search for a user\n3- Display all users\n4- Back to the main\n> ";
string book_menu = "BOOKS MENU\n1- Create a book and add it to the list\n2- Search for a book\n3- Display all books (with book rating)\n4- Get the highest rating\n5- Get all books of a user\n6- Back to the main menu\n> ";
string search_menu_user = "SEARCH FOR A USER\n1- Search by name\n2- Search by id\n3- Return to users Menu\n> ";
string search_menu_author = "SEARCH FOR A Author\n1- Search by name\n2- Search by id\n3- Return to Book Menu\n> ";
string search_menu_book = "SEARCH FOR A Book\n1- Search by Title\n2- Search by id\n3- Return to Books Menu\n> ";
string DefineUserNameOrId = "Define User using\n1- Name\n2- ID\n3- Return to Book menu\n> ";
//===============================Function Declaration===========================
void Book_Menu();
void User_Menu();
void freeHeapUser(User_t *head);
void freeHeapBook(Book_t* head);
#endif // MAIN_H_INCLUDED
