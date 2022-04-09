#include <stdio.h>
#include <conio.h>
#include <math.h>
double riemann(int dilimsayisi);
int main()
{
	while(1){
	int dilimsayisi;
	char tmmdvm;
	double cevap=0;
	double eski_cevap=0;
	printf("Bu program, sizlerin cok kullandigi; ancak islemlerinin cok zor oldugu bir islemi,\n");
	printf("e uzeri x karenin integralini almayi, sizler icin gorev bilir\n");
	cevap=riemann(dilimsayisi);
	printf("%.3lf bu islemin cevabidir..",cevap);
	printf("\nBaska islem yapmak ister misiniz?(e/h)");
	scanf(" %c",&tmmdvm);
	while(tmmdvm!='e'&& tmmdvm!='h'){printf("Lutfen gecerli harfe tiklayiniz"); scanf(" %c",&tmmdvm);
	}
	if(tmmdvm=='e')
		system("cls");
	else{
		printf("Iyi gunleer..");
		getch();
		return 0;}}
}
double riemann(int dilimsayisi)
{
	double aralik, sol_uc,sag_uc, cevap=0,eski_cevap = 0;
	int dilim_no=1;
	printf("Islemin kac dilimlik hassasiyetle hesaplanmasini istersiniz(Tam sayi)");
	scanf("%d",&dilimsayisi);
	while(dilimsayisi<0){
	printf("Lutfen gecerli deger giriniz"); scanf("%d",&dilimsayisi);
	}
	printf("Hangi sayi degerleri arasini hesaplamak istersiniz?\n");
	printf("Sol uc degerini giriniz(Ondalikli sayi)");
	scanf("%lf",&sol_uc);
	printf("Sag uc degerini giriniz(Ondalikli sayi)");
	scanf("%lf",&sag_uc);
	while(sag_uc<=sol_uc){
	printf("Lutfen gecerli deger giriniz(Sag uc sol uctan buyuk sayi olmali)"); scanf("%lf",&sag_uc);
	}
	aralik=(sag_uc-sol_uc)/(double)dilimsayisi;
	printf("Integralin sonucu [%.3lf , %.3lf] sayi araliginda, %d bolume ayrilarak hazirlaniyor..\n", sol_uc, sag_uc, dilimsayisi);
	for(sol_uc;sol_uc<sag_uc;sol_uc=sol_uc+aralik){
		eski_cevap = cevap;
		cevap=((pow(M_E,pow(sol_uc,2.0)))*sol_uc);
		printf("Dilim No\tX degeri\t\tToplam\n");
		printf("%d\t\t%lf\t\t%lf\n",dilim_no, sol_uc,cevap);
		eski_cevap = eski_cevap+cevap;
		dilim_no++;
	}
	return eski_cevap;
	}
