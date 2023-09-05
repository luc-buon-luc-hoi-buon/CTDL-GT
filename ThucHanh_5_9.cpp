/* Bai toan: my pham, sach, quan ao, vat lieu xay dung, dien thoai, may tinh

Yeu cau

Xay dung cau truc doi tuong duoc quan ly (chon 01 doi tuong co it nhat 5 thuoc tinh) Cai dat cac thao tac voi danh sach (moi thao tac tuong ung voi mot CTC

“Nhap mot mang doi tuong. man lai mang mang doi tuong

•Tim kiem mot doi tuong nao do theo In danh sach cac doi tuong theo dieu kien nao do • Sap xep cac doi tuong theo tieu chi nao do (su dung thuat toan

InsertSort, BubbleSort, QuickSort)

•Tim gia tri lon nhat trong mang doi tuong

Chuong trinh chinh (ap dung cac CTC da cai dat tren •De nghi cai dat duoi menu lua chon*/

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
//	cout<<"ma nhan vien: "<<x.maNV<<endl;
//	cout<<"ho ten nhan vien: "<<x.hten<<endl;
//	cout<<"dia chi nhan vien: "<<x.diachi<<endl;
//	cout<<"sdt nhan vien: "<<x.sdt<<endl;
//	cout<<"luong nhan vien: "<<x.luong<<endl;
//	cout<<"=========================================="<<endl;
    printf("%-10d%-20s%-30s%-15s%-15.2f%-20.2f\n", x.maNV, x.hten.c_str(), x.diachi.c_str(), x.sdt.c_str(), x.hsl, x.luong);
    cout << "=====================================================================================================\n";
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
//hien thi nhan vien co luong >7000
void incodieukien(int n, NhanVien ds[]){
	for(int i=0; i<n; i++){
		if(ds[i].luong>7000) innhanvien(ds[i]);
		else cout<<"Khong co nhan vien nao thoa man!!"<<endl;
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
		printf("%-10s%-20s%-30s%-15s%-10s%-20s\n", "Ma NV", "Ho ten", "Dia chi", "SDT", "He so luong", "Luong");
    	cout << "=====================================================================================================\n";
		innhanvien(ds[middle]);
	}
		else cout<<"khong tim thay!!";
}
	// swap function
	void Swap(NhanVien &b, NhanVien &c) {
    NhanVien temp = b;
    b = c;
    c = temp;
}

// sap xep thong tin theo luong bang quicksort
int partition(int l, int r, NhanVien ds[]) {
    int pivot = ds[r].luong; // Chen phan tu pivot  cuoi mang
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (ds[j].luong <= pivot) {
            i++;
            Swap(ds[i], ds[j]);
        }
    }
    // Ðua pivot ve giua mang dã sap xep
    i++;
    Swap(ds[i], ds[r]);
    return i; // Tra ve vi trí cua pivot
}
//hien thi nhan vien co luong >7000
void hiencodieukien(int n, NhanVien ds[]){
	int dem=0;
	for(int i=0; i<n; i++){
		if(ds[i].luong>7000) innhanvien(ds[i]);
		else dem++;
	} 
	if (dem==0)cout<<"khong co nhan vien nao thoa ma!!"<<endl;
}

void quicksort(int l, int r, NhanVien ds[]) {
    if (l >= r) return; // Ðieu kien dung de quy khi chi còn mot phan tu hoac không có phan tu nào
    int p = partition(l, r, ds);
    quicksort(l, p - 1,ds);
    quicksort(p + 1, r,ds);
}
int main() {
    int n = 5, x;
    int l = 0, r = n - 1;
    NhanVien ds[n];
    
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Nhap danh sach nhan vien" << endl;
        cout << "2. Hien thi danh sach nhan vien" << endl;
        cout << "3. Tim kiem nhan vien theo ma" << endl;
        cout << "4. Sap xep danh sach nhan vien theo luong" << endl;
        cout << "5. Hien thi nhan vien co luong cao nhat" << endl;
        cout << "6. Hien thi nhan vien co luong >7000" << endl;
        cout << "7. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                nhapdanhsachnhanvien(n, ds);
                break;
            case 2:
            	printf("%-10s%-20s%-30s%-15s%-15s%-10s\n", "Ma NV", "Ho ten", "Dia chi", "SDT", "He so luong", "Luong");
  				cout << "=====================================================================================================\n";
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
                printf("%-10s%-20s%-30s%-15s%-15s%-10s\n", "Ma NV", "Ho ten", "Dia chi", "SDT", "He so luong", "Luong");
    		cout << "=====================================================================================================\n";
                indanhsachnhanvien(n, ds);
                break;
            case 5:
            	quicksort(l, r, ds);
            	printf("%-10s%-20s%-30s%-15s%-15s%-10s\n", "Ma NV", "Ho ten", "Dia chi", "SDT", "He so luong", "Luong");
    			cout << "=====================================================================================================\n";
                innhanvien(ds[n-1]);
                break;
            case 6:
            	printf("%-10s%-20s%-30s%-15s%-15s%-10s\n", "Ma NV", "Ho ten", "Dia chi", "SDT", "He so luong", "Luong");
    			cout << "=====================================================================================================\n";
			    hiencodieukien(n, ds);
			    break;
            case 7:
                return 0; 
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    }

    return 0;
}
