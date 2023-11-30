#include <bits/stdc++.h>
using namespace std;

struct dichVu{
   int maDV;
   char tenDV[50];
   int sl,donGia,thanhTienDichVu;
};
struct hoaDon{
   int maHD,loaiPhong,hangPhong,soNgayThue;
   char tenKH[30],ngaySinh[12],diaChi[30],sdt[12];
   int thanhTienThuePhong,sldv,tongTien;
   char ngayBD[12],ngayLHD[12];
   dichVu arrDV[30];
};

struct NodeHD{
   hoaDon data;
   struct NodeHD *next;
};

struct listHD {
  NodeHD *Top;
};

void init(listHD &Q){
   Q.Top = NULL;
}
NodeHD *getNode(hoaDon x){
   NodeHD *p = new NodeHD;
   if (p==NULL){
     cout <<"Khong du bo nho!";
     exit(1);
   }
   p->data = x;
   p->next = NULL;
   return p;
}

int checkRong(listHD Q){
  if (Q.Top==NULL){
    return 1;
  }
  return 0;
}
void push(listHD &Q,NodeHD *e){
   if (checkRong(Q)==1){
      Q.Top=e;
   } else {
     e->next = Q.Top;
     Q.Top = e;
   }
}
void tieuDeDV(){
  cout<<"\n       ----------------------------------------------";
  cout<<"\n"<<setw(10)<<"Ma DV"<<setw(15)<<"Ten dich vu"<<setw(14)<<"So Luong"<<setw(10)<<"Don Gia"<<setw(15)<<"Thanh Tien";
}
void nhapDV(dichVu &x){
   cout <<"\n1.Giat ui quan ao - 100k    2.Xe dua don san bay - 400k   3.Spa - 500k\n4.Quay bar - 500k           5.Fitness center - 150k       6.Golf va Tennis - 300k";
   cout <<"\nNhap ma dich vu muon chon: ";cin>>x.maDV;
   switch (x.maDV){
       case 1: strcpy(x.tenDV, "Giat ui quan ao");
               x.donGia = 100000;
               break;
       case 2: strcpy(x.tenDV,"Xe dua don san bay");
               x.donGia = 400000;
               break;
       case 3: strcpy(x.tenDV,"Spa");
               x.donGia = 500000;
               break;
       case 4: strcpy(x.tenDV,"Quay bar");
               x.donGia = 500000;
               break;
       case 5: strcpy(x.tenDV,"Fitness center");
               x.donGia = 150000;
               break;
       case 6: strcpy(x.tenDV,"Golf and Tennes");
               x.donGia = 300000;
               break;
   }
   cout <<"Nhap so luong cho dich vu nay: ";cin>>x.sl;
   x.thanhTienDichVu = x.sl*x.donGia;
}
void nhapHD(hoaDon &x){
   cout <<"\nNhap ma hoa don: "; cin>>x.maHD;
   cout <<"Nhap ten khach hang: ";cin.ignore();cin.getline(x.tenKH,30);
   cout <<"Nhap ngay/thang/nam sinh: "; cin>>x.ngaySinh;
   cout <<"Nhap dia chi: ";cin.ignore();cin.getline(x.diaChi,30);
   cout <<"Nhap SDT: ";cin>>x.sdt;
   cout <<"Phong don - 1 | Phong doi - 2\n   Nhap ma loai phong: ";cin>>x.loaiPhong;
   cout <<"Phong thuong gia - 1 (3000k/ngay) | Phong binh dan - 2 (500k/ngay)\n   Nhap ma hang phong: ";cin>>x.hangPhong;
   cout <<"Nhap so ngay thue: ";cin>>x.soNgayThue;
   cout <<"Nhap ngay bat dau thue : ";cin>>x.ngayBD;
   cout <<"Nhap ngay lap hoa don: ";cin>>x.ngayLHD;
   if (x.hangPhong == 1) x.thanhTienThuePhong = (x.soNgayThue*x.loaiPhong*3000000);     //thuong gia
   if (x.hangPhong == 2) x.thanhTienThuePhong = (x.soNgayThue*x.loaiPhong*500000);     //binh dan
   cout <<"Nhap so luong dich vu: "; cin>>x.sldv;
   for (int i = 0;i<x.sldv;i++){
     nhapDV(x.arrDV[i]);
   }
   x.tongTien = x.thanhTienThuePhong;
   for(int i = 0;i<x.sldv;i++){
     x.tongTien += x.arrDV[i].thanhTienDichVu;
   }
}
void xuatDV(dichVu x){
   cout<<"\n"<<setw(7)<<x.maDV<<setw(19)<<x.tenDV<<setw(7)<<x.sl<<setw(14)<<x.donGia<<setw(13)<<x.thanhTienDichVu;
}
void xuatHD(hoaDon x){
   cout <<"\nMa hoa don: "<<x.maHD;
   cout <<"\nTen khach hang: "<<x.tenKH;
   cout <<"\nNgay/thang/nam sinh: "<<x.ngaySinh;
   cout <<"\nDia chi: "<<x.diaChi;
   cout <<"\nSDT: "<<x.sdt;
   cout <<"\nLoai phong: "<<x.loaiPhong;
   cout <<"\nHang phong: "; if (x.hangPhong == 1) cout <<"Thuong gia"; else cout <<"Binh dan";
   cout <<"\nSo ngay thue: "<<x.soNgayThue;
   cout <<"\nNgay bat dau thue: "<<x.ngayBD;
   cout <<"\nNgay lap hoa don: "<<x.ngayLHD;
   cout <<"\nThanh tien thue phong: "<< x.thanhTienThuePhong;
   cout <<"\nSo luong dich vu: "<<x.sldv;
   tieuDeDV();
   for(int i = 0;i<x.sldv;i++){
        xuatDV(x.arrDV[i]);
   }
   cout<<"\n"<<setw(50)<<"Tong tien: "<<x.tongTien<<endl;
}
void nhapDSHD(listHD &Q){
   int n;
   hoaDon x;
   cout <<"\nNhap so luong hoa don: ";cin>>n;
   NodeHD *p;
   for(int i = 0;i<n;i++){
     nhapHD(x);
     p = getNode(x);
     push(Q,p);
   }
}
void xuatDSHD(listHD Q){
    NodeHD *p;
    cout<<"\n==========DANH SACH HOA DON==========="<<endl;
    for(p=Q.Top;p!=NULL;p=p->next){
        xuatHD(p->data);
    }
}
void ghiFile(FILE *f,listHD Q){
      f = fopen("stack.dat","wb");
      int n = 0;
      NodeHD *p;
      for(p = Q.Top;p!=NULL;p=p->next){
        n +=1;
      }
      fwrite(&n,sizeof(int),1,f);
      for(p = Q.Top;p!=NULL;p=p->next){
        fwrite(&p->data,sizeof(hoaDon),1,f);
      }
      fclose(f);
      cout<<"\nGhi file thanh cong!";
}
void docFile(FILE *f, listHD &Q){
    hoaDon x;
    int n;
    NodeHD*p;
    f = fopen("stack.dat","rb");
    fread(&n,sizeof(int),1,f);
    for(int i = 0;i<n;i++ ){
        fread(&x,sizeof(hoaDon),1,f);
        p = getNode(x);
        push(Q,p);
    }
    fclose(f);
    cout<<"\nDoc file thanh cong! Hay chon thu chuc nang 2 de xem"<<endl;
}
void dsHDThuePhongThuongGia(listHD Q){
   NodeHD *p;
   for (p =Q.Top;p!=NULL;p=p->next ){
      if (p->data.hangPhong==1)      //1 la thuong gia
      {
          xuatHD(p->data);
      }
   }
}
void themHoaDonVTBatKi(listHD &Q){
    int vt;
    int count=0;
    for(NodeHD *p = Q.Top;p!=NULL;p=p->next){
        count++;
    }
    hoaDon x;
    nhapHD(x);

    do {
         cout <<"\nNhap vi tri can them: "; cin>>vt;
         if ((vt<1 || vt>count+1)) {
            cout <<"Vi tri can them phai nam trong doan[1;"<<count+1<<"]"<<endl;
         }
    } while(vt<1 || vt>count+1);

    NodeHD *e = getNode(x);
    if (Q.Top==NULL || vt == 1){
        push(Q,e);

    }else if(vt == count +1){
        int dem = 0;
        NodeHD *cuoi = new NodeHD;
        for (NodeHD *k = Q.Top;k!=NULL;k=k->next){
            dem++;
            if(dem==count){
                cuoi = k;
                NodeHD *chen = getNode(x);
                cuoi->next=chen;
                chen->next=NULL;
            }
        }
    }

    else {
        int dem = 0;
        NodeHD *truoc = new NodeHD;
        for (NodeHD *k = Q.Top;k!=NULL;k=k->next){
            dem++;
            if (dem == vt){
                NodeHD *chen = getNode(x);
                chen->next=k;
                truoc->next=chen;
                break;
            }
            truoc=k;
        }
    }
    cout <<"\nThem thanh cong. Hay xuat lai danh sach de kiem tra!"<<endl;
}

bool kiemTraCuoi(listHD Q, int ma){
  int count = 0;
  int vt=0;
  for(NodeHD *q = Q.Top;q!=NULL;q=q->next){
     count++;
  }
  for (NodeHD *q = Q.Top;q!=NULL;q=q->next){
        vt++;
    if (q->data.maHD==ma && vt==count){
        return true;
    }
  }
  return false;
}
void xoaHDTheoMa(listHD &Q){
    if (Q.Top!=NULL){
     int ma;
     cout <<"\nNhap ma hoa don muon xoa: ";cin>>ma;

          if (Q.Top->data.maHD==ma){                              //xoa dau
             NodeHD *p = Q.Top;
             Q.Top=Q.Top->next;
             delete p;
          }

          else if(kiemTraCuoi(Q,ma)==true){                       //xoa cuoi
                int index=0;
                NodeHD *truoc = new NodeHD;
                for (NodeHD *k = Q.Top;k!=NULL;k=k->next){
                   if(k->data.maHD==ma){
                      truoc->next=NULL;
                      delete k;
                      break;
                   }
                   truoc = k;
               }
          }

          else {                                                  //xoa bat ki
              NodeHD *truoc = new NodeHD;
              for (NodeHD *k = Q.Top;k!=NULL;k=k->next){
                  if (k->data.maHD==ma){
                    truoc->next = k->next;
                    delete k;
                    break;
                  }
                  truoc=k;
              }
          }
   cout <<"\nXoa thanh cong. Hay xuat lai danh sach de kiem tra!";
 } else {
   cout <<"\nDanh sach dang khong co hoa don nao!";
 }
}

void timKiemHDTheoMa(listHD Q){
  int x;
  cout <<"\nNhap ma hoa don muon tim: ";cin>>x;
  NodeHD *p;
  for(p=Q.Top;p!=NULL;p=p->next){
     if (p->data.maHD==x){
        xuatHD(p->data);
     }
  }
}
void sapXepHDTheoTongTien(listHD &Q){
  NodeHD *p;
  NodeHD *q;
  for(p=Q.Top;p!=NULL;p=p->next){
    for(q=p->next;q!=NULL;q=q->next){
        if (p->data.tongTien > q->data.tongTien ) {
            swap(p->data,q->data);
        }
    }
  }
  cout <<"\nDa sap xep thanh cong!Hay xuat danh sach de kiem tra"<<endl;
}
void thongKeHDTTTren10TR(listHD Q){
   NodeHD *p;
   for(p=Q.Top;p!=NULL;p=p->next){
     if (p->data.tongTien>=10000000){
        xuatHD(p->data);
     }
  }
}
void tongTienLonNhat(listHD Q){
   int TTLN = Q.Top->data.tongTien;
   NodeHD *p;
   for(p=Q.Top;p!=NULL;p=p->next){
     if (p->data.tongTien >= TTLN){
        TTLN = p->data.tongTien;
     }
  }
  for(p=Q.Top;p!=NULL;p=p->next){
     if (p->data.tongTien == TTLN){
        xuatHD(p->data);
     }
  }
}
void thongTinHDTheoTenKH(listHD Q){
   string ten;
   int check=0;
   cout <<"\nNhap ten khach hang muon tim hoa don: ";cin.ignore();  getline(cin,ten);
   NodeHD *p;
   for(p=Q.Top;p!=NULL;p=p->next){
     if (p->data.tenKH ==ten){
        check++;
        cout <<"\n---Hoa don cua khach hang nay---";
        xuatHD(p->data);
        break;
     }
  }
  if (check==0) cout <<"\nKhong co ten khach hang nay trong danh sach hoa don!";
}
void dichVuDuocSDNN(listHD Q){
  int dv1=0,dv2=0,dv3=0,dv4=0,dv5=0,dv6=0;
  for (NodeHD *p = Q.Top;p!=NULL;p=p->next){
     for(int i = 0;i < p->data.sldv;i++){
        switch (p->data.arrDV[i].maDV){
           case 1: dv1+=p->data.arrDV[i].sl;break;
           case 2: dv2+=p->data.arrDV[i].sl;break;
           case 3: dv3+=p->data.arrDV[i].sl;break;
           case 4: dv4+=p->data.arrDV[i].sl;break;
           case 5: dv5+=p->data.arrDV[i].sl;break;
           case 6: dv6+=p->data.arrDV[i].sl;break;
        }
     }
  }
  int maximum = max({dv1,dv2,dv3,dv4,dv5,dv6});
  cout <<"\nDich vu duoc su dung nhieu nhat voi tong "<<maximum<<" lan duoc su dung la: ";
  if(maximum==dv1) cout <<"Giat ui quan ao ";
  if(maximum==dv2) cout <<"Xe dua don san bay ";
  if(maximum==dv3) cout <<"Spa ";
  if(maximum==dv4) cout <<"Quay bar ";
  if(maximum==dv5) cout <<"Fitness center ";
  if(maximum==dv6) cout <<"Golf va Tennis ";
}
void thongKeHDSLDVTren4(listHD Q){
   NodeHD *p;
   cout<<"\nDanh sach hoa don su dung so luong dich vu >= 4: ";
   for(p=Q.Top;p!=NULL;p=p->next){
     if (p->data.sldv >= 4){
        xuatHD(p->data);
     }
  }
}
void suaHoaDon(listHD &Q){
   int mhd,snt;
   cout <<"\nNhap ma hoa don muon sua: ";cin>>mhd;
   cout <<"\nNhap so ngay thue moi: ";cin>>snt;
   NodeHD *p;
   for(p=Q.Top;p!=NULL;p=p->next){
     if (p->data.maHD==mhd){
        p->data.soNgayThue=snt;
        if (p->data.hangPhong == 1) {
             p->data.thanhTienThuePhong = (p->data.soNgayThue*p->data.loaiPhong*3000000);
        } else {
             p->data.thanhTienThuePhong = (p->data.soNgayThue*p->data.loaiPhong*500000);
        }
        p->data.tongTien = p->data.thanhTienThuePhong;
        for(int i = 0;i< p->data.sldv;i++){
            p->data.tongTien += p->data.arrDV[i].thanhTienDichVu;
        }
        cout <<"\nHoa don moi sau khi sua:";
        xuatHD(p->data);
        break;
     }
  }
}

int main(){
  listHD Q;
  init(Q);
  FILE *f = new FILE();
  int luaChon;
  do{
    cout<<"\n================MENU===============";
    cout<<"\n1.Nhap danh sach hoa don";
    cout<<"\n2.Xuat danh sach hoa don";
    cout<<"\n3.Ghi file hoa don";
    cout<<"\n4.Doc file hoa don";
    cout<<"\n5.Danh sach hoa don thue phong thuong gia";
    cout<<"\n6.Them hoa don vao vi tri bat ki";
    cout<<"\n7.Xoa hoa don theo ma bat ki nhap vao";
    cout<<"\n8.Tim kiem hoa don theo ma hoa don";
    cout<<"\n9.Sap xep hoa don theo tong tien tang dan";
    cout<<"\n10.Thong ke hoa don co tong tien >= 10tr";
    cout<<"\n11.In ra hoa don co tong tien lon nhat";
    cout<<"\n12.In hoa don theo ten khach hang";
    cout<<"\n13.Thong ke dich vu duoc su dung nhieu nhat";
    cout<<"\n14.Thong ke hoa don co so luong dich vu >= 4";
    cout<<"\n15.Sua thong tin hoa don(khach)theo ma HD nhap tu ban phim";
    cout<<"\n0.Thoat" ;
    cout<<"\n===================================";
    cout<<"\n--Nhap lua chon: "; cin>>luaChon;
    switch(luaChon){
        case 1:nhapDSHD(Q); break;
        case 2:xuatDSHD(Q); break;
        case 3:ghiFile(f,Q); break;
        case 4:docFile(f,Q); break;
        case 5:dsHDThuePhongThuongGia(Q); break;
        case 6:themHoaDonVTBatKi(Q); break;
        case 7:xoaHDTheoMa(Q); break;
        case 8:timKiemHDTheoMa(Q); break;
        case 9:sapXepHDTheoTongTien(Q); break;
        case 10:thongKeHDTTTren10TR(Q); break;
        case 11:tongTienLonNhat(Q); break;
        case 12:thongTinHDTheoTenKH(Q); break;
        case 13:dichVuDuocSDNN(Q); break;
        case 14:thongKeHDSLDVTren4(Q); break;
        case 15:suaHoaDon(Q); break;
      }
  }while(luaChon!=0);

 return 0;
}
