// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
bool laSoChinhPhuong(int n) {
    if (n < 0) return false;
    int k = sqrt(n);
    return (k * k == n);
}
void kiemTraSoNguyen() {
    int x;
    char tiep;

    do {
        printf("nhap so nguyen x: ");
        scanf("%d", &x);

        printf("%d la so nguyen\n", x);
        if (laSoNguyenTo(x)) {
            printf("%d la so nguyen to\n", x);
        }
        else {
            printf("%d khong la so nguyen to\n", x);
        }

        if (laSoChinhPhuong(x)) {
            printf("%d la so chinh phuong\n", x);
        }
        else {
            printf("%d khong la so ching phuong\n", x);
        }
        printf("ban muon tiep tuc lap lai chuc nang[y/n]: ");
        scanf(" %c", &tiep);

    } while (tiep == 'y' || tiep == 'Y');
}


int timUCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int timBCNN(int a, int b) {
    return (a * b) / timUCLN(a, b);
}
void uocChungBoiChungCua2So() {
    int x, y;
    char tiep;
    do {
        printf("nhap so nguyen thu nhat: ");
        scanf("%d", &x);
        printf("nhap so nguyen thu hai: ");
        scanf("%d", &y);

        int ucln = timUCLN(x, y);
        int bcnn = timBCNN(x, y);

        printf("uoc so chung lon nhat %d va %d la: %d\n", x, y, ucln);
        printf("uoc boi chung nho nhat %d va %d la: %d\n", x, y, bcnn);

        printf("ban muon lap lai chuc nang[y/n]: ");
        scanf(" %c", &tiep);
    } while (tiep == 'y' || tiep == 'Y');
}


void tinhTienQuanKaraoke() {
    int start, end;
    float tien;
    char tiep;
    do {
        printf("\n=== CHUC NANG 3: TINH TIEN KARAOKE ===\n");

        printf("Nhap gio bat dau: ");
        scanf("%d", &start);

        printf("Nhap gio ket thuc: ");
        scanf("%d", &end);

        // Kiểm tra giờ hợp lệ
        if (start < 12 || start > 23 || end < 12 || end > 23 || end <= start) {
            printf("Gio khong hop le! Quay chi hoat dong tu 12h den 23h.\n");
            return;
        }

        int soGio = end - start;

        // Tính tiền
        if (soGio <= 3) {
            tien = soGio * 150000;
        }
        else {
            tien = 3 * 150000 + (soGio - 3) * (150000 * 0.7);  // giờ 4 trở đi giảm 30%
        }

        // Giảm 10% nếu bắt đầu từ 14h - 17h
        if (start >= 14 && start <= 17) {
            tien *= 0.9;
        }

        printf("So tien can thanh toan: %.0f VND\n", tien);
        printf("ban muon tiep tuc chuc nang[y/n]: ");
        scanf(" %c", &tiep);
    } while (tiep == 'y' || tiep == 'Y');
}


void tinhTienDien() {
    int kwh;
    double tien = 0;
    char tiep;
    do {
        printf("\n=== CHUC NANG 4: TINH TIEN DIEN ===\n");
        printf("Nhap so kWh su dung: ");
        scanf("%d", &kwh);

        if (kwh < 0) {
            printf("So kWh khong hop le!\n");
            return;
        }

        if (kwh <= 50) {
            tien = kwh * 1678;
        }
        else if (kwh <= 100) {
            tien = 50 * 1678 + (kwh - 50) * 1734;
        }
        else if (kwh <= 200) {
            tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
        }
        else if (kwh <= 300) {
            tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
        }
        else if (kwh <= 400) {
            tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
        }
        else {
            tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
        }

        printf("So tien dien phai tra: %.0lf VND\n", tien);
        printf("ban muon tiep tuc chuc nang[y/n]: ");
        scanf(" %c", &tiep);
    } while (tiep == 'y' || tiep == 'Y');
}


//void doiTien() {
//    int sotien;
//    int tiep;
//
//    do {
//        printf("Nhap so tien can doi: ");
//        scanf_s("%d", &sotien);
//
//        int menhgia[] = { 500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000 };
//        int i = 0;
//
//        for (i = 0; i < 9; i++)
//        {
//            int soTo = sotien / menhgia[i];
//            if (soTo > 0)
//                printf("%d VND: %d to\n", menhgia[i], soTo);
//            sotien %= menhgia[i];
//            printf("ban muon tiep tuc chuc nang[y/n]: ");
//            scanf(" %c", &tiep);
//        } while (tiep == 'y' || tiep == 'Y');
//    }
//}

void tinhLaiXuatVayNganHangTraGop() {
    double tienVay;
    int check;
    char tiep;

    do {
        do
        {
            printf("Nhap so tien muon vay (>0): ");
            check = scanf_s("%lf", &tienVay);

            if (check != 1 || tienVay <= 0)
            {
                printf("Sai dinh dang! Nhap lai so tien vay (>0):\n");
                while (getchar() != '\n'); // Clear input buffer
            }
        } while (check != 1 || tienVay <= 0);

        double laiSuat = 0.05;     // 5% / tháng
        int kyHan = 12;            // 12 tháng
        double gocPhaiTraMotThang = tienVay / kyHan;
        double soTienConLai = tienVay;

        printf("\n=== BANG TINH TRA GOP 12 THANG ===\n");
        printf("Ky\tLai phai tra\tGoc tra\t\tTong tra\tSo tien con lai\n");

        for (int i = 1; i <= kyHan; i++)
        {
            double laiPhaiTra = soTienConLai * laiSuat;
            double tongPhaiTra = gocPhaiTraMotThang + laiPhaiTra;
            soTienConLai -= gocPhaiTraMotThang;

            printf("%d\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", i, laiPhaiTra, gocPhaiTraMotThang, tongPhaiTra, soTienConLai);
        }

        printf("\nHoan thanh bang tra gop 12 thang!\n");

        printf("ban muon lap lai chuc nang[y/n]: ");
        scanf(" %c", &tiep);
    } while (tiep == 'y' || tiep == 'Y');
}

void tinhTienMuaXe() {
    float phanTramVay;
    const float giaTriXe = 500000000; // 500 triệu
    const float laiSuatNam = 0.072;   // 7.2%
    const int soNam = 24;
    const int soThang = soNam * 12;
    char tiep;

    do {
        printf("Nhap phan tram vay toi da (VD: 80): ");
        scanf("%f", &phanTramVay);

        float traTruoc = giaTriXe * (100 - phanTramVay) / 100.0;
        float tienVay = giaTriXe * phanTramVay / 100.0;

        float laiSuatThang = laiSuatNam / 12.0; // 0.006

        // Công thức tính tiền trả hàng tháng
        float traHangThang = (tienVay * laiSuatThang) /
            (1 - pow(1 + laiSuatThang, -soThang));

        printf("\n=== KET QUA VAY MUA XE ===\n");
        printf("Tien xe: %.0f VND\n", giaTriXe);
        printf("Tra truoc: %.0f VND\n", traTruoc);
        printf("Tien vay: %.0f VND\n", tienVay);
        printf("Tra hang thang: %.0f VND/thang trong %d thang\n", traHangThang, soThang);

        printf("ban muon tiep tuc chuc nang[y/n]: ");
        scanf(" %c", &tiep);
    } while (tiep == 'y' || tiep == 'Y');
}

typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;
void xepLoai(float diem, char* hocLuc) {
    if (diem >= 9.0)
        strcpy(hocLuc, "Xuat sac");
    else if (diem >= 8.0)
        strcpy(hocLuc, "Gioi");
    else if (diem >= 6.5)
        strcpy(hocLuc, "Kha");
    else if (diem >= 5.0)
        strcpy(hocLuc, "Trung binh");
    else
        strcpy(hocLuc, "Yeu");
}
void sapXep(SinhVien* sv, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
void sapXepThongTinSinhVien() {
    int n;
    char tiep;

    do {
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
        getchar(); // loại bỏ ký tự '\n' còn trong buffer

        // Cấp phát động cho mảng sinh viên
        SinhVien* sv = (SinhVien*)malloc(n * sizeof(SinhVien));
        if (sv == NULL) {
            printf("Khong du bo nho!\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            printf("\nNhap ho ten sinh vien %d: ", i + 1);
            fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
            sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = '\0';

            printf("Nhap diem: ");
            scanf("%f", &sv[i].diem);
            getchar(); // loại bỏ '\n' sau khi nhập số

            xepLoai(sv[i].diem, sv[i].hocLuc);
        }

        sapXep(sv, n);

        printf("\n=== DANH SACH SINH VIEN SAP XEP GIAM DAN ===\n");
        printf("%-25s | %-6s | %-12s\n", "Ho Ten", "Diem", "Hoc Luc");
        for (int i = 0; i < n; i++) {
            printf("%-25s | %-6.2f | %-12s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
        }

        free(sv); // giải phóng bộ nhớ

        printf("Ban muon tiep tuc chuc nang [y/n]: ");
        scanf(" %c", &tiep);
        getchar(); // loại bỏ '\n'
    } while (tiep == 'y' || tiep == 'Y');
}


void gameFpoly() {
    int num1, num2;
    int r1, r2;
    int trung = 0;
    char tiep;

    do {
        // Nhập số của người chơi
        printf("Nhap so thu nhat (1-15): ");
        scanf("%d", &num1);
        printf("Nhap so thu hai (1-15): ");
        scanf("%d", &num2);

        // Sinh số ngẫu nhiên
        srand(time(NULL));
        r1 = rand() % 15 + 1;
        r2 = rand() % 15 + 1;

        printf("\n=== KET QUA FPOLY-LOTT ===\n");
        printf("So cua ban: %d - %d\n", num1, num2);
        printf("So he thong: %d - %d\n", r1, r2);

        // Kiểm tra trúng
        trung = 0;
        if (num1 == r1 || num1 == r2) trung++;
        if (num2 == r1 || num2 == r2) trung++;

        // In kết quả
        if (trung == 0)
            printf("Chuc ban may man lan sau!\n");
        else if (trung == 1)
            printf("Chuc mung ban da trung giai NHI!\n");
        else
            printf("Chuc mung ban da trung giai NHAT!!!\n");

        printf("ban muon tiep tuc chuc nang[y/n]: ");
        scanf(" %c", &tiep);
    } while (tiep == 'y' || tiep == 'Y');
}


typedef struct {
    int tu;
    int mau;
} PhanSo;
// Hàm tính UCLN
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// Hàm rút gọn phân số
void rutGon(PhanSo* ps) {
    int u = gcd(ps->tu, ps->mau);
    ps->tu /= u;
    ps->mau /= u;
    if (ps->mau < 0) { // chuẩn hóa dấu
        ps->tu *= -1;
        ps->mau *= -1;
    }
}

// Hàm nhập phân số
void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
    } while (ps->mau == 0);
}

// Hàm in phân số
void inPhanSo(PhanSo ps) {
    printf("%d/%d", ps.tu, ps.mau);
}

// Các hàm tính toán
void cong(PhanSo a, PhanSo b, PhanSo* kq) {
    kq->tu = a.tu * b.mau + b.tu * a.mau;
    kq->mau = a.mau * b.mau;
    rutGon(kq);
}

void tru(PhanSo a, PhanSo b, PhanSo* kq) {
    kq->tu = a.tu * b.mau - b.tu * a.mau;
    kq->mau = a.mau * b.mau;
    rutGon(kq);
}

void nhan(PhanSo a, PhanSo b, PhanSo* kq) {
    kq->tu = a.tu * b.tu;
    kq->mau = a.mau * b.mau;
    rutGon(kq);
}

void chia(PhanSo a, PhanSo b, PhanSo* kq) {
    kq->tu = a.tu * b.mau;
    kq->mau = a.mau * b.tu;
    rutGon(kq);
}

void tinhToanPhanSo() {
    PhanSo a, b, kq;
    char tiep;

    do {
        printf("Nhap phan so thu nhat:\n");
        nhapPhanSo(&a);

        printf("Nhap phan so thu hai:\n");
        nhapPhanSo(&b);

        // Tính toán
        cong(a, b, &kq);
        printf("\nTong: ");
        inPhanSo(a); printf(" + "); inPhanSo(b); printf(" = "); inPhanSo(kq);

        tru(a, b, &kq);
        printf("\nHieu: ");
        inPhanSo(a); printf(" - "); inPhanSo(b); printf(" = "); inPhanSo(kq);

        nhan(a, b, &kq);
        printf("\nTich: ");
        inPhanSo(a); printf(" * "); inPhanSo(b); printf(" = "); inPhanSo(kq);

        chia(a, b, &kq);
        printf("\nThuong: ");
        inPhanSo(a); printf(" / "); inPhanSo(b); printf(" = "); inPhanSo(kq);

        printf("\n");

        printf("ban muon tiep tuc[y/n]: ");
        scanf(" %c", &tiep);
    } while (tiep == 'y' || tiep == 'y');

}

void menu() {
        printf("===============\n");
        printf("MENU\n");
        printf("===============\n");
        printf("0: thoat\n");
        printf("1: kiem tra so nguyen\n");
        printf("2: tim uoc chung boi chung cua hai so\n");
        printf("3: tinh tien quan karaoke\n");
        printf("4: tinh tien dien\n");
        printf("5: doi tien\n");
        printf("6: tinh lai xuat vay ngan hang tra gop\n");
        printf("7: tinh tien mua xe\n");
        printf("8: sap xep thong tin sinh vien\n");
        printf("9: game FPOLY-LOOT\n");
        printf("10: tinh toan phan so\n");
}

int main() {
    int chon;
    char tiepTuc;
    do {
    menu();
    printf("xin moi nhap lua chon[0-10]: ");
    scanf("%d", &chon);
    switch (chon) {
        case 0:
            printf("thoat\n");
            break;
        case 1:
            kiemTraSoNguyen();
            break;
        case 2:
            uocChungBoiChungCua2So();
            break;
        case 3:
            tinhTienQuanKaraoke();
            break;
        case 4:
            tinhTienDien();
            break;
        case 5:
            doiTien();
            break;
        case 6:
            tinhLaiXuatVayNganHangTraGop();
            break;
        case 7:
            tinhTienMuaXe();
            break;
        case 8:
            sapXepThongTinSinhVien();
            break;
        case 9:
            gameFpoly();
            break;
        case 10:
            tinhToanPhanSo();
            break;
        default:
            printf("lua chon khong phu hop xin moi nhap lai[0-10]: ");
            break;
        }
        if (chon != 0) {
            printf("ban muon nap lai menu [y/n]: ");
            scanf(" %c", &tiepTuc);
        }
        else {
            tiepTuc = 'n';
        }

    } while (tiepTuc == 'y' || tiepTuc == 'Y');
    
    return 0;
}

// Debug/Run chuong trinh: bam "F5" hoac "Debug > Start Debugging" tren menu

// Danh cho nguoi moi bat dau:
//   1. Mo "View" > "Solution Explorer"
//          de them/quan ly cac files
//   2. Mo "View" > "Output"
//          de kiem tra "build output" va "cac thong bao khac"
//   3. Mo "View" > "Error List"
//          de xem loi
//   4. Chon Project > "Add" > "New Item"
//          de tao moi file code,
//      hoac Project > "Add" > "Existing Item"
//          de them file da ton tai vao project nay.
//   5. Sau nay, de mo lai project nay,
//          chon "File > Open > Project" va chon file *.sln
//      Co the xem thu muc project, noi luu file *.sln bang cach
//          trong cua so "Solution Explorer"
//          bam chuot phai vao "Solution"
//          chon "Open Folder in File Explorer"

// GV: AnhTT184