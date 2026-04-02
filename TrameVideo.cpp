#include "TrameVideo.h"

TrameVideo::TrameVideo()
{
	strcpy(req, "GET / HTTP/1.1\r\nHost: 127.0.0.1:9912\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nsec-ch-ua: \"Google Chrome\";v=\"111\", \"Not(A:Brand\";v=\"8\", \"Chromium\";v=\"111\"\r\nsec-ch-ua-mobile: ?0\r\nsec-ch-ua-platform: \"Windows\"\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\r\nSec-Fetch-Site: none\r\nSec-Fetch-Mode: navigate\r\nSec-Fetch-User: ?1\r\nSec-Fetch-Dest: document\r\nAccept-Encoding: gzip, deflate, br\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n");
	strcpy(req2, "GET / HTTP/1.1\r\nHost: 127.0.0.1:9913\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nsec-ch-ua: \"Google Chrome\";v=\"111\", \"Not(A:Brand\";v=\"8\", \"Chromium\";v=\"111\"\r\nsec-ch-ua-mobile: ?0\r\nsec-ch-ua-platform: \"Windows\"\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\r\nSec-Fetch-Site: none\r\nSec-Fetch-Mode: navigate\r\nSec-Fetch-User: ?1\r\nSec-Fetch-Dest: document\r\nAccept-Encoding: gzip, deflate, br\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n");
	nom[500];
	nom2[500];
	numImage = 0;
	numImage2 = 0;
	sprintf(nom, "Image%d.jpg", numImage++);
	sprintf(nom2, "2Image%d.jpg", numImage2++);
	o.open(nom, ios_base::binary);
	O.open(nom2, ios_base::binary);
	debut = false;
	fin = false;
	premiereTrame = false;
	debut2 = false;
	fin2 = false;
	premiereTrame2 = false;
	f.open("PHILEA2023.config");
    f >> temp >> temp;
	f >> temp >> ipCam1;
	f >> temp >> ipCam2;
	f.close();
	//ShowMessage((ipCam1+" "+ipCam2).c_str()); //Debug
}

void TrameVideo::ConnexionVLC()
{
	char commande[500], commandeBis[500];
	sprintf(commande, "vlc -vvv -Idummy rtsp://admin:admin@%s:1554/live/ch1 --sout #transcode{vcodec=MJPG,venc=ffmpeg{strict=1},fps=10,width=640,height=360}:standard{access=http{mime=multipart/x-mixed-replace;boundary=--7b3cc56e5f51db803f790dad720ed50a},mux=mpjpeg,dst=:9913/}", ipCam1.c_str());
	WinExec(commande, 0);
	sprintf(commandeBis, "vlc -vvv -Idummy rtsp://admin:admin@%s:554/live/ch1 --sout #transcode{vcodec=MJPG,venc=ffmpeg{strict=1},fps=10,width=640,height=360}:standard{access=http{mime=multipart/x-mixed-replace;boundary=--7b3cc56e5f51db803f790dad720ed50a},mux=mpjpeg,dst=:9912/}", ipCam2.c_str());
	WinExec(commandeBis, 0);
}

void TrameVideo::ConnexionVideo()
{
	CO.SeConnecterAUnServeur("127.0.0.1", 9913);
	CO.Envoyer(req, strlen(req));
}

void TrameVideo::ConnexionVideo2()
{
	CO2.SeConnecterAUnServeur("127.0.0.1", 9912);
	CO2.Envoyer(req2, strlen(req2));
}

void TrameVideo::Video()
{
	int P;
	P = CO.Recevoir(donnee, 1500);
	if(!debut)
	{
		for(int i = 0; i < P; i++)
		 {  if(donnee[i] == 0xff && donnee[i+1] == 0xd8)
			{
				debut = true;
				premiereTrame = true;
				for(int j = i; j < P; j++)
				{
					o.put(donnee[j]);
				}
			}
		 }
	}
	if(debut && !premiereTrame)
	{
		for(int i = 0; i < P; i++)
		{
			if(donnee[i] == 0xff && donnee[i+1] == 0xd9)
			{
				fin = true;
				debut = false;
				P = i + 2;
			}
		}
		for(int j = 0; j < P; j++)
		{
			o.put(donnee[j]);
		}
		if(fin)
		{
			fin = false;
			o.close();
			f.open(nom,ios_base::binary);
			unsigned char c1 = f.get();
			unsigned char c2 = f.get();
			f.close();
			if(c1 == 0xff && c2 == 0xd8)
			{
				image1->Picture->LoadFromFile(nom);
			}
			sprintf(nom, "Image%d.jpg", numImage);
			numImage = (numImage + 1)%21;
			o.open(nom, ios_base::binary);
		}
	}
	premiereTrame = false;
}

void TrameVideo::Video2()
{
	int R;
	R = CO2.Recevoir(donnee2, 1500);
	if(!debut2)
	{
		for(int i = 0; i < R; i++)
		 {  if(donnee2[i] == 0xff && donnee2[i+1] == 0xd8)
			{
				debut2 = true;
				premiereTrame2 = true;
				for(int j = i; j < R; j++)
				{
					O.put(donnee2[j]);
				}
			}
		 }
	}
	if(debut2 && !premiereTrame2)
	{
		for(int i = 0; i < R; i++)
		{
			if(donnee2[i] == 0xff && donnee2[i+1] == 0xd9)
			{
				fin2 = true;
				debut2 = false;
				R = i + 2;
			}
		}
		for(int j = 0; j < R; j++)
		{
			O.put(donnee2[j]);
		}
		if(fin2)
		{
			fin2 = false;
			O.close();
			F.open(nom2,ios_base::binary);
			unsigned char C1 = F.get();
			unsigned char C2 = F.get();
			F.close();
			if(C1 == 0xff && C2 == 0xd8)
			{
				image2->Picture->LoadFromFile(nom2);
			}
			sprintf(nom2, "2Image%d.jpg", numImage2);
			numImage2 = (numImage2 + 1)%21;
			O.open(nom2, ios_base::binary);
		}
	}
	premiereTrame2 = false;
}