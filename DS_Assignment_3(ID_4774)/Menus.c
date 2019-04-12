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


void MainMenu()
{
    initializeTable();
    initializeTableSC();
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
    char fileName[500];
    int index;
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
                printf("\nEnter The ImageFile Name:\t");
                scanf("%s", fileName);
                readImage(fileName);
                put(hashCode(newImage), newImage);
                break;
            case 2:
                printf("\nEnter The ImageFile Name:\t");
                scanf("%s", fileName);
                readImage(fileName);
                index = removeFromTable(newImage);
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
                printf("\nEnter The ImageFile Name:\t");
                scanf("%s", fileName);
                readImage(fileName);
                index = get(newImage);
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
    char fileName[500];
    int index;
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
                printf("\nEnter The ImageFile Name:\t");
                scanf("%s", fileName);
                readImage(fileName);
                putSC(hashCode(newImage), newImage);
                break;
            case 2:
                printf("\nEnter The ImageFile Name:\t");
                scanf("%s", fileName);
                readImage(fileName);
                index = removeFromTableSC(newImage);
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
                printf("\nEnter The ImageFile Name:\t");
                scanf("%s", fileName);
                readImage(fileName);
                temp = getSC(newImage);
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
