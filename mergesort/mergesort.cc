#include <algorithm>
using namespace std;

inline void copyArray( int* a, int startA, int* b, int startB, int length ){
	for( int i=0 ; i< length ; i++ ){
		a[startA+i] = b[startB+i];
	}
}

void mergeArray( int* array, int* workArray, int startA, int startB, int end ){
	int indexa = startA;
	int indexb = startB;
	int indexaEnd = startB;
	int indexbEnd = end;

	for( int i=startA ; i<indexbEnd ; i++ ){
		if( indexa < indexaEnd && indexb < indexbEnd ){
			if( array[indexa]>array[indexb]){
				workArray[i]=array[indexb];
				indexb++;
			}else{
				workArray[i]=array[indexa];
				indexa++;
			}	
		}else if( indexa == indexaEnd ){
			copyArray( workArray , i , array , indexb , (indexbEnd-i) );
			break;
		}else{
			copyArray( workArray, i , array , indexa , (indexbEnd-i) );
			break;
		}
	}

}

void mergesort( int* array, int length ){

	int * workArray = new int[length];

 	if( (length == 0) || (length == 1 ) ) 
 	  return;
 	
	int * arrayA;
	int * arrayB;
	for( int i=1 ; i< length ; i=i*2 ){
		if(arrayA!=array){
			arrayA=array;
			arrayB=workArray;
		}else{
			arrayA=workArray;
			arrayB=array;
		}
		for( int j=0 ; j <length ; j=(j+(i*2)) ){
			mergeArray( arrayA , arrayB , j , min( (j+i), length ) , min((j+2*i),length) );
		}
	}
	if(arrayA==array)
		copyArray( array , 0 , workArray , 0 , length );

	delete [] workArray;
}

