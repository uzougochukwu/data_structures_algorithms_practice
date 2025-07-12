#include <stdio.h>

int main() {

  int number_list[] = {1,2,3,4,5,6,7,8,9};

  int target = 9;

  int count = sizeof(number_list)/sizeof(number_list[0]);

  int start_point = 0;
  int end_point = count -1;

  int median_pos = 0;

  int gap = end_point - start_point;

    if (gap % 2 == 0) {
      median_pos = gap/2;
      
    } else {

      median_pos = (gap + 1) / 2;
    }

    // printf("%d", median_pos);
for (int i = 0; i < count; i++){

    if (number_list[median_pos] == target){
      printf("%d", median_pos);
      goto end;
    }

    if ( number_list[median_pos] > target ) {
      end_point = median_pos;
      start_point = 0;

    } else {
      end_point = count -1;
      start_point = median_pos;
    }

    int gap = end_point - start_point;
    
    //printf("%d", start_point);
    
    if (gap % 2 == 0) {
      median_pos = gap/2;
      //must add start point
      median_pos+=start_point;

      // printf("%d", median_pos);
      
    } else {

      median_pos = (gap + 1) / 2;
      // must add start point
       median_pos+=start_point;
    }

    
  }
    

 end:

}
