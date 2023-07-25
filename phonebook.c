#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH_NAME 25
#define MAX_LENGTH_ADDRESS 50
#define MAX_LENGTH_NUMBER 12
#define MAX_ENTRIES 30


struct PhonebookEntry
 {
   char name[MAX_LENGTH_NAME];
   char address[MAX_LENGTH_ADDRESS];
   char phoneNumber[MAX_LENGTH_NUMBER];
 };


 
	 void createEntry(struct PhonebookEntry *phonebook,int *numEntries)//to create new entries
	 {
	  //check if array is full
	    if(*numEntries >= MAX_ENTRIES)
	      {
	       printf("Phonebook is full,cannot add new entry\n");
	       return;
	       }
	     struct PhonebookEntry newEntry;
	     printf("\n\n\t\u2022Enter the phone number (Max Number %d:)",MAX_LENGTH_NUMBER-1);
	     fgets(newEntry.phoneNumber,sizeof(newEntry.phoneNumber),stdin);
	     newEntry.phoneNumber[strcspn(newEntry.phoneNumber,"\n")]='\0';
	     
	     
	     printf("\n\n\t\u2022Enter the name (Max Character %d:)",MAX_LENGTH_NAME-1);
	     fgets(newEntry.name,sizeof(newEntry.name),stdin);
	     newEntry.name[strcspn(newEntry.name,"\n")]='\0';
	     
	     
	     printf("\n\n\t\u2022Enter the Address (Max Address Character %d:)",MAX_LENGTH_ADDRESS-1);
	     fgets(newEntry.address,sizeof(newEntry.address),stdin);
	     newEntry.address[strcspn(newEntry.address,"\n")]='\0';
	     
	     
	     phonebook[*numEntries] = newEntry;
	     
	     (*numEntries)++;
	     printf("new entry added to phonebook");
	     
	 }   
    int display_menu()
     { 
     //Main MENU
     system("clear");
       printf("\n\n===============================================================================================PHONE BOOK==================================================================================================\n");
       
       printf("\n\t1.Create new entry\n");
       printf("\n\t2. View Entries\n");
       printf("\n\t3.Update Entry\n");
       printf("\n\t4. Delete Entry\n");
       printf("\n\t5.Exit\n\n");
       printf("================================================================================================================================================================================================\n");
       printf("\n\t\u2022Enter Your Choice: ");
       }
    
    int main()
    {
    
    struct PhonebookEntry phonebook[MAX_ENTRIES];
    int numEntries=0;
     char choice;
     //yet to write the linked list code :
     
     while(1){
     display_menu();
     scanf(" %c",&choice);
     getchar();
     switch(choice){
         case '1':
                   createEntry(phonebook,&numEntries);
                   printf("You Selected 'Create new entry'.\n");
                   break;
          case '2':
                   viewEntry(phonebook,&numEntries);
                   printf("You Selected 'View  Entries.\n");
                   break;
           case '3':
                   //call Update funtion
                   printf("You Selected 'Update Entry'.\n");
                   break;  
            case '4':
                   //call Delete funtion
                   printf("You Selected 'Delete Entry'.\n");
                   break;
             case '5':
                   
                   printf("Now exiting the phone book\n");
                   
                   break;
             default : printf("Invalid choice.Please try again.\n");
            }
           }
           return 0;
      }
