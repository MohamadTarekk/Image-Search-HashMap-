#include <stdio.h>
#include <stdlib.h>
#include "AssistingFunctions.h"
#include "LinearProbingHashTable.h"
#include "Menus.h"
#include "SeparateChainingHashTable.h"
#include "Structs.h"

#define LIMIT 1000 // maximum size of the HashTable
#define sizeOfFlie 785 // an image with dimensions (28*28) + (1) position for the id

///Global Variables
data_item HashTable[LIMIT]; // The HashTable
image newImage; // An Image For Reading Every New Image
data_item_SC HashTableSC[LIMIT]; // Separate Chaining HashTable

int main()
{
    MainMenu();
    return 0;
}
