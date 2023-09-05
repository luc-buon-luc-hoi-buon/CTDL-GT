//�B�i to�n: m? ph?m, s�ch, qu?n �o, v?t li?u x�y d?ng, di?n tho?i, m�y t�nh
//
//Y�u c?u
//
//X�y d?ng c?u tr�c d?i tu?ng du?c qu?n l� (ch?n 01 d?i tu?ng c� �t nh?� 5 thu?c t?nh) C�i d?t c�c thao t�c v?i danh s�ch (m?i thao t�c tuong ?ng v?i m?t CTC
//
//�Nh?p m?t m?ng d?i tu?ng. m�n l?i m?ng m?ng d?i tu?ng
//
//�T�m ki?m m?t d?i tu?ng n�o d? theo In danh s�ch c�c d?i tu?ng theo di?u ki?n n�o d� � S?p x?p c�c d?i tu?ng theo ti�u ch? n�o d? (s? d?ng thu?t to�n
//
//InsertSort, BubbleSort, QuickSort)
//
//�T�m gi� tr? l?n nh?t trong m?ng d?i tu?ng
//
//Chuong tr�nh ch�nh (�p d?ng c�c CTC d� c?i d?t tr�n ��? ngh? c�i d?t du?i menu l?a ch?n
#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std ;
struct  NhanVien{
	int maNV;
	string hten;
	string diachi;
	string sdt;
	float hsl;
	float luong;
	
};
// nhap nhan vien
void nhapnhanvien(NhanVien &x){
	cout<<"nhap ma nhan vien: "; cin>>x.maNV;
	cin.ignore();
	cout<<"nhap ho ten nhan vien: "; getline(cin, x.hten);
	cout<<"nhap dia chi nhan vien: "; getline(cin, x.diachi);
	cout<<"nhap sdt nhan vien: "; getline(cin, x.sdt);
	cout<<"nhap hsl nhan vien: "; cin>>x.hsl;
	x.luong = x.hsl * 1250;
	cout<<"=========================================="<<endl;
}
// in nhan vien
void innhanvien(NhanVien &x){
	cout<<"ma nhan vien: "<<x.maNV<<endl;
	cout<<"ho ten nhan vien: "<<x.hten<<endl;
	cout<<"dia chi nhan vien: "<<x.diachi<<endl;
	cout<<"sdt nhan vien: "<<x.sdt<<endl;
	cout<<"luong nhan vien: "<<x.luong<<endl;
	cout<<"=========================================="<<endl;
//	cout<<x.maNV<<endl;
//	cout<<x.hten<<endl;
//	cout<<x.diachi<<endl;
//	cout<<x.sdt<<endl;
//	cout<<x.luong<<endl;

}
// nhap danh sach nhan vien
void nhapdanhsachnhanvien(int n, NhanVien ds[]){
	for(int i=0; i<n; i++){
		nhapnhanvien(ds[i]);
	}
}
// in danh sach nhan vien
void indanhsachnhanvien (int n, NhanVien ds[]){
	for(int i=0; i<n; i++){
		innhanvien(ds[i]);
	} 
}
// tim kiem doi tuong theo ma nhan vien
void  timkiemnhanvien (int x, int n, NhanVien ds[]){
	int left = 0, right =n-1, middle;
    	do {
    		middle = (left + right)/2;
    		if(ds[middle].maNV==x) break;
    		else if(ds[middle].maNV>x) right = middle -1;
			else left = middle +1; 
		}while (left<=right);
		if (left<=right) {
		cout<<"ma nhan vien: "<<ds[middle].maNV<<endl;
		cout<<"ho ten nhan vien: "<<ds[middle].hten<<endl;
		cout<<"dia chi nhan vien: "<<ds[middle].diachi<<endl;
		cout<<"sdt nhan vien: "<<ds[middle].sdt<<endl;
		cout<<"luong nhan vien: "<<ds[middle].luong<<endl;
		cout<<"=========================================="<<endl;
	}
		else cout<<"khong tim thay!!";
}
	// swap function
	void Swap(float& b, float& c){
	 int temp = b;
		 b = c;
		 c = temp ;
	}
// sap xep thong tin theo luong bang quicksort
int partition(int l, int r, NhanVien ds[]) {
    int pivot = ds[r].luong; // Chen phan tu pivot  cuoi mang
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (ds[j].luong <= pivot) {
            i++;
            Swap(ds[i].luong, ds[j].luong);
        }
    }
    // �ua pivot ve giua mang d� sap xep
    i++;
    Swap(ds[i].luong, ds[r].luong);
    return i; // Tra ve vi tr� cua pivot
}

void quicksort(int l, int r, NhanVien ds[]) {
    if (l >= r) return; // �ieu kien dung de quy khi chi c�n mot phan tu hoac kh�ng c� phan tu n�o
    int p = partition(l, r, ds);
    quicksort(l, p - 1,ds);
    quicksort(p + 1, r,ds);
}
int main (){
	int n= 3, x ;
	int l=0,r=n-1;	
	NhanVien ds[20];
	nhapdanhsachnhanvien(n, ds);
	indanhsachnhanvien(n, ds);
//	cout<<"nhap ma nhan vien tim kiem "; cin>>x; 	
//	timkiemnhanvien(x,n,ds);
	cout<<"SAU KHI SAP XEP: "<<endl;
	quicksort(l, r, ds);
	indanhsachnhanvien(n, ds);
// nhan vien co luong cao nhat
	cout<<"nhan vien co luong cao nhat: "<<endl;
	cout<<"ma nhan vien: "<<ds[n-1].maNV<<endl;
	cout<<"ho ten nhan vien: "<<ds[n-1].hten<<endl;
	cout<<"dia chi nhan vien: "<<ds[n-1].diachi<<endl;
	cout<<"sdt nhan vien: "<<ds[n-1].sdt<<endl;
	cout<<"luong nhan vien: "<<ds[n-1].luong<<endl;	
 	
}//main
