// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>

void thongTinMonHoc()
{
	char tenMonHoc[50];
	int tinChi;

	while (getchar() != '\n');
	printf("nhap ten mon hoc: ");
	fgets(tenMonHoc, sizeof(tenMonHoc), stdin);

	printf("nhap so tien tin chi: ");
	scanf("%d", &tinChi);

	printf("mon hoc:%s", tenMonHoc);
	puts(tenMonHoc);

	printf("tien tin chi: %d\n", tinChi);
}

void tinhTongSoLe(int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += i;
		printf("tong la %d\n", tong);
	}
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) {
			printf("%d la so chan\n", i);
		}
		else
		{
			printf("%d la so le\n", i);
		}
	}
}
void thongTinDiemLab()
{

}
int main()
{
	int chon, tiepTuc;
	int x;
	do {
		printf("MENU\n");
		printf("1. thong tin mon hoc\n");
		printf("2 tinh tong so le\n");
		printf("3 thong ton diem lab\n");
		printf("0 thoat\n");

		printf("moi chon chuc nang: ");
		scanf("%d", &chon);

		if (chon == 0)
		{
			printf("thoat\n");
			return;
		}
		tiepTuc = 1;
		while (tiepTuc == 1)
		{
			switch (chon)
			{
			case 1:
				thongTinMonHoc();
				break;
			case 2:
				printf("nhap so nguyen duong x: ");
				scanf("%d", &x);
				tinhTongSoLe(x);
				break;
			case 3:
				thongTinDiemLab();
				break;
			default:
				printf("chon lai [0-3]: ");
				break;
			}
			printf("ban muon tiep tuc menu: ");
			scanf("%d", &tiepTuc);
			syteam("cls");
		}
	} while (chon != 0);
}



// GV: AnhTT184