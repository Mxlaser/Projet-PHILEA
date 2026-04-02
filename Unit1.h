//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "TrameVideo.h"
#include "PortCom.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <fstream>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <string>


using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Button3;
	TShape *Shape1;
	TShape *Shape2;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label2;
	TButton *Button7;
	TButton *Button8;
	TLabel *Label3;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TRichEdit *RichEdit1;
	TEdit *Edit2;
	TLabel *Label4;
	TTimer *Timer1;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Button13;
	TButton *Button14;
	TTimer *Timer2;
	TImage *Image2;
	TImage *Image1;
	TButton *Button15;
	TTimer *Timer3;
	TEdit *Edit7;
	TLabel *Label9;
	TTimer *Timer4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
private:	// Déclarations utilisateur
	PortCom port;
	TrameVideo video;
	ifstream f;
	string trame;
	bool clic;
	int tempo;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
