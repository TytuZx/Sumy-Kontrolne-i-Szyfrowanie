#define _CRT_SECURE_NO_WARNINGS
#include "Program.h"
#include <iostream>
#include <fstream>

bool xorek(std::string plikXorowany_str, std::string plikWyjsciowy_str, std::string klucz_str)
{
    const char* plikXorowany = plikXorowany_str.c_str();
    const char* plikWyjsciowy = plikWyjsciowy_str.c_str();
    const char* klucz = klucz_str.c_str();

    FILE* plik = fopen(plikXorowany, "rb");
    FILE* zaszyfrowany = fopen(plikWyjsciowy, "wb");

    if (plik != NULL && zaszyfrowany != NULL)
    {
        //udane otwarcie pliku do zaszyfrowania i wyjsciowego
        int length = strlen(klucz);
        int znak, xorChar;
        int mod = 0;

        //szyfrowanie XOR znak po znaku
        do
        {
            if (mod >= length)
                mod = 0;
            znak = fgetc(plik);
            xorChar = znak ^ klucz[mod];
            mod++;
            if (znak != EOF)
                fputc(xorChar, zaszyfrowany);
        } while (znak != EOF);

        //zapisywanie plikow (zamykanie)
        if (fclose(zaszyfrowany) == 0 && fclose(plik) == 0)
            return true;
        else
            return false;

    }
    else
        return false;
}

void szyfrowanie() {
    printf("Podaj nazwe pliku do zaszyfrowania\n");
    std::string file;
    std::cin >> file;
    std::string filexor = file + ".xor";
    printf("Podaj klucz szyfruj¹cy\n");
    std::string klucz;
    std::cin >> klucz;
    if (xorek(file, filexor, klucz)) {
        printf("Plik zostal zaszyfrowany");
    }
    else {
        printf("Wystapil blad!!!");
    }
    system("pause");
}

void deszyfrowanie() {
    printf("Podaj nazwe pliku do zdeszyfrowania\n");
    std::string filexor;
    std::cin >> filexor;
    std::string file = filexor;
    for (int i = 4; i > 0; i--) {
        file.pop_back();
    }
    printf("Podaj klucz szyfruj¹cy\n");
    std::string klucz;
    std::cin >> klucz;
    if (xorek(filexor, file, klucz)) {
        printf("Plik zostal zdeszyfrowany");
    }
    else {
        printf("Wystapil blad!!!");
    }
    system("pause");
}


void Szyfr() {
    bool work = true;
    while (work) {
        system("cls");
        printf("Wybierz co chcesz zrobic\n1.Zaszyfruj plik\n2.Zdeszyfruj plik\n0.Powrot do menu\n");
        int s;
        std::cin >> s;
        switch (s) {
        case 1:
            szyfrowanie();
            break;
        case 2:
            deszyfrowanie();
            break;
        case 0:
            work = false;
            break;
        default:
            printf("Bledne dane wybierz poprawna liczbe!");
            system("pause");
        }
    }
}