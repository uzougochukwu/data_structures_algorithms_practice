// create a linked list of 'mem_block'
// call sbrk(0) to see what the current memory break is
// when malloc called, go to free list for a block that is larger than or equal to requested memory
// if no block is found, use sbrk syscall to increase heap allocation, increase the heap by some multiple of the page size (4096 bytes on linux) - add that to the free list with a flag saying that the memory is being used
// need to determine the size of the current block and then add that to mem address of next
// if a block is found and it is exactly equal, then return a pointer to the block
// if a block is found that is larger, split the block into two sections:
// section 1 is the desired memory allocation, which is marked as used
// section 2 is the remaining, which is marked as free
// each block should have a header saying whether it is used, free, length of block, starting memory address of block, pointer to previous and pointer to next block
// must implement malloc and free
// free takes a memory address and goes through the linked list until it finds the bloc that has that mem address at the start
// calls sbrk to reduce amount of heap memory


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct block {
  int used; // 1 means block is being used, 0 means it is free
  int block_size; // length of memory block
  int *start_mem_of_block; // starting memory address of this block
  struct block* previous; // pointer to previous memory block
  struct block* next; // pointer to next memory block
};

typedef struct block mem_block;
  

int main() {

// declare initial head block - we pretend that it has been used, as it makes the code easier
mem_block *head = sbrk(sizeof(mem_block));
head->used = 1;
head->block_size = 0;
head->previous = NULL;
head->next = NULL;
head->start_mem_of_block = sbrk(32);

// check that the memory locations were not corrupted
 printf("%d used\n", head->used);
 printf("%d size\n", head->block_size);
 
// printf(" program break at start is %d\n", head);

return 0;
}
