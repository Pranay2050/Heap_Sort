#include<stdio.h>
#include<stdlib.h>
#define n 100

void sort(int heap[] , int size){
	int temp, parent , child;
	while(size>0){
	temp=heap[0];
	heap[0] = heap[size-1];
	heap[size-1] = temp;
	size--;
	temp = heap[0];
	parent =0; child=1;
	while(child < size){
		if(child + 1 < size && heap [child] <heap[child+1]) child ++ ;
		if(heap[parent] > heap[child] ) break;
		heap[parent] = heap[child];
		parent = child;
		child = (parent *2) +1 ;
		}
	heap[parent] =temp;

	}
}



void insert(int heap[] ,int size, int item)
{
	int i = size;
	while((i>0) &&(item > heap [(i-1)/2])){
		heap[i] = heap[(i-1)/2];
		i=(i-1)/2;
	}
	heap[i]=item;
}



void display(int heap[] , int size)
{
	for(int i=0;i<size;i++) printf("%d ",heap[i]);
}
void main()
{
	int heap[n],currentsize=0 , item;
	printf("Enter Elements[-1 to exit]\n");
	while(1)
	{
		if(currentsize<n)
			scanf("%d",&item);
		else break;
		if(item==-1)
			break;

		insert(heap,currentsize,item);
		currentsize++;
	}
printf("\nThe sorted elements are : ");
sort(heap,currentsize);
display(heap , currentsize);
}

/*OUTPUT
Enter Elements[-1 to exit]
1
4
3
5
2
6
7
-1

The sorted elements are : 1 2 3 4 5 6 7
*/
