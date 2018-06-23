void swapArrayElement(int* array, int a, int b){
	int buf;
	buf = array[a];
	array[a] = array[b];
	array[b] = buf;
}

void quicksort(int* array, int length){
	int pivot = 0;
	int PartitionLine = 1;
	int middle = length/2;

 	if ((length == 0) || (length == 1)) 
 	  return;
 	
	//Sort first,last,and middle for median-of-three
	//pretend the array[0] is the midlde position to save swap
	
	if (array[middle] > array[0]){
		swapArrayElement( array,0, middle);
	}
	if (array[0] > array[length-1]){
		swapArrayElement( array,0, (length-1) );
		if (array[middle] > array[0]){
			swapArrayElement( array,0,middle );
		}
	}
	//position 0 would be the midian of three
	pivot=array[0];

  	for (int i = 1; i < length; i++){
  		if (array[i] <= pivot){
			swapArrayElement(array, i , PartitionLine);
  	    		PartitionLine++;
  	  	}
  	}   
  	array[0] = array[PartitionLine-1];
  	array[PartitionLine-1] = pivot;

	quicksort(array, PartitionLine-1);
	quicksort(array+PartitionLine, length-PartitionLine);
}
