// Verilen bir arrayin min heap olup olmadýðýný bulan fonk.
int minHeap(int A[], int size){
	int i;
	for(i=1;i<size/2;i++){
		if(2*i<size && A[i]>A[2*i])
			return 0;
		if(2*i+1 <size && A[i]>A[2*i+1])
			return;
	}
	return 1;
}

int main(){ 
    int arr[] = {1, 4, 6, 8, 10, 12, 5};
    int n = sizeof(arr) / sizeof(int)-1;
    
    minHeap(arr,n) == 1 ? printf("Yes") : printf("No"); 
  
}
