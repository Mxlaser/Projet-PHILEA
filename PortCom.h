#ifndef PORTCOM_H
#define PORTCOM_H

#include "PortComDI.h"

using namespace std;
class PortCom
{


	private:
		bool ouvert;
		bool connecte;
		string com;
		string trame;

	public:
		Rs232 *PortCom1;
		PortCom();
		//~PortCom();
		void ModifierCOM(string mcom);
		bool OuvrirPort();
		void FermerPort();
		bool ConnexionCom();
		void DeconnexionCom();
		void EnvoyerTrame(string trame);
		char * RecevoirTrame();

};
#endif
