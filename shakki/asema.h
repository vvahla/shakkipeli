#pragma once

#include <list>
#include <string>
#include "siirto.h"


// Ns. "forward declaration". Nyt Asema-luokassa voidaa esitell‰ Nappula-osoittimia ilman,
// ett‰ nappula.h -tiedostoa t‰ytyy includoida.
class Nappula;


// Asema sis‰lt‰‰ kaiken tarvittavan informaation pelitilanteen kuvaamiseksi
// (nappuloiden sijainti, siirtovuoro, linnoitusoikeudet jne.).
class Asema
{

public:
	// Pelilauta sis‰lt‰‰ osoittimet kunkin ruudun nappula-olioon (nullptr/NULL/0 jos ruutu on tyhj‰).
	// Public-m‰‰reell‰, koska t‰t‰ k‰ytet‰‰n paljon muualla.
	Nappula* _lauta[8][8];

	// Nappula-oliot. Huomaa, ett‰ samaa nappulaa voidaan k‰ytt‰‰ useissa eri ruuduissa.
	// M‰‰ritelty static-m‰‰reell‰, joten nappulat ovat kaikkien lauta-olioiden "yhteisk‰ytˆss‰"
	// (suorituskyvyn vuoksi).
	static Nappula *vk, *vd, *vt, *vl, *vr, *vs;	// Valkeat nappulat.
	static Nappula *mk, *md, *mt, *ml, *mr, *ms;	// Mustat nappulat.

	// Ohestalyˆnti‰ varten (-1 = sotilaan kaksoisaskelta ei tapahtunut edellisell‰ siirrolla).
	int kaksoisaskelSarakkeella = -1;


	Asema(); // Asettaa alkuaseman.
	void paivitaAsema(Siirto* siirto);

	int getSiirtovuoro();
	void setSiirtovuoro(int vari);
	bool getOnkoValkeaKuningasLiikkunut();
	bool getOnkoMustaKuningasLiikkunut();
	bool getOnkoValkeaDTliikkunut();
	bool getOnkoValkeaKTliikkunut();
	bool getOnkoMustaKTliikkunut();
	bool getOnkoMustaDTliikkunut();	
	void annaLaillisetSiirrot(std::list<Siirto>& lista);
	// sis‰ll‰ kutsutaan getSiirtovuoro() >> looppi joka k‰y koko laudan l‰pi ja tsekkaa if (getSiirtovuoro() == nappulan.getv‰ri()) >> kutsuu sille nappulalle annasiirrot

private:
	int siirtovuoro;
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTliikkunut;
	bool onkoValkeaKTliikkunut;
	bool onkoMustaDTliikkunut;
	bool onkoMustaKTliikkunut;

};
