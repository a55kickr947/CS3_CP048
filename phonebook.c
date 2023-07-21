#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*  struct PhoneBookEntry{
   char name[25];
   char address[50];
   char phone_number[12];
   }
   
   strcut listnode{
    struct PhoneBookEntry data;
    struct listnode *next;
    }
    
    */
    
    void clear_screen(){
    //this is an ANSI escape sequence to clear the terminal
    printf("\033[2J\033[H");
    }
    
    
    int display_menu()
     { 
     //Main MENU
     clear_screen();
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
     char choice;
     //yet to write the linked list code :
     
     while(1){
     display_menu();
     scanf("%c",&choice);
     
     switch(choice){
         case '1':
                   //call create funtion
                   printf("You Selected 'Create new entry'.\n");
                   break;
          case '2':
                   //call view entry funtion
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
