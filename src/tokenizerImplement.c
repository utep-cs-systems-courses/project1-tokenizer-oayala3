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
  if(c!='\t' && c!=' ')
    {
    bool=1;
    }
  return bool;
}

char *word_start(char *str)
{
  int stop=0;
  char check;
  for(int i=0; i<100 && stop==0;i++)
    {
      stop=non_space_char(str[0]);
      if(stop==0)
	{
	  str++;
	}
    }
  if(stop==0)
    {
      printf("not found\n");
      str=0;
    }
  return str;
}
char *word_terminator(char *word)
{
  int stop=0;
    for(int i=0; i<100 && stop==0;i++)
      {
	stop=space_char(word[0]);
	if(stop==0)
	  {
	    word++;
	  }
      }
    if(stop==0)
      {
	printf("not found\n");
	word=0;
      }
    return word;
}
int count_words(char *str)
{
  int counter=0;
   while(word_start(str)!=0 && counter<12) 
    {
      counter++;
     str=word_terminator(str);
    }
   printf("%d\n",counter);
   return counter;
}
  char *copy_str(char *inStr, short len)
  {
    
    char newStr [len];
    char *newStrP;
    newStrP=newStr;
    for(int i =0; i<len;i++)
      {
	newStr[i]=*inStr;
	inStr++;
      }
    return newStrP;
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
  char test[]="Oscar Ayala Cries\0";
  char *c=&test[0];
  char *d=&test[5];
  char *e=&test[6];
  int test1=0;
  char *test2;
  test1=space_char(x);
  printf("%d\n",test1);
  
  test1=non_space_char(x);
  printf("%d\n",test1);

  test1=space_char(y);
  printf("%d\n",test1);

  test1=non_space_char(y);
  printf("%d\n",test1);

  printf("end\n");

  printf("char O is in %p \n char space is in %p \n char A is in %p\n",c,d,e);

  test2=word_start(c);
  printf("%p\n",test2);
  test2=word_terminator(c);
  printf("%p\n",test2);

  printf("%d\n",count_words(c));
  // return 0;
}
