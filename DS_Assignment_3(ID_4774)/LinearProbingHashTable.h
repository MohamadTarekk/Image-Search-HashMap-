#ifndef LINEARPROBINGHASHTABLE_H_INCLUDED
#define LINEARPROBINGHASHTABLE_H_INCLUDED
#include "Structs.h"

int get(image img);
void put(int key, image current_image);
int removeFromTable(image img);
void initializeTable();

#endif // LINEARPROBINGHASHTABLE_H_INCLUDED
