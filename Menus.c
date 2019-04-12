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
data_item HashTable[LIMIT]; // The HashTable
image newImages[LIMIT]; // An Image Array To Hold The New Images
int currentIndex; // A holder for an image in the array to be processed
data_item_SC HashTableSC[LIMIT]; // Separate Chaining HashTable
clock_t start, end;
double linearProbing, separateChaining;


void MainMenu()
{
    int option;
    while (1)
    {
        printf("\n//---------MAIN MENU--------//\n");
        printf("1. Linear-Probing-Based HashTable\n");
        printf("2. Separate-Chaining-Based HashTable\n");
        printf("3. Exit\n");
        printf("Enter Your Option:\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                LinearProbingHashTable();
                break;
            case 2:
                SeparateChainingHashTable();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Input!\n");
                break;
        }
    }
}

void LinearProbingHashTable()
{
    int option;
    int index;
    int imageNumber;
    while(1)
    {
        printf("\n//-----Linear Probing Based HashTable----//\n");
        printf("1. Insert a Record\n");
        printf("2. Delete a Record\n");
        printf("3. Search a Record\n");
        printf("4. Back To Main Menu\n");
        printf("Enter Your Option:\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\nEnter The Image Number:\t");
                scanf("%d", &imageNumber);
                chooseImage(imageNumber-1);
                put(hashCode(newImages[currentIndex]), newImages[currentIndex]);
                break;
            case 2:
                printf("\nEnter The Image Number:\t");
                scanf("%d", &imageNumber);
                chooseImage(imageNumber-1);
                index = removeFromTable(newImages[currentIndex]);
                if(index == -1)
                {
                    printf("\nImage Not Found\n");
                }
                else
                {
                    printf("Image Deleted Successfully. ID is %d\n", index);
                }
                break;
            case 3:
                printf("\nEnter The Image Number:\t");
                scanf("%d", &imageNumber);
                chooseImage(imageNumber-1);
                index = get(newImages[currentIndex]);
                if(index == -1)
                {
                    printf("\nImage Not Found\n");
                }
                else
                {
                    printf("\nImage Found at Index Position:\t%d with ID: %d\n", index, HashTable[index].data.img_arr[sizeOfFlie - 1]);
                }
                break;
            case 4:
                MainMenu();
                break;
            default:
                printf("Invalid Input!\n");
        }
    }
}

void SeparateChainingHashTable()
{
    int option;
    int index;
    int imageNumber;
    Node *temp;
    while(1)
    {
        printf("\n//-----Separate Chaining Based HashTable----//\n");
        printf("1. Insert a Record\n");
        printf("2. Delete a Record\n");
        printf("3. Search a Record\n");
        printf("4. Back To Main Menu\n");
        printf("Enter Your Option:\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\nEnter The Image Number:\t");
                scanf("%d", &imageNumber);
                chooseImage(imageNumber-1);
                putSC(hashCode(newImages[currentIndex]), newImages[currentIndex]);
                break;
            case 2:
                printf("\nEnter The Image Number:\t");
                scanf("%d", &imageNumber);
                chooseImage(imageNumber-1);
                index = removeFromTableSC(newImages[currentIndex]);
                if(index == -1)
                {
                    printf("\nImage Not Found\n");
                }
                else
                {
                    printf("Image Deleted Successfully. ID is %d\n", index);
                }
                break;
            case 3:
                printf("\nEnter The Image Number:\t");
                scanf("%d", &imageNumber);
                chooseImage(imageNumber-1);
                temp = getSC(newImages[currentIndex]);
                if(temp == NULL)
                {
                    printf("\nImage Not Found\n");
                }
                else
                {
                    printf("\nImage Found at with ID: %d\n", temp->data.img_arr[sizeOfFlie - 1]);
                }
                break;
            case 4:
                MainMenu();
                break;
            default:
                printf("Invalid Input!\n");
        }
    }
}
