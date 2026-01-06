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
#include <math.h>



struct block {
  int used; // 1 means block is being used, 0 means it is free
  int block_size; // length of memory block
  int *start_mem_of_block; // starting memory address of this block
  struct block* previous; // pointer to previous memory block
  struct block* next; // pointer to next memory block
};

typedef struct block mem_block;

mem_block* initialise(){
// declare initial head block - we pretend that it has been used, as it makes the code easier
// need to declare head pointer at sbrk(0)
// then do sbrk(sizeof(mem_block))
// that provides enough memory for the head mem_block header
mem_block* head = sbrk(0);
sbrk(sizeof(mem_block)); 
head->used = 1;
head->block_size = 0;
head->previous = NULL;
head->next = NULL;
head->start_mem_of_block = sbrk(1);
// declare a tail node
return head;

}

int check_for_memory(int desired_memory, mem_block* current_node){
  // return 1 means we have a block of memory larger than the desired memory
  // return 0 means we need to allocate a block that is large enough
  
  while (current_node-> next != NULL){
    if ( (current_node->block_size > desired_memory) && (current_node->used == 0) ){
      return 1;
    }
    current_node = current_node->next;
  }

return 0;
}

int allocate_more_memory(int desired_memory, mem_block* current_node){
while (current_node->next != NULL){
    current_node = current_node->next;
  }
  
// declare new node - one byte above the end of the previous node
mem_block* tmp = sbrk(1);

// make current_node next point to that new node
current_node->next = tmp;

// make new node prev point to the current_node
tmp->previous = current_node;

double PAGE_SIZE = 4096.0;
 
double mem_to_add = ceil(desired_memory/PAGE_SIZE) * PAGE_SIZE;

int mem_addition = (int)mem_to_add; 

printf("%d of memory to add\n", mem_addition);

// we have our tmp pointer at the start of the new memory block but now we need to actually allocate memory for the header of the tmp node
sbrk(sizeof(mem_block));
tmp->used = 0; 
tmp->next = NULL;
// block size will be set after the sbrk syscall has been used
tmp->start_mem_of_block = sbrk(1);
// create the block of memory 
sbrk(mem_addition);
tmp->block_size = mem_addition;
 
return 0; 
}

int split_block(int desired_memory, mem_block* current_node){
  // return one means a block has been split
  // return 0 means a block has not been split
  

  while( (current_node->next != NULL) ){
    if ( (current_node->used == 0) && (current_node->block_size > desired_memory) ){
      // split the block
      mem_block* tmp = sbrk(0);
       // check if next of current_node exists
      if (current_node->next != NULL){
	tmp->next = current_node->next;
      } else {
	tmp->next = NULL;
      }

      current_node->next = tmp;
      tmp->previous = current_node;
      // move tmp to correct position
      tmp->start_mem_of_block = (int *)((char *)tmp - desired_memory);
      tmp = (int *)((char *)tmp - sizeof(mem_block) - desired_memory);
      
      current_node->block_size = current_node->block_size - sizeof(mem_block);
      current_node->block_size = current_node->block_size - desired_memory;

      tmp->block_size = desired_memory;
      tmp->used = 1;
      
      return 1;
    }
    current_node=current_node->next;

}
  return 0;

}

mem_block* fetch(int desired_memory, mem_block* current_node){

  while(current_node->next != NULL){
    if (current_node->block_size == desired memory){
      return current_node->start_mem_of_block;
    }
    current_node=current_node->next;
  }
  return 0;
}

mem_block* malloc(int desired_memory){

//int outcome = check_for_memory

outcome = check_for_memory(desired_memory, head);

if (outcome == 0)
   allocate_more_memory(desired_memory, head);
  
split_block(desired_memory, head);

 int *ptr = fetch(desired_memory, head);

 return ptr;
}

int free(int *mem_address, mem_block* current_node){

  while(current_node->next != NULL){
    if (current_node->start_mem_of_block == mem_address){
      current_node->used = 0;
    }
    current_node=current_node->next;
  }

  return 0;

}

int main() {
// when allocating a new mem_block (which should be done infrequently)
// loop through linked_list to check if a block is available 
// loop to end of linked list and do mem_block *old = head
// if no block is found that is larger than desired_memory 
// do mem_block *tmp = sbrk(1);
// that increases the heap break by one byte, which is where the next blocks header will start
// then go to the previous block and make sure that head->next = tmp
// then in the new block make sure that head->previous equals the old block
// then do sbrk(sizeof(mem_block))
// that provides enough memory for the header of this new block
// do set all the values
// then sbrk( ceiling(desired_memory/page_size) * page_size )
 
// if a larger block is found, lets call it current
// create a new block pointing to current->start_mem_of_block + (current->block_size - desired_memory)
// then sbrk(sizeof(mem_block), for header
// make sure current->next points to the block we just added in
// make sure current->block_size is decreased by (desired_memory + sizeof(mem_block))

// allocating new memory happens in three stages:
// stage1: see if a block is large enough
// stage2: if it isn't, allocate more mem with sbrk, if it is go to stage 3
// stage3: split the block into two by freeing the memory portion that isn't need, the first block is used, the second block is free (when blocks are split, remember to account for the amount of memory used by the header)

// free goes to the block with the same mem_start as the memory address passed into the function  

mem_block* head = initialise();
  
// check that the memory locations were not corrupted
 
printf("%d used\n", head->used);
printf("%d block-size\n", head->block_size);
printf("%d prev\n", head->previous);
printf("%d next\n", head->next);
printf("%d start mem\n", head->start_mem_of_block);
printf("%d actual size\n", sizeof(mem_block));

//int outcome = check_for_memory(50, head);

printf("outcome is %d as we do not have enough memory\n", outcome); 

int alloc = allocate_more_memory(50, head);
 
return 0;
}
