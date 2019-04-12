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


Node* getSC(image img)
{
    int key, position;
    key = hashCode(img);
    position = key % LIMIT;
    data_item_SC theList = HashTableSC[position];
    Node *temp = theList.head;
	while (temp != NULL)
    {
		if (temp->key == key)
        {
			return temp;
		}
  		temp = temp->next;
	}
	return NULL;
}

void putSC(int key, image current_image)
{
    Node *item = (Node*) malloc(sizeof(Node));
    item->data = current_image;
    item->key = key;
    item->next = NULL;
    int position = key % LIMIT;
    if(HashTableSC[position].head == NULL)
    {
        HashTableSC[position].head = item;
        HashTableSC[position].tail = item;
        printf("\nImage Inserted into Hash Table\n");
        return;
    }
    else
    {
        Node *temp = HashTableSC[position].head;
        while(temp->next != NULL)
        {
            if(temp->key == key)
            {
                printf("\nDuplicate image (an image with the same key already exists)\n");
                return;
            }
            temp = temp->next;
        }
        if(temp->key == key)
        {
            printf("\nDuplicate image (an image with the same key already exists)\n");
            return;
        }
        temp->next = item;
        HashTableSC[position].tail = item;
        printf("\nImage Inserted into Hash Table\n");
    }
}

int removeFromTableSC(image img)
{
    int key = hashCode(img);
    int position = key % LIMIT;
    if(HashTableSC[position].head == NULL)
    {
        return -1;
    }
    else
    {
        int index = findNode(HashTableSC[position], key);
        if (index == -1)
        {
            return -1;
        }
        else
        {
            Node *item = getSC(img);
            Node *current = HashTableSC[position].head;
            int id = item->data.img_arr[sizeOfFlie - 1];
            if (index == 0)
            {
                HashTableSC[position].head = HashTableSC[position].head->next;
                free(current);
                return id;
            }
            while(current->next != item)
            {
                current = current->next;
            }
            current->next = item->next; // current->next = current->next->next (Jumping over the item to be deleted)
            free(item);
            return id;
        }
    }
}

int findNode(data_item_SC theList, int key)
{
	int count = 0;
	Node *temp = theList.head;
	while (temp != NULL)
    {
		if (temp->key == key)
        {
			return count;
		}
  		temp = temp->next;
		count++;
	}
	return -1;

}

void initializeTableSC()
{
    int i;
    for (i=0; i<LIMIT; i++)
    {
        HashTableSC[i].head = NULL;
        HashTableSC[i].tail = NULL;
    }
}
