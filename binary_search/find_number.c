#include <stdio.h>

int main() {

  int number_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

  int target = 12;

  int count = sizeof(number_list)/sizeof(number_list[0]);

  int start_point = 0;
  int end_point = count -1;

  int median_pos = 0;

  int limit = count*count;

  int gap = end_point - start_point;

    if (gap % 2 == 0) {
      median_pos = gap/2;
      
    } else {

      median_pos = (gap + 1) / 2;
    }
      

    int med_change = 0;

    for (int i = 0; i < 50; i++){

      if(median_pos == 1) { // ideally if median is 1 we would do floor(1/2), but that requires doubles and I can't be bothered to change at this stage
            if (number_list[median_pos] == target){
	printf("%d", median_pos);
	goto end;
      }
	    median_pos--;
      } 

      if (number_list[median_pos] == target){
	printf("%d", median_pos);
	goto end;
      }

      if (target > number_list[median_pos]) {
	start_point = median_pos;
	end_point = count - 1;
	
      gap = end_point - start_point;

      if ( (gap % 2) == 0 ) {
	med_change = gap/2;

	median_pos +=med_change;

      } else {

	med_change = (gap+1)/2;

	median_pos +=med_change;
      }


      } else {
	
	end_point = median_pos;
	
      gap = end_point - start_point;

      if ( (gap % 2) == 0 ) {
	median_pos = gap/2;


      } else {

	median_pos = (gap+1)/2;

      }
	

      }
      

    }
    

 end:

}
