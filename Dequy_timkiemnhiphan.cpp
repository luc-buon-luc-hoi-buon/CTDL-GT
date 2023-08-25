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

 int main(){
 	int x;
 	int n=9;
 	int a[n]={3,6,7,9,13,15,16,18,20};
 	cout<<"Tong = "<<De_quy(n)<<endl;
 	cout<<"Tong = "<<khu_de_quy(n)<<endl;
 	cout<<"Tong fibonaci = "<<fibonaci(n)<<endl;
 	cout<<"Tong fibonaci = "<<fibonaci_khudequy(n)<<endl;
 	cout<<"nhap so tim kiem "; cin>>x; 	
 	if(binarysearch(a, x, n) != -1) 
 	cout<<"vi tri so can tim la: "<<binarysearch(a, x, n);
 	else cout<<"khong tim thay!!";
 }
