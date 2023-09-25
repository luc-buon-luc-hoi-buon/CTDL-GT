#include<iostream>
using namespace std;
// truct hang hoa
struct HangHoa{
	string sMaHH, sTenHH;
	int iSL;
	float fDG, fThanhTien;
};
struct Node{
	HangHoa data;
	Node *next;
};
typedef struct Node* node ;
node Makenode(){
	HangHoa data;
	cout<<"Nhap ma hang hoa: "; getline(cin, data.sMaHH);
	cout<<"Nhap ten hang hoa: "; getline(cin, data.sTenHH);
	cout<<"Nhap so luong hang hoa: "; cin>>data.iSL;
	cout<<"Nhap don gia hang hoa: "; cin>>data.fDG;
	data.fThanhTien= data.iSL*data.fDG;
	node tmp = new Node();
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}
int Size(node Head){
	int cnt = 0;
	while(Head != NULL){
		++cnt;
		Head = Head->next; // gan dia chi cua not tiep theo cho node hien tai
		//cho node hien tai nhay sang not tiep theo
	}
	return cnt;
}
// them vao dau danh sach
void insertFirst(node &Head){
	node tmp = Makenode();
	if(Head == NULL) Head = tmp;
	else {
	tmp->next = Head;
	Head = tmp;
    }
}
// them danh sach hang hoa
void insertList(node &Head, int n){
	cout<<"nhap so luong hang hoa: "; cin>>n;
	cin.ignore();
	for(int i = 0; i<n; i++){
		insertFirst(Head); cin.ignore();
	}
}
void Display(HangHoa data){
	
	cout<<"Ma Hang Hoa: "<< data.sMaHH<<endl;
	cout<<"Ten Hang Hoa: "<< data.sTenHH<<endl;
	cout<<"So luong Hang Hoa: "<< data.iSL<<endl;
	cout<<"Don gia Hang Hoa: "<< data.fDG<<endl;
	cout<<"Thanh Tien Hang Hoa: "<< data.fThanhTien<<endl;
	
}
void DisplayList(node Head){
	cout << "Danh sach Hang Hoa co so luong:"<<Size(Head)<<endl;
	cout << "Danh sach Hang Hoa :\n";
	while (Head != NULL){
		Display(Head->data);
		Head = Head->next;
	}
}
// sap xep mang 
void selectionSort(node &Head){
	for(node p = Head; p->next != NULL; p = p->next){
		node max = p;
		for(node q = p->next; q != NULL; q = q->next){
			if(q->data.iSL > max->data.iSL){
				max = q;
			}
		}
		HangHoa tmp = max->data;
		max->data = p->data;
		p->data = tmp;
	}
}
// tim kiem hang hoa theo ten
void Searching(node Head, string s){
	cout<<"Nhap ten hang hoa muon tim kiem: "; getline(cin, s);
	int count=0;
	while(Head != NULL){
		if(s == Head->data.sTenHH) {
		Display(Head->data);
		count++;
		break;
		}
		Head = Head->next;
	} 
	cout<<(count == 0 ? "Khong tim thay hang hoa!!":"")<<endl;
}
// hang hoa co don gia cao nhat
void findMax(node Head){
	node Max = Head;
	while(Head != NULL){
		if(Head->data.fDG > Max->data.fDG) Max = Head;
		Head = Head->next;
	}
	Display(Max->data);
}
// chinh sua thong tin theo ma k
void Update(node &Head, string k){
	cout<<"nhap ma can sua: ";  getline(cin, k);
	int count = 0;
	while (Head != NULL){
		if(Head->data.sMaHH == k){
			HangHoa newData;

            cout << "Nhap ten hang hoa: ";
            getline(cin, newData.sTenHH);

            cout << "Nhap so luong hang hoa: ";
            cin >> newData.iSL;

            cout << "Nhap don gia hang hoa: ";
            cin >> newData.fDG;

            newData.fThanhTien = newData.iSL * newData.fDG;

            Head->data = newData;
            count++;
            break;
		}
		Head = Head->next;
	}
	cout<<(count == 0 ? "Khong tim thay hang hoa!!":"")<<endl;
}

int main() {
    node Head = NULL; 
	int n;
	string s, k;
    int choice;
    do {
        cout << "========== MENU ==========" << endl;
        cout << "1. Them danh sach hang hoa" << endl;
        cout << "2. Hien thi danh sach hang hoa" << endl;
        cout << "3. Sap xep danh sach theo so luong" << endl;
        cout << "4. Tim kiem hang hoa theo ten" << endl;
        cout << "5. Tim hang hoa co don gia cao nhat" << endl;
        cout << "6. Chinh sua thong tin theo ma" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (1) {
            case 1:
                insertList(Head, n);
                break;
            case 2:
                DisplayList(Head);
                break;
            case 3:
                selectionSort(Head);
                cout << "Da sap xep danh sach theo so luong." << endl;
                break;
            case 4:
                cin.ignore();
                Searching(Head, s);
                break;
            case 5:
                findMax(Head);
                break;
            case 6:
                cin.ignore(); 
                Update(Head, k);
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (choice != 0);

    return 0;
}



