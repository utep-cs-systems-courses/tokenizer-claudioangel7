#include <stdio.h>     
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if(c =='\0'|| c == ' ' || c == '\t'){
      return 1;
    }
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
    if(c == ' ' || c == '\t' || c == '\n' ){
      return 0; 
    }
    return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  while(*str != '\0'){
    if(non_space_char(*str))  //return the pointer current position if character being pointed is letter.
      return str;    
    else              //Move pointer if character being pointed is space
      str++;
  }
  return NULL;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *str)
{

  int i = 0;
  
  while(str[i] != '\0'){

      if(non_space_char(str[i]) == 0){
        return &str[i];
      }

      if(space_char(str[i]) == 0){
        i++;
      }
    }
    return &str[i];
 
}
    
/* Counts the number of words in the string argument. */
int count_words(char *str)
{
   
    int count = 0;
    int pass = 0;

    while(*str){
	
        if (space_char(str[0]) == 1){ /*Excluding spaces, tabs or new lines */
            pass = 0;
        } else if (pass == 0){ /*Else if that founds a word hence increment the counter */
            pass = 1;
            count++;
        }
        str++;
    }
    
    return count;
}


/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)
{

  int token_size = len;
  char *token =(char*) malloc((token_size+1)*sizeof(char));   /*Allocate memory for the word*/
 

  
  /*Iterate letter by letter for allocating each letter in memory*/
  for(int i = 0; i < token_size; i++){    
    *token = *inStr;         
    token++;       /* moving pointer to keep allocating the letters */       
    inStr++;
  }
  
  *token = '\0'; /*assigning null to the last*/         
  return token -= token_size;

}


/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str)
{

  int numWords = count_words(str);
  char **tokens =(char**) malloc((numWords+1)*sizeof(char*));  //Allocate memory for number of words
  
  tokens[numWords] = NULL;       /*Assign a null character to the last space in memory*/
  
  char *startT = word_start(str);     
  
  for(int i = 0; i < numWords; i++){
    tokens[i] = copy_str(startT, (word_terminator(startT) - word_start(startT)));
    startT = word_terminator(startT);     
    startT = word_start(startT);    
  }
  
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i = 0;
  while(*tokens != NULL){
    printf("token at [%d]: %s\n",i, *tokens);  
    tokens++;
    i++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
  while(*tokens != NULL)
  {
    free(*tokens);
    tokens++;
  }
}
