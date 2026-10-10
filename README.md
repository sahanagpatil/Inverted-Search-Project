# 🔍 Inverted Search Engine in C
An Inverted Search Engine implemented in C using hash tables and linked lists to index words from multiple text files, enabling efficient word searching and database management

## 📌 Project Overview

The **Inverted Search Engine** is a C programming project that implements an inverted index to search for words across multiple text files efficiently.

An inverted index maps each unique word to the files in which it appears, along with its occurrence count. Instead of scanning every file for each search request, the application uses the created database to retrieve information about the searched word.

This project demonstrates the practical application of **C programming, data structures, pointers, file handling, dynamic memory allocation, and modular programming**.

## 🎯 Objectives

- Implement an inverted index for multiple text files.
- Create a database containing words and their associated file information.
- Search for words using the created database.
- Display, save, and update the database.
- Validate input files supplied through command-line arguments.
- Develop a modular C application using multiple source files.

## ✨ Features

- **File Validation:** Validates input files before processing.
- **Database Creation:** Builds an inverted index from multiple text files.
- **Word Searching:** Searches the database for a specified word.
- **Database Display:** Displays indexed words and associated file information.
- **Database Saving:** Saves the database to a file.
- **Database Updating:** Supports the update functionality implemented in the project.
- **Modular Design:** Separates operations into individual C source files.
- **Automated Compilation:** Uses a Makefile to compile and link the project.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Build Tool:** Makefile
- **Concepts:** Pointers, structures, functions, file handling, and command-line arguments
- **Data Structures:** Inverted index and the supporting structures implemented in the project

## 📂 Project Structure

```text
Inverted_Search/
│
├── main.c
├── validate.c
├── create_database.c
├── display_database.c
├── save_database.c
├── search_database.c
├── update_database.c
│
├── header.h
├── Makefile
├── save_database
│
├── file.txt
├── file2.txt
├── file3.txt
│
└── README.md
```

*Note: `header.h` is used here as the assumed header filename. Replace it with your exact header filename if it differs. The `save_database` entry is shown as you described it; it may be a saved database file or another project artifact.*

## 📄 File Descriptions

| File Name | Description |
|---|---|
| `main.c` | Contains the `main()` function and coordinates the application's operations, including processing command-line arguments. |
| `validate.c` | Validates the input filenames and checks whether files meet the application's requirements. |
| `create_database.c` | Reads words from the input text files and builds the inverted index with associated file information and occurrence counts. |
| `display_database.c` | Displays the contents of the created database. |
| `save_database.c` | Saves the database contents to a file. |
| `search_database.c` | Searches the database for a word and retrieves its associated information. |
| `update_database.c` | Implements the database update functionality supported by the application. |
| `header.h` | Contains shared structure definitions, macros, and function declarations, if included in your implementation. |
| `Makefile` | Automates compilation of source files and linking of object files to generate the executable. |
| `save_database` | A project file or database artifact; its exact purpose depends on how the application uses it. |
| `file.txt` | Sample input text file used to build the inverted index. |
| `file2.txt` | Additional sample input file for indexing and searching. |
| `file3.txt` | Another sample input file for testing database creation and word searching. |
| `README.md` | Documents the project, features, file structure, and execution instructions. |

## ⚙️ Compilation

### Prerequisites

Make sure GCC and Make are installed on your system. You can use Linux, Ubuntu, or WSL.

### Step 1: Open the project directory

Navigate to the directory containing your source files and Makefile.

```bash
cd path/to/Inverted_Search
```

### Step 2: Compile the project

Run:

```bash
make
```

Your Makefile compiles the C source files and links the object files. Based on your current build output, the executable is named `a.out`.

If compilation succeeds, you are ready to run the application.

## ▶️ How to Run the Application

### Step 1: Provide the input text files

Your project includes these sample input files:

- `file.txt`
- `file2.txt`
- `file3.txt`

### Step 2: Execute the program

Run the executable with the input filenames as command-line arguments:

```bash
./a.out file.txt file2.txt file3.txt
```

**Important:** Running `./a.out` without filenames displays `Error: Invalid Command lines` in your current implementation because the program expects input filenames.

### Step 3: Perform database operations

Follow the prompts or menu provided by the application to perform the supported operations, such as:

1. Create the database.
2. Display the database.
3. Search for a word.
4. Save the database.
5. Update the database.

The available options and their exact order depend on your implementation.

## 🔄 How the Project Works

1. **Input Processing:** The application receives text filenames through command-line arguments.
2. **File Validation:** The input files are checked before processing.
3. **Database Creation:** Words are extracted from the files and organized into an inverted index.
4. **Database Display:** The created index can be displayed for inspection.
5. **Word Searching:** A search query retrieves information about the requested word.
6. **Database Saving:** The database is stored in a file for future use.
7. **Database Updating:** The application performs the update operations supported by the implementation.

## 🔎 Example of an Inverted Index

Suppose your input files contain the following text.

**file.txt**
```text
apple mango apple
```

**file2.txt**
```text
mango banana apple
```

**file3.txt**
```text
banana orange mango
```

The inverted index conceptually stores each word along with the files where it occurs and the number of occurrences.

| Word | File Name | Occurrences |
|---|---|---:|
| apple | file.txt | 2 |
| apple | file2.txt | 1 |
| mango | file.txt | 1 |
| mango | file2.txt | 1 |
| mango | file3.txt | 1 |
| banana | file2.txt | 1 |
| banana | file3.txt | 1 |
| orange | file3.txt | 1 |

For example, searching for `mango` retrieves the files containing that word and the corresponding occurrence counts.

*This is an illustrative example; the output format may differ from your actual program.*

## 🧠 Concepts Demonstrated

- C programming and modular design
- Pointers and structures
- Data structure implementation
- File handling and command-line arguments
- Input validation and error handling
- Database creation and searching
- Dynamic memory management, where implemented
- Compilation and linking using Makefiles

## 🚀 Learning Outcomes

Through this project, I gained practical experience in:

- Applying data structures to a word-searching problem.
- Organizing words and their file references using an inverted index.
- Processing multiple text files in C.
- Developing a modular, multi-file C application.
- Understanding database creation, searching, and persistence.
- Automating compilation using a Makefile.
- Improving debugging and problem-solving skills.

## 🔮 Future Enhancements

- Improve searching performance for large text collections.
- Add more comprehensive input validation and error handling.
- Support case-insensitive searching.
- Handle punctuation and duplicate files consistently.
- Add automated test cases for all database operations.
- Improve saved database recovery and update handling.

## 👩‍💻 Author
Sahana Patil
B.E. Electrical & Electronics Engineering  
Embedded Systems Enthusiast
