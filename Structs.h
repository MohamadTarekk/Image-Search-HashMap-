#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "Structs.h"
#define sizeOfFlie 785

typedef struct image
{

    int img_arr[sizeOfFlie];

}image;

typedef struct data_item
{

    image data;
    int key;

}data_item;

typedef struct Node
{

    image data;
    int key;
    struct Node *next;

}Node;

typedef struct data_item_SC
{

    Node *head;
    Node *tail;

}data_item_SC;

#endif // STRUCTS_H_INCLUDED
