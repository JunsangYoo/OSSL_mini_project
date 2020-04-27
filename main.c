#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

//function prototypes
void display_menu();
void input_handler(char[], Record[]);

//main function
int main()
{
  Record records[MAX_RECORDS] = {0};
  char user_input[64] = "";
  while(strcmp(user_input, "q") != 0)
  {
    display_menu();
    printf("\nSelect a menu> ");
    fgets(user_input, 64, stdin);
    user_input[strlen(user_input)-1] = '\0';
    input_handler(user_input, records);
  }
  return 0;
}


//Funcion : display_menu()
//Input : none
//Output : none
// - displays the menu for the user to see and decide what function to use
void display_menu(){
  printf("\n");
	printf("**********************************\n");
  printf("Basketball Team Management Program\n");
 	printf("**********************************\n");
	printf("1. Add new player\n");
	printf("2. List out players information\n");
	printf("3. Update player detail\n");
	printf("4. Delete player\n");
	printf("5. Search\n");
	printf("6. Load a new data file\n");
  printf("7. Add records from an outside data file\n");
	printf("8. Save to a data file\n");
  printf("9. Make a report file\n");
	printf("10. Optimize the records\n");
	printf("11. Sort\n");
  printf("q. quit\n");
}


//Function : input_handler()
//Input : user_input - array of characters; to figure out the menu
//        record - array of Records; this may contain empty elements in the middle
//Output : none
// - Handles the user input and invokes functions that correspnd to the user input
void input_handler(char input[], Record records[]){
  if(!strcmp(input, "1"))
    add_record(records);
  else if(!strcmp(input, "2"))
    list_record(records);
  else if(!strcmp(input, "3"))
    update_record(records);
  else if(!strcmp(input, "4"))
    delete_record(records);
  else if(!strcmp(input, "5"))
    search_record(records);
  else if(!strcmp(input, "6"))
    load_record(records);
  else if(!strcmp(input, "7"))
    add_from_file(records);
  else if(!strcmp(input, "8"))
    export_record(records);
  else if(!strcmp(input, "9"))
    report(records);
  else if(!strcmp(input, "10"))
    defragment(records);
  else if(!strcmp(input, "11"))
    sort_record(records);
  else if(!strcmp(input, "q") || !strcmp(input, "Q"))
    printf("Terminating... bye!\n");
  else
    printf("Unknown menu : %s  \n\n", input);
}

