#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "islemler.h"


int main(){
    int cikarmaKontrol=0;
    int menuKontrol = 0;
    int secenek = 0;
    int islem = 0;
    uint8_t *sayi1,*sayi2;
    int sayi1Size, sayi2Size = 0;
    char filename1[50],filename2[50];
    printf("==================Buyuk Sayilar Ile Matematiksel Islemler==================\n");
    printf("1) Dosyadan Sayilari Oku (1)\n");
    printf("2) Okunan Sayilari Ekrana Yaz (2)\n");
    printf("3) Islem Sec (+ -) (3)\n");
    printf("4) Islemi yap, Sonucu Ekrana Yazdir (4)\n");
    printf("5) Cikis (5)\n");
    while(menuKontrol==0){
        printf("Bir secenek giriniz: ");
        scanf("%d", &secenek);
        switch(secenek){
            case 1:
            printf("1. Dosyanin ismini giriniz(sayi1.txt gibi): ");
            scanf("%49s",filename1);
            printf("2. Dosyanin ismini giriniz(sayi1.txt gibi): ");
            scanf("%49s",filename2);
            sayi1Size = memoryAllocate(filename1,&sayi1);
            sayi2Size = memoryAllocate(filename2,&sayi2);
            readFile(filename1,sayi1,sayi1Size);
            readFile(filename2,sayi2,sayi2Size);
            buyukSayiBul(sayi1Size,sayi2Size,sayi1,sayi2);
            cikarmaKontrol=0;
            break;
            
            case 2:
            printf("1. Sayi: \n");
            printSayi(sayi1,sayi1Size);
            printf("2. Sayi: \n");
            printSayi(sayi2,sayi2Size);
            break;
            
            case 3:
            islem = islemSec();
            break;
            
            case 4:
            if(sayi1[0]==1){
                cikarmaKontrol = islemiYap(sayi1,sayi2,buyukSayiBoyutBul(sayi1Size,sayi2Size),kucukSayiBoyutBul(sayi1Size,sayi2Size),islem,cikarmaKontrol);
            }else{
                cikarmaKontrol = islemiYap(sayi2,sayi1,buyukSayiBoyutBul(sayi1Size,sayi2Size),kucukSayiBoyutBul(sayi1Size,sayi2Size),islem,cikarmaKontrol);
            }
            break;
            
            case 5:
            printf("Cikis Yapildi.");
            free(sayi1);
            free(sayi2);
            menuKontrol=1;
            break;
            
            default:
            printf("Lutfen menude olan bir sayi giriniz!\n");
            break;
        }
    }
}