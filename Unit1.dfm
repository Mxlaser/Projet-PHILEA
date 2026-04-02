object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 698
  ClientWidth = 823
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 45
    Width = 101
    Height = 13
    Caption = 'Indiquez le port COM'
  end
  object Shape1: TShape
    Left = 279
    Top = 64
    Width = 20
    Height = 20
    Pen.Style = psClear
    Visible = False
  end
  object Shape2: TShape
    Left = 105
    Top = 112
    Width = 20
    Height = 20
    Pen.Style = psClear
    Visible = False
  end
  object Label2: TLabel
    Left = 24
    Top = 16
    Width = 40
    Height = 13
    Caption = 'MUPUS'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 248
    Width = 41
    Height = 13
    Caption = 'ROMAP'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 72
    Top = 223
    Width = 94
    Height = 13
    Caption = 'Temps en secondes'
  end
  object Label5: TLabel
    Left = 24
    Top = 333
    Width = 46
    Height = 13
    Caption = 'Cam'#233'ra 1'
  end
  object Label6: TLabel
    Left = 176
    Top = 333
    Width = 46
    Height = 13
    Caption = 'Cam'#233'ra 2'
  end
  object Label7: TLabel
    Left = 111
    Top = 333
    Width = 20
    Height = 13
    Caption = 'Port'
  end
  object Label8: TLabel
    Left = 263
    Top = 333
    Width = 20
    Height = 13
    Caption = 'Port'
  end
  object Image1: TImage
    Left = 26
    Top = 392
    Width = 385
    Height = 289
  end
  object Image2: TImage
    Left = 417
    Top = 392
    Width = 385
    Height = 289
  end
  object Label9: TLabel
    Left = 242
    Top = 221
    Width = 23
    Height = 13
    Caption = 'D'#233'lai'
  end
  object Button1: TButton
    Left = 224
    Top = 62
    Width = 49
    Height = 25
    Caption = 'Port'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 24
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 24
    Top = 64
    Width = 187
    Height = 21
    TabOrder = 2
  end
  object Button3: TButton
    Left = 136
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Deployer'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 224
    Top = 112
    Width = 75
    Height = 25
    Caption = 'L'#226'cher'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 136
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Ranger'
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 224
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Verrouiller'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 24
    Top = 280
    Width = 75
    Height = 25
    Caption = 'D'#233'ployer'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 136
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Ranger'
    TabOrder = 8
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 136
    Top = 192
    Width = 75
    Height = 25
    Caption = 'D'#233'mo'
    TabOrder = 9
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 24
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Etat'
    TabOrder = 10
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 24
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Vibration'
    TabOrder = 11
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 224
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Etat'
    TabOrder = 12
    OnClick = Button12Click
  end
  object RichEdit1: TRichEdit
    Left = 328
    Top = 64
    Width = 185
    Height = 241
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'RichEdit1')
    ParentFont = False
    TabOrder = 13
    Zoom = 100
  end
  object Edit2: TEdit
    Left = 105
    Top = 194
    Width = 25
    Height = 21
    MaxLength = 2
    TabOrder = 14
  end
  object Edit3: TEdit
    Left = 24
    Top = 352
    Width = 81
    Height = 21
    TabOrder = 15
  end
  object Edit4: TEdit
    Left = 176
    Top = 352
    Width = 81
    Height = 21
    TabOrder = 16
  end
  object Edit5: TEdit
    Left = 111
    Top = 352
    Width = 34
    Height = 21
    TabOrder = 17
  end
  object Edit6: TEdit
    Left = 263
    Top = 352
    Width = 33
    Height = 21
    TabOrder = 18
  end
  object Button13: TButton
    Left = 328
    Top = 350
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 19
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 432
    Top = 350
    Width = 75
    Height = 25
    Caption = 'Vid'#233'o'
    TabOrder = 20
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 513
    Top = 350
    Width = 75
    Height = 25
    Caption = 'Vid'#233'o'
    TabOrder = 21
    OnClick = Button15Click
  end
  object Edit7: TEdit
    Left = 217
    Top = 194
    Width = 82
    Height = 21
    TabOrder = 22
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 488
    Top = 16
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer2Timer
    Left = 536
    Top = 16
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer3Timer
    Left = 584
    Top = 16
  end
  object Timer4: TTimer
    Enabled = False
    Interval = 5500
    OnTimer = Timer4Timer
    Left = 632
    Top = 16
  end
end
