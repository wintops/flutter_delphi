unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm2 = class(TForm)
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;


function start:integer; stdcall;
implementation

{$R *.dfm}

const
  DLLName = 'Dll1.dll';

function start:integer; external DLLName;

procedure TForm2.Button1Click(Sender: TObject);
begin
   start;
end;

end.
