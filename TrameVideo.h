#ifndef TRAMEVIDEO_H
#define TRAMEVIDEO_H

#include "SNClientTCP.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include <vcl.h>

using namespace std;
class TrameVideo
{
	private:
		SNClientTCP CO, CO2;
		ofstream o, O;
		ifstream f, F;
		string temp, ipCam1, ipCam2;
		bool debut, fin, premiereTrame;
		bool debut2, fin2, premiereTrame2;
		char req[1500];
		char req2[1500];
		char nom [500];
		char nom2 [500];
		unsigned char donnee[1500];
		unsigned char donnee2[1500];
		int numImage, numImage2;
		TImage* image1;
		TImage* image2;

	public:
		void PImage(TImage* img) {image1 = img;};
		void PImage2(TImage* img2) {image2 = img2;};
		TrameVideo();
		void ConnexionVLC();
		void ConnexionVideo();
		void ConnexionVideo2();
		void Video();
		void Video2();
};
#endif