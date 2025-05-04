#include <stdio.h>

// This took a long time to make, figuring out to get multiple inputs was difficult when I wanted to do it on one line, but easy when I just pressed return. The moral is to go with that's easiest, ifa the function isn't working just write it in main. Every time I printArray() it insisted the array was only 2 entries long. So annoying, but it worked out eventually. I can now sort any array I want!!


void main(){
	// ask how big the array is and tie it to a variable
	int arrSize;
	printf("How many integers do you want to sort?\n: ");
	scanf("%d", &arrSize);
	int nums[arrSize];
	
	printf("Please type all your integers pressing enter between them:\n");
	int i;
	for(i=0; i<arrSize; i++){
		int tempInt;
		scanf("%d", &tempInt);
		nums[i] = tempInt;
		printf("you entered %d, type next number and hit enter\n", *(nums+i));
	}
	// I used the sizeof equation here to easily copy and paste this code to loop through arrays, I explained it in the unused print array's function cause it's so freaking broken, but I still copy and pasted it into main and it works so, yeah	
	for(i=0; i<sizeof nums/sizeof *nums; i++){
		printf("%d ", nums[i]);		
	}
	printf("], let's sort it!\n");
	// I wanted to get that extra point by using a different sorting algorithim, so I went with selection sort, very equivelent complexity-wise to bubble sort. Loop through every element minus the last, then in the inner loop check the two elements ahead and go backwards seeing if and elements need to swap places. If they do, do so, that's the exact same code for swap(). Repeat n^2 times later and boom thats a selection sorted list. 
	int j;
	for (i =0; i<arrSize-1; i++){
		for (j = i+2; j>=1; j--){
			if(nums[j] < nums[j-1]) {
				int tempInt = *(nums+j-1);
				nums[j-1] = *(nums+j);
				nums[j] = tempInt;
			}
		}
	}
	 	
	printf("Here's the array size again: %d\nArray: [", sizeof nums/sizeof *nums);
	for(i=0; i<sizeof nums/sizeof *nums; i++){
		printf("%d ", nums[i]);
	}
	printf("] and sorted!\n");		
}


// This function does not work. I have tried 3 hours to make it work but it will not. I am commenting it out
// I am done with it ruining my life I will do it in main()
/*
void printNums(int arr[]){
 
	// size of returns the size of the element, sizeof nums gets memory length of array
	// size of *nums gets the size of the first element, because all elements are same length just divide
	int size = sizeof arr / sizeof *arr;
	printf("Array size is %d\n[", size);
	int i;	
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("]\n");
} 
*/
