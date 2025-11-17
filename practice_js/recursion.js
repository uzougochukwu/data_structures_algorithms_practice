// function factorial(number){

// // while (number >=0){

// // }
// console.log(number)
// number--;
// return number;
// }
// let n = 5;
// while (n>=0){
//    n= factorial(n)
// }

// function factorial(x) {
//   // base case: factorial of 0 is 1
//   if (x === 0) {
//     return 1;
//   }

//   // recursive case: x! = x * (x-1)!
//   return x * factorial(x - 1);
// }

// console.log(factorial(5));

// function factorial(x) {
//   // base case if x is 0 return 1

//   if (x == 0) {
//     return 1;
//   }

//   return x * factorial(x - 1);
// }

// console.log(factorial(4))

// function getRange(x,y){
//     if (x == y){
//         return Array;
//     }

//     return(getRange(x,++x))
// }

// console.log(getRange(2,5));

var range = function (start_num, end_num) {
  // base case: if the difference between end_num and start_num is 2
  // return an array containing the number between them

  if (end_num - start_num === 2) {
    return [start_num + 1];
  } else {
    // recrusive case: generate the range between start_num and end_num -1
    // then push the current end_num -1 to the array

    var list = range(start_num, end_num - 1);
    list.push(end_num - 1);
    return list;
  }
};

console.log(range(2, 9));
