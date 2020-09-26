#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizerImplement.c"
#include "historyInitialize.c"

void add_tokens(List *list,char **tokens)

{

  while(**tokens != '\0')

    {

      add_history(list,*tokens);

      tokens++;
 
    }
}
void search_tokens(List *list)
{
  int stop=0;
  int stop1=0;
  int id;
  char *yes="yes\0";
  char *no="no\0";
  char *choice;
  printf("You selected search. Please enter the ID. Rremeber the IDs start at 0");
  while(stop==0)
    {
      scanf("%d",&id);
      char *found=get_history(list,id);
      if(found=NULL)
	{
	  printf("We found this in the history: ID: %d, Token: %s",id, found);
	  stop=1;
	}
      else
	{
	  printf("That ID you input doesnt doesnt exist\n Do you want to try again?");
	  choice=getLine();
	  while(stop1==0)
	    if(strcasecmp(choice,yes)==10)
	      {
		stop=0;
		stop1=1;
		printf("enter a valid ID remeber they start at 0");
	      }
	    else if(strcasecmp(choice,no)==10)
	      {
		stop=1;
		stop1=1;
	      }
	    else
	      {
		printf("please say 'yes' or 'no'");
	      }
	}
    }
}

char *getLine() {
  
  char *line = malloc(100), * linep = line;
  size_t lenmax = 100, len = lenmax;

  int c;

  if(line == NULL)

    return NULL;
  for(;;) {
    c = fgetc(stdin);
    if(c == EOF)
      break;
    if(--len == 0) {
      len = lenmax;
      char * linen = realloc(linep, lenmax *= 2);
      if(linen == NULL) {
	free(linep);
	return NULL;
      }
      line = linen + (line - linep);
      linep = linen;
    }
    if((*line++ = c) == '\n')
      break;
  }
  *line = '\0';
  return linep;
}


void ui ()
{
  List *list=init_history();
  char *choice;
  char *userInput;
  char **tokens;
  int stop=0;
  int cont=0;
  
  char *exit="exit\0";
  char *print="print\0";
  char *continue1="continue\0";
  char *search="search\0";
  printf("Welcome to tokenizer\nYou should start by entering a Sentence\n");
  
  while(stop==0)
    {
      userInput=getLine();
      
      printf("after scan\n");
      if(strcasecmp(userInput,exit)!=10)
	{
	  cont=0;
	  printf("before tokens\n");
	  tokens=tokenize(userInput);
	  printf("sfter tokens\n");
	  add_tokens(list,tokens);
	  printf("Your string was tokenized and stored. You can input 'print' to see the results or 'continue' to add another sentence.You can say 'search' to search using ID. You also can say 'exit' to finish.\n ");
	  while(cont==0)
	    {
	      choice=getLine();
	      printf(choice);
	      printf("result compare = %d \n",strcasecmp(choice,print));
	      if(strcasecmp(choice,print)==10)
		{
		  print_history(list);
		  cont=1;
		  printf("printing\n");
		}
	      else if(strcasecmp(choice,exit)==10)
		{
		  stop=1;
		  cont=1;
		}
	      else if(strcasecmp(choice,continue1)==10)
		{
		  cont=1; 
		}
	      else if(strcasecmp(choice,search)==10)
		{
		  cont=1;
		  search_tokens(list);
		}
	      else
		{
		  printf("Please input one of the three choices [print] [continue] [exit]\n");
		  cont=0;
		}
	    }
	  if(stop==0){
	    printf("You can add a new Sentence or say 'exit'\n");
	  }
	}else
	{
	  stop=1;
	}
    }
  printf("You selected exit your list will be cleared. Thank You have a good day\n");
  free_history(list);
}
void main()
{
  ui();
}
