# Sumy Kontrolne i Szyfrowanie

# PL
Program do generowania oraz sprawdzania sum kontrolnych(MD5,sha256,sha512) i Szyfrowania plików.

Program umożliwia:
1. Generowanie sum kontrolnych z wykorzystaniem skrótów MD5, SHA256 oraz SHA512 dla dowolnych wartości tekstowych oraz plików.
2. Sprawdzanie poprawności sum kontrolnych dla plików z wykorzystaniem skrótów MD5, SHA256 oraz SHA512.
3. Szyfrowanie oraz deszyfrowanie plików metodą XOR z użyciem klucza podanego przez użytkownika.

Program jest aplikacją konsolową i do uruchomienia wymaga komputera z systemem Windows.

Program został napisane z użyciem Biblioteki CryptoPP : https://cryptopp.com
Aby wprowadzić zmiany w projekcie do kompilacji programu potrzebne jest zbudowanie biblioteki CryptoPP i dodanie pliku Cryptlib.lib do folderu CryptoPP wewnątrz projektu.

# ENG
This is a program to generate and check checksums(MD5,sha256,sha512) and Encrypt files.

The program allows you to:
1. generate checksums using MD5, SHA256 and SHA512 hashes for any text values and files.
2. validation of checksums for files using MD5, SHA256 and SHA512 hashes.
3. encryption and decryption of files by the XOR method using a key specified by the user.

This program is a console application and requires a Windows computer to run.

The program was written using the CryptoPP Library : https://cryptopp.com
To make changes to the project and to compile the program, you need to build the CryptoPP library and add the Cryptlib.lib file to the CryptoPP folder inside the project.
