//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int etape;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	etape = 0;
	string temp;
	string portCom, ipCam1, ipCam2, portCam1, portCam2, tempo;

	RichEdit1->Text = "";
	f.open("PHILEA2023.config");
	f >> temp >> portCom;
	f >> temp >> ipCam1;
	f >> temp >> ipCam2;
	f >> temp >> portCam1;
	f >> temp >> portCam2;
	f >> temp >> tempo;

	Timer4->Interval = AnsiString(tempo.c_str()).ToInt();
	Edit1->Text = AnsiString(portCom.c_str());
	Edit3->Text = AnsiString(ipCam1.c_str());
	Edit4->Text = AnsiString(ipCam2.c_str());
	Edit5->Text = AnsiString(portCam1.c_str());
	Edit6->Text = AnsiString(portCam2.c_str());
	Edit7->Text = Timer4->Interval;
	video.PImage(Image1);
	video.PImage2(Image2);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	string mcom = AnsiString(Edit1->Text).c_str(); //ouverture port COM
	port.ModifierCOM(mcom);
	if(port.OuvrirPort())
	{
		Shape1->Visible = true;
		Shape1->Brush->Color = clGreen;
	}
	else
	{
		Shape1->Visible = true;
		Shape1->Brush->Color = clRed;
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	bool connexion;
	if(clic == 0) //connexion
	{
	   if(connexion = port.ConnexionCom())
	   {
			Button2->Caption = "Deconnexion";
			Shape2->Visible = true;
			Shape2->Brush->Color = clGreen;
			clic = true;
	   }
	   else if (connexion == false)
	   {
			Shape2->Visible = true;
			Shape2->Brush->Color = clRed;
	   }
	}
	else if(clic == 1) //deconnexion
	{
		port.DeconnexionCom();
		Button2->Caption = "Connexion";
		Shape2->Visible = true;
		Shape2->Brush->Color = clRed;
		clic = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	trame = "T000007200\r";	//déployer
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	trame = "T000007400\r";	//lacher
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	trame = "T000007500\r";	//ranger
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	trame = "T000007600\r";	//verrouiller
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	trame = "T000006300\r";	//déployer ROMAP
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	trame = "T000006200\r";	//ranger ROMAP
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	trame = "T000007100\r";	//demande d'état
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	trame = "T000007301";	//temps de vibration
	trame += AnsiString(Edit2->Text).c_str();
	trame += "\r";
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	trame = "T000006100\r";	//demande d'état
	port.EnvoyerTrame(trame);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	char c;
	char reception[500];
	int i = 0, n;
	do
	{
		n = port.PortCom1->recevoir(&c);
		if(n >= 0)
		{
			reception[i++]=c;
		}
	}while(n >= 0);
	reception[i]=0;

	if(i) //---Gerer affichage message dans un 2e timer
	{
		string str(reception);
		std::size_t position = str.find("10");
		if(position != std::string::npos)
		{
			if(position == 5 || position == 3)
			{
				RichEdit1->Lines->Add("Bien reçu");
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	video.ConnexionVLC();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	video.ConnexionVideo();
	Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	video.Video();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	video.ConnexionVideo2();
	Timer3->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	video.Video2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	switch (etape++)	//machine d'etat
	{
		case 0:
		trame = "T000006300\r";	//deployer romap
		port.EnvoyerTrame(trame);
		Timer1->Enabled = true;
		break;
		case 1:
		trame = "T000007200\r";	//deployer mupus
		port.EnvoyerTrame(trame);
		Timer1->Enabled = true;
		Timer4->Interval *= 2;
		break;
		case 2:
		trame = "T000007400\r";	//lacher marteau + aimant on
		port.EnvoyerTrame(trame);
		Timer1->Enabled = true;
		Timer4->Interval /= 2;
		break;
		case 3:
		trame = "T000007500\r";	//ranger mupus
		port.EnvoyerTrame(trame);
		Timer1->Enabled = true;
		Timer4->Interval *= 2;
		break;
		case 4:
		trame = "T00000730109\r";	//viber 10s
		port.EnvoyerTrame(trame);
		Timer1->Enabled = true;
		break;
		case 5:
		trame = "T000007600\r";	//fermer verrou + aimant off
		port.EnvoyerTrame(trame);
		Timer1->Enabled = true;
		Timer4->Interval /= 2;
		break;
		case 6:
		trame = "T000006200\r";	//ranger romap
		port.EnvoyerTrame(trame);
		Timer1->Enabled = true;
		etape = 0;
		Timer4->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Timer4->Enabled=true;
}
//---------------------------------------------------------------------------

