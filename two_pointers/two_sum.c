#include <stdio.h>

int doubleSum(int array[], int target, int count){
  int first = 0;
  int second = 0;

  int i = count - 1;

  while (i >= 0) {
    
    if (array[i] >= target){
      i--;
    }
    else{
      first = array[i];
    break;
    }

    
    
  }

 printf("The first number is %d\n", first);

 int gap = target - first;
 i = 0;

 while (i <= count) {

   if (array[i] != gap) {
     
     i++;
   } else {
     second = array[i];
     break;
   }

 }
 
 printf("The second number is %d", second);
  return 0;
}

int main(void) {

  int array[] = {1,2,3,4,5,6,7,8,9,10,11};

  int target = 5;

  int count = sizeof(array)/sizeof(array[0]);

  doubleSum(array, target, count);

  return 0;
}
