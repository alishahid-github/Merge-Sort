#include<iostream> 
#include<fstream>
#include<string>
#include<chrono>
using namespace std;

void merge(int arr[], int p, int q, int r) 
{ 
	int n1 = q - p + 1; 
	int n2 = r - q; 

	int L[n1+1], R[n2+1]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[p + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[q + 1+ j]; 
		
	L[n1]=65535;
	R[n2]=65535;	
	int i, j=0; 
	int k = p; 
	for(; k<=r ; k++) 
	{ 
		if (L[i] <= R[j]) 
			arr[k] = L[i++];  
		else
			arr[k] = R[j++];  
	} 

} 


void mergeSort(int arr[], int p, int r) 
{ 
	if (p < r) 
	{ 
		int q = p+(r-p)/2; 
		
		mergeSort(arr, p ,q); 
		mergeSort(arr, q+1, r); 
		merge(arr, p, q, r); 
	} 
} 



int main() 
{ 
	
	int arr[100000];
	ifstream file;
	file.open("data100Ka.txt");
	for (int i = 0; i < 100000; i++)
	{
		file >> arr[i];
	}
	chrono::steady_clock::time_point start = chrono::steady_clock::now();

	mergeSort(arr, 0, 100000 - 1);

	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	chrono::steady_clock::duration d = end - start;
	cout << "Time taken is = " << chrono::duration_cast<chrono::seconds>(d).count() << endl;

	cout << "\nSorted array is \n";
	for (int i = 0; i < 100000; i++)
		cout << "  " << arr[i];
	return 0;
} 

