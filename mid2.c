#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int Abs(int num){
	if(num<0){
		return num*(-1);
	}
	else return num;
}
void swap(int* input, int i, int j) {
        if (i == j)
            return;
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
}
void minHeapify(int* input, int i, int heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // find the smallest
        int smallest = i;

        if (left < heapSize && input[left] < input[smallest]) {
            smallest = left;
        }

        if (right < heapSize && input[right] < input[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            //swap
            swap(input, i, smallest);
            //recursive call
            minHeapify(input, smallest, heapSize);
        }
}
void buildMinHeap(int* input, int heapSize) {
        int depth = (heapSize - 1) / 2;
        for (int i = depth; i >= 0; i--) {
            minHeapify(input, i, heapSize);
        }
}
void maxHeapify(int* input, int i, int heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // find the largest
        int largest = i;

        if (left < heapSize && input[left] > input[largest]) {
            largest = left;
        }

        if (right < heapSize && input[right] > input[largest]) {
            largest = right;
        }

        if (largest != i) {
            //swap
            swap(input, i, largest);
            //recursive call
            maxHeapify(input, largest, heapSize);
        }
}
void buildMaxHeap(int* input, int heapSize) {
        int depth = (heapSize - 1) / 2;
        for (int i = depth; i >= 0; i--) {
            maxHeapify(input, i, heapSize);
        }
}
int main(){
	int cnt=0;
	int a[100000];
	int minHeap[100000];
	int maxHeap[100000];
	int minHeapSize = 0;
        int maxHeapSize = 0;
	int currentMedian=0;
	int num;	
	while(scanf("%d",&num)!=EOF){
		a[cnt] = num;
		if(a[cnt]<currentMedian){
			maxHeap[maxHeapSize++] = a[cnt];
			if (maxHeap[maxHeapSize - 1] > maxHeap[0]) {
                    		swap(maxHeap, maxHeapSize - 1, 0);
                	}
		}
		else{
			minHeap[minHeapSize++] = a[cnt];
			if (minHeap[minHeapSize - 1] < minHeap[0]) {
                    		swap(minHeap, minHeapSize - 1, 0);
                	}
		}
		if (Abs(maxHeapSize - minHeapSize) > 1) {
                	if (maxHeapSize > minHeapSize) {
                    		swap(maxHeap, maxHeapSize - 1, 0);
                    		minHeap[minHeapSize++] = maxHeap[--maxHeapSize];
                    		swap(minHeap, 0, minHeapSize - 1);
                    		buildMaxHeap(maxHeap, maxHeapSize);
                	} 
			else{
                    		swap(minHeap, minHeapSize - 1, 0);
                    		maxHeap[maxHeapSize++] = minHeap[--minHeapSize];
                    		swap(maxHeap, 0, maxHeapSize - 1);
                    		buildMinHeap(minHeap, minHeapSize);
                	}
            	}
		if (maxHeapSize == minHeapSize) {
                	currentMedian = (minHeap[0] + maxHeap[0]);
                	currentMedian = currentMedian / 2;
            	}
		else if (maxHeapSize > minHeapSize) {
                	currentMedian = maxHeap[0];
            	}
		else{
                	currentMedian = minHeap[0];
            	}

            	printf("%d\n",currentMedian);
	}
}
