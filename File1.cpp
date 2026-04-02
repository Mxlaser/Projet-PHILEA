#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <string>
#include <iostream>

#include "PortComDI.h"
#include "PortCom.h"

using namespace std;
 int _tmain(int argc, _TCHAR* argv[])
{
	PortCom port;
	string com;
	char choix;

	cout << "Entrez port COM (exemple : COM3) : ";
	cin >> com;
	port.ModifierCOM(com);

	if(port.OuvrirPort());
	{
        port.ConnexionCom();
	}

	cout << "Voulez-vous deployer le bras ? (y/n) : ";
	cin >> choix;
	if(choix == 'y')
	{
		port.EnvoyerTrame();
	}

	port.DeconnexionCom();
	port.FermerPort();

	return 0;
}
