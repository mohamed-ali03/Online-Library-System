
#include "User.h"
int User::count = 1 ;
string search_menu = "SEARCH FOR A USER\n1- Search by name\n2- Search by id\n3- Return to users Menu\n";
// Class functions Defintion
User::User(){
/*
    cout<<"Enter your name : ";
    getline(cin,name);
    cout<<"Enter your age : ";
    if (!(cin >> age) || age <= 0) {
        throw invalid_argument("Invalid age! Age must be a positive number.");
    }
    cout<<"Enter your email : ";
    cin >> email;
    if (email.find('@') == string::npos) {  // Check if email contains '@'
        throw invalid_argument("Invalid email! Email must contain '@'.");
    }
    cout<<"Enter your password : ";
    cin>>password;
    if (password.empty()) {  // Check if password is empty
        throw invalid_argument("Invalid password! Password cannot be empty.");
    }
    this->id = count;
    count++;
*/
}

User::User(string name , int  age, string  email, string password ){
    this->name = name ;
    if (age <= 0) {
        throw invalid_argument("Invalid age! Age must be a positive number.");
    }
    this->age = age;
    if (email.find('@') == string::npos) {  // Check if email contains '@'
        throw invalid_argument("Invalid email! Email must contain '@'.");
    }
    this->email = email;
    if (password.empty()) {  // Check if password is empty
        throw invalid_argument("Invalid password! Password cannot be empty.");
    }
    this->password = password;
    this->id = count;
    count++;
}

User::User(const User& user){
    this->name = user.name ;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;
    this->id = user.id;
}


void User::setUser(string name , int age , string email, string  password){
    this->name = name ;
    if (age <= 0) {
        throw invalid_argument("Invalid age! Age must be a positive number.");
    }
    this->age = age;
    if (email.find('@') == string::npos) {  // Check if email contains '@'
        throw invalid_argument("Invalid email! Email must contain '@'.");
    }
    this->email = email;
    if (password.empty()) {  // Check if password is empty
        throw invalid_argument("Invalid password! Password cannot be empty.");
    }
    this->password = password;
    this->id = count;
    count++;
}

bool User::operator==(const User& user){
    if (this->name != user.name || this->age != user.age || this->email != user.email
        || this->password != user.password || this->id != user.id)
        return false ;
    return true;
}


void User::setName(string name){
    if(name.empty()){
        throw invalid_argument("Invalid name! Name cannot be empty.");
    }
    this->name = name;
}
string User::getName() const{
    return this->name;
}

void User::setPassword(string password){
    if(password.empty()){
        throw invalid_argument("Invalid password! Password cannot be empty.");
    }
    this->password = password;
}
string User::getPassword()const{
    return this->password;
}

void User::setEmail(string email){
    if(email.find('a') == string::npos){
        throw invalid_argument("Invalid email! Email must contain '@'.");
    }
    this->email = email;
}
string User::getEmail()const {
    return this->email;
}

void User::setAge(int age){
    if (age <= 0) {
        throw invalid_argument("Invalid age! Age must be a positive number.");
    }
    this->age = age;
}
int User::getAge(){
    return this->age;
}

void User::setId(int id){
    if (id <= 0) {
        throw invalid_argument("Invalid id! id must be a positive number.");
    }
    this->id = id;
}
int User::getId(){
    return id;
}

void User::Display(){
    cout<<"Name : "<<name;
    cout<<"  ||  Age : "<<age;
    cout<<"  ||  ID : "<<id;
    cout<<"  ||  Email : "<<email<<endl;
}

ostream &operator<<(ostream &out, const User &user){
    out<<"Name : "<<user.name;
    out<<"  ||  Age : "<<user.age;
    out<<"  ||  ID : "<<user.id;
    out<<"  ||  Email : "<<user.email<<endl;
    return out ;
}

istream &operator>>( istream &in , User &user){
    cout<<"Enter your name : ";
    in.ignore();
    getline(in,user.name);
    cout<<"Enter your age : ";
    if (!(in >> user.age) || user.age <= 0) {
        throw invalid_argument("Invalid age! Age must be a positive number.");
    }
    cout<<"Enter your email : ";
    in >> user.email;
    if (user.email.find('@') == string::npos) {  // Check if email contains '@'
        throw invalid_argument("Invalid email! Email must contain '@'.");
    }
    cout<<"Enter your password : ";
    in>>user.password;
    if (user.password.empty()) {  // Check if password is empty
        throw invalid_argument("Invalid password! Password cannot be empty.");
    }
    user.id = User::count;
    User::count++;

    in.ignore();  // Clear input buffer
    return in;  // Allow chaining: cin >> user1 >> user2;
}



// User menu Function Defintions
void CreateNewUser(User_t *head){
    User_t *trav = head;
    if(User::count == 1)
    {
        cin>>head->user;
        head->next = NULL;
    }
    else{
        User_t temp;
        cin>>temp.user;
        temp.next = NULL;
        while(trav->next){
            trav = trav->next;
        }
        trav->next = &temp;
    }
}

void SearchForUser(User_t *head){
    int choiceSearch ;
    bool ExitSearch= false;
    while(!ExitSearch){
        cout<<search_menu;
        cin>>choiceSearch;

        switch(choiceSearch){
            case 1 :{
                string name;
                cout<<"Enter Name : ";
                cin>>name;
                SearchName(name,head);
                break;
            }
            case 2 :{
                int id ;
                cout<<"Enter ID : ";
                cin>>id;
                SearchID(id,head);
                break;
            }
            case 3 :
                ExitSearch = true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
    }
}

void SearchName(string name,User_t *head){
    User_t *trav = head;
    while(trav){
        if(trav->user.getName() == name){
            cout<<trav->user;
            return;
        }
        trav = trav->next;
    }
    cout<<"User not Exit"<<endl;
}

void SearchID(int id,User_t *head){
    User_t *trav = head;
    while(trav){
        if(trav->user.getId() == id){
            cout<<trav->user;
            return;
        }
        trav = trav->next;
    }
    cout<<"User not Exit"<<endl;
}

void DisplayAllUsers(User_t *head){
    User_t *trav = head;
    if(User::count == 1)
        cout<<"Users list is Empty"<<endl;
    else
        while(trav){
            cout<<trav->user;
            trav = trav->next;
        }
}

