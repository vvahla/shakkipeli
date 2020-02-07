#include <list>
#include <string>
#include "asema.h"
#include "nappula.h"
#include "kayttoliittyma.h"
using namespace std;




void Torni::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{

}


void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	// ville
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
	/*perusidea on että kaikki viereiset ruudut ovat sallittuja. kuten tornilla ja lähetillä,
	oman nappulan päälle ei voi mennä ja vastustajan nappulan voi syödä.

	Kaikki muu kuninkaaseen liittyvä tarkistus tehdään eri paikassa*/

	// jere tekee

}


void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu* ruutu, Asema* asema, int vari)
{
	// valkea = 0 musta = 1 
	// ville
}


void Sotilas::lisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema) 
{
	// katsotaan myöhemmin
}

