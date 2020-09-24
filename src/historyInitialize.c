#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list=malloc(sizeof(List));
  list->root=malloc(sizeof(Item));
  return list;
}
void add_history(List *list, char *str)
{
  Item *current=list->root;
  if(list->root->str==NULL)
    {
      current->id=0;
      current->str=str;
      list->root=current;
    }
  else
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
   while(found==0 && current!=NULL)
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
  else
    {
        str=NULL;
    }
    return str;
}
void print_history(List *list)
{
  int stop=0;
  Item *current=list->root;
 while(current->str!=NULL && stop==0 )
   {
     printf("ID:%d String %s\n",current->id,current->str);
     if(current->next!=NULL)
       {
	 printf("next not null\n");
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
/*
void main(){
  printf("start\n");
  List *list=init_history();
  printf("after list\n");
  char *testAdd1="Oscar";
  char *testAdd2="Ayala";
  char *testAdd3="cries";
  printf("before add\n");
  add_history(list,testAdd1);
  add_history(list,testAdd2);
  add_history(list,testAdd3);
  printf("after add\n");
  print_history(list);
  char *testGet=get_history(list,2);
  // char testGetStr=testGet->*str;
  printf("get");
  printf("%s\n",testGet);
  print_history(list);
 free_history(list);
    }
*/
