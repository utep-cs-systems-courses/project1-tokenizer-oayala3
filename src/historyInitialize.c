#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list=malloc(sizeof(List));
  list->root=malloc(sizeof(Item));// empty list and root
  return list;
}
void add_history(List *list, char *str)
{
  Item *current=list->root;
  if(list->root->str==NULL) //if there is no root make it root
    {
      current->id=0;
      current->str=str;
      list->root=current;
    }
  else //add it on the next free space
    {
      current=list->root;
      int iD=0;
      while(current->next !=NULL)
	{
	  iD++;
	  current=current->next;
	}
      current->id=iD;
      current->str=str;
    }
  current->next=malloc(sizeof(Item));
}
char *get_history(List *list, int id)
{
   Item* current= list->root;
  int found=0;
  char *str;
  while(found==0 && current!=NULL)// look at all ids until you find or there is no more
    {
       if(current->id==id)
	{
	  found=1;
	}
      else
	{
      current=current->next;
	}
    }
    if(found==1){
    str=current->str;
  }
    else //if not found then return null
    {
        str=NULL;
    }
    return str;
}
void print_history(List *list)
{
  int stop=0;
  Item *current=list->root;
  while(current->str!=NULL && stop==0 ) //print until you find the end o the list
   {
     printf("ID:%d String %s\n",current->id,current->str);
     if(current->next!=NULL)
       {
	 current=current->next;
       }
     else
       {
	 stop=1;
       }
   }
}
void free_history(List *list)
{
  int stop=0;
  Item* current= list->root;
  while(list->root!=NULL)
    {
      current=list->root;
      list->root=list->root->next;
      free(current);
    }
  printf("freed");
}
