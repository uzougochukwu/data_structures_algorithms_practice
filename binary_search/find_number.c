#include <stdio.h>

int main() {

  int number_list[] = {1,2,3,4,5};

  int target = 5;

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
    
    //printf("%d", median_pos);
    

    int med_change = 0;

    for (int i = 0; i < count; i++){

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
	//printf("%d", median_pos);
      } else {

	med_change = (gap+1)/2;

	median_pos +=med_change;
      }

	

      } else {
	
	end_point = median_pos;
	
      gap = end_point - start_point;

      if ( (gap % 2) == 0 ) {
	median_pos = gap/2;

	//printf("%d", median_pos);

      } else {

	median_pos = (gap+1)/2;


      }


	

      }


      

    }
    

 end:

}
