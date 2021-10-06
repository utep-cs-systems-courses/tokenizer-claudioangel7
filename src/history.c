#ifndef _HISTORY_
#define _HISTORY_
#include<stdio.h>
#include<stdlib.h>
#include "history.h"
#include "tokenizer.h"

typedef struct s_Item
{
  int id;
  char *str;
  struct s_Item *next;
}Item;

typedef struct s_List
{
  struct s_Item *root;
} List;

/* Initialize the linked list ot keep the history. */
List* init_history()
{
  List *head = (List*) malloc(sizeof(List)); /* getting space for list */

  head->root = NULL;

  return head;
}
 

/* Add a history item to the end of the list. 
   List* list - the linked list 
   int id - the id of the Item to find */
void add_history(List *list, char *str)
{
  char *helper = str;

  while(*helper != '\0'){
    helper++;
  }

  int len = helper-str-1;

  char *str_copy = copy_str(str,len);

  if(list->root == NULL){
    list->root = (Item*) malloc(sizeof(Item));
    list->root->str = str_copy;
    list->root->id = 1;
    list->root->next = NULL;
  }

  else{

    Item* temp;
    temp = list->root;

    while(temp->next != NULL){
      temp = temp->next;
    }

    temp->next = (Item*) malloc(sizeof(Item));
    temp->next->str = str_copy;
    temp->next->id = temp->id+1;
    temp->next->next = NULL;
    }
}

/* Retrive the string s
tored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *temp = list->root;

  while(temp != NULL){

    if(temp->id == id){ /* have reached desired id */
      return temp->str;
    }

    else if(temp->next == NULL){ /*if reached then id is larger than amount of tokens */
      return "OutOfBounds";
    }

    temp = temp->next;
  }
}

/* Print the entire contents of the list */
void print_history(List* list){
  Item* temp = list->root;
  
  while(temp!=NULL){
    printf("Item [%d]:  %s \n",temp->id,temp->str);
    temp=temp->next;

  }
}

/* Free the history list and the strings it references */
void free_history(List *list)
{
  Item *temp = list->root;

  while(temp != NULL){ /* when reached then it's end of list*/

    free(temp->str);
    // free(temp->id);
    free(temp);

    temp = temp->next; /*traversing the list */
  }
  
  free(list);
}


#endif
