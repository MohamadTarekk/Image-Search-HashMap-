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


int hashCode(image img)
{
    int a[28];
    int key = 0;
    int i, j;
    for (i=0; i<28; i++)
    {
        a[i]=0;
        for (j=0; j<28; j++)
        {
            a[i] += img.img_arr[j];
        }
        a[i] *= (i+1);
        key += a[i];
    }
    return key;
}

void readImage(char fileName[500])
{
    FILE *f = fopen(fileName,"r");
    int i;
    for(i=0; i<sizeOfFlie; i++)
    {
        fscanf(f, "%d\t", &newImage.img_arr[i]);
    }
    fclose(f);
}
