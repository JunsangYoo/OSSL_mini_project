#ifndef _RECORD_H_
#define _RECORD_H_

// - Information of a player : empty(if empty state is 0, it has not been used, if 1, it is being used, if 2, it has been deleted and is empty), name, number(=back number or jersy number), pos(G for gaurd, F for forward, C for center), points, assists, games
typedef struct{
  int empty;
  char name[30];
  int number;
  char pos;
  int points;
  int assists;
  int games;
} Record;

#endif
