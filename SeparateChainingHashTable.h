#ifndef SEPARATECHAININGHASHTABLE_H_INCLUDED
#define SEPARATECHAININGHASHTABLE_H_INCLUDED
#include "Structs.h"

Node* getSC(image img);
void putSC(int key, image current_image);
int removeFromTableSC(image img);
int findNode(data_item_SC theList, int key);
void initializeTableSC();
void fillTableSC();

#endif // SEPARATECHAININGHASHTABLE_H_INCLUDED
