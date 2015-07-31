/*******************************************************
* @file: Sorts.hpp
* @author: Dravid Joseph
* @date: 7/24/15
* @brief: Templated implementation file for Sorts class
********************************************************/

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
	
	//This bubble sort bubbles towards the end of the list
	
	bool swapped = false; //flag to terminate sort early if list is already sorted
	
	//iterates through every element of the list
	for(int i = 0;i<size;i++){
		
		//iterates through every element of the list but the last
		for(int j = 0;j<size-1;j++){
			//swap if case holds
			if(arr[i]<arr[j]){
				
				swap(arr,i,j);
				swapped = true;	//flag to continue bubble sort	
			}
		}
		
		if(!swapped){
			//then list is sorted
			return;
		}
		else{
			swapped = false;	//reset flag for next comparison
		}
		
	}
	
	assert(Sorts<T>::isSorted(arr, size));
}
/**
void Sorts<T>::quickSort(T arr[], int size){
	
	
	quickSortRec(arr,size,false);
	
	assert(Sorts<T>::isSorted(arr, size));
	
}

void Sorts<T>::quickSortMedian(T arr[], int size){
	

	quickSortRec(arr,size,true);

	assert(Sorts<T>::isSorted(arr, size));
	
}
*/
template<typename T>
void Sorts<T>::mergeSort(T arr[], int size){
	
	int mid = size/2;
	
	T* a1 = arr + 0;
	T* a2 = arr + mid;
	
	if(mid > 0){
		mergeSort(a1,mid);
		mergeSort(a2,size-mid);
		
		merge(a1,a2,mid,size-mid);
	}
	
	
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::insertionSort(T arr[], int size){
	
	//loop goes through elements 1:size-1
	
	for(int i = 1;i<size;i++){
		
		//holds element
		T next = arr[i];
		
		int j = i;
		
		//while j isn't the end and the adjacent left element is greater than next
		while(j>0 && arr[j-1]>next){
			
			//shift to the right
			arr[j] = arr[j-1];
			
			//decrement
			j--;
		}
		
		//insert into proper index
		arr[j] = next;
	}
	
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::selectionSort(T arr[], int size){
	
	for(int i = 0;i<size-1;i++){
		
		int min = i;
		
		for(int j = i+1; j< size; j++){
			
			if(arr[j]<arr[min]){
				min = j;
			}
			
		}
		
		if(arr[min]!= i){
			swap(arr,i,min);
		}
		
	}
	
	assert(Sorts<T>::isSorted(arr, size));
	
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size){
	
	
	//runs through array
	for(int i = 0;i<size-1;i++){
		
		//if i+1 element isn't greater than or equal to the ith element, it's not sorted 
		if(arr[i] >= arr[i+1]){
			return false;
		}
	}
	return true;
	
}
/**
double Sorts<T>::sortTimer(std::function<void(T[],int)>,T arr[], int size){
	return 0.0;
}
*/


template<typename T>
void Sorts<T>::swap(T arr[], int firstIndex, int secondIndex){
	
	//create a temporary holding variable
	T temp = arr[firstIndex];
	
	//swap 
	
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
		
}

template<typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2){
	
	T* arr = new int[size1+size2];
	
	int first1 = 0;
	int last1 = size1-1;
	
	int first2 = 0;
	int last2 = size2-1;
	
	int index = first1;
	
	while((first1 <= last1 && first2 <= last2)){
		
		if(a1[first1]<=a2[first2]){
			arr[index] = a1[first1];
			first1++;
		}
		else{
			arr[index] = a2[first2];
			first2++;
		}
		index++;	
	}
	
	while(first1 <= last1){
		arr[index] = a1[first1];
		first1++;
		index++;
	}
	
	while(first2 <=last2){
		arr[index] = a2[first2];
		first2++;
		index++;
	}
	
	
	for(index = 0;index <= size1+size2-1;index++){
		a1[index] = arr[index];
	}
	
		
	delete arr;
	arr = nullptr;
	
}
/**
template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median){
	
}

void setMedianPivot(T arr[], int first, int last){
	
}


int partition(T arr[], int first, int last, bool median){
	
}


void shuffle(T arr[], int size){
	
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(0,size-1);
	
	for(int i = 0;i<size;i++){
		
		swap(arr,i,distribution(generator));
		
	}
	
}
*/