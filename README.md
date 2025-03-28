# Online Library System

## Overview
This repository contains the **Online Library System**, a comprehensive system for managing **users** and **books**. The system handles user-related functionalities such as user creation, searching, and display, using C++.

## Features
### **Users Module**
- **User Registration**: Users can create accounts with validated details (name, age, email, password).
- **User Search**: Allows searching for users by name or ID.
- **User Display**: Lists all registered users.
- **Interactive Menu**: Provides a user-friendly command-line interface.

## File Structure
```
├── main.cpp        # Main program file handling interactions
├── main.h          # Header file containing menu function declarations
├── User.cpp        # Implementation of the User class and related operations
├── User.h          # Header file defining the User class and function prototypes
└── README.md       # Documentation for the project
```

## Installation & Compilation
### **1. Clone the Repository**
```sh
git clone https://github.com/yourusername/online-library-system.git
cd online-library-system
```

### **2. Compile the Project**
Use `g++` to compile the source files:
```sh
g++ main.cpp User.cpp -o library_system
```

### **3. Run the Program**
```sh
./library_system
```

## Usage Guide
1. Launch the program.
2. Navigate to the **Main Menu**.
3. Choose an action:
   - **User Menu**:
     - Register a new user
     - Search for an existing user
     - List all users
   - **Exit the program**

## Code Explanation
### **User Module (`User.h` & `User.cpp`)**
- Defines user attributes: `name`, `age`, `id`, `email`, and `password`.
- Implements **constructor validation** to enforce correct input formats.
- Includes **setter and getter functions** for data integrity.
- Supports **operator overloading** for streamlined user comparison and input/output handling.

### **Main Program (`main.cpp`)**
- Provides a command-line interface for user interactions.
- Calls `Main_Menu()` to facilitate navigation between modules.

## Example Session
```
Select one of the following choices
1- Book Menu
2- User Menu
3- Exit
2

USERS MENU
1- Create a USER and add it to the list
2- Search for a user
3- Display all users
4- Back to the main
1

Enter your name : mohamed
Enter your age : 21
Enter your email : mohamed@gmail.com
Enter your password : mohamed

USERS MENU
1- Create a USER and add it to the list
2- Search for a user
3- Display all users
4- Back to the main
1

Enter your name : ahmed
Enter your age : 23
Enter your email : ahmed@gmail.com
Enter your password : ahmed

USERS MENU
1- Create a USER and add it to the list
2- Search for a user
3- Display all users
4- Back to the main
3

Name : mohamed  ||  Age : 21  ||  ID : 1  ||  Email : mohamed@gmail.com
Name : ahmed  ||  Age : 23  ||  ID : 2  ||  Email : ahmed@gmail.com

USERS MENU
1- Create a USER and add it to the list
2- Search for a user
3- Display all users
4- Back to the main
2

SEARCH FOR A USER
1- Search by name
2- Search by id
3- Return to users Menu
2

Enter ID : 2
Name : ahmed  ||  Age : 23  ||  ID : 2  ||  Email : ahmed@gmail.com

SEARCH FOR A USER
1- Search by name
2- Search by id
3- Return to users Menu
2

Enter ID : 1
Name : mohamed  ||  Age : 21  ||  ID : 1  ||  Email : mohamed@gmail.com

```
