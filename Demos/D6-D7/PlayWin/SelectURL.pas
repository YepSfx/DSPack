unit SelectURL;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TFormSelectURL = class(TForm)
    btOK: TButton;
    btCancel: TButton;
    URL: TEdit;
  private
    { D�clarations priv�es }
  public
    { D�clarations publiques }
  end;

var
  FormSelectURL: TFormSelectURL;

implementation

{$R *.dfm}

end.
