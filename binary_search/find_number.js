let sorted_array = [-1, 0, 2, 4, 7, 8, 9];

const binary_search = (array, value) => {
    let left = 0;
    let right = array.length - 1;
    let mid;

    while (left <= right){

	mid = Math.ceil(left + (right - left)/2);

	if (array[mid] == value){

	    break;
	}

	if (array[mid] > value) {
	    right = mid - 1;

	}else {
	    left = mid + 1;

	}

    }

    console.log(`Your value is in position ${mid}`); 
}

binary_search(sorted_array, 7);

