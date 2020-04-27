#include <stdio.h>
#include <string.h>
#include "base.h"

//Function : add_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
// - add a record or mulitple records @@@@@
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
void add_record(Record records[]){
  int count = 0;
  for(int i = 0; records[i].empty != 0; i++)
    count++;
  records[count].empty = 1;
  printf("Enter the player's name : ");
  fgets(records[count].name, 30, stdin);
  records[count].name[strlen(records[count].name) - 1] = '\0';
  while(1){
    printf("Enter the position : ");
    scanf("%c", &records[count].pos);
    while (getchar() != '\n');      //clear input buffer
    if(records[count].pos == 'F' || records[count].pos == 'G' || records[count].pos == 'C')
      break;
    else
      printf("Invalid position.\n F : forward G : guard C : center\n");
  }
  printf("Enter the back number of the player : ");
  scanf("%d", &records[count].number);
  printf("Enter total points : ");
  scanf("%d", &records[count].points);
  printf("Enter total assists : ");
  scanf("%d", &records[count].assists);
  printf("Enter the number of games played : ");
  scanf("%d", &records[count].games);
  printf("Player added\n");
  while (getchar() != '\n');      //clear input buffer
}

//Function : list_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
//list all the records
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
void list_record(Record records[]){
  printf("Do you wish to print all? y/n >");
  char yesno;
  scanf("%c", &yesno);
  while(getchar() != '\n');
  printf("\n");
  if(yesno == 'y'){
    for(int i = 0; records[i].empty != 0; i++){
      if(records[i].empty == 1){
        printf("name : %s\n", records[i].name);
        printf("position : %c\n", records[i].pos);
        printf("back number : %d\n", records[i].number);
        printf("total points : %d\n", records[i].points);
        printf("total assists : %d\n", records[i].assists);
        printf("games played : %d\n", records[i].games);
        printf("\n");
      }
    }
    printf("End of list\n");
  }
  else{
    printf("How many do you wish to print? >");
    int n;
    scanf("%d", &n);
    while(getchar() != '\n');
    for(int i = 0; i < n; i++){
      if(records[i].empty == 1){
        printf("name : %s\n", records[i].name);
        printf("position : %c\n", records[i].pos);
        printf("back number : %d\n", records[i].number);
        printf("total points : %d\n", records[i].points);
        printf("total assists : %d\n", records[i].assists);
        printf("games played : %d\n", records[i].games);
        printf("\n");
      }
    }
    printf("End of list\n");
  }
}

//Function : update_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
//finds the record by name and updates it
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
void update_record(Record records[]){
  printf("Select an option : \n");
  printf("1. single record\n");
  printf("2. add +1 games to all\n");
  printf("3. add +1 games to certain position\n");
  int option;
  scanf("%d", &option);
  while(getchar() != '\n');
  if(option == 1){
    char name_in[30] = "";
    printf("Enter the name of the player you wish to update : ");
    fgets(name_in, 30, stdin);
    name_in[strlen(name_in) - 1] = '\0';
    for(int i = 0; records[i].empty != 0; i++){
      if(strcmp(records[i].name, name_in) == 0){
        char yesno;
        printf("Change name? y / n >");
        scanf("%c", &yesno);
        while (getchar() != '\n');      //clear input buffer
        if(yesno == 'y'){
          printf("Enter name : ");
          fgets(records[i].name, 30, stdin);
          records[i].name[strlen(records[i].name) - 1] = '\0';
        }
        printf("Change position? y / n >");
        scanf("%c", &yesno);
        while (getchar() != '\n');      //clear input buffer
        if(yesno == 'y'){
          while(1){
            printf("Enter the position : ");
            scanf("%c", &records[i].pos);
            while (getchar() != '\n');      //clear input buffer
            if(records[i].pos == 'F' || records[i].pos == 'G' || records[i].pos == 'C')
              break;
            else
              printf("Invalid position.\n F : forward G : guard C : center\n");
          }
        }
        printf("Change back number? y / n >");
        scanf("%c", &yesno);
        while (getchar() != '\n');      //clear input buffer
        if(yesno == 'y'){
          printf("Enter number : ");
          scanf("%d", &records[i].number);
          while (getchar() != '\n');      //clear input buffer
        }
        printf("Change total points? y / n >");
        scanf("%c", &yesno);
        while (getchar() != '\n');      //clear input buffer
        if(yesno == 'y'){
          printf("Enter points : ");
          scanf("%d", &records[i].points);
          while (getchar() != '\n');      //clear input buffer
        }
        printf("Change total assists? y / n >");
        scanf("%c", &yesno);
        while (getchar() != '\n');      //clear input buffer
        if(yesno == 'y'){
          printf("Enter assists : ");
          scanf("%d", &records[i].assists);
          while (getchar() != '\n');      //clear input buffer
        }
        printf("Change games played? y / n >");
        scanf("%c", &yesno);
        while (getchar() != '\n');      //clear input buffer
        if(yesno == 'y'){
          printf("Enter games : ");
          scanf("%d", &records[i].games);
          while (getchar() != '\n');      //clear input buffer
        }
        printf("Player data updated\n");
        return;
      }
    }
  }
  else if(option == 2){
    printf("Do you wish to add +1 games to all players? y/n >\n");
    char yesno;
    scanf("%c", &yesno);
    while(getchar() != '\n');
    if(yesno != 'y'){
      printf("update cancelled\n");
      return;
    }
    for(int i = 0; records[i].empty != 0; i++)
      records[i].games++;
    printf("update complete : add +1 games to all players\n");
    return;
  }
  else if(option == 3){
    char position;
    while(1){
    printf("Enter the position : ");
    scanf("%c", &position);
    while (getchar() != '\n');      //clear input buffer
    if(position == 'F' || position == 'G' || position == 'C')
      break;
    else
      printf("Invalid position.\n F : forward G : guard C : center\n");
    }
    printf("Do you wish to add +1 games to all players with %c position? y/n >\n", position);
    char yesno;
    scanf("%c", &yesno);
    while(getchar() != '\n');
    if(yesno != 'y'){
      printf("update cancelled\n");
      return;
    }
    for(int i = 0; records[i].empty != 0; i++){
      if(records[i].pos == position)
        records[i].games++;
    }
    printf("update complete : add +1 games to all players with %c position", position);
    return;
  }
  printf("Cannot find player\n");
}

//Function : delete_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
//finds the record by name and deletes it. the members are set to "" or 0 and empty sate is set to 2
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
void delete_record(Record records[]){
  printf("Select an option\n");
  printf("1. delete a player\n");
  printf("2. delete all players\n");
  printf("3. delete all players with certain position\n");
  char option;
  scanf("%c", &option);
  while(getchar() != '\n');//clearing input buffer
  if(option == '1'){
    char name_in[30] = "";
    printf("Enter the name of the player you wish to delete : ");
    fgets(name_in, 30, stdin);
    name_in[strlen(name_in) - 1] = '\0';
    for(int i = 0; records[i].empty != 0; i++){
      if(strcmp(records[i].name, name_in) == 0){
        char yesno;
        printf("Do you wish to delete data of %s? y / n >", name_in);
        scanf("%c", &yesno);
        while (getchar() != '\n');      //clear input buffer
        if(yesno == 'y'){
          for(int j = 0; j < 30; j++)
            records[i].name[j] = 0;
          records[i].pos = 0;
          records[i].number = 0;
          records[i].points = 0;
          records[i].assists = 0;
          records[i].games = 0;
          records[i].empty = 2;
        }
        printf("Data of %s deleted\n", name_in);
        return;
      }
    }
    printf("Cannot find player\n");
  }
  else if(option == '2'){
    printf("Do you really wish to delete all the data? y/n >");
    char yesno;
    scanf("%c", &yesno);
    while(getchar() != '\n');
    if(yesno != 'y'){
      printf("delete cancelled\n");
      return;
    }
    for(int i = 0; records[i].empty != 0; i++){
      for(int j = 0; j < 30; j++)
            records[i].name[j] = 0;
          records[i].pos = 0;
          records[i].number = 0;
          records[i].points = 0;
          records[i].assists = 0;
          records[i].games = 0;
          records[i].empty = 0;
    }
    printf("All data deleted\n");
  }
  else if(option == '3'){
    char position;
    while(1){
    printf("Enter the position : ");
    scanf("%c", &position);
    while (getchar() != '\n');      //clear input buffer
    if(position == 'F' || position == 'G' || position == 'C')
      break;
    else
      printf("Invalid position.\n F : forward G : guard C : center\n");
    }
    printf("Do you wish to delete all players with %c position? y/n >\n", position);
    char yesno;
    scanf("%c", &yesno);
    while(getchar() != '\n');
    if(yesno != 'y'){
      printf("delete cancelled\n");
      return;
    }
    for(int i = 0; records[i].empty != 0; i++){
      if(records[i].pos == position){
        for(int j = 0; j < 30; j++)
          records[i].name[j] = 0;
        records[i].pos = 0;
        records[i].number = 0;
        records[i].points = 0;
        records[i].assists = 0;
        records[i].games = 0;
        records[i].empty = 2;
      }
    }
    printf("All players with %c position is deleted\n", position);
  }
  else
    printf("invalid option : %c\n", option);
}

//Function : search_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
//finds the record by name and shows the player's information
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
void search_record(Record records[]){
  char name_in[30] = "";
  printf("Enter the name of the player you wish to look at : ");
  fgets(name_in, 30, stdin);
  name_in[strlen(name_in) - 1] = '\0';
  for(int i = 0; records[i].empty != 0; i++){
    if(strcmp(records[i].name, name_in) == 0){
      printf("Name : %s\n", records[i].name);
      printf("position : %c\n", records[i].pos);
      printf("Back number : %d\n", records[i].number);
      printf("total points : %d\n", records[i].points);
      printf("total assists : %d\n", records[i].assists);
      printf("Games played : %d\n", records[i].games);
      return;
    }
  }
  printf("Cannot find player\n");
}

//Function : reset()
//Input : str_input - string for member input
//        loc_ptr - location in the add_element for input
//Output : none
// - sets *loc_ptr which will be star_loc to location after the semi-colon. and empties the str_input.
void reset(char str_input[], int* loc_ptr){
  *loc_ptr += strlen(str_input) + 1;    //+1 added to start after the semi-colon
  for(int i = 0; i < 30; i++)     //empty the str_input
    str_input[i] = '\0';
}

//Function : stoi()
//Input : add_element - the line of data user wishes to Input
//        str_input - string for member input
//        loc_ptr - location in the add_element for input
//Output : int type that has been converted from str_input
int stoi(char add_element[], char str_input[], int* loc_ptr){
  int int_input = 0;
  for(int i = *loc_ptr; add_element[i] != ';'; i++){
    str_input[i - *loc_ptr] = add_element[i];
  }
  for(int i = 0; i < strlen(str_input); i++){
    int_input *= 10;
    int_input += str_input[i] - '0';
  }
  return int_input;
}
//Function : clear_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
// - clear all the member of the record
void clear_record(Record* records){
  for(int i = 0; i < 30; i++)
    records->name[i] = '\0';
  records->pos = 0;
  records->number = 0;
  records->points = 0;
  records->assists = 0;
  records->games = 0;
  records->empty = 0;
}
//Function : load_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
// - load the record with an outside file ***this proccess will overwrite all the data saved in the memory right now***
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
/* - data.txt file should look like this : 
  Lebron James;10;23;5000;4500;320;
  Stephen Curry;5;30;3000;1500;150;
*/
// - the file to load should be named data.txt
void load_record(Record records[]){
  for(int i = 0; records[i].empty != 0;i++){
    clear_record(&records[i]);
  }
  int count = 0;         //which array number to save input
  char str_input[30] = "";     //used to change input types to match member's type
  int start_loc = 0;      //start location to continue on with the line's input
  FILE * readfile = fopen("load.txt", "r");
  if(readfile == NULL){
    printf("File open error\n");
    return;
  }
  printf("The data that has been saved in the program will be deleted.\nDo you wish to load from load.txt? y / n >");
  char yesno;
  scanf("%c", &yesno);
  while (getchar() != '\n');      //clear input buffer
  if(yesno == 'y');
  else{
    printf("Loading canceled\n");
    return;
  }
  char add_element[200];
  int element_count = 0;
  fgets(add_element, 50, readfile);
  for(int i = 0; add_element[i] != ':'; i++)
    start_loc++;
  start_loc += 2;
  element_count = stoi(add_element, str_input, &start_loc);
  reset(str_input, &start_loc);
  start_loc = 0;
  for(int j = 0; j < element_count; j++){
    fgets(add_element, 200, readfile);
    add_element[strlen(add_element) - 1] = '\0';
    records[count].empty = 1;
    for(int i = 0; add_element[i] != ';'; i++){     //name start
      str_input[i] = add_element[i];
    }
    strcpy(records[count].name, str_input);
    reset(str_input, &start_loc);   //reset variables, makes the start_loc one after the semi-colon 
    str_input[0] = add_element[start_loc];      //pos start. used str_input for constancy
    records[count].pos = str_input[0];
    reset(str_input, &start_loc);
    records[count].number = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    records[count].points = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    records[count].assists = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    records[count].games = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    printf("\n");
    count ++;
    start_loc = 0;
  }
  printf("Loading complete\n");
}

//Function : add_from_file()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
// - add data from an outside file
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
/* - data.txt file should look like this : 
  Lebron James;10;23;5000;4500;320;
  Stephen Curry;5;30;3000;1500;150;
*/
// - the file to add the data should be named add.txt
void add_from_file(Record records[]){
  int count = 0;         //which array number to save input
  char str_input[30] = "";     //used to change input types to match member's type
  int start_loc = 0;      //start location to continue on with the line's input
  for(int i = 0; records[i].empty != 0; i++)
    count++;
  FILE * readfile = fopen("add.txt", "r");
  if(readfile == NULL){
    printf("File open error\n");
    return;
  }
  printf("Do you wish to add from add.txt? y / n >");
  char yesno;
  scanf("%c", &yesno);
  while (getchar() != '\n');      //clear input buffer
  if(yesno == 'y');
  else{
    printf("Adding canceled\n");
    return;
  }
  char add_element[200];
  int element_count = 0;
  fgets(add_element, 50, readfile);
  for(int i = 0; add_element[i] != ':'; i++)
    start_loc++;
  start_loc += 2;
  element_count = stoi(add_element, str_input, &start_loc);
  reset(str_input, &start_loc);
  start_loc = 0;
  for(int j = 0; j < element_count; j++){
    fgets(add_element, 200, readfile);
    add_element[strlen(add_element) - 1] = '\0';
    records[count].empty = 1;
    for(int i = 0; add_element[i] != ';'; i++){     //name start
      str_input[i] = add_element[i];
    }
    strcpy(records[count].name, str_input);
    reset(str_input, &start_loc);   //reset variables
    str_input[0] = add_element[start_loc];      //pos start. used str_input for constancy
    records[count].pos = str_input[0];
    reset(str_input, &start_loc);
    records[count].number = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    records[count].points = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    records[count].assists = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    records[count].games = stoi(add_element, str_input, &start_loc);
    reset(str_input, &start_loc);
    printf("\n");
    count ++;
    start_loc = 0;
  }
  printf("Adding complete\n");
}
//Function : itos()
//input : str_num - int converted to string will be saved here.
//        num - integer that we want to convert to string
//output : none
// - clears str_num, converts num into string and save into str_num
void itos(char str_num[], int num){
  int digits = 0;
  int len_str_num = strlen(str_num);
  for(int i = 0; i < len_str_num; i++)   //clearing str_num
    str_num[i] = '\0';
  for(int i = num; i != 0; i /= 10)
    digits++;
  for(int i = 0; i < digits; i++){
    str_num[digits - 1 - i] = num % 10 + '0';
    num /= 10;
  }
}

//Function : export_record()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
// - export the data to outside file
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
/* - data.txt file should look like this : 
  Lebron James;10;23;5000;4500;320;
  Stephen Curry;5;30;3000;1500;150;
*/
void export_record(Record records[]){
  printf("Do you wish to export to export.txt? y / n >");
  char yesno;
  scanf("%c", &yesno);
  while (getchar() != '\n');      //clear input buffer
  if(yesno == 'y');
  else{
    printf("Export canceled\n");
    return;
  }
  
  int records_count = 0;    //how many records there are
  int digits = 0;
  char str_num[10] = "";
  FILE * writefile = fopen("export.txt", "w");
  for(int i = 0; records[i].empty != 0; i++){
    records_count ++;
  }
  fputs("number of files : ", writefile);
  itos(str_num, records_count);
  fputs(str_num, writefile);
  fputc(';',writefile);
  fputc('\n',writefile);
  for(int i = 0; i < records_count; i++){
    if(records[i].empty == 1){
      fputs(records[i].name, writefile);
      fputc(';', writefile);
      fputc(records[i].pos, writefile);
      fputc(';', writefile);
      itos(str_num, records[i].number);
      fputs(str_num, writefile);
      fputc(';', writefile);
      itos(str_num, records[i].points);
      fputs(str_num, writefile);
      fputc(';', writefile);
      itos(str_num, records[i].assists);
      fputs(str_num, writefile);
      fputc(';', writefile);
      itos(str_num, records[i].games);
      fputs(str_num, writefile);
      fputc(';', writefile);
      fputc('\n', writefile);
    }
  }
  if(fclose(writefile) == 0)
    printf("export complete\n");
  return;
}

//Function : report()
//Input : record - array of Records; this may contain empty element in the middle
//Output : none
// - make the data into report txt file which will be in same format as list_records() function's result
// - empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty)
void report(Record records[]){
  printf("Do you wish to make report file report.txt? y / n >");
  char yesno;
  scanf("%c", &yesno);
  while (getchar() != '\n');      //clear input buffer
  if(yesno == 'y');
  else{
    printf("report making canceled\n");
    return;
  }

  int records_count = 0;    //how many records there are
  int digits = 0;
  char str_num[10] = "";
  FILE * writefile = fopen("report.txt", "w");
  for(int i = 0; records[i].empty != 0; i++){
    records_count ++;
  }
  fputs("number of files : ", writefile);
  itos(str_num, records_count);
  fputs(str_num, writefile);
  fputc('\n',writefile);
  fputc('\n', writefile);
  for(int i = 0; i < records_count; i++){
    if(records[i].empty == 1){
      fputs("name : ", writefile);        //name
      fputs(records[i].name, writefile);
      fputc('\n', writefile);
      fputs("position : ", writefile);    //position
      fputc(records[i].pos, writefile);
      fputc('\n', writefile);
      fputs("back number : ", writefile);            //backnumber
      itos(str_num, records[i].number);
      fputs(str_num, writefile);
      fputc('\n', writefile);
      fputs("total points : ", writefile);           //points
      itos(str_num, records[i].points);
      fputs(str_num, writefile);
      fputc('\n', writefile);
      fputs("total assists : ", writefile);          //assists
      itos(str_num, records[i].assists);
      fputs(str_num, writefile);
      fputc('\n', writefile);
      fputs("games played : ", writefile);           //games played
      itos(str_num, records[i].games);
      fputs(str_num, writefile);
      fputc('\n', writefile);
      fputc('\n', writefile);
    }
  }
  if(fclose(writefile) == 0)
    printf("report complete\n");
}
