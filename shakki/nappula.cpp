#include <list>
#include <string>
#include "asema.h"
#include "nappula.h"
#include "kayttoliittyma.h"
using namespace std;


void Torni::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int lahto_x = ruutu->getRivi();
	int lahto_y = ruutu->getSarake();
	int lahtoruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
	int tuloruudunNappulanVari;

	lahto_x++;
	//OIKEALLE
	while (lahto_x < 8)
	{
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}
		lahto_x++;
	}


	//VASEMMALLE
	lahto_x = ruutu->getRivi() - 1;

	while (lahto_x > -1)
	{
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}
		lahto_x--;
	}

	//ALAS
	lahto_y = ruutu->getSarake() - 1;
	while (lahto_y > -1)
	{
		// oikealle ja alas
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}
		lahto_y--;
	}


	//YLÖS
	lahto_y = ruutu->getSarake() + 1;

	while (lahto_y < 8)
	{
		// ylös
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}
		lahto_y++;
	}
}


void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int lahto_x = ruutu->getRivi();
	int lahto_y = ruutu->getSarake();
	int lahtoruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
	int tuloruudunNappulanVari;

	//kaksi ylös ja yksi oikealle 
	Nappula* n = asema->_lauta[lahto_x + 1][lahto_y+2];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y+2);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x + 1][lahto_y+2]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y+2);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	//kaksi ylös ja yksi vasemmalle
	n = asema->_lauta[lahto_x - 1][lahto_y + 2];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y + 2);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 1][lahto_y + 2]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y + 2);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	// kaksi vasemmalle ja yksi ylös
	n = asema->_lauta[lahto_x - 2][lahto_y + 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x -2, lahto_y + 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 2][lahto_y + 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 2, lahto_y + 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	// kaksi vasemmalle ja yksi alas
	n = asema->_lauta[lahto_x - 1][lahto_y + 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x - 2, lahto_y - 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 2][lahto_y - 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 2, lahto_y - 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	//kaksi alas ja yksi vasemmalle
	n = asema->_lauta[lahto_x - 1][lahto_y - 2];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y -2);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 1][lahto_y - 2]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y - 2);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	// kaksi alas ja yksi oikealle
	n = asema->_lauta[lahto_x + 1][lahto_y - 2];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y - 2);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x + 1][lahto_y - 2]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y - 2);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	//kaksi oikealle ja yksi alas
	n = asema->_lauta[lahto_x +2][lahto_y - 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x + 2, lahto_y - 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x + 2][lahto_y - 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x + 2, lahto_y - 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	// kaksi oikealle ja yksi ylös
	n = asema->_lauta[lahto_x + 2][lahto_y + 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x + 2, lahto_y + 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x + 2][lahto_y + 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x + 2, lahto_y + 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
}


void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	// tehty yhdessä
	int lahto_x = ruutu->getRivi();
	int lahto_y = ruutu->getSarake();
	int lahtoruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
	int tuloruudunNappulanVari;
	lahto_x++;
	lahto_y++;
	while (lahto_x < 8 && lahto_y < 8)
	{
		
		// oikealle ja ylös
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}

		lahto_x++;
		lahto_y++;
	}
	lahto_x = ruutu->getRivi()-1;
	lahto_y = ruutu->getSarake()-1;
	
	while (lahto_x > -1 && lahto_y > -1)
	{
		// vasemmalle ja alas
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}
		lahto_x--;
		lahto_y--;
	}
	lahto_x = ruutu->getRivi() +1;
	lahto_y = ruutu->getSarake() -1 ;
	while (lahto_x < 8 && lahto_y > -1)
	{
		// oikealle ja alas
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}
		lahto_x++;
		lahto_y--;
	}
	lahto_x = ruutu->getRivi() - 1;
	lahto_y = ruutu->getSarake() + 1;

	while (lahto_x > -1 && lahto_y < 8)
	{
		// vasemmalle ja ylös
		Nappula* n = asema->_lauta[lahto_x][lahto_y];
		if (n == nullptr)
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		else
		{
			// värien vertailu
			tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
			if (lahtoruudunNappulanVari == tuloruudunNappulanVari)
			{
				break;
			}
			else
			{
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);
				break;
			}
		}
		lahto_x--;
		lahto_y++;
	}

}


void Daami::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	// pelkkä perintä
}


void Kuningas::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	int lahto_x = ruutu->getRivi();
	int lahto_y = ruutu->getSarake();
	int lahtoruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();
	int tuloruudunNappulanVari;
	
	//yksi oikealle
	Nappula* n = asema->_lauta[lahto_x+1][lahto_y];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x+1, lahto_y);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x+1][lahto_y]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x+1, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}
		
	}
	//yksi oikealle ja yksi ylös
	n = asema->_lauta[lahto_x + 1][lahto_y+1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y+1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x + 1][lahto_y+1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y+1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	// yksi ylös
	n = asema->_lauta[lahto_x][lahto_y + 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y + 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y + 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y + 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	// yksi vasemmalle ja yksi ylös
	n = asema->_lauta[lahto_x - 1][lahto_y + 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y + 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 1][lahto_y + 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y + 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	//yksi vasemmalle
	n = asema->_lauta[lahto_x - 1][lahto_y];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 1][lahto_y]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	//yksi vasemmalle ja yksi alas 
	n = asema->_lauta[lahto_x - 1][lahto_y - 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y - 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 1][lahto_y - 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y - 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	//yksi alas
	n = asema->_lauta[lahto_x][lahto_y - 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y - 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x][lahto_y - 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y - 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	//yksi oikealle ja yksi alas
	n = asema->_lauta[lahto_x - 1][lahto_y - 1];
	if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
	{
		// tallennetaan
		Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y - 1);
		Siirto siirto(*ruutu, tulo_ruutu);
		lista.push_back(siirto);
	}
	else // jos ei ole tyhjä niin tsekataan onko siinä vastustajan nappula, sillon voi siirtyä (ja syödä) joten lisätään listaan
	{
		// värien vertailu
		tuloruudunNappulanVari = asema->_lauta[lahto_x - 1][lahto_y - 1]->getVari();
		if (lahtoruudunNappulanVari != tuloruudunNappulanVari)
		{
			Ruutu tulo_ruutu = Ruutu(lahto_x - 1, lahto_y - 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
		}

	}
	/*perusidea on että kaikki viereiset ruudut ovat sallittuja. kuten tornilla ja lähetillä,
	oman nappulan päälle ei voi mennä ja vastustajan nappulan voi syödä.

	Kaikki muu kuninkaaseen liittyvä tarkistus tehdään eri paikassa*/

	// jere tekee

}


void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	// valkea = 0 musta = 1 
	
	int lahto_x = ruutu->getRivi();
	int lahto_y = ruutu->getSarake();
	int lahtoruudunNappulanVari = asema->_lauta[lahto_x][lahto_y]->getVari();

	bool voidaankoTehdaTuplasiirto = true;

	//VALKOINEN
	if (vari == 0) {

		//Tsekataan ekaksi voidaanko tehdä "tuplasiirto"
		if (voidaankoTehdaTuplasiirto == true) {
			Nappula* n = asema->_lauta[lahto_x][lahto_y + 2];
			if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
			{
				// tallennetaan
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y + 2);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);

				//falselle niin ei voida enää
				voidaankoTehdaTuplasiirto = false;
			}
		}

		//Sitten kaikki normisiirrot
		Nappula* n = asema->_lauta[lahto_x][lahto_y + 1];
		if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y + 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
			voidaankoTehdaTuplasiirto = false;
		}
		

		//Tsekataan 2 "viistossa" olevaa ruutua, jos niissä on vihuja. Voidaan syödä jos on.
		int tuloruudun1NappulanVari = asema->_lauta[lahto_x + 1][lahto_y + 1]->getVari();
		int tuloruudun2NappulanVari = asema->_lauta[lahto_x - 1][lahto_y + 1]->getVari();

		if (lahtoruudunNappulanVari != tuloruudun1NappulanVari)
		{
			//eka viisto
			Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y + 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
			voidaankoTehdaTuplasiirto = false;

			//toka viisto
			Ruutu tulo_ruutu2 = Ruutu(lahto_x - 1, lahto_y + 1);
			Siirto siirto_2(*ruutu, tulo_ruutu2);
			lista.push_back(siirto_2);
			voidaankoTehdaTuplasiirto = false;
		}

	}
	//MUSTA
	else if (vari == 1) {

		//Tsekataan ekaksi voidaanko tehdä "tuplasiirto"
		if (voidaankoTehdaTuplasiirto == true) {
			Nappula* n = asema->_lauta[lahto_x][lahto_y - 2];
			if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
			{
				// tallennetaan
				Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y - 2);
				Siirto siirto(*ruutu, tulo_ruutu);
				lista.push_back(siirto);

				//Falselle niin ei voida enää
				voidaankoTehdaTuplasiirto = false;
			}
		}


		//Sitten kaikki normisiirrot
		Nappula* n = asema->_lauta[lahto_x][lahto_y - 1];
		if (n == nullptr) // jos tyhjä ruutu niin siihen voi siirtyä, lisätään listaan
		{
			// tallennetaan
			Ruutu tulo_ruutu = Ruutu(lahto_x, lahto_y - 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
			voidaankoTehdaTuplasiirto = false;
		}


		//Tsekataan 2 "viistossa" olevaa ruutua, jos niissä on vihuja. Voidaan syödä jos on.
		int tuloruudun1NappulanVari = asema->_lauta[lahto_x + 1][lahto_y - 1]->getVari();
		int tuloruudun2NappulanVari = asema->_lauta[lahto_x - 1][lahto_y - 1]->getVari();

		if (lahtoruudunNappulanVari != tuloruudun1NappulanVari)
		{
			//eka viisto
			Ruutu tulo_ruutu = Ruutu(lahto_x + 1, lahto_y + 1);
			Siirto siirto(*ruutu, tulo_ruutu);
			lista.push_back(siirto);
			voidaankoTehdaTuplasiirto = false;

			//toka viisto
			Ruutu tulo_ruutu2 = Ruutu(lahto_x - 1, lahto_y + 1);
			Siirto siirto_2(*ruutu, tulo_ruutu2);
			lista.push_back(siirto_2);
			voidaankoTehdaTuplasiirto = false;
		}
	}

}


void Sotilas::lisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema) 
{
	// katsotaan myöhemmin
}

