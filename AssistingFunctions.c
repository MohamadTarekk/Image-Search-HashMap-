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

int hashCode(image img)
{
    int i;
    int key = 0;
    int sum = 0;
    int row = 1;
    for(i=0; i<sizeOfFlie-1; i++)
    {
        sum += img.img_arr[i];
        if((i+1)%28==0)
        {
            key += row * sum;
            sum = 0;
            row++;
        }
    }
    return key;
}

void initializeImages()
{
    printf("//************Getting The Tables Ready************//");
    int i, j;

    /* Reading From The File*/
    FILE *f = fopen("TableFiller.txt","r");
    while(!feof(f))
    {
        for(j=0; j<LIMIT; j++)
        {
            //Scanning the image ARRAY
            for(i=0; i<sizeOfFlie-1; i++)
            {
                fscanf(f, "%d\t", &newImages[j].img_arr[i]);
            }
            //scanning the image ID
            fscanf(f, "%d\n", &newImages[j].img_arr[sizeOfFlie-1]);
        }
    }
    fclose(f);
    /* End Of Reading*/
    fillTable();
    fillTableSC();
    /* Printing total time of the 2 processes*/
    printf("\n//******Time Of Linear Probing*****//\n");
    printf("-----> %lf\n", linearProbing);
    printf("//****Time Of Separate Chaining****//\n");
    printf("-----> %lf\n", separateChaining);
    printf("\n//************Initialization Completed************//\n");
}

void readImages()
{
    char fileName[500];
    printf("\nEnter The ImageFile Name:\t");
    scanf("%s", fileName);
    FILE *f = fopen(fileName,"r");
    int i, j;
    for(j=0; j<5; j++)
    {
        for(i=0; i<sizeOfFlie-1; i++)
        {
            fscanf(f, "%d\t", &newImages[j].img_arr[i]);
        }
        newImages[j].img_arr[sizeOfFlie-1] = -8;
        fscanf(f, "\n");
    }
    fclose(f);
}

void chooseImage(int index)
{
    currentIndex = index;
}
