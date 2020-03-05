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

	siirtovuoro = 0;
	onkoValkeaKuningasLiikkunut = false;
	onkoMustaKuningasLiikkunut = false;
	onkoValkeaDTliikkunut = false;
	onkoValkeaKTliikkunut = false;
	onkoMustaDTliikkunut = false;
	onkoMustaKTliikkunut = false;
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

bool Asema::onkoRuutuUhattu(Ruutu* ruutu, int vastustajanVari)
{
	std::list<Siirto> vastustajaSiirrotLista;
	//Väreittäin käydään läpi kaikki ruudut ja niissä olevan nappulan siirrot kerätään vastustajan siirtolistaan
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->_lauta[i][j] == NULL) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() == vastustajanVari)
				this->_lauta[i][j]->annaSiirrot(vastustajaSiirrotLista, &Ruutu(i, j), this, vastustajanVari); // myöh.sidonta
		}
	}
	// Käydään vastustajaSiirtoLista läpi ja jos sieltä löytyy tarkasteltava ruutu niin tiedetään sen olevan uhattu
	bool ruutuOk = true;
	for (auto s : vastustajaSiirrotLista)
	{
		if (ruutu->getSarake() == s.getLoppuruutu().getSarake() && ruutu->getRivi() == s.getLoppuruutu().getRivi()) {
			ruutuOk = false;
			break;
		}
	}
	return ruutuOk;
}

void Asema::huolehdiKuninkaanShakeista(std::list<Siirto>& lista, int vari)
{
	// poistaa listasta siirrot jotka vievät oman kuninkaan shakkiin
	// käydään saatua siirtolistaa läpi ja jos siellä oleva siirto asettaa kuninkaan shakkiin, 
	// niin siirto poistetaan listasta
	int kuninkaanX;
	int kuninkaanY;
	if (vari == 0) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (this->_lauta[i][j] == NULL)
					continue;
				if (this->_lauta[i][j]->getKoodi() == VK) {
					kuninkaanX = i;
					kuninkaanY = j;
					break;
				}
			}
		}
	}
	if (vari == 1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (this->_lauta[i][j] == NULL)
					continue;
				if (this->_lauta[i][j]->getKoodi() == MK) {
					kuninkaanX = i;
					kuninkaanY = j;
					break;
				}
			}
		}
	}
	// Jotta ei jouduta perumaan oikeaan asemaan tehtyä siirtoa
	Asema testiAsema;
	std::list<Siirto> siivottuSiirrotLista;
	for (auto s : lista) {
		testiAsema = *this;
		testiAsema.paivitaAsema(&s);
		int x, y;

		// Kuninkaan siirto?
		if (s.onkoLyhytLinna())
		{
			x = 6;
			if (this->getSiirtovuoro() == 0)
				y = 0;
			else
				y = 7;
		}
		else if (s.onkoPitkalinna())
		{
			x = 2;
			if (this->getSiirtovuoro() == 0)
				y = 0;
			else
				y = 7;
		}
		else
		{
			Nappula* siirtyva = this->_lauta[s.getAlkuruutu().getSarake()][s.getAlkuruutu().getRivi()];
			if (siirtyva->getKoodi() == VK || siirtyva->getKoodi() == MK)
			{
				x = s.getLoppuruutu().getSarake();
				y = s.getLoppuruutu().getRivi();
			}
			else
			{
				// Ei ole, kuninkaan sijainti sama kuin ennen siirron s kokeilua
				x = kuninkaanX;
				y = kuninkaanY;
			}
		}

		// huom !vari
		if (testiAsema.onkoRuutuUhattu(&Ruutu(x, y), !vari) == true) {
			siivottuSiirrotLista.push_back(s);
		}
	}
	lista = siivottuSiirrotLista;
}

void Asema::annaLinnoitusSiirrot(std::list<Siirto>& lista, int vari)
{
	//// Linnoituksien huomioiminen
	//// 1. Kuningas ei saa olla liikkunut
	//// 2. Torni ei saa olla liikkunut
	//// 3. Kuningas ei saa olla shakattuna
	//// 4. Ruutujen pitää olla tyhjät
	//// 5. Ruudut eivät saa olla uhattuja
	if (vari == 0) {
		//valkean lyhyt linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaKTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 0), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(5, 0), !vari) && this->onkoRuutuUhattu(&Ruutu(6, 0), !vari)
			&& this->_lauta[5][0] == NULL && this->_lauta[6][0] == NULL) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lisätään listaan lyhyt linna
		}
		//valkean pitkä linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaDTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 0), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(3, 0), !vari) && this->onkoRuutuUhattu(&Ruutu(3, 0), !vari)
			&& this->_lauta[3][0] == NULL && this->_lauta[2][0] == NULL) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lisätään listaan lyhyt linna
		}
	}
	if (vari == 1) {
		//mustan lyhyt linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaKTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 7), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(5, 7), !vari) && this->onkoRuutuUhattu(&Ruutu(6, 7), !vari)
			&& this->_lauta[5][7] == NULL && this->_lauta[6][7] == NULL) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lisätään listaan lyhyt linna
		}
		//mustan pitkä linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaDTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 7), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(3, 7), !vari) && this->onkoRuutuUhattu(&Ruutu(3, 7), !vari)
			&& this->_lauta[3][7] == NULL && this->_lauta[2][7] == NULL) {
			//päivitetään listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lisätään listaan lyhyt linna
		}
	}
}

void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista) {
	int vari = this->getSiirtovuoro();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Ei kysele tyhjiltä ruuduilta nappulan nimeä
			if (this->_lauta[i][j] == NULL) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() != vari) {
				continue;
			}
			
			this->_lauta[i][j]->annaSiirrot(lista, &Ruutu(i, j), this, vari); // myöhäinen sidonta!
		}
	}
	this->annaLinnoitusSiirrot(lista, vari);
	this->huolehdiKuninkaanShakeista(lista, vari);

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

double Asema::evaluoi() {

	double arvo = 0;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (this->_lauta[x][y] != NULL) {
				int nappula = this->_lauta[x][y]->getKoodi();

				//Valkoiset
				
					if (nappula == VD)
						arvo += 9;
					else if (nappula == VT)
						arvo += 5;
					else if (nappula == VL)
						arvo += 3.25;
					else if (nappula == VR)
						arvo += 3;
					else if (nappula == VS)
						arvo += 1;
				
				//Mustat
				
					if (nappula == MD)
						arvo -= 9;
					else if (nappula == MT)
						arvo -= 5;
					else if (nappula == ML)
						arvo -= 3.25;
					else if (nappula == MR)
						arvo -= 3;
					else if (nappula == MS)
						arvo -= 1;

			}
		}
	}

	return arvo * 0.02532; // palauttaa arvon -1 ja 1 väliltä

}

MinMaxPaluu Asema::minimax(int syvyys)
{
	MinMaxPaluu paluuarvo;

	// Generoidaan aseman lailliset siirrot.
	std::list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);

	// Rekursion kantatapaus 1: peli on loppu
	if (siirrot.size() == 0)
	{
		// *** TODO ***
		// tutki kumpi voitti ja palauta sen mukainen arvo (tasapeli 0).
		paluuarvo._evaluointiArvo = 0;
		return paluuarvo;
	}

	// Rekursion kantatapaus 2: katkaisusyvyydessä
	if (syvyys == 0)
	{
		paluuarvo._evaluointiArvo = evaluoi();
		return paluuarvo;
	}

	// Rekursioaskel: kokeillaan jokaista laillista siirtoa s
	// (alustetaan paluuarvo huonoimmaksi mahdolliseksi).
	paluuarvo._evaluointiArvo = (siirtovuoro == 0 ? -1000000 : 100000);
	for (auto s : siirrot)
	{
		// Seuraaja-asema (tehdään nykyisessä asemassa siirto s).
		Asema uusi_asema = *this;
		uusi_asema.paivitaAsema(&s);

		// Rekursiivinen kutsu.
		MinMaxPaluu arvo = uusi_asema.minimax(syvyys - 1);

		// Tutkitaan ollaan löydetty uusi paras siirto.
		if
			(
			(siirtovuoro == 0 && arvo._evaluointiArvo > paluuarvo._evaluointiArvo) ||
				(siirtovuoro == 1 && arvo._evaluointiArvo < paluuarvo._evaluointiArvo)
				)
		{
			// Löydettiin uusi paras siirto.
			paluuarvo._evaluointiArvo = arvo._evaluointiArvo;
			paluuarvo._parasSiirto = arvo._parasSiirto;
		}
	}
	return paluuarvo;
}
MinMaxPaluu Asema::maxi(int syvyys)
{
	std::list<Siirto> lista;
	Ruutu kuninkaanRuutu;
	this->annaLaillisetSiirrot(lista);
	double arvo;
	Asema uusiAsema;
	Siirto _parasSiirto;
	MinMaxPaluu paluu;
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (lista.size() == 0) {
		//selvitä kuninkaan ruutu
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (this->_lauta[x][y] != NULL) {
					if (this->_lauta[x][y]->getKoodi() == VK) {
						kuninkaanRuutu.setSarake(x);
						kuninkaanRuutu.setRivi(y);
					}
				}
			}
		}
		//matti
		if (this->onkoRuutuUhattu(&kuninkaanRuutu, 1)) {
			paluu._evaluointiArvo = -1000000;
			return paluu;
		}
		//patti
		if (!this->onkoRuutuUhattu(&kuninkaanRuutu, 1)) {
			paluu._evaluointiArvo = 0;
			return paluu;
		}
	}
	// Jos ei ole matti tai patti niin käy pelipuuta läpi rekursiivisesti
	if (syvyys == 0) { // rekursion kanta
		paluu._evaluointiArvo = this->evaluoi();
		return 	paluu;
	}
	double maximi = -100000; // iso arvo jotta varmasti paranee
	for (auto s : lista) {
		uusiAsema = *this;
		uusiAsema.paivitaAsema(&s);
		arvo = uusiAsema.mini(syvyys - 1)._evaluointiArvo;
		if (arvo > maximi) {
			maximi = arvo;
			_parasSiirto = s;
		}
	}
	paluu._evaluointiArvo = maximi;
	paluu._parasSiirto = _parasSiirto;
	return paluu;
}


MinMaxPaluu Asema::mini(int syvyys)
{
	std::list<Siirto> lista;
	Ruutu kuninkaanRuutu;
	this->annaLaillisetSiirrot(lista);
	double arvo;
	Asema uusiAsema;
	Siirto _parasSiirto;
	MinMaxPaluu paluu;
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (lista.size() == 0) {
		//selvitä kuninkaan ruutu
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (this->_lauta[x][y] != NULL) {
					if (this->_lauta[x][y]->getKoodi() == MK) {
						kuninkaanRuutu.setSarake(x);
						kuninkaanRuutu.setRivi(y);
					}
				}
			}
		}
		//matti
		if (this->onkoRuutuUhattu(&kuninkaanRuutu, 0)) {
			paluu._evaluointiArvo = 1000000;
			return paluu;
		}
		//patti
		if (!this->onkoRuutuUhattu(&kuninkaanRuutu, 0)) {
			paluu._evaluointiArvo = 0;
			return paluu;
		}
	}
	// Jos ei ole matti tai patti niin käy pelipuuta läpi rekursiivisesti
	if (syvyys == 0) { // rekursion kanta
		paluu._evaluointiArvo = this->evaluoi();
		//paluu._parasSiirto = MITÄ
		return 	paluu;
	}
	double minimi = 100000; // iso arvo jotta varmasti paranee
	for (auto s : lista) {
		uusiAsema = *this;
		uusiAsema.paivitaAsema(&s);
		arvo = uusiAsema.maxi(syvyys - 1)._evaluointiArvo;
		if (arvo < minimi) {
			minimi = arvo;
			_parasSiirto = s;
		}
	}
	paluu._evaluointiArvo = minimi;
	paluu._parasSiirto = _parasSiirto;
	return paluu;
}
