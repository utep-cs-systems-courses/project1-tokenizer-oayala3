
#include <stdio.h>
#include "tokenizer.h"
int space_char(char c)
{
  int bool=0;
  if(c=='\t' || c==' ')
    {
      bool=1;
    }
  return bool;
}

int non_space_char(char c)
{
  int bool=0;
  if(c!='\t' && c!=' ' && c!='\0')
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
	  if(stop==0)
	    {
	      str++;
	    }
    }
  
  if(stop==0)
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
      stop=space_char(word[0]);
      if(stop==0)
	{
	  word++;
	}
    }
  
  if(stop==0)
    {
      word=NULL;
    }
  return word;
}
int count_words(char *str)
{
  int counter=0;
   while(str!=NULL && counter<12) 
    {
      str=word_start(str);
      if(str!=NULL)
	{
	  counter++;
	  str=word_terminator(str);
    }
    }
   
   return counter;
}
  char *copy_str(char *inStr, short len)
  {
    char *use=&inStr[0];
    char newStr [len];
   
    for(int i =0; i<len;i++)
      {
	newStr[i]=use[i];
      }
    newStr[len]='\0';
    // printf("%s\n",newStr);
    char *newStrP=&newStr[0];
   return newStrP;
  }
char **tokenize(char* str)
{
  int size=count_words(str);
  char *tokens[size];
  char **tokenPP=tokens;
  char *pointerStart;
  long wordSize;
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
     tokens[i]=copy_str(pointerStart,wordSize); //Assigning the string pointer to the array
     printf("tokens %s and locaion %d\n",tokenPP[i],i);
    }
  return tokenPP;
}

void main()
{
  printf("start\n");
  char x ='o';
  char y =' ';
  char *a;
  a=&x;
  char *b;
  b=&y;
  char test[]="Oscar Ayala Cries alot";
  char *c=&test[0];
  char *d=&test[5];
  char *e=&test[6];
  int test1=0;
  char *test2;
  test1=space_char(x);
  //  printf("%d\n",test1);
  
  test1=non_space_char(x);
  // printf("%d\n",test1);

  test1=space_char(y);
  //  printf("%d\n",test1);

  test1=non_space_char(y);
  // printf("%d\n",test1);

  // printf("end\n");

  //  printf("char O is in %p \n char space is in %p \n char A is in %p\n",c,d,e);

  test2=word_start(c);
  // printf("%p\n",test2);
  test2=word_terminator(c);
  // printf("%p\n",test2);

  // printf("%d\n",count_words(c));
char *copytest=copy_str(c,5);
// printf("%s\n",&copytest[0]);

 char **tokenS=tokenize(c);
 char *tokenTest=tokenS[0];
 // char tokenA=tokenS[0];
 printf("token testing %s\n",&tokenTest[0]);
 printf("token1 %s\n",&tokenTest[1]);
 printf("token2 %s\n",&tokenTest[2]);
 printf("token3 %s\n",&tokenTest[3]);

 // printf("%s\n",tokenA);
  // return 0;
}
