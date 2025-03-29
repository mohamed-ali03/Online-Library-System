# Online Library System

## Overview
This repository contains the **Online Library System**, a comprehensive system for managing **users** and **books**. The system handles user-related functionalities such as user creation, searching, and display, as well as book management operations like adding books, searching, and listing them. The system is implemented using **C++**.

## Features
### **Users Module**
- **User Registration**: Users can create accounts with validated details (name, age, email, password).
- **User Search**: Allows searching for users by name or ID.
- **User Display**: Lists all registered users.
- **Interactive Menu**: Provides a user-friendly command-line interface.

### **Books Module**
- **Book Addition**: Enables adding new books to the system.
- **Book Search**: Allows searching for books by title or ID.
- **Book Listing**: Displays all available books in the system.
- **Book Management**: Supports book borrowing and returning (if applicable in future updates).

## File Structure
```
├── main.cpp        # Main program file handling interactions
├── main.h          # Header file containing menu function declarations
├── User.cpp        # Implementation of the User class and related operations
├── User.h          # Header file defining the User class and function prototypes
├── Book.cpp        # Implementation of the Book class and related operations
├── Book.h          # Header file defining the Book class and function prototypes
└── README.md       # Documentation for the project
```

## Installation & Compilation
### **1. Clone the Repository**
```sh
git clone git@github.com:mohamed-ali03/Online-Library-System.git
cd online-library-system
```

### **2. Compile the Project**
Use `g++` to compile the source files:
```sh
g++ main.cpp User.cpp Book.cpp -o library_system
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
   - **Book Menu**:
     - Add a new book
     - Search for a book
     - List all books
   - **Exit the program**

## Code Explanation
### **User Module (`User.h` & `User.cpp`)**
- Defines user attributes: `name`, `age`, `id`, `email`, and `password`.
- Implements **constructor validation** to enforce correct input formats.
- Includes **setter and getter functions** for data integrity.
- Supports **operator overloading** for streamlined user comparison and input/output handling.

### **Book Module (`Book.h` & `Book.cpp`)**
- Defines book attributes: `title`, `author`, `id`, and `availability status`.
- Implements **functions for adding, searching, and listing books**.
- Supports **operator overloading** to streamline book-related operations.

### **Main Program (`main.cpp`)**
- Provides a command-line interface for user interactions.
- Calls `Main_Menu()` to facilitate navigation between modules.

## Example Session
```
Select one of the following choices:
1- User Menu
2- Book Menu
3- Exit

> 2
BOOKS MENU
1- Add a new book
2- Search for a book
3- List all books
4- Back to the main menu

> 1
Enter book title: The Great Gatsby
Enter author name: F. Scott Fitzgerald
Book added successfully!
```

## Future Enhancements
- Implement file storage for persistent data.
- Enhance search functionality with case-insensitive matching.
- Introduce authentication features for secure user access.
- Add a **book borrowing system** for tracking borrowed books.



