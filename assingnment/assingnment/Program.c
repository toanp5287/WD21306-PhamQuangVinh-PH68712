// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

 /* =========================
    HÀM TIỆN ÍCH CHUNG
    ========================= */
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;

}

bool laSoChinhPhuong(int n) {
    if (n < 0) return false;
    int k = (int)sqrt(n);
    return (k * k == n);
}

int timUCLN(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int timBCNN(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a / timUCLN(a, b)) * b; /* tránh overflow hơn một chút */
}

/* =========================
   CHỨC NĂNG 1: KIỂM TRA SỐ NGUYÊN
   ========================= */
void kiemTraSoNguyen() {
    int x;
    char tiep;
    do {
        printf("\n--- KIEM TRA SO NGUYEN ---\n");
        printf("Nhap so nguyen x: ");
        if (scanf("%d", &x) != 1) {
            printf("Nhap sai! Hay nhap so nguyen.\n");
            while (getchar() != '\n'); /* clear */
            continue;
        }

        printf("%d %s so nguyen to\n", x, laSoNguyenTo(x) ? "la" : "khong la");
        printf("%d %s so chinh phuong\n", x, laSoChinhPhuong(x) ? "la" : "khong la");

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 2: UCLN & BCNN
   ========================= */
void uocChungBoiChungCua2So() {
    int x, y;
    char tiep;
    do {
        printf("\n--- UCLN & BCNN ---\n");
        printf("Nhap so nguyen thu nhat: ");
        if (scanf("%d", &x) != 1) { while (getchar() != '\n'); continue; }
        printf("Nhap so nguyen thu hai: ");
        if (scanf("%d", &y) != 1) { while (getchar() != '\n'); continue; }

        printf("UCLN(%d, %d) = %d\n", x, y, timUCLN(x, y));
        printf("BCNN(%d, %d) = %d\n", x, y, timBCNN(x, y));

        printf("Ban muon lap lai chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 3: TÍNH TIỀN KARAOKE
   ========================= */
void tinhTienQuanKaraoke() {
    int start, end;
    float tien;
    char tiep;
    do {
        printf("\n--- TINH TIEN QUAN KARAOKE ---\n");
        printf("Nhap gio bat dau (12-23): ");
        if (scanf("%d", &start) != 1) { while (getchar() != '\n'); continue; }
        printf("Nhap gio ket thuc (12-23): ");
        if (scanf("%d", &end) != 1) { while (getchar() != '\n'); continue; }

        if (start < 12 || start > 23 || end < 12 || end > 23 || end <= start) {
            printf("Gio khong hop le! (hoat dong tu 12 den 23 va end > start)\n");
            printf("Ban muon thu lai? [y/n]: ");
            scanf(" %c", &tiep);
            while (getchar() != '\n');
            if (tiep == 'y' || tiep == 'Y') continue;
            else break;
        }

        int soGio = end - start;
        if (soGio <= 3) tien = soGio * 150000.0f;
        else tien = 3 * 150000.0f + (soGio - 3) * (150000.0f * 0.7f);

        if (start >= 14 && start <= 17) tien *= 0.9f; /* giam 10% */

        printf("So tien can thanh toan: %.0f VND\n", tien);

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 4: TÍNH TIỀN ĐIỆN
   ========================= */
void tinhTienDien() {
    int kwh;
    double tien;
    char tiep; 
    do {
        printf("\n--- TINH TIEN DIEN ---\n");
        printf("Nhap so kWh su dung: ");
        if (scanf("%d", &kwh) != 1) { while (getchar() != '\n'); continue; }

        if (kwh < 0) {
            printf("So kWh khong hop le!\n");
            continue;
        }

        if (kwh <= 50) tien = kwh * 1678.0;
        else if (kwh <= 100) tien = 50 * 1678.0 + (kwh - 50) * 1734.0;
        else if (kwh <= 200) tien = 50 * 1678.0 + 50 * 1734.0 + (kwh - 100) * 2014.0;
        else if (kwh <= 300) tien = 50 * 1678.0 + 50 * 1734.0 + 100 * 2014.0 + (kwh - 200) * 2536.0;
        else if (kwh <= 400) tien = 50 * 1678.0 + 50 * 1734.0 + 100 * 2014.0 + 100 * 2536.0 + (kwh - 300) * 2834.0;
        else tien = 50 * 1678.0 + 50 * 1734.0 + 100 * 2014.0 + 100 * 2536.0 + 100 * 2834.0 + (kwh - 400) * 2927.0;

        printf("So tien dien phai tra: %.0lf VND\n", tien);

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 5: ĐỔI TIỀN
   ========================= */
void doiTien() {
    int sotien;
    char tiep;
    const int menhgia[] = { 500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000 };
    const int mCount = sizeof(menhgia) / sizeof(menhgia[0]);

    do {
        printf("\n--- DOI TIEN ---\n");
        printf("Nhap so tien can doi (nghin VND): ");
        if (scanf("%d", &sotien) != 1) { while (getchar() != '\n'); continue; }

        if (sotien <= 0) {
            printf("So tien phai > 0\n");
        }
        else {
            printf("Ket qua doi tien:\n");
            for (int i = 0; i < mCount; i++) {
                int soTo = sotien / menhgia[i];
                if (soTo > 0) {
                    printf("%8d VND : %d to\n", menhgia[i], soTo);
                }
                sotien %= menhgia[i];
            }
        }

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 6: TÍNH LÃI VAY TRẢ GÓP (12 tháng)
   ========================= */
void tinhLaiXuatVayNganHangTraGop() {
    double tienVay;
    char tiep;
    do {
        printf("\n--- TINH LAI XUAT TRA GOP (12 thang) ---\n");
        printf("Nhap so tien muon vay (VND): ");
        if (scanf("%lf", &tienVay) != 1) { while (getchar() != '\n'); continue; }
        if (tienVay <= 0) {
            printf("So tien phai > 0\n");
            continue;
        }

        const double laiSuatThang = 0.05; /* 5%/thang */
        const int kyHan = 12;
        double goc = tienVay / kyHan;
        double conLai = tienVay;

        printf("Ky\tLai\t\tGoc\t\tTong\t\tCon lai\n");
        for (int i = 1; i <= kyHan; i++) {
            double lai = conLai * laiSuatThang;
            double tong = goc + lai;
            conLai -= goc;
            printf("%d\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", i, lai, goc, tong, conLai);
        }

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 7: TÍNH TIỀN MUA XE (trả góp)
   ========================= */
void tinhTienMuaXe() {
    float phanTramVay;
    const float giaTriXe = 500000000.0f; /* 500 triệu */
    const float laiSuatNam = 0.072f;     /* 7.2%/năm */
    const int soNam = 24;                /* 24 năm? (giữ theo code trước) */
    const int soThang = soNam * 12;
    char tiep;

    do {
        printf("\n--- TINH TIEN MUA XE ---\n");
        printf("Nhap phan tram vay toi da (VD: 80 cho 80%%): ");
        if (scanf("%f", &phanTramVay) != 1) { while (getchar() != '\n'); continue; }
        if (phanTramVay < 0 || phanTramVay > 100) {
            printf("Phan tram phai giua 0 va 100\n");
            continue;
        }

        float traTruoc = giaTriXe * (100.0f - phanTramVay) / 100.0f;
        float tienVay = giaTriXe * phanTramVay / 100.0f;
        float laiThang = laiSuatNam / 12.0f;
        float traHangThang = (tienVay * laiThang) / (1 - powf(1 + laiThang, -soThang));

        printf("Tien xe: %.0f VND\n", giaTriXe);
        printf("Tra truoc: %.0f VND\n", traTruoc);
        printf("Tien vay: %.0f VND\n", tienVay);
        printf("Tra hang thang: %.0f VND (trong %d thang)\n", traHangThang, soThang);

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 8: SẮP XẾP THÔNG TIN SINH VIÊN
   ========================= */
typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;

void xepLoai(float diem, char* hocLuc) {
    if (diem >= 9.0f) strcpy(hocLuc, "Xuat sac");
    else if (diem >= 8.0f) strcpy(hocLuc, "Gioi");
    else if (diem >= 6.5f) strcpy(hocLuc, "Kha");
    else if (diem >= 5.0f) strcpy(hocLuc, "Trung binh");
    else strcpy(hocLuc, "Yeu");
}

void sapXep(SinhVien* sv, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                SinhVien tmp = sv[i];
                sv[i] = sv[j];
                sv[j] = tmp;
            }
        }
    }
}

void sapXepThongTinSinhVien() {
    int n;
    char tiep;
    do {
        printf("\n--- SAP XEP THONG TIN SINH VIEN ---\n");
        printf("Nhap so luong sinh vien: ");
        if (scanf("%d", &n) != 1) { while (getchar() != '\n'); continue; }
        if (n <= 0) { printf("So luong phai > 0\n"); continue; }
        getchar(); /* clear newline */

        SinhVien* sv = (SinhVien*)malloc(n * sizeof(SinhVien));
        if (!sv) {
            printf("Khong du bo nho!\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            printf("Nhap ho ten sinh vien %d: ", i + 1);
            fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
            sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = '\0';

            printf("Nhap diem: ");
            if (scanf("%f", &sv[i].diem) != 1) { sv[i].diem = 0.0f; }
            getchar();

            xepLoai(sv[i].diem, sv[i].hocLuc);
        }

        sapXep(sv, n);

        printf("\n--- DANH SACH SAP XEP GIAM DAN ---\n");
        printf("%-30s | %-6s | %-12s\n", "Ho Ten", "Diem", "Hoc Luc");
        for (int i = 0; i < n; i++) {
            printf("%-30s | %-6.2f | %-12s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
        }

        free(sv);

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
    } while (tiep == 'y' || tiep == 'Y');
}

/* =========================
   CHỨC NĂNG 9: GAME FPOLY-LOTT
   ========================= */
void gameFpoly() {
    int num1, num2, r1, r2, trung;
    char tiep;
    do {
        printf("\n--- GAME FPOLY-LOTT ---\n");
        printf("Nhap so thu nhat (1-15): ");
        if (scanf("%d", &num1) != 1) { while (getchar() != '\n'); continue; }
        printf("Nhap so thu hai (1-15): ");
        if (scanf("%d", &num2) != 1) { while (getchar() != '\n'); continue; }

        r1 = rand() % 15 + 1;
        r2 = rand() % 15 + 1;

        printf("So cua ban: %d - %d\n", num1, num2);
        printf("So he thong: %d - %d\n", r1, r2);

        trung = 0;
        if (num1 == r1 || num1 == r2) trung++;
        if (num2 == r1 || num2 == r2) trung++;

        if (trung == 0) printf("Chuc ban may man lan sau!\n");
        else if (trung == 1) printf("Chuc mung ban trung giai NHI!\n");
        else printf("Chuc mung ban trung giai NHAT!!!\n");

        printf("Ban muon tiep tuc chuc nang? [y/n]: ");
        scanf(" %c", &tiep);
        while (getchar() != '\n');
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

/* =========================
   MENU CHUNG & MAIN
   ========================= */
void menu() {
    printf("\n========== MENU CHUNG ==========\n");
    printf(" 0  : Thoat\n");
    printf(" 1  : Kiem tra so nguyen\n");
    printf(" 2  : Tim UCLN & BCNN\n");
    printf(" 3  : Tinh tien quan karaoke\n");
    printf(" 4  : Tinh tien dien\n");
    printf(" 5  : Doi tien\n");
    printf(" 6  : Tinh lai xuat vay ngan hang tra gop\n");
    printf(" 7  : Tinh tien mua xe\n");
    printf(" 8  : Sap xep thong tin sinh vien\n");
    printf(" 9  : Game FPOLY-LOTT\n");
    printf(" 10 : Tinh toan phan so\n");
    printf("================================\n");
}

int main(void) {
    srand((unsigned int)time(NULL)); /* seed RNG 1 lần */
    int chon;
    char tiepTuc;
    do {
        menu();
        printf("Nhap lua chon [0-10]: ");
        if (scanf("%d", &chon) != 1) {
            printf("Nhap khong hop le. Thu lai.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (chon) {
        case 0:
            printf("Thoat chuong trinh. Tam biet!\n");
            break;
        case 1: kiemTraSoNguyen(); break;
        case 2: uocChungBoiChungCua2So(); break;
        case 3: tinhTienQuanKaraoke(); break;
        case 4: tinhTienDien(); break;
        case 5: doiTien(); break;
        case 6: tinhLaiXuatVayNganHangTraGop(); break;
        case 7: tinhTienMuaXe(); break;
        case 8: sapXepThongTinSinhVien(); break;
        case 9: gameFpoly(); break;
        case 10: tinhToanPhanSo(); break;
        default:
            printf("Lua chon khong hop le. Vui long chon 0-10.\n");
            break;
        }

        if (chon != 0) {
            printf("\nBan muon ve menu chinh? [y/n]: ");
            scanf(" %c", &tiepTuc);
            while (getchar() != '\n');
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