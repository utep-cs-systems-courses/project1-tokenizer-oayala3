#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list=NULL;
  return list;
}
void add_history(List *list, char *str)
{
  Item *node=(Item *)malloc(sizeof(Item));
  node-> str=str;
  node->next=NULL;
  int stop=0;
  if(list->root==NULL)
    {
      list->root=node;
    }
  else
    {
      Item *current=list->root;
      while(stop==0)
	{
	  current==current->next;
	  if(current==NULL)
	    {
	      stop=1;
	    }
	}
      current->next=node;
    }
}
char *get_history(List *list, int id)
{
  Item* current= list->root;
  int found=0;
  char *str;
  while(found==0 && current!=NULL)
    {
      if(current->id==id)
	{
	  found=1;
	}
      current=current->next;
    }
  
  if(found=1){
    str= current->str;
    
  }
  else
    {
      str=NULL;
    }
  
  return str;
}
void print_history(List *list)
{
  Item* current=list->root;
  while(current!=NULL)
    {
      printf("ID:%d String %s",current->id, &current->str);
      current=current->next;
    }
}
void free_history(List *list)
{
  Item* current= list->root;
  while(current->next!=NULL)
    {
      while(current->next!=NULL)
	{
	  current=current->next;
	}
      free(current);
      current=list->root;
    }
  free(list->root);
}
void main(){

}
