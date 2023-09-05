#include<iostream>
using namespace std;
   	// tinh giai thua su dung de quy
long De_quy(int n){
	int sum;
 		if (n==1)	return 1;
 		else return (n*De_quy(n-1));
	 }
	 // tinh giai thua su dung khu de quy
int khu_de_quy(int n){
	int sum=1;
    for(int i=1; i<=n;i++){
    	sum*=i;
	}
    return sum;
}
	//  tinh fibonaci su dung de quy
long fibonaci(int n){
	if(n==1||n==2) return 1;
	else return fibonaci(n-1) + fibonaci(n-2);
}
	//  tinh fibonaci su dung khu de quy
long fibonaci_khudequy(int n){
	int f0 = 0;
    int f1 = 1;
    int fn = 1;
    int i;
    if (n < 0) {
        return -1;
    } else if (n == 0 || n == 1) {
        return n;
    } else {
        for (i = 2; i < n; i++) {
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;
        }
    }
     return fn;
}
   
    // tìm kiem nhi phan
    int binarysearch(int a[], int x, int n){
    	int left = 0, right =n-1, middle;
    	do {
    		middle = (left + right)/2;
    		if(a[middle]==x) break;
    		else if(a[middle]>x) right = middle -1;
			else left = middle +1; 
		}while (left<=right);
		if (left<=right) return middle;
		else return -1;
	}
	
	// swap function
	void Swap(int& b, int& c){
	 int temp = b;
		 b = c;
		 c = temp ;
	}
	
	// print function 
	void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
	
	// selectionSort
	void selectionSort(int a[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }
}

// selectionSort_reverse
	void selectionSort_reverse(int a[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] > a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }
}

// insertionSort
void insertionSort(int a[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

// insertionSort_reverse
void insertionSort_reverse(int a[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < temp) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

//bubbleSort
void bubbleSort(int a[], int n){
 for(int i=0; i<n;i++ ){
 	for(int j=i+1; j<n; j++){
 		if(a[i]>a[j]) swap(a[i],a[j]);
	 }
 }
}

//bubbleSort_reverse
void bubbleSort_reverse(int a[], int n){
 for(int i=0; i<n;i++ ){
 	for(int j=i+1; j<n; j++){
 		if(a[i]<a[j]) swap(a[i],a[j]);
	 }
 }
}
// quicksort
	int partition(int a[], int l, int r) {
    int pivot = a[r]; // Chen phan tu pivot  cuoi mang
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            Swap(a[i], a[j]);
        }
    }
    // Ðua pivot ve giua mang dã sap xep
    i++;
    Swap(a[i], a[r]);
    return i; // Tra ve vi trí cua pivot
}

void quicksort(int a[], int l, int r) {
    if (l >= r) return; // Ðieu kien dung de quy khi chi còn mot phan tu hoac không có phan tu nào
    int p = partition(a, l, r);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}
	// quicksort_reverse
	int partition_reverse(int a[], int l, int r) {
    int pivot = a[r]; // Chen phan tu pivot  cuoi mang
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] >= pivot) {
            i++;
            Swap(a[i], a[j]);
        }
    }
    // Ðua pivot ve giua mang dã sap xep
    i++;
    Swap(a[i], a[r]);
    return i; // Tra ve vi trí cua pivot
}

void quicksort_reverse(int a[], int l, int r) {
    if (l >= r) return; // Ðieu kien dung de quy khi chi còn mot phan tu hoac không có phan tu nào
    int p = partition_reverse(a, l, r);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}
 int main(){
 	int x;
 	int n=9,b=4,c=5;
 	int a[n]={3,6,7,9,13,15,16,18,20};
// 	cout<<"Tong = "<<De_quy(n)<<endl;
// 	cout<<"Tong = "<<khu_de_quy(n)<<endl;
// 	cout<<"Tong fibonaci = "<<fibonaci(n)<<endl;
// 	cout<<"Tong fibonaci = "<<fibonaci_khudequy(n)<<endl;
// 	cout<<"nhap so tim kiem "; cin>>x; 	
// 	if(binarysearch(a, x, n) != -1) 
// 	cout<<"vi tri so can tim la: "<<binarysearch(a, x, n)<<endl;
// 	else cout<<"khong tim thay!!";
// 	Swap(b,c);
// 	cout<<"so b,c lan luot: "<<b<<" "<<c<<endl;

	// selectionSort
 	cout<<"selectionSort: "<<endl;
	selectionSort(a,n);
 	printArray(a,n);
 	cout<<endl;
 	
 	// selectionSort_reverse
 	cout<<"selectionSort_reverse: "<<endl;
 	selectionSort_reverse(a,n);
 	printArray(a,n);
 	cout<<endl;
 	
 	// insertionSort
 	cout<<"insertionsort: "<<endl;
 	insertionSort(a,n);
 	printArray(a,n);
 	cout<<endl;
 	
 	// insertionSort_reverse
 	cout<<"insertionsort_reverse: "<<endl;
 	insertionSort_reverse(a,n);
 	printArray(a,n);
 	cout<<endl;

 	//bubbleSort
 	cout<<"bubbleSort: "<<endl;
 	bubbleSort(a,n);
 	printArray(a,n);
 	cout<<endl;
	
	//bubbleSort_reverse
 	cout<<"bubbleSort_reverse: "<<endl;
 	bubbleSort_reverse(a,n);
 	printArray(a,n);
 	cout<<endl;
 	
 	// quicksort
 	int l=0,r=n-1;
	cout<<"quicksort: "<<endl;
 	quicksort(a,l,r);
 	printArray(a,n);
 	cout<<endl;
 	
 	// quicksort_reverse
 	l=0,r=n-1;
 	cout<<"quicksort_reverse: "<<endl;
 	quicksort_reverse(a,l,r);
 	printArray(a,n);
 	cout<<endl;
 }
