#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char address[100];
};

void addContactToFile(FILE *file, const struct Contact *contact) {
    fprintf(file, "%s,%s,%s\n", contact->name, contact->phone, contact->address);
}

void loadContactsFromFile(FILE *file, struct Contact phonebook[], int *numContacts) {
    struct Contact newContact;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", newContact.name, newContact.phone, newContact.address) != EOF) {
        phonebook[*numContacts] = newContact;
        (*numContacts)++;
    }
}

void saveContactsToFile(FILE *file, const struct Contact phonebook[], int numContacts) {
    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "%s,%s,%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].address);
    }
}

void displayContacts(struct Contact phonebook[], int numContacts) {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("Phonebook Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\nPhone: %s\nAddress: %s\n",
               phonebook[i].name, phonebook[i].phone, phonebook[i].address);
        printf("--------------------------------\n");
    }
}

int searchContactByPhone(struct Contact phonebook[], int numContacts, const char *phoneNumber) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].phone, phoneNumber) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s\nPhone: %s\nAddress: %s\n",
                   phonebook[i].name, phonebook[i].phone, phonebook[i].address);
            return i; // Return index of the found contact
        }
    }
    return -1; // Contact not found
}

void deleteContact(struct Contact phonebook[], int *numContacts, int index) {
    if (index >= 0 && index < *numContacts) {
        for (int i = index; i < (*numContacts) - 1; i++) {
            phonebook[i] = phonebook[i + 1];
        }
        (*numContacts)--;
        printf("Contact deleted.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void addContact(struct Contact phonebook[], int *numContacts) {
    if (*numContacts >= 100) {
        printf("Phonebook is full.\n");
        return;
    }

    struct Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter address: ");
    scanf(" %[^\n]", newContact.address);

    phonebook[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
}

int main() {
    FILE *phonebookFile = fopen("phonebook.txt", "a+"); // Open for appending and reading

    if (phonebookFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Contact phonebook[100];
    int numContacts = 0;
    int choice;

    loadContactsFromFile(phonebookFile, phonebook, &numContacts);

    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact by Phone\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phonebook, &numContacts);
                addContactToFile(phonebookFile, &phonebook[numContacts - 1]); // Add to file
                break;
            case 2:
                displayContacts(phonebook, numContacts);
                break;
            case 3:
                {
                    char searchPhone[15];
                    printf("Enter the phone number to search: ");
                    scanf("%s", searchPhone);
                    int index = searchContactByPhone(phonebook, numContacts, searchPhone);
                    if (index == -1) {
                        printf("Contact not found.\n");
                    }
                }
                break;
            case 4:
                {
                    int deleteIndex;
                    printf("Enter the index of the contact to delete: ");
                    scanf("%d", &deleteIndex);
                    deleteContact(phonebook, &numContacts, deleteIndex);
                    saveContactsToFile(phonebookFile, phonebook, numContacts); // Update file after deletion
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

    fclose(phonebookFile);

    return 0;
}
