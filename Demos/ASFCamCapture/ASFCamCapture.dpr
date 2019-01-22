program ASFCamCapture;

uses
  Forms,
  main in 'main.pas' {VideoForm};

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'ASFCamCapture';
  Application.CreateForm(TVideoForm, VideoForm);
  Application.Run;
end.
