#include <iostream>
#include "asema.h"
#include "nappula.h"

Nappula* Asema::vk = new Nappula(L"\u2654", 0, VK);
Nappula* Asema::vd = new Nappula(L"\u2655", 0, VD);
Nappula* Asema::vt = new Nappula(L"\u2656", 0, VT);
Nappula* Asema::vl = new Nappula(L"\u2657", 0, VL);
Nappula* Asema::vr = new Nappula(L"\u2658", 0, VR);
Nappula* Asema::vs = new Nappula(L"\u2659", 0, VS);

Nappula* Asema::mk = new Nappula(L"\u265A", 1, MK);
Nappula* Asema::md = new Nappula(L"\u265B", 1, MD);
Nappula* Asema::mt = new Nappula(L"\u265C", 1, MT);
Nappula* Asema::ml = new Nappula(L"\u265D", 1, ML);
Nappula* Asema::mr = new Nappula(L"\u265E", 1, MR);
Nappula* Asema::ms = new Nappula(L"\u265F", 1, MS);


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