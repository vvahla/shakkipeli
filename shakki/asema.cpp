#include <iostream>
#include "asema.h"
#include "nappula.h"
#include "kayttoliittyma.h"


Nappula* Asema::vk = new Kuningas(L"\u2654", 0, VK);
Nappula* Asema::vd = new Daami(L"\u2655", 0, VD);
Nappula* Asema::vt = new Torni(L"\u2656", 0, VT);
Nappula* Asema::vl = new Lahetti(L"\u2657", 0, VL);
Nappula* Asema::vr = new Ratsu(L"\u2658", 0, VR);
Nappula* Asema::vs = new Sotilas(L"\u2659", 0, VS);

Nappula* Asema::mk = new Kuningas(L"\u265A", 1, MK);
Nappula* Asema::md = new Daami(L"\u265B", 1, MD);
Nappula* Asema::mt = new Torni(L"\u265C", 1, MT);
Nappula* Asema::ml = new Lahetti(L"\u265D", 1, ML);
Nappula* Asema::mr = new Ratsu(L"\u265E", 1, MR);
Nappula* Asema::ms = new Sotilas(L"\u265F", 1, MS);


Asema::Asema()
{
	// Ensin alustetaan kaikki laudan ruudut nappulalla "NULL", koska muuten ruuduissa satunnaista tauhkaa
	// _lauta aseta kaikki null loopilla
	// Asetetaan alkuaseman mukaisesti nappulat ruuduille
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			_lauta[x][y] = NULL;
		}
	}
	_lauta[0][0] = vt;
	_lauta[0][1] = vr;
	_lauta[0][2] = vl;
	_lauta[0][3] = vk;
	_lauta[0][4] = vd;
	_lauta[0][5] = vl;
	_lauta[0][6] = vr;
	_lauta[0][7] = vt;
	_lauta[1][0] = vs;
	_lauta[1][1] = vs;
	_lauta[1][2] = vs;
	_lauta[1][3] = vs;
	_lauta[1][4] = vs;
	_lauta[1][5] = vs;
	_lauta[1][6] = vs;
	_lauta[1][7] = vs;

	_lauta[7][0] = mt;
	_lauta[7][1] = mr;
	_lauta[7][2] = ml;
	_lauta[7][3] = mk;
	_lauta[7][4] = md;
	_lauta[7][5] = ml;
	_lauta[7][6] = mr;
	_lauta[7][7] = mt;
	_lauta[6][0] = ms;
	_lauta[6][1] = ms;
	_lauta[6][2] = ms;
	_lauta[6][3] = ms;
	_lauta[6][4] = ms;
	_lauta[6][5] = ms;
	_lauta[6][6] = ms;
	_lauta[6][7] = ms;

}
void Asema::paivitaAsema(Siirto* siirto)
{
	Ruutu alkuruutu = siirto->getAlkuruutu();
	int x_a = alkuruutu.getRivi();
	int y_a = alkuruutu.getSarake();
	
	Ruutu loppuruutu = siirto->getLoppuruutu();
	int x_l = loppuruutu.getRivi();
	int y_l = loppuruutu.getSarake();
	Nappula* n = _lauta[x_a][y_a];
	_lauta[x_a][y_a] = NULL;
	_lauta[x_l][y_l] = n;

	/*Muuta asema - luokan tilaa annetulla siirrolla(siirto saadaan parametrina).Ts.Rg1 - f3.g1 - ruutu tyhjä ja f3 ruutu nappula olio.

		a) Selvitä siirto oliosta lähtöruudun x ja y koordinaatti
		b) Selvitä siirto oliosta tuloruudun x ja y koordinaatti
		c) Ota talteen lähtöpaikassa oleva nappula
		c) Laita lähtöpaikkaan null
		d) Laita tulopaikkaan juuri talteen ottamasi nappula*/
}

void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista) {

	//käydään lauta läpi eka
	for (int x = 7; x >= 0; x--) {
		for (int y = 0; y < 8; y++) {

			Nappula* n = _lauta[x][y];

			if (n != nullptr) {
				//tallennetaan ruutu
				Ruutu* haluttuRuutu = &Ruutu(x, y);

				//anna siirrot
				n->annaSiirrot(lista, haluttuRuutu, this, n->getVari);
				//???
			}


		}
	}

}

bool Asema::getOnkoMustaDTliikkunut()
{
	return onkoMustaDTliikkunut;
}
bool Asema::getOnkoMustaKTliikkunut()
{
	return onkoMustaKTliikkunut;
}
bool Asema::getOnkoMustaKuningasLiikkunut()
{
	return onkoMustaDTliikkunut;
}
bool Asema::getOnkoValkeaDTliikkunut()
{
	return onkoValkeaDTliikkunut;
}
bool Asema::getOnkoValkeaKTliikkunut()
{
	return onkoValkeaKTliikkunut;
}
bool Asema::getOnkoValkeaKuningasLiikkunut()
{
	return onkoValkeaKuningasLiikkunut;
}
int Asema::getSiirtovuoro()
{
	return siirtovuoro;
}
void Asema::setSiirtovuoro(int vari)
{
	siirtovuoro = vari;
}