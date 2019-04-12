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
extern data_item HashTable[LIMIT]; // The HashTable
extern image newImage; // An Image For Reading Every New Image
extern data_item_SC HashTableSC[LIMIT]; // Separate Chaining HashTable


int get(image img)
{
      int key, count, temp, position;
      key = hashCode(img);
      temp = key % LIMIT;
      position = temp;
      for(count = 1; count != LIMIT - 1; count++)
      {
            if(HashTable[position].key == -1)
            {
                  return -1;
            }
            if(HashTable[position].key == key)
            {
                  return position;
            }
            position = (temp + count) % LIMIT;
      }
      return -1;
}

void put (int key, image current_image)
{
      int count, position, temp;
      temp = key % LIMIT;
      position = temp;
      for(count = 1; count != LIMIT - 1; count++)
      {
            if(HashTable[position].key == -1)
            {
                  HashTable[position].data = current_image;
                  HashTable[position].key = key;
                  printf("\nImage Inserted into Hash Table\n");
                  return;
            }
            if(HashTable[position].key == key)
            {
                  printf("\nDuplicate image (an image with the same key already exists)\n");
                  return;
            }
            position = (temp + count) % LIMIT;
      }
      printf("\nHash Table Limit Exceeded\n");
}

int removeFromTable(image img)
{
      int position = get(img);
      if(position == -1)
      {
            return -1;
      }
      else
      {
            HashTable[position].key = -1;
            return HashTable[position].data.img_arr[sizeOfFlie - 1];
      }
}

void initializeTable()
{
    int i;
    for (i=0; i<LIMIT; i++)
    {
        HashTable[i].key = -1; // -1 indicates an empty position in the table
    }
}
