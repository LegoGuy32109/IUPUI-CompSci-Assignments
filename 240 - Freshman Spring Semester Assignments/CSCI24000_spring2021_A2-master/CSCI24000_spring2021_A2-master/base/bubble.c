/* bubble.c
 * famous bubble sort
 * implement the swap element with pointers
 */


#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};

int main(){
  printf("Before: \n");
  printValues();
  sort(); 
  printf("After: \n");
  printValues();

  return(0);
} // end main

void printValues(){
	int i;
	printf("[");
	for(i=0; i<MAX; i++){
		printf("%d ",values[i]);
	}
	printf("]\n");
}

void swap(int* addressA, int* addressB){
	int temp = *addressA;
	*addressA = *addressB;
	*addressB = temp;
	printValues();
}

void sort(){
	int i;
	int j;
	for(i=0; i<MAX-1; i++){
		for(j=0; j<MAX-1; j++){
			if(values[j] > values[j+1]){
				swap(&values[j], &values[j+1]);
			}
		}
	}
}

