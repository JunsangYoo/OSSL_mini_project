#include <stdio.h>
#include <string.h>
#include "extras.h"
#include "base.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - removes all the data with empty state of 2 and move every data after the data with empty state of 2 one space forward in array.
int defragment(Record records[]){ 
  char yesno;
  printf("Do you wish to proceed defragment? >");
  scanf("%c", &yesno);
  while (getchar() != '\n');      //clear input buffer
  if(yesno != 'y'){
    printf("Defragment failed\n");
    return 0;
  }
  for(int count = 0; records[count].empty != 0; count++){
    if(records[count].empty == 2){
      for(int i = count; records[i].empty != 0; i++){
        clear_record(&records[i]);
        strcat(records[i].name, records[i+1].name);
        records[i].pos = records[i+1].pos;
        records[i].number = records[i+1].number;
        records[i].points = records[i+1].points;
        records[i].assists = records[i+1].assists;
        records[i].games = records[i+1].games;
        records[i].empty = records[i+1].empty;
      }
    }
  }
  printf("Defragment complete\n");
  return 1;
}
// Function: copy_record()
// Input: record - r1, r2
// Output: none
// - copies r2 to r1
void copy_record(Record *r1, Record r2){ //add to extras.h
  for(int i = 0; i < 30; i++)
    r1->name[i] = 0;
  strcpy(r1->name, r2.name);
  r1->pos = r2.pos;
  r1->number = r2.number;
  r1->points = r2.points;
  r1->assists = r2.assists;
  r1->games = r2.games;
  r1->empty = r2.empty;
}
// Function: sort_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// sorts data by name, position, back number, points, assists, games.
void sort_record(Record records[]){
  printf("Select sort option : \n");
  printf("1. name\n");
  printf("2. position\n");
  printf("3. back number\n");
  printf("4. points\n");
  printf("5. assists\n");
  printf("6. games played\n");
  printf("q. quit sorting\n");
  printf(">");
  char option;
  scanf("%c", &option);
  while (getchar() != '\n');      //clear input buffer
  if(option == 'q'){
    printf("sorting canceled");
    return;
  }
  else if(option == '1'){
    Record temp;
    for(int j = 0; records[j].empty != 0; j++){
      for(int i = j; records[i].empty != 0; i++){
        if(strcmp(records[j].name, records[i].name) > 0){
          copy_record(&temp, records[i]);
          copy_record(&records[i], records[j]);
          copy_record(&records[j], temp);
        }
      }
    }
  }
  else if(option == '2'){
    Record temp;
    for(int j = 0; records[j].empty != 0; j++){
      for(int i = j; records[i].empty != 0; i++){
        if(records[j].pos > records[i].pos){
          copy_record(&temp, records[i]);
          copy_record(&records[i], records[j]);
          copy_record(&records[j], temp);
        }
      }
    }
  }
  else if(option == '3'){
    Record temp;
    for(int j = 0; records[j].empty != 0; j++){
      for(int i = j; records[i].empty != 0; i++){
        if(records[j].number > records[i].number){
          copy_record(&temp, records[i]);
          copy_record(&records[i], records[j]);
          copy_record(&records[j], temp);
        }
      }
    }
  }
  else if(option == '4'){
    Record temp;
    for(int j = 0; records[j].empty != 0; j++){
      for(int i = j; records[i].empty != 0; i++){
        if(records[j].points > records[i].points){
          copy_record(&temp, records[i]);
          copy_record(&records[i], records[j]);
          copy_record(&records[j], temp);
        }
      }
    }
  }
  else if(option == '5'){
    Record temp;
    for(int j = 0; records[j].empty != 0; j++){
      for(int i = j; records[i].empty != 0; i++){
        if(records[j].assists > records[i].assists){
          copy_record(&temp, records[i]);
          copy_record(&records[i], records[j]);
          copy_record(&records[j], temp);
        }
      }
    }
  }
  else if(option == '6'){
    Record temp;
    for(int j = 0; records[j].empty != 0; j++){
      for(int i = j; records[i].empty != 0; i++){
        if(records[j].games > records[i].games){
          copy_record(&temp, records[i]);
          copy_record(&records[i], records[j]);
          copy_record(&records[j], temp);
        }
      }
    }
  }
  printf("Sorting complete\n");
}

void advanced_search (Record records[]){
    
    char input_name[30] = "";
    char input_pos = 'F';
    int input_number = -1;

        
    printf("Enter the name of the player you wish to search : ");
    fgets(input_name, 30, stdin);
    input_name[strlen(input_name) - 1] = '\0';
    
    while(1){
    	printf("Enter the position of the player you wish to search ('F', 'G', 'C') : ");
        scanf("%c", &input_pos);
        while (getchar() != '\n');      //clear input buffer
        if(input_pos == 'F' || input_pos == 'G' || input_pos == 'C')
        	break;
        else
                printf("Invalid position.\n F : forward G : guard C : center\n");
    }
      
    printf("Enter back number of the player you wish to search : ");
    scanf("%d", &input_number);
    while (getchar() != '\n');  //clear input buffer
     
    
    for(int i = 0; records[i].empty != 0; i++){
      if(records[i].empty == 1){
          if( ( !strcmp(input_name,records[i].name) ) && ( input_pos == records[i].pos ) && (input_number == records[i].number) )
          {
              printf("The result |  The information of the player you want \n");
              printf("name : %s\n", records[i].name);
              printf("position : %c\n", records[i].pos);
              printf("back number : %d\n", records[i].number);
              printf("total points : %d\n", records[i].points);
              printf("total assists : %d\n", records[i].assists);
              printf("games played : %d\n", records[i].games);
              printf("\n");
            
          }
        
          
      }

   }  
}
