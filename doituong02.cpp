#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Hocsinh {
private:
    string Hoten;
    string MSV;
    string lop;
    float dtoan;
    float dvan;
    float danh;
    float dtb;
    string xeploai;
    void tinhdtb() {
        dtb = (dtoan + dvan + danh) / 3.0f;
    }
    void tinhxeploai() {
        if (dtb >= 8.5 && dtoan >= 6.5 && dvan >= 6.5 && danh >= 6.5) {
            xeploai = "gioi";
        } else if (dtb >= 7.0 && dtoan >= 6.5 && dvan >= 6.5 && danh >= 6.5) {
            xeploai = "kha";
        } else if (dtb >= 5.5) {
            xeploai = "trung binh";
        } else if (dtb >= 4.0) {
            xeploai = "yeu";
        } else {
            xeploai = "truot";
        }
    }

public:
    string getMSV() { return MSV; }     //get la ham dung de lay va doc 
    string getHoten() { return Hoten; }
    float getDtb() { return dtb; }
    void tinhToan() {
        tinhdtb();
        tinhxeploai();
    }
    void nhap1HS();
    void in1HS();
};
void Hocsinh::nhap1HS() {
    cout << "Nhap ma sinh vien: ";
    cin >> MSV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, Hoten);
    cout << "Nhap lop: ";
    getline(cin, lop);
    cout << "Nhap diem Toan: ";
    cin >> dtoan;
    cout << "Nhap diem Van: ";
    cin >> dvan;
    cout << "Nhap diem Anh: ";
    cin >> danh;
    tinhToan();
}

// Hàm in 1 hoc sinh
void Hocsinh::in1HS() {
    cout << MSV << "\t" << Hoten << "\t" << lop << "\t"
         << dtoan << "\t" << dvan << "\t" << danh << "\t"
         << dtb << "\t" << xeploai << endl;
}
// nhap danh sach hoc sinh
void nhapDS(Hocsinh a[], int &n) {
    cout << "Nhap so luong sinh vien (0 < n < 200): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---\n";
        a[i].nhap1HS();
    }
}
// In danh sách
void inDS(Hocsinh a[], int n) {
    cout << "\nMSV\tHo Ten\tLop\tToan\tVan\tAnh\tDTB\tXep Loai\n";
    for (int i = 0; i < n; i++) {
        a[i].in1HS();
    }
}
// xap xep theo diem trung binh cua danh sach quan ly hoc sinh giam dan
void xapxep(Hocsinh a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].getDtb() < a[j].getDtb()) {
                Hocsinh temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "\nDa sap xep danh sach giam dan theo DTB!\n";
}
// tim kiem theo ten or msv
void timkiem(Hocsinh a[], int n) {
    cin.ignore();
    string tuKhoa;
    cout << "\nNhap MSV hoac Ho ten can tim: ";
    getline(cin, tuKhoa);
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (a[i].getMSV() == tuKhoa || a[i].getHoten() == tuKhoa) {
            if (!timThay) {
                cout << "\n--- KET QUA TIM KIEM ---\n";
                timThay = true;
            }
            a[i].in1HS();
        }
    }
    if (!timThay) cout << "Khong tim thay sinh vien!\n";
}
// // chen 1 thanh vien vao danh sach quan ly ma ban chi dinh
void chen(Hocsinh a[], int &n) {
    int k;
    cout << "\nNhap vi tri can chen (1 den " << n + 1 << "): ";
    cin >> k;
    if (k < 1 || k > n + 1) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    for (int i = n; i >= k; i--) {
        a[i] = a[i - 1];
    }
    cout << "--- Nhap thong tin sinh vien moi ---\n";
    a[k - 1].nhap1HS();
    n++;
    cout << "Da chen thanh cong!\n";
}
// xoa 1 thanh vien ra khoi danh sach quan ly
void xoa(Hocsinh a[], int &n) {
    int k;
    cout << "\nNhap vi tri can xoa (1 den " << n << "): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    for (int i = k - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    cout << "Da xoa thanh cong!\n";
}
int main() {
    Hocsinh ds[200];
    int n = 0;
    int chon;
    do {
        cout << "\n=== MENU QUAN LY SINH VIEN ======\n";
        cout << "   1. Nhap danh sach\n";         
        cout << "   2. In danh sach\n";
        cout << "   3. Sap xep theo DTB giam dan\n";
        cout << "   4. Tim kiem\n";
        cout << "   5. Chen 1 sinh vien\n";
        cout << "   6. Xoa 1 sinh vien\n";
        cout << "   0. Thoat\n";
        cout << "   Chon chuc nang:";
        cin >> chon;
 
        switch (chon) {
            case 1: nhapDS(ds, n); break;
            case 2: inDS(ds, n); break;
            case 3: xapxep(ds, n); inDS(ds, n); break;
            case 4: timkiem(ds, n); break;
            case 5: chen(ds, n); inDS(ds, n); break;
            case 6: xoa(ds, n); inDS(ds, n); break;
        }
    } while (chon != 0);
    return 0;
}
