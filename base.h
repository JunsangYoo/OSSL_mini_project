#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

//function protypes
void add_record(Record[]);
void list_record(Record[]);
void update_record(Record[]);
void delete_record(Record[]);
void search_record(Record[]);
void clear_record(Record* records);
void reset(char[], int*);
int stoi(char[], char[], int*);
void load_record(Record[]);
void add_from_file(Record[]);
void itos(char[], int);
void export_record(Record[]);
void report(Record[]);

#endif
