#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "history.h"
#include "tokenizer.h"
#define max_lim 100

int main()
{
  char str[max_lim]; /* string to tokenize */
  char *ans;

  List *list = init_history(); /*list to keep history */

  char num;
  char opt;

  printf("\nTOKENIZER\n");

  
  while(num != -1){

    printf("Select 1 to tokenize a new string\n");
    printf("Select 2 to view history\n");
    printf("Select 3 to retrieve a string from history\n");
    printf("Select 0 to quit the program\n");

    scanf("%d", &num);
    char hold; //in order to get new strings
    scanf("%c", &hold);


    if(num == 1){
      printf("$ ");
      fgets(str,max_lim,stdin);
      char **token = tokenize(str);
      print_tokens(token);
      

      printf("\n");
      char *first = word_start(str);

      /* getting the number of words*/
      int num_words = count_words(str);
      printf("The number of words in the string is: ");
      printf("%d\n", num_words);

      add_history(list, str); //adding the token into the history
     
      printf("\n");
    }
    if(num == 0){
      break;
    }

    if(num == 2){
      printf("Tokenized items\n");
      print_history(list);

    }
    
    if(num == 3){
        printf("\nInput the id of the string to be tokenized\n");
        scanf("%d", &opt);
        ans = get_history(list, opt);
        char **token = tokenize(ans);
        print_tokens(token);
        
   }
    
  }

  free_history(list);
  printf("Ending tokenizer\n");

  return 0;
}
