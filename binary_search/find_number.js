let sorted_array = [-1, 0, 2, 4, 7, 8, 9];

const binary_search = (array, value) => {
    let left = 0;
    let right = array.length - 1;
    let mid;

    while (left <= right){

	mid = Math.floor(left + (right - left)/2); // works for both floor and ceiling
	// if you calculate mid without floor or ceil and get a fraction, that means that right and left are next to each other, since the gap is only 1
	// depending on whether you use ceil or floor, the mid can become equal to the right or left respectively
	// if you use ceil, mid becomes the right - if the value at mid is the search value, exit. if the value at mid is still more than search value, then we move the right pointer one space left and now both right and left are on the same value - the next check is the final check before exit with 'did not find'
	// if you use floor, mid becomes the left - if the value at mid is the search value, exit. if the value at mid is still less than the search value, then we move the left pointer one space right and now both right and left are on the same value - the next check is the final check before exit with 'did not find'

	if (array[mid] == value){

	    console.log(`Your value is in position ${mid}`); 

	    return;
	}

	if (array[mid] > value) {
	    right = mid - 1;

	}else {
	    left = mid + 1;

	}

    }

    console.log("The value was not found");
}

binary_search(sorted_array, 4);

