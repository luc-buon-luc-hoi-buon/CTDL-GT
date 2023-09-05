//•Bài toán: m? ph?m, sách, qu?n áo, v?t li?u xây d?ng, di?n tho?i, máy tính
//
//Yêu c?u
//
//Xây d?ng c?u trúc d?i tu?ng du?c qu?n lý (ch?n 01 d?i tu?ng có ít nh?à 5 thu?c t?nh) Cài d?t các thao tác v?i danh sách (m?i thao tác tuong ?ng v?i m?t CTC
//
//“Nh?p m?t m?ng d?i tu?ng. mãn l?i m?ng m?ng d?i tu?ng
//
//•Tìm ki?m m?t d?i tu?ng nào d? theo In danh sách các d?i tu?ng theo di?u ki?n nào dó • S?p x?p các d?i tu?ng theo tiêu ch? nào d? (s? d?ng thu?t toàn
//
//InsertSort, BubbleSort, QuickSort)
//
//•Tìm giá tr? l?n nh?t trong m?ng d?i tu?ng
//
//Chuong trình chính (áp d?ng các CTC dã c?i d?t trên •Ð? ngh? cài d?t du?i menu l?a ch?n
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
    // Ðua pivot ve giua mang dã sap xep
    i++;
    Swap(ds[i].luong, ds[r].luong);
    return i; // Tra ve vi trí cua pivot
}

void quicksort(int l, int r, NhanVien ds[]) {
    if (l >= r) return; // Ðieu kien dung de quy khi chi còn mot phan tu hoac không có phan tu nào
    int p = partition(l, r, ds);
    quicksort(l, p - 1,ds);
    quicksort(p + 1, r,ds);
}
int main() {
    int n = 3, x;
    int l = 0, r = n - 1;
    NhanVien ds[20];
    
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Nhap danh sach nhan vien" << endl;
        cout << "2. Hien thi danh sach nhan vien" << endl;
        cout << "3. Tim kiem nhan vien theo ma" << endl;
        cout << "4. Sap xep danh sach nhan vien theo luong" << endl;
        cout << "5. Hien thi nhan vien co luong cao nhat" << endl;
        cout << "6. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                nhapdanhsachnhanvien(n, ds);
                break;
            case 2:
                indanhsachnhanvien(n, ds);
                break;
            case 3:
                cout << "Nhap ma nhan vien can tim: ";
                cin >> x;
                timkiemnhanvien(x, n, ds);
                break;
            case 4:
                quicksort(l, r, ds);
                cout << "Danh sach nhan vien sau khi sap xep theo luong:" << endl;
                indanhsachnhanvien(n, ds);
                break;
            case 5:
                cout << "Nhan vien co luong cao nhat: " << endl;
                cout << "Ma nhan vien: " << ds[n - 1].maNV << endl;
                cout << "Ho ten nhan vien: " << ds[n - 1].hten << endl;
                cout << "Dia chi nhan vien: " << ds[n - 1].diachi << endl;
                cout << "So dien thoai nhan vien: " << ds[n - 1].sdt << endl;
                cout << "Luong nhan vien: " << ds[n - 1].luong << endl;
                break;
            case 6:
                return 0; // Exit the program
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    }

    return 0;
}
