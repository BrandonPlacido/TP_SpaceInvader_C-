#include "Vaisseau.h"
#include"Laser.h"
#include "ExtraTerrestre.h"
#include "Martien.h"
#include "Coord.h"
#include "UIKit.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>




int main()
{

	Vaisseau Vaisseau;




	Laser laserJoueur;
	laserJoueur.isAlive = false;




	UIKit Cadre;

	Cadre.cadre(0, 0, 60, 45, FOREGROUND_GREEN);
	Cadre.curseurVisible(false);
	char touche;

	while (true) {


		if (_kbhit()) {
			touche = _getch();


			if (touche == 'a') {
				if (!laserJoueur.isAlive) {
					laserJoueur.startLaser(Vaisseau.coord.getPositionX());
				}
			}
			else {
				Vaisseau.modifierPosition(touche);
			}

			
		}
		if (laserJoueur.isAlive)
			laserJoueur.moveLaser();

		Sleep(100);
	}
	return 0;
}