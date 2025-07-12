#include <stdio.h>

int main() {

  int number_list[] = {1,2,3,4,5,6,7,8,9};

  int target = 6;

  int count = sizeof(number_list)/sizeof(number_list[0]);

  int start_point = 0;
  int end_point = count -1;

  int median_pos = 0;
  /*
   if (number_list[median_pos] == target){
      printf("%d", median_pos);
      goto end;
      }*/

  int gap = end_point - start_point;

    if (gap % 2 == 0) {
      median_pos = gap/2;
      
    } else {

      median_pos = (gap + 1) / 2;
    }

    int first_median = median_pos;

for (int i = 0; i < count; i++){

    if (number_list[median_pos] == target){
      printf("%d", median_pos);
      goto end;
    }

    if ( number_list[median_pos] > target ) {
      end_point = median_pos;
      start_point = 0;

    } else {
      end_point = count -1 -median_pos;
      start_point = median_pos;
    }

    int gap = end_point - start_point;
    

    
    if (gap % 2 == 0) {
      median_pos = gap/2;
      
      //must add start point // maybe add current median to first median
      if (target < number_list[median_pos]) {
      median_pos+=start_point;
      }else {
	median_pos+=median_pos;
      }

      
    } else {

      median_pos = (gap + 1) / 2;
      // must add start point
      
      if (target < number_list[median_pos]) {
      median_pos+=start_point;
      }else {
	median_pos+=median_pos;
      }
      
    }

    
  }
    

 end:

}
