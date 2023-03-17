#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void buyukSayiBul(int size1, int size2, uint8_t *sayi1, uint8_t *sayi2){
    if(size1>size2){
        sayi1[0]=1;
        sayi2[0]=0;
    }else if(size2>size1){
        sayi1[0]=0;
        sayi2[0]=1;
    }else if(size1==size2){
        sayi1[0]=1;
        sayi2[0]=1;
        for(int i=1;i<=size1;i++){
            if(sayi1[i]>sayi2[i]){
                sayi1[0]=1;
                sayi2[0]=0;
                break;
            }else if(sayi2[i]<sayi2[i]){
                sayi1[0]=0;
                sayi2[0]=1;
                break;
            }else{
            }
        }
    }
}
int buyukSayiBoyutBul(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int kucukSayiBoyutBul(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
void readFile(char* fileName, uint8_t *sayi, int size){
    FILE *fptr = fopen(fileName,"r");
    for(int i = 1;i<size+1;i++){
        fscanf(fptr, "%1u", &sayi[i]);
    }
}
int memoryAllocate(char* fileName, uint8_t **sayi){
    FILE *fptr = fopen(fileName,"r");
    int size=0;
    if (fptr == NULL) {
        printf("Dosya bulunamadi!\n");
        return 0;
    }else{
        char c;
        while(((c = fgetc(fptr)) != EOF)){
            if(c>='0' && c<='9'){
                size++;
            }
        }
        printf("%s %d basamakli\n", fileName, size);
        *sayi = malloc((size+1)*sizeof(uint8_t));
    return size;
}
}
void printSayi(uint8_t *sayi,int size){
    if(size==0){
        printf("Sayi bulunamadi, lutfen dosyalari tekrar okutun.\n");
    }else{
        for(int i=1;i<size+1;i++){
        printf("%d", sayi[i]);
        }
        printf("\n");
    }
}
int islemSec(){
    int islem;
    printf("Toplama(+) islemi icin 1, cikarma(-) islemi icin 2 giriniz: ");
    scanf("%d", &islem);
    if(islem == 1){
        return 1;
    }else if(islem == 2){
        return 2;
    }else{
        printf("Lutfen dogru secenek girdiginizden ve sayilari okuttugunuzdan emin olun!\n");
        return 0;
    }
}
int islemiYap(uint8_t *buyuksayi, uint8_t *kucuksayi, int buyukSayiBoyut, int kucukSayiBoyut, int islem, int cikarmaKontrol){
    if(buyukSayiBoyut==0||kucukSayiBoyut==0||islem==0){
        printf("Lutfen dosyadan sayilari okudugunuzdan ve islem sectiginizden emin olun. \n");
    }else if(cikarmaKontrol==1){
        printf("Lutfen bir kez cikarma islemi yaptiktan sonra sayilari tekrar dosyadan okutun.\n");
    }
    else{
        int sayi3Boyut = buyukSayiBoyut+2;
        uint8_t *sayi3;
        sayi3 = (uint8_t*)calloc(sayi3Boyut,sizeof(uint8_t));
        if(islem == 1){
            int elde = 0;
            int temp;
            int x=buyukSayiBoyut;
            int z=kucukSayiBoyut;
            for(int i = sayi3Boyut-1;i>0;i--){
                if(z<0){
                    temp=buyuksayi[x]+elde;
                }else{
                    temp=buyuksayi[x]+kucuksayi[z]+elde;
                }
                if(temp>9){
                    elde=1;
                }else{
                    elde=0;
                }
                sayi3[i]=temp%10;
                z--;
                x--;
            }
            printf("Toplama isleminin sonucu: \n");
            sayi3[1]=0;
            printSayi(sayi3,sayi3Boyut-1);
            FILE *fptr = fopen("sonuclar.txt","w");
            if(fptr==NULL){
                printf("Sonuc dosyasi bulunamadi. \n");
            }
            for(int i = 1; i<sayi3Boyut;i++){
                fprintf(fptr,"%u",*(sayi3+i));
            }

            return 0;
        }
        else if(islem==2){
            int temp;
            int x = buyukSayiBoyut;
            int z = kucukSayiBoyut;
            for(int i = sayi3Boyut-1;i>0;i--){
                if(z<0){
                    temp=buyuksayi[x];
                }
                else if(buyuksayi[x]-kucuksayi[z]<0){
                    for(int j=x-1;j>0;j--){
                        if(buyuksayi[j]>0){
                            buyuksayi[j]-=1;
                            break;
                        }else{
                            buyuksayi[j]=9;
                        }
                    }
                    temp=10+buyuksayi[x]-kucuksayi[z];
                }else{
                    temp=buyuksayi[x]-kucuksayi[z];
                }
                sayi3[i]=temp;
                x--;
                z--;
            }
            printf("Cikarma isleminin sonucu: \n");
            sayi3[1]=0;
            printSayi(sayi3,sayi3Boyut-1);
            return 1;
        }
    }
}
