#include <stdio.h>
#include <string.h>


int main(){

  char text[] = "hello";

  int length = strlen(text);

  char reverseText[1][length] = {};

  int j = 0;

  for (int i = length -1; i >= 0; i--){
    reverseText[1][j] = text[i];
    j++;
  }

  printf("%s", reverseText[0]);
  
  return 0;


}
