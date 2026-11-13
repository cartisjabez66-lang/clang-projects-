C Programming Projects
A collection of C language projects, algorithms, and data structures built to practice low-level programming, memory management, and system design.
📋 Table of Contents
About the Repository
Projects List
Prerequisites
Getting Started
Directory Structure
Contributing
License
📖 About the Repository
This repository serves as a portfolio and sandbox for various C programming exercises and applications. All projects are written following standard C practices (C99/C11) with a focus on clean code, efficiency, and proper memory handling (zero memory leaks).
🚀 Projects List
Project Name
Description
Key Concepts Used
Project 1 Name
Brief description of what this project does (e.g., A CLI-based Task Manager).
File I/O, Structs, Pointers
Project 2 Name
Brief description of what this project does (e.g., Custom Memory Allocator).
Dynamic Memory (malloc/free), Bitwise Ops
Project 3 Name
Brief description of what this project does (e.g., Simple HTTP Server).
Sockets, Multithreading, Networking

(Update the table above with your actual project folders and descriptions)
🛠️ Prerequisites
To compile and run these projects, you will need:
GCC (GNU Compiler Collection) or Clang
Make (optional, for projects with a Makefile)
Valgrind (optional, for checking memory leaks)
💻 Getting Started
1. Clone the repository
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name


2. Compile and Run a Project
Using GCC directly:
cd project-1
gcc -Wall -Wextra -Werror main.c -o app
./app


Using Make (if a Makefile is present):
cd project-1
make
./app


3. Memory Leak Check (Linux/macOS)
valgrind --leak-check=full ./app


📁 Directory Structure
.
├── project-1/
│   ├── src/
│   │   └── main.c
│   ├── include/
│   │   └── header.h
│   └── Makefile
├── project-2/
│   └── main.c
├── README.md
└── LICENSE


🤝 Contributing
Contributions, issues, and feature requests are welcome! Feel free to check the issues page if you want to contribute.
Fork the Project
Create your Feature Branch (git checkout -b feature/AmazingFeature)
Commit your Changes (git commit -m 'Add some AmazingFeature')
Push to the Branch (git push origin feature/AmazingFeature)
Open a Pull Request
📝 License
This project is licensed under the MIT License - see the LICENSE file for details.
