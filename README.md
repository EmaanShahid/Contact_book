# C++ Contact Book Project

## Introduction
The C++ Contact Book is a simple command-line application that allows users to manage their contacts. It provides functionalities to add, edit, delete, search, and display contacts. The program stores the contact details in a text file, enabling the user to access and manage the contacts even after closing the program.

## Features
- **Add Contact:** Users can add new contacts to the contact book. Each contact can have a name, phone number, and an optional label (e.g., Family, Friend, Emergency).
- **Edit Contact:** Users can edit the name and phone number of existing contacts in the contact book.
- **Delete Contact:** Users can delete specific contacts by name or phone number. They can also choose to delete all contacts at once.
- **Search Contacts:** Users can search for contacts either by name or phone number. The program displays the matching contacts' details if found.
- **Display Contacts:** Users can view all contacts in alphabetical order or filter and display contacts with a specific label (Family, Friend, Emergency).

## Class Structure

### `Node` Class
- This class represents a single node of the doubly linked list used to store contact information.
- Attributes:
  - `name`: Stores the name of the contact.
  - `phone_no`: Stores the phone number of the contact.
  - `group`: Stores the label or group of the contact (e.g., Family, Friend, Emergency).
  - `next`: Pointer to the next node in the linked list.
  - `prev`: Pointer to the previous node in the linked list.

### `Contact_BOOK` Class
- This class represents the Contact Book and handles all the operations related to the contact management.
- Attributes:
  - `head`: Pointer to the first node of the doubly linked list.
  - `FileName`: An instance of `fstream` used to read and write contact information from/to a text file.
  
- Member Functions:
  - **`menu()`**: Displays the main menu of the contact book and handles user inputs for various operations.
  - **`Editrecord()`**: Allows users to edit the contact details (name or phone number) of an existing contact.
  - **`search()`**: Enables users to search for contacts by name or phone number and displays the matching contacts' details.
  - **`option()`**: Helper function to prompt the user to choose a label (Family, Friend, Emergency) for a new contact.
  - **`del()`**: Helper function to delete a contact node from the linked list based on user input.
  - **`deletedata()`**: Reads the contact information from the text file and removes the corresponding contact from the linked list and file.
  - **`storedatafromLL()`**: Writes the contact information from the linked list to the text file.
  - **`storefiledata()`**: Reads the contact information from the text file and creates a doubly linked list of contacts.
  - **`create()`**: Allows users to add a new contact to the contact book and writes it to the text file.
  - **`DisplayAll()`**: Displays all contacts present in the contact book.
  - **`displayspecific(string n)`**: Displays contacts with a specific label (Family, Friend, Emergency).
  - **`display()`**: Displays the contacts in alphabetical order or contacts with a specific label based on user input.
  - **`BubbleSort()`**: Sorts the contacts in alphabetical order using the bubble sort algorithm.

## Usage
1. Run the program, and the main menu will be displayed.
2. Select the appropriate option from the menu to perform the desired operation:
   - `1`: Add a new contact.
   - `2`: Edit an existing contact.
   - `3`: Delete contacts (specific or all).
   - `4`: Search for contacts.
   - `5`: Display contacts (all or specific label).
   - `6`: Exit the program.

## Cool Features
1. Easy Contact Management: Users can easily add, edit, delete, search, and display their contacts through a simple command-line interface.
2. Labeling Contacts: Users can label their contacts as Family, Friend, or Emergency, making it convenient to filter and manage different types of contacts separately.
3. Sorting: The contacts are displayed in alphabetical order, making it easy to find a particular contact quickly.
4. Persistent Storage: The contacts are stored in a text file, ensuring that the user's data is saved even after closing the program, and it can be accessed in subsequent sessions.

## Future Enhancements
To enhance the project, additional features like data validation, data encryption, or a graphical user interface (GUI) can be implemented.

## 
