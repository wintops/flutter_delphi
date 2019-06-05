unit Unit2;

{$IFDEF FPC}
  {$MODE Delphi}
{$ENDIF}

interface

uses
  {$IFnDEF FPC}
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;
{$ELSE}
 Classes,  Forms,  StdCtrls;
{$ENDIF}


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

{$IFnDEF FPC}
  {$R *.dfm}
{$ELSE}
  {$R *.lfm}
{$ENDIF}

const
  DLLName = 'Dll1.dll';

function start:integer; external DLLName;

procedure TForm2.Button1Click(Sender: TObject);
begin
   start;
end;

end.
