#include <Windows.h>
#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include "kayttoliittyma.h"
#include "asema.h"


using namespace std;


void Kayttoliittyma::piirraLauta()
{

	//Saa unicode shakkinappulat toimimaan printf kanssa:
	SetConsoleOutputCP(65001);
	/*char q[] = "King: \xE2\x99\x94.\n";
	printf(q);
	printf("King: \xE2\x99\x95\n");*/

	//Saa unicode shakkinappulat toimimaan cout:n kanssa:
	_setmode(_fileno(stdout), _O_U16TEXT);



	/*
		Kaksinkertainen for silmukka joka k‰y asema-olion laudan l‰pi ja jos
		siin‰ on nappula olio, niin kysyt‰‰n sen nimi
		ja tulostetaan se muussa tapauksessa tulostetaan 2 tyhj‰‰ v‰lilyˆnti‰.
		Parillisuuteen perustuen v‰rj‰t‰‰n jokatoisen "ruudun" taustav‰ri
	*/
	// if ((rivi+8) + sarake % 2 == 0)
	// { valkea ruutu }
	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);*/
	
	wcout << "8 ";
	int montakoRivia = 8;

	for (int x = 7; x >= 0; x--)
	{
		for (int y = 0; y < 8; y++)
		{
			if (x % 2 == 1 && y % 2 == 0 || x % 2 == 0 && y % 2 == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			
			Nappula* n = _asema->_lauta[x][y];
			if (n == nullptr)
			{
				wcout << "  ";
			}
			else
			{
				wstring unicode = n->getUnicode();
				int vari = n->getVari();
				// printtaa unicode ja vari


				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

				wcout << unicode << " ";

			}

			if (y == 7)
			{
				wcout << endl;
			}

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		montakoRivia--;

		if (montakoRivia != 0) {
			wcout << montakoRivia << " ";
		}

	}


	//Piirr‰ laudan pohjalle "ABCDEFGH"
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	for (int i = 0; i <= 7; i++) {
		switch (i) {
		case 0:
			wcout << "  A" << " ";
		case 1:
			wcout << "B" << " ";
		case 2:
			wcout << "C" << " ";
		case 3:
			wcout << "D" << " ";
		case 4:
			wcout << "E" << " ";
		case 5:
			wcout << "F" << " ";
		case 6:
			wcout << "G" << " ";
		case 7:
			wcout << "H" << " ";
			break;
		}
		break;
	}

}
Siirto Kayttoliittyma::annaVastustajanSiirto() {

	string siirtoString;

	wcout << "\nAnna siirto: ";
	cin >> siirtoString;

	if (siirtoString.size() == 6) {
		siirtoString.erase(0, 1);
	}

	int lahtoX = siirtoString[0] - 'a';
	int lahtoY = siirtoString[1] - 1 - '0';
	int tuloX = siirtoString[3] - 'a';
	int tuloY = siirtoString[4] - 1 - '0';
	Ruutu lahtoRuutu = Ruutu(lahtoX, lahtoY);
	Ruutu tuloRuutu = Ruutu(tuloX, tuloY);
	// wcout << "\n" << tuloX << "  " << tuloY << "   " << lahtoX << "   " << lahtoY << endl;
	return Siirto(lahtoRuutu, tuloRuutu);
}



