#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AssistingFunctions.h"
#include "LinearProbingHashTable.h"
#include "Menus.h"
#include "SeparateChainingHashTable.h"
#include "Structs.h"

#define LIMIT 1000 // maximum size of the HashTable
#define sizeOfFlie 785 // an image with dimensions (28*28) + (1) position for the id

///Global Variables
extern data_item HashTable[LIMIT]; // The HashTable
extern image newImages[LIMIT]; // An Image Array To Hold The New Images
extern int currentIndex; // A holder for an image in the array to be processed
extern data_item_SC HashTableSC[LIMIT]; // Separate Chaining HashTable
extern clock_t start, end;
extern double linearProbing, separateChaining;


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
            if(HashTable[position].key == -1 || HashTable[position].key == -2)
            {
                  HashTable[position].data = current_image;
                  HashTable[position].key = key;
                  printf("\nImage Inserted into Hash Table At Index %d with ID %d with key %d\n", position, current_image.img_arr[sizeOfFlie - 1], key);
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
            HashTable[position].key = -2;
            return HashTable[position].data.img_arr[sizeOfFlie - 1];
      }
}

void fillTable()
{
        /* Filling The Linear Probing HashTable*/
    int i;
    start = clock();
    for(i=0; i<LIMIT; i++)
    {
        put(hashCode(newImages[i]), newImages[i]);
    }
    end = clock();
    linearProbing = ((double) (end - start)) / CLOCKS_PER_SEC;
    /* End*/

}

void initializeTable()
{
    int i;
    for (i=0; i<LIMIT; i++)
    {
        HashTable[i].key = -1; // -1 indicates an empty position in the table
    }
}
