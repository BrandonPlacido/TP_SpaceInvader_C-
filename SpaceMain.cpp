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
	Laser laserVaisseau;
	UIKit Cadre;
	
	Cadre.cadre(0, 0, 60, 45, FOREGROUND_GREEN);
	Cadre.curseurVisible(false);
	char touche;

	while (true) {
		
		
			 if (_kbhit()) {
				touche = _getch();

				//Apparision et mouvement du Laser du Vaisseau
				
				if (touche == 'a') {
					laserVaisseau.startLaser(Vaisseau.coord.getPositionX());
					if (laserVaisseau.coord.getPositionY() > 1) {
						laserVaisseau.moveLaser();
						Sleep(50);

						
					}
					//Destruction du laser
					if(laserVaisseau.coord.getPositionY() == 1)
					laserVaisseau.removeLaser();
				}



				//Mouvement du vaisseau

				Vaisseau.modifierPosition(touche);
				if (Vaisseau.coord.getPositionX() < 1) {
					Vaisseau.coord.setPositionX(0);

				}else  if (Vaisseau.coord.getPositionX() > 59) {

					Vaisseau.coord.setPositionX(59);
				}

			

				

			}
		}
	


	return 0;
}