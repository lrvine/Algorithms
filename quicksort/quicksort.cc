void quicksort( int* array, int length ){
	int pivot=0;
	int PartitionLine=1;
	int buf=0;
	int middle=length/2;

 	if( (length == 0) || (length == 1 ) ) 
 	  return;
 	
	//Sort first,last,and middle for median-of-three
	//pretend the first at the midlde position
	
	if( array[middle]>array[0]){
		buf=array[0];
		array[0]=array[middle];
		array[middle]=buf;
	}
	if( array[0]>array[length-1]){
		buf=array[0];
		array[0]=array[length-1];
		array[length-1]=buf;
	
		if( array[middle]>array[0]){
			buf=array[0];
			array[0]=array[middle];
			array[middle]=buf;
		}
	}
	//position 0 would be the midian of three
	pivot=array[0];

  	for(int i=1; i<length ; i++){
  	  if(array[i]<=pivot){
  	    if(PartitionLine != i){
  	      buf=array[i];
  	      array[i]=array[PartitionLine];
  	      array[PartitionLine]=buf;
  	    }
  	    PartitionLine++;
  	  }
  	}   
  	array[0]=array[PartitionLine-1];
  	array[PartitionLine-1]=pivot;

	quicksort( array, PartitionLine-1 );
	quicksort( array+PartitionLine, length-PartitionLine);
}

