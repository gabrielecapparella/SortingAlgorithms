#include <stdio.h>

void insertionSort(int *a, int len);
void selectionSort(int *a, int len);
void bubbleSort(int *a, int len);
void gnomeSort(int *a, int len);
void countingSort(int *a, int len);
void mergeSort(int *a, int len);
void quickSort(int *a, int len);

// auxiliary
int min(int *a, int s, int len);  
void swap(int *arr, int a, int b);
void mergeSortAux(int *a, int l, int r);
void merge(int *a, int l, int c, int r);
void quickSortAux(int *a, int s, int e);
int partition(int *a, int s, int e);

int main() {
	int a[6] = {3, 9, 3, 0, 2, -5};
	
	quickSort(a, 6);
	
	int i;
	for(i=0; i<6; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}

void insertionSort(int *a, int len) {
	int i, j;
	
	for(i=1; i<len; i++) {
		j = i;
		while(j>0 && a[j]<a[j-1]) {
			swap(a, j, j-1);
			j--;
		}
	}
}

void selectionSort(int *a, int len) {
	int i, m;
	
	for(i=0; i<len-1; i++) {
		m = min(a, i, len);
		swap(a, i, m);
	}
}

void bubbleSort(int *a, int len) {
	int i, sorted;
	
	do {
		sorted = 1;
		for(i=0; i<len-1; i++) {
			if(a[i]>a[i+1]) {
				sorted = 0;
				swap(a, i, i+1);
			}
		}
	} while(!sorted);
}

void gnomeSort(int *a, int len) {
	int i = 0;
	
	while(i<len) {
		if(i==0 || a[i]>=a[i-1]) {
			i++;
		} else {
			swap(a, i, i-1);
			i--;
		}
	}
}

void countingSort(int *a, int len) {
	int i, j, k;
	int max = a[0];
	int min = a[0];
	
	for(i=1; i<len; i++) {
		if(a[i]>max) max = a[i];
		if(a[i]<min) min = a[i];
	}
	
	int clen = max-min+1;
	int c[clen];
	
	for(i=0; i<clen; i++) { c[i] = 0; }
	for(i=0; i<len; i++) { c[a[i]-min]++; }
	
	k = 0;
	for(i=0; i<clen; i++) {
		for(j=0; j<c[i]; j++) {
			a[k] = i+min;
			k++;
		}
	}	
}

void mergeSort(int *a, int len) {
	mergeSortAux(a, 0, len-1);	
}

void mergeSortAux(int *a, int l, int r) {
	int center;
	if (l<r) {
		center = (l+r)/2;
		printf("%d %d %d \n", l, center, r);
		mergeSortAux(a, l, center);
		mergeSortAux(a, center+1, r);
		merge(a, l, center, r);
	}
}

void quickSort(int *a, int len) {
	quickSortAux(a, 0, len-1);
}

void quickSortAux(int *a, int s, int e) {
	int p;
	
	if(s<e) {
		p = partition(a, s, e);
		quickSortAux(a, s, p-1);
		quickSortAux(a, p+1, e);
	}
}

int min(int *a, int s, int len) { // returns the min element's index
	int i;
	int m = s;
	
	for(i=s+1; i<len; i++) {
		if(a[i]<a[m]) m = i;
	}
	
	return m;
}

void swap(int *arr, int a, int b) {
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}

void merge(int *a, int l, int c, int r) {
	int temp[r-l+1];
	int i, j, k;
	
	i = l;
	j = c+1;
	k = 0;
	
	while(i<=c && j<=r) {
		if(a[i]>a[j]) {
			temp[k] = a[j];
			j++;
		} else {
			temp[k] = a[i];
			i++;
		}
		k++;
	}
	
	while(i<=c) {
		temp[k] = a[i];
		i++;
		k++;
	}
	
	while(j<=r) {
		temp[k] = a[j];
		j++;
		k++;
	}
	
	for(k=l; k<=r; k++) {
		a[k] = temp[k-l];
	}	
}

int partition(int *a, int s, int e) {
	int p, i, j;
	
	p = a[e]; //pivot
	i = s-1;
	
	for(j=s; j<e; j++) {
		if(a[j]<=p) {
			i++;
			swap(a, i, j);
		}
	}
	
	//if(a[e]<a[i+1]) 
	swap(a, i+1, e);
	
	return i+1;
}
