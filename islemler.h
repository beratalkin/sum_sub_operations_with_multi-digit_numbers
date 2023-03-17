#ifndef ISLEMLER_H
#define ISLEMLER_H
#include <stdio.h>
#include <stdint.h>

void buyukSayiBul(int size1, int size2, uint8_t *sayi1, uint8_t *sayi2);
int buyukSayiBoyutBul(int a, int b);
int kucukSayiBoyutBul(int a, int b);
void readFile(char* fileName, uint8_t *sayi, int size);
int memoryAllocate(char* filename, uint8_t **sayi);
void printSayi(uint8_t *sayi,int size);
int islemSec();
int islemiYap(uint8_t *buyuksayi, uint8_t *kucuksayi, int buyukSayiBoyut, int kucukSayiBoyut, int islem, int cikarmaKontrol);

#endif