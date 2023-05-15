#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "Program.h"
#include <iostream>
#include <fstream>
#include <sha.h>
#include <hex.h>>
#include <md5.h>

using namespace CryptoPP;

void FileSum(){
    printf("Podaj nazwe pliku\n");
    std::string filepath;
    std::cin>>filepath;
    std::ifstream infile(filepath, std::ios::binary);
    if (!infile) {
      std::cerr << "Error: Failed to open file" << std::endl;
    } else {
        int s;
        infile.seekg(0, std::ios::end);
        size_t filesize = infile.tellg();
        infile.seekg(0, std::ios::beg);
        byte buffer[4096];
        std::cout << "Wybierz algorytm do obliczenia sumy kontrolnej:\n1.SHA512\n2.SHA256\n3.MD5\n";
        std::cin >> s;
        switch (s) {
        case 1:
            {
            SHA512 sha512;
            while (infile.good()) {
                infile.read((char*)buffer, sizeof(buffer));
                size_t bytesRead = infile.gcount();
                sha512.Update(buffer, bytesRead);
            }
            byte digest512[SHA512::DIGESTSIZE];
            sha512.Final(digest512);
            std::string sha512Hex;
            HexEncoder encoder512(new StringSink(sha512Hex), false);
            encoder512.Put(digest512, sizeof(digest512));
            encoder512.MessageEnd();
            std::cout << "SHA-512 Hex for " << filepath << ": " << sha512Hex << std::endl;
            break;
            }
        case 2:
            {   
            SHA256 sha256;
            while (infile.good()) {
                infile.read((char*)buffer, sizeof(buffer));
                size_t bytesRead = infile.gcount();
                sha256.Update(buffer, bytesRead);
            }
            byte digest256[SHA256::DIGESTSIZE];
            sha256.Final(digest256);
            std::string sha256Hex;
            HexEncoder encoder256(new StringSink(sha256Hex), false);
            encoder256.Put(digest256, sizeof(digest256));
            encoder256.MessageEnd();
            std::cout << "SHA-256 Hex for " << filepath << ": " << sha256Hex << std::endl;
            break;
            }
        case 3:
            {
            Weak::MD5 hashMD5;
            while (infile.good()) {
                infile.read((char*)buffer, sizeof(buffer));
                size_t bytesRead = infile.gcount();
                hashMD5.Update(buffer, bytesRead);
            }
            byte digestMD5[Weak::MD5::DIGESTSIZE];
            hashMD5.Final(digestMD5);
            HexEncoder encoderMD5;
            std::string MD5Hex;
            encoderMD5.Attach(new StringSink(MD5Hex));
            encoderMD5.Put(digestMD5, sizeof(digestMD5));
            encoderMD5.MessageEnd();
            std::cout << "MD5 Hex for " << filepath << ": " << MD5Hex << std::endl;
            break;
            }
            
        default:
            printf("Bledne dane wybierz poprawna liczbe!");
            system("pause");
        }

    }
    system("pause");
}

void TextSum(){
    printf("Podaj tekst\n");
    std::string text;
    std::cin>>text;

    byte digestMD5[Weak::MD5::DIGESTSIZE];
    Weak::MD5 hash;
    hash.CalculateDigest(digestMD5, (const byte*)text.c_str(), text.length());
    HexEncoder encoderMD5;
    std::string MD5Hex;
    encoderMD5.Attach(new StringSink(MD5Hex));
    encoderMD5.Put(digestMD5, sizeof(digestMD5));
    encoderMD5.MessageEnd();

    byte digest256[SHA256::DIGESTSIZE];
    SHA256().CalculateDigest(digest256, (byte*)text.c_str(), text.length());
    std::string sha256Hex;
    HexEncoder encoder256(new StringSink(sha256Hex), false);
    encoder256.Put(digest256, sizeof(digest256));
    encoder256.MessageEnd();

    byte digest512[SHA512::DIGESTSIZE];
    SHA512().CalculateDigest(digest512, (byte*)text.c_str(), text.length());
    std::string sha512Hex;
    HexEncoder encoder512(new StringSink(sha512Hex), false);
    encoder512.Put(digest512, sizeof(digest512));
    encoder512.MessageEnd();

    std::cout << "MD5 Hex: " << MD5Hex << std::endl;
    std::cout << "SHA-256 Hex: " << sha256Hex << std::endl;
    std::cout << "SHA-512 Hex: " << sha512Hex << std::endl;
    

    system("pause");
}

void GenSum(){
    bool work=true;
    while(work){
    system("cls");
    printf("Wybierz tryb dzialania:\n1.Suma kontrolna dla pliku\n2.Suma kontrolna dla tekstu\n0.Powrot do menu\n");
    int s;
    std::cin >> s;
    switch(s){
        case 1:
            FileSum();
        break;
        case 2:
            TextSum();
        break;
        case 0:
            work=false;
        break;
        default:
            printf("Bledne dane wybierz poprawna liczbe!");
            system("pause");
    }
    }
}






