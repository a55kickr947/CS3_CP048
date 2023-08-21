**PHONEBOOK  MANAGEMENT SYSTEM**

Phonebook Management System in the C programming language is a software application that allows users to store, organize and manage large numbers of contact records efficiently. 
The system is designed to have functions such as adding, updating, viewing, listing and deleting contacts.

**Description:**

You can learn the fundamentals of functions, file handling, and data structure by working on the Phonebook Management System. 
This system will show you how to add, list, change or edit, search for, and remove data from/to a file. The functions that make up 
this project's menu include adding new records, listing them, editing and updating them, looking for saved contacts, and deleting phonebook entries.

**Table of Contents**

1.Features

2.Getting Started

3.Usage

4.File Format

5.Limitations

6.Contributing

**Features**

* Add new contacts with names, phone numbers, and addresses.
* Display the list of all contacts in the phonebook.
* Search for contacts using phone numbers.
* Delete contacts from the phonebook.
* Contacts are stored in a file for persistence.

**Getting Started**

To use the Phonebook Application, follow these steps:

1.Compile the source code:
  gcc phonebook.c -o phonebook
  
2.Run the compiled executable:
  ./phonebook
  
3.The program will present a menu with options for managing contacts.

**Usage**

**1.Add Contact:** Choose this option to add a new contact. Enter the contact's name, phone number, and address when prompted.

**2.Display Contacts:** View the list of all contacts in the phonebook. If the phonebook is empty, a message will be displayed.

**3.Search Contact by Phone:** Enter a phone number to search for a contact. If found, the contact's information will be displayed.

**4.Delete Contact:** Enter the index of the contact you want to delete. The contact will be removed from the phonebook.

**5.Exit:** Choose this option to exit the application.

**File Format**

Contacts are stored in a file named 'phonebook.txt'.
  Name,Phone,Address
  
Contacts are loaded from this file when the program starts and are saved back to the file after adding or deleting contacts.

**Limitations**

* The phonebook supports up to 100 contacts.
* Phone numbers are assumed to be unique.
* Error handling for file operations is minimal.

**Contributing**

Contributions to this project are welcome! If you find any issues or want to add enhancements, feel free to open an issue or submit a pull request.

