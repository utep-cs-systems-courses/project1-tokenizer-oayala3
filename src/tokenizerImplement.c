#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
int space_char(char c)
{
  int bool=0;
  if(c=='\t' || c==' ')  //if char c is a space turn boolean to true
    {
      bool=1;
    }
  return bool;
}

int non_space_char(char c)
{
  int bool=0;
  if(c!='\t' && c!=' ' && c!='\0')  // if char c is not a space or \0 turn boolean true
    {
      bool=1;
    }
  return bool;
}

char *word_start(char *str)
{
  int stop=0;
  for(int i=0; i<10 && stop==0 && str[0]!='\0';i++)
    {
	  stop=non_space_char(str[0]);
	  if(stop==0) //if you find the non_space then stop the loop.
	    {
	      str++;
	    }
    }
  
  if(stop==0) // if you didnt find a start then return null
    {
      str=NULL;
    }
  return str;
}

char *word_terminator(char *word)
{
  int stop=0;
  
  for(int i=0; i<100 && stop==0 && word[0]!='\0';i++)
    {
      stop=space_char(word[0]); //if you find a space stop the loop.
      if(stop==0)
	{
	  word++;
	}
    }
  
  if(stop==0)// if you dont find a space return null
    {
      word=NULL;
    }
  return word;
}
int count_words(char *str)
{
  int counter=0;
  while(str!=NULL && counter<12) // check that the str has something
    {
      str=word_start(str); //go to the start of the word
      if(str!=NULL)
	{
	  counter++;
	  str=word_terminator(str);//go to the end. 
	}
    }
  
   return counter;
}
  char *copy_str(char *inStr, short len)
  {
    char *newStrP=malloc(sizeof(char) * (len + 1));
    char *temp=newStrP;
    for(int i=0;i<len;i++)
      {
	*temp=*inStr;
	temp++;
	inStr++;
      }
   *temp='\0';
    return newStrP;
  }

 char **tokenize(char* str)
{
  int size=count_words(str);
  char **tokensPP=malloc(sizeof(char*) * (size + 1));
  char *pointerStart;
  int wordSize;
  for(int i=0;i<size; i++)
    {
      str=word_start(str);
      pointerStart=str;
      str=word_terminator(str);
      int stop=1;
      if(str==NULL)         // This is used to find the length of the last word
	{
	  str=pointerStart;
	  for(int j=0;j<10 && stop==1 && str[0]!='\0'; j++)
	    {
	      stop=non_space_char(str[0]);
	      str++;
	    }
	}
      wordSize=str-pointerStart;  // You can find he lenght of the word like this
      *tokensPP=copy_str(pointerStart,wordSize); //Assigning the string pointer to the array
      tokensPP++;
    }
  char *lst = malloc(sizeof(char)); //allocates mem and creates 0 token

  *lst = '\0';

  *tokensPP = lst;

  tokensPP  = tokensPP - size;

  return tokensPP;

}
void print_tokens(char **tokens)
{
  while(**tokens != '\0')
    {
      printf("%s\n",*tokens);
      tokens++;
    }
}
void free_tokens(char **tokens)
{
 char **temp = tokens;
  while(**temp != '\0') {
    free(*temp);
    temp++;
  }
  free(*temp);
  free(tokens);
}
