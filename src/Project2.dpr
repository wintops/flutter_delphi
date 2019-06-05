program Project2;

{$IFDEF FPC}
{$MODE Delphi}
{$ENDIF}

uses
{$IFDEF FPC}
  Interfaces,
{$ENDIF}
  Forms,
  Unit2 in 'Unit2.pas' {Form2};

{$R *.res}

begin
{$IFDEF FPC}
  RequireDerivedFormResource := True;
  Application.Scaled := True;
{$ENDIF}
  Application.Initialize;

  Application.CreateForm(TForm2, Form2);
  Application.Run;

end.
