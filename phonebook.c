#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_NAME 25
#define MAX_LENGTH_ADDRESS 50
#define MAX_LENGTH_NUMBER 12
#define MAX_ENTRIES 30

struct PhonebookEntry {
    char name[MAX_LENGTH_NAME];
    char address[MAX_LENGTH_ADDRESS];
    char phoneNumber[MAX_LENGTH_NUMBER];
};

// Function to save phonebook entries to a file
void savePhonebookToFile(struct PhonebookEntry *phonebook, int numEntries) {
    FILE *file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s,%s,%s\n", phonebook[i].name, phonebook[i].phoneNumber, phonebook[i].address);
    }

    fclose(file);
}

// Function to load phonebook entries from a file and display them on the terminal
void loadPhonebookFromFile(struct PhonebookEntry *phonebook, int *numEntries) {
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Phonebook file not found. Starting with an empty phonebook.\n");
        return;
    }

    *numEntries = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%[^\n]", phonebook[*numEntries].name, phonebook[*numEntries].phoneNumber, phonebook[*numEntries].address);
        (*numEntries)++;
    }

    fclose(file);

    if (*numEntries == 0) {
        printf("Phonebook is empty. No entries to display.\n");
        return;
    }

    printf("\n=========================================================================================================");
    printf("===================================================================================PHONEBOOK====================================================================================\n");
    printf("%-25s %-12s %-50s\n", "Name", "Phone Number", "Address");
    printf("======================================================================================================================================\n");

    for (int i = 0; i < *numEntries; i++) {
        printf("%-25s %-12s %-50s\n", phonebook[i].name, phonebook[i].phoneNumber, phonebook[i].address);
    }

    printf("======================================================================================================================================\n");
    printf("=====================================================================================\n");
}

// Function to create a new entry
void createEntry(struct PhonebookEntry *phonebook, int *numEntries) {
    if (*numEntries >= MAX_ENTRIES) {
        printf("Phonebook is full, cannot add a new entry.\n");
        return;
    }

    struct PhonebookEntry newEntry;
    printf("\n\n\t• Enter the phone number (Max Number %d): ", MAX_LENGTH_NUMBER - 1);
    fgets(newEntry.phoneNumber, sizeof(newEntry.phoneNumber), stdin);
    newEntry.phoneNumber[strcspn(newEntry.phoneNumber, "\n")] = '\0';

    printf("\n\n\t• Enter the name (Max Character %d): ", MAX_LENGTH_NAME - 1);
    fgets(newEntry.name, sizeof(newEntry.name), stdin);
    newEntry.name[strcspn(newEntry.name, "\n")] = '\0';

    printf("\n\n\t• Enter the Address (Max Address Character %d): ", MAX_LENGTH_ADDRESS - 1);
    fgets(newEntry.address, sizeof(newEntry.address), stdin);
    newEntry.address[strcspn(newEntry.address, "\n")] = '\0';

    phonebook[*numEntries] = newEntry;
    (*numEntries)++;
    printf("New entry added to the phonebook.\n");

    savePhonebookToFile(phonebook, *numEntries);
}

// Function to view phonebook entries
void viewEntry(struct PhonebookEntry *phonebook, int numEntries) {
    if (numEntries == 0) {
        printf("Phonebook is empty. No entries to display.\n");
        return;
    }

    printf("\n=========================================================================================================");
    printf("===================================================================================PHONEBOOK====================================================================================\n");
    printf("%-25s %-12s %-50s\n", "Name", "Phone Number", "Address");
    printf("======================================================================================================================================\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%-25s %-12s %-50s\n", phonebook[i].name, phonebook[i].phoneNumber, phonebook[i].address);
    }

    printf("======================================================================================================================================\n");
    printf("=====================================================================================\n");
}

// Function to delete a phonebook entry
void deleteEntry(struct PhonebookEntry *phonebook, int *numEntries) {
    if (*numEntries == 0) {
        printf("Phonebook is empty. No entries to delete.\n");
        return;
    }

    char deleteName[MAX_LENGTH_NAME];
    printf("\nEnter the name of the entry to delete: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            found = 1;
            // Shift entries to overwrite the deleted entry
            for (int j = i; j < *numEntries - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            (*numEntries)--;
            printf("Entry for '%s' deleted from the phonebook.\n", deleteName);
            break;
        }
    }

    if (!found) {
        printf("Entry for '%s' not found in the phonebook.\n", deleteName);
    }

    savePhonebookToFile(phonebook, *numEntries);
}

// Function to update a phonebook entry
void updateEntry(struct PhonebookEntry *phonebook, int numEntries) {
    if (numEntries == 0) {
        printf("Phonebook is empty. No entries to update.\n");
        return;
    }

    char updateName[MAX_LENGTH_NAME];
    printf("\nEnter the name of the entry to update: ");
    fgets(updateName, sizeof(updateName), stdin);
    updateName[strcspn(updateName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, updateName) == 0) {
            found = 1;

            printf("\nUpdating entry for '%s':\n", updateName);

            printf("Enter the phone number (Max Number %d): ", MAX_LENGTH_NUMBER - 1);
            fgets(phonebook[i].phoneNumber, sizeof(phonebook[i].phoneNumber), stdin);
            phonebook[i].phoneNumber[strcspn(phonebook[i].phoneNumber, "\n")] = '\0';

            printf("Enter the Address (Max Address Character %d): ", MAX_LENGTH_ADDRESS - 1);
            fgets(phonebook[i].address, sizeof(phonebook[i].address), stdin);
            phonebook[i].address[strcspn(phonebook[i].address, "\n")] = '\0';

            printf("Entry for '%s' updated in the phonebook.\n", updateName);
            break;
        }
    }

    if (!found) {
        printf("Entry for '%s' not found in the phonebook.\n", updateName);
    }

    savePhonebookToFile(phonebook, numEntries);
}

void display_menu() {
    system("clear");
    printf("\n\n===============================================================================================PHONE BOOK==================================================================================================\n");
    printf("\n\t1. Create new entry\n");
    printf("\n\t2. View Entries\n");
    printf("\n\t3. Update Entry\n");
    printf("\n\t4. Delete Entry\n");
    printf("\n\t5. Exit\n\n");
    printf("================================================================================================================================================================================================\n");
    printf("\n\t• Enter Your Choice: ");
}

int main() {
    struct PhonebookEntry phonebook[MAX_ENTRIES];
    int numEntries = 0;

    loadPhonebookFromFile(phonebook, &numEntries); // Load existing entries from the file

    char choice;
    while (1) {
        display_menu();
        scanf(" %c", &choice);
        getchar(); // Consume the newline character left in the input buffer

        switch (choice) {
            case '1':
                createEntry(phonebook, &numEntries);
                printf("You Selected 'Create new entry'.\n");
                break;
            case '2':
                viewEntry(phonebook, numEntries);
                printf("You Selected 'View Entries'.\n");
                break;
            case '3':
                updateEntry(phonebook, numEntries);
                printf("You Selected 'Update Entry'.\n");
                break;
            case '4':
                deleteEntry(phonebook, &numEntries);
                printf("You Selected 'Delete Entry'.\n");
                break;
            case '5':
                printf("Now exiting the phone book.\n");
                // Before exiting, save the phonebook entries to the file
                savePhonebookToFile(phonebook, numEntries);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }//
    }
}
