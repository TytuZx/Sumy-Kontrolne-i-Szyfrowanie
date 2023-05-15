#include "Program.h"
#include <iostream>



int main() {
	printf("Witaj Uzytkowniku!\n");
	bool work = true;
	while (work) {
		system("cls");
		printf("Wybierz funkcje ktorej chcesz uzyc. \n1. Generowanie sumy kontrolnej. \n2. Sprawdzenie sumy kontrolnej\n3. Szyfrowanie/odszyfrowywanie pliku\n0. Wyjscie z programu\n");
		int s;
		std::cin >> s;
		switch (s) {
		case 1:
			GenSum();
			break;
		case 2:
			CheckSum();
			break;
		case 3:
			Szyfr();
			break;
		case 0:
			work = false;
			break;
		default:
			printf("Bledne dane wybierz poprawna liczbe!");
			system("pause");
		}
	}
	return 0;
}