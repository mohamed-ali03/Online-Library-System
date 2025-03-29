
#include "User.h"
int User::count = 1 ;
string modifyUser_menu = "1- Delete user\n2- Return to users Menu\n> ";
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
    return this->id;
}

void User::Display(){
    cout<<"Name : "<<name;
    cout<<"  ||  Age : "<<age;
    cout<<"  ||  ID : "<<id;
    cout<<"  ||  Email : "<<email<<endl;
}

bool User::operator==(User& user){
    if(this->name != user.name || this->email != user.email || this->age != user.age || this->id != user.id)
        return false;
    return true;
}

ostream &operator<<(ostream &out, const User &user){
    out<<"Name : "<<user.name;
    out<<"  ||  Age : "<<user.age;
    out<<"  ||  ID : "<<user.id;
    out<<"  ||  Email : "<<user.email<<endl;
    return out ;
}

istream &operator>>( istream &in , User &user){
    cout<<"Enter name : ";
    in.ignore();
    getline(in,user.name);
    cout<<"Enter age : ";
    if (!(in >> user.age) || user.age <= 0) {
        throw invalid_argument("Invalid age! Age must be a positive number.");
    }
    cout<<"Enter email : ";
    in >> user.email;
    if (user.email.find('@') == string::npos) {  // Check if email contains '@'
        throw invalid_argument("Invalid email! Email must contain '@'.");
    }
    cout<<"Enter password : ";
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
        User_t *temp = new User_t;
        cin>>temp->user;
        temp->next = NULL;
        while(trav->next){
            trav = trav->next;
        }
        trav->next = temp;
    }
    cout<<endl;
}

User_t* SearchForUser(User_t *head,string msg){
    User_t* user = new User_t;
    int choiceSearch ;
    bool exitSearch = false;
    while(!exitSearch){
        cout<<msg;
        if (!(cin >> choiceSearch) || choiceSearch <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }
        cout<<endl;
        switch(choiceSearch){
            case 1 :{
                string name;
                cout<<"Enter Name : ";
                cin>>name;
                user = SearchName(name,head);
                break;
            }
            case 2 :{
                int id ;
                cout<<"Enter ID : ";
                if (!(cin >> id) || id <= 0) {
                    throw invalid_argument("Invalid id! id must be a positive number.");
                }
                user = SearchID(id,head);
                break;
            }
            case 3 :
                exitSearch = true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
        if(user)
            ModifyUserData(head,user);

        if(user == NULL){
            cout<<"User list is empty"<<endl;
            break;
        }
    }
    cout<<endl;
    return user;
}

User_t* SearchName(string name,User_t *head){
    User_t *trav = head;
    while(trav){
        if(trav->user.getName() == name){
            cout<<trav->user;
            return trav;
        }
        trav = trav->next;
    }
    cout<<"User not Exit,please try again\n"<<endl;
    return NULL;
}

User_t* SearchID(int id,User_t *head){
    User_t *trav = head;
    while(trav){
        if(trav->user.getId() == id){
            cout<<trav->user;
            return trav;
        }
        trav = trav->next;
    }
    cout<<"User not Exit,please try again\n"<<endl;
    return NULL;
}


void ModifyUserData(User_t*head,User_t*user){
    int choiceModify ;
    bool ExitModify= false;
    bool deleteflag = false;
    while(!ExitModify){
        cout<<modifyUser_menu;
        if (!(cin >> choiceModify) || choiceModify <= 0) {
            throw invalid_argument("Invalid Choice! Choice must be a positive number.");
        }
        cout<<endl;
        switch(choiceModify){
            case 1 :
                DeleteUser(head,user->user.getId());
                deleteflag = true;
                ExitModify =true;
                break;
            case 2 :
                ExitModify =true;
                break;
            default:
                cout<<"Invaild input ,Please try again"<<endl;
                break;
        }
        if(!deleteflag || !ExitModify)
            cout<<user->user<<endl;
    }
}

void DeleteUser(User_t *head, int id) {
    if (!head) {
        cout << "User list is empty!" << endl;
        return;
    }

    User_t *trav = head, *prev = nullptr;

    // If head itself is the book to delete
    if (head->user.getId() == id) {
        User_t *temp = head;
        head = head->next; // Update head
        delete temp;
        cout << "User " << id << " is deleted" << endl;
        return;
    }

    // Traverse the list
    while (trav && trav->user.getId() != id) {
        prev = trav;
        trav = trav->next;
    }

    if (!trav) {
        cout << "User not found!" << endl;
        return;
    }

    // Remove the node
    prev->next = trav->next;
    delete trav;
    cout << "User " << id << " is deleted\n" << endl;
}


void DisplayAllUsers(User_t *head){
    if (head == nullptr) {
        cout << "User list is empty" << endl;
        return;
    }

    User_t *trav = head;
    while (trav) {
        cout << trav->user;
        trav = trav->next;
    }
    cout<<endl;
}

