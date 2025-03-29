
#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

//======================================Includies=====================================
#include "StdLibrary.h"
//======================================Class Declaration =====================================
class User{
private:
           string name = "unknown";
           int age;
           int id;
           string password;
           string email;
public:
          static int count;
          User();
          User(string  , int  , string  , string  );
          User(const User& );
          void setUser(string  , int  , string  , string  );
          bool operator==(const User&  );
          void setName(string );
          string getName() const;
          void setPassword(string );
          string getPassword()const;
          void setEmail(string );
          string getEmail()const ;
          void setAge(int );
          int getAge();
          void setId(int );
          int getId();
          void Display ();
          bool operator==(User&);
          friend ostream &operator<<(ostream &, const User &);
          friend istream &operator>>( istream & , User &);
};

typedef struct user{
    User user;
    struct user *next;
}User_t;

void CreateNewUser(User_t *);
User_t* SearchForUser(User_t *,string);
    User_t* SearchName(string ,User_t *);
    User_t* SearchID(int ,User_t *);
void ModifyUserData(User_t*,User_t*);
void DeleteUser(User_t *, int );
void DisplayAllUsers(User_t *);



#endif // USER_H_INCLUDED


