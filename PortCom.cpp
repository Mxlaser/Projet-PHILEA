#include "PortCom.h"

PortCom::PortCom()
{
	ouvert = false;
	connecte = false;
}

void PortCom::ModifierCOM(string mcom)
{
    com = mcom;
}

bool PortCom::OuvrirPort()
{
	PortCom1 = new Rs232(com);
	PortCom1->configurer(CBR_57600,8,NOPARITY,ONESTOPBIT);
	PortCom1->ouvrir();
	if(PortCom1->envoyer(0x02)!= -1)
	{
        ouvert = true;
	}
	return ouvert;
}

bool PortCom::ConnexionCom()
{
	char config[10] = "CFFFFFF\r";
	if(ouvert)
	{
		if(PortCom1->envoyer('v') != -1)
		{   //v
			connecte = true;
			PortCom1->envoyer('\r');
			Sleep(100);
			RecevoirTrame();

			//CFFFFFF. 3fois
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < strlen(config); j++)
				{
					PortCom1->envoyer(config[j]);
				}

				Sleep(100);
				RecevoirTrame();
			}

			//S6.
			PortCom1->envoyer('S');
			PortCom1->envoyer('6');

			PortCom1->envoyer('\r');
			Sleep(100);
			RecevoirTrame();

			//Z1.
			PortCom1->envoyer('Z');
			PortCom1->envoyer('1');
			PortCom1->envoyer('\r');
			Sleep(100);
			RecevoirTrame();

			//O.
			PortCom1->envoyer('O');
			PortCom1->envoyer('\r');
			Sleep(100);
			RecevoirTrame();

			return true;
		}
		else
		{
            return false;
        }
	}
}

void PortCom::FermerPort()
{
	PortCom1->fermer();
	delete PortCom1;
}

void PortCom::DeconnexionCom()
{
	if(ouvert)
	{
		PortCom1->envoyer('C');
		PortCom1->envoyer('\r');
		Sleep(100);
		RecevoirTrame();
		connecte = false;
	}
}

void PortCom::EnvoyerTrame(string trame)
{
	for(int i = 0; i < strlen(trame.c_str()); i++)
	{
		PortCom1->envoyer(trame[i]);
	}
}

char * PortCom::RecevoirTrame()
{
    char buf[100], c;
	for(int i = 0; i < 9; i++)
	{
		PortCom1->recevoir(&c);
		buf[i] = c;
	}
	buf[9] = 0;

	return buf;
}
