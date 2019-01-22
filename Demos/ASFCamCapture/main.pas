unit main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, DXSUtil, StdCtrls, DSPack, DirectShow9, Menus, ExtCtrls;

type

  TVideoForm = class(TForm)
    MainMenu1     : TMainMenu;
    vDevices      : TMenuItem;
    aDevices      : TMenuItem;
    Profiles      : TMenuItem;
    Capture       : TMenuItem;
    SaveDialog    : TSaveDialog;

    FilterGraph   : TFilterGraph;
    vFilter       : TFilter;
    aFilter       : TFilter;
    ASFWriter     : TASFWriter;
    VideoWindow   : TVideoWindow;
    SampleGrabber : TSampleGrabber;

    procedure FormCreate(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);

  private
    { Déclarations privées }
    FaDevNum    : Integer;
    FvDevNum    : Integer;
    FcProfile   : Integer;
    FmState     : Integer;
    FipPort     : Cardinal;
    FFileName   : String;
    FOriginCap  : String;
    function StartCapture(FileName : String) : Boolean;
    function StopCapture()  : Boolean;
    function TakeSanpshot(FileName : String) : Boolean;
  public
    { Déclarations publiques }
    procedure OnSelectVideoDevice(sender: TObject);
    procedure OnSelectAudioDevice(sender: TObject);
    procedure OnSelectProfiles(sender: TObject);
    procedure OnSelectCapture(sender: TObject);
    Procedure OnSelectSnapshot(sender: TObject );
  end;

var
  VideoForm : TVideoForm;

implementation

{$R *.dfm}

var
  vSysDev   : TSysDevEnum;
  aSysDev   : TSysDevEnum;

const IP_PORT       : Cardinal = 32768;
const MAXPROFILES   : Integer = 27;
const ASFFmtStrings : array[0..26] of string = (
                      'wmp_V80_255VideoPDA',              // 0
                      'wmp_V80_150VideoPDA',              // 1
                      'wmp_V80_28856VideoMBR',            // 2
                      'wmp_V80_100768VideoMBR',           // 3
                      'wmp_V80_288100VideoMBR',           // 4
                      'wmp_V80_288Video',                 // 5
                      'wmp_V80_56Video',                  // 6
                      'wmp_V80_100Video',                 // 7
                      'wmp_V80_256Video',                 // 8
                      'wmp_V80_384Video',                 // 9
                      'wmp_V80_768Video',                 //10
                      'wmp_V80_700NTSCVideo',             //11
                      'wmp_V80_1400NTSCVideo',            //12
                      'wmp_V80_384PALVideo',              //13
                      'wmp_V80_700PALVideo',              //14
                      'wmp_V80_288MonoAudio',             //15
                      'wmp_V80_288StereoAudio',           //16
                      'wmp_V80_32StereoAudio',            //17
                      'wmp_V80_48StereoAudio',            //18
                      'wmp_V80_64StereoAudio',            //19
                      'wmp_V80_96StereoAudio',            //20
                      'wmp_V80_128StereoAudio',           //21
                      'wmp_V80_288VideoOnly',             //22
                      'wmp_V80_56VideoOnly',              //23
                      'wmp_V80_FAIRVBRVideo',             //24
                      'wmp_V80_HIGHVBRVideo',             //25
                      'wmp_V80_BESTVBRVideo' );           //26

procedure TVideoForm.FormCreate(Sender: TObject);
var
  i : Integer;
  Device, Prof, Cap : TMenuItem;
begin
  vSysDev:= TSysDevEnum.Create(CLSID_VideoInputDeviceCategory);
  if vSysDev.CountFilters > 0 then
    for i := 0 to vSysDev.CountFilters - 1 do
    begin
      Device          := TMenuItem.Create(vDevices);
      Device.Caption  := vSysDev.Filters[i].FriendlyName;
      Device.Tag      := i;
      Device.OnClick  := OnSelectVideoDevice;
      vDevices.Add(Device);
    end;

  aSysDev:= TSysDevEnum.Create(CLSID_AudioInputDeviceCategory);
  if aSysDev.CountFilters > 0 then
    for i := 0 to aSysDev.CountFilters - 1 do
    begin
      Device          := TMenuItem.Create(vDevices);
      Device.Caption  := aSysDev.Filters[i].FriendlyName;
      Device.Tag      := i;
      Device.OnClick  := OnSelectAudioDevice;
      aDevices.Add(Device);
    end;

  for i := 0 to MAXPROFILES - 1 do
  begin
    Prof              := TMenuItem.Create(Profiles);
    Prof.Caption      := ASFFmtStrings[i];
    Prof.Tag          := i;
    Prof.OnClick      := OnSelectProfiles;
    Profiles.Add(Prof);
  end;

  Cap         := TMenuItem.Create(Capture);
  Cap.Caption := 'Start';
  Cap.Tag     := 0;
  Cap.OnClick := OnSelectCapture;
  Capture.Add(Cap);

  Cap         := TMenuItem.Create(Capture);
  Cap.Caption := 'Stop';
  Cap.Tag     := 1;
  Cap.OnClick := OnSelectCapture;
  Capture.Add(Cap);

  Cap         := TMenuItem.Create(Capture);
  Cap.Caption := 'Snapshot';
  Cap.Tag     := 2;
  Cap.OnClick := OnSelectSnapshot;
  Capture.Add(Cap);

  FaDevNum   :=  0;
  FvDevNum   :=  0;
  FcProfile  :=  0;
  FmState    :=  1;
  FFileNaMe  := '';
  FipPort    := IP_PORT;
  FOriginCap := Caption;

  SaveDialog.DefaultExt     := 'asf';
  SaveDialog.Filter         := 'ASF Format (*.asf)|*.asf';

  aDevices.Items[FaDevNum].Checked := True;
  vDevices.Items[FvDevNum].Checked := True;
  Profiles.Items[FcProfile].Checked:= True;

  Capture.Items[0].Enabled := True;
  Capture.Items[1].Enabled := False;
  Capture.Items[2].Enabled := False;
end;

procedure TVideoForm.OnSelectVideoDevice(sender: TObject);
begin
  vDevices.Items[FvDevNum].Checked := False;
  FvDevNum := TMenuItem(Sender).Tag;
  vDevices.Items[FvDevNum].Checked := True;
end;

procedure TVideoForm.OnSelectAudioDevice(sender: TObject);
begin
  aDevices.Items[FaDevNum].Checked := False;
  FaDevNum := TMenuItem(Sender).Tag;
  aDevices.Items[FaDevNum].Checked := True;;
end;

procedure TVideoForm.OnSelectProfiles(sender: TObject);
begin
  Profiles.Items[FcProfile].Checked := False;
  FcProfile := TMenuItem(Sender).Tag;
  Profiles.Items[FcProfile].Checked := True;
end;

procedure TVideoForm.OnSelectCapture(sender: TObject);
  var OriginalStage, SelectStage : Integer;
begin

  OriginalStage := FmState;
  SelectStage   := TMenuItem(Sender).Tag;

  case SelectStage of
    0:begin         //Start Capture
        if FmState <> SelectStage then
        begin
           FmState := SelectStage;
           Capture.Items[0].Enabled := False;
           Capture.Items[1].Enabled := True;
           Capture.Items[2].Enabled := True;

           vDevices.Enabled         := False;
           aDevices.Enabled         := False;
           Profiles.Enabled         := False;
        end;
      end;
    1:begin         //Stop Capture
        if FmState <> SelectStage then
        begin
           FmState := SelectStage;
           Capture.Items[0].Enabled := True;
           Capture.Items[1].Enabled := False;
           Capture.Items[2].Enabled := False;

           vDevices.Enabled         := True;
           aDevices.Enabled         := True;
           Profiles.Enabled         := True;
        end;
      end;
  end;

  case FmState of
  0:begin
      if SaveDialog.Execute() then
      begin
        FFileName := SaveDialog.FileName;
        if not StartCapture(FFileName) then
        begin
          Capture.Items[FmState].Checked := False;
          FmState := OriginalStage;
          Capture.Items[FmState].Checked := True;
          FFileName := '';
        end;
      end else begin
                  FmState := OriginalStage;
                  Capture.Items[0].Enabled := True;
                  Capture.Items[1].Enabled := False;
                  Capture.Items[2].Enabled := False;
                  FFileName := '';

                  vDevices.Enabled         := True;
                  aDevices.Enabled         := True;
                  Profiles.Enabled         := True;
               end;
    end;
  1:begin
      StopCapture();
    end;
  end;

end;

procedure TVideoForm.OnSelectSnapshot(sender: TObject);
begin

//  if SaveSnapDialog.Execute() then
//  begin
//    TakeSanpshot(SaveSnapDialog.FileName);
//  end;

end;

procedure TVideoForm.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  vSysDev.Free;
  aSysDev.Free;

  vDevices.Clear();
  vDevices.Free();

  aDevices.Clear();
  aDevices.Free();

  Profiles.Clear();
  Profiles.Free();

  Capture.Clear();
  Capture.Free();

  FilterGraph.ClearGraph();
  FilterGraph.Active := False;
end;

function TVideoForm.StartCapture(FileName : String) : Boolean;
begin
  FilterGraph.ClearGraph();
  FilterGraph.Active         := False;

  ASFWriter.Profile          := TWMPofiles8(FcProfile);
  ASFWriter.FileName         := FileName;
  ASFWriter.Port             := FipPort;
  vFilter.BaseFilter.Moniker := vSysDev.GetMoniker(FvDevNum);
  aFilter.BaseFilter.Moniker := aSysDev.GetMoniker(FaDevNum);
  FilterGraph.Active         := True;

  case FcProfile of
    15..21:begin       // Audio Only Profile
            try
              with FilterGraph as ICaptureGraphBuilder2 do
              begin
//                CheckDSError(RenderStream(@PIN_CATEGORY_CAPTURE , nil, vFilter as IBaseFilter, nil, ASFWriter as IbaseFilter));
                CheckDSError(RenderStream(@PIN_CATEGORY_CAPTURE , nil, aFilter as IBaseFilter, nil, ASFWriter as IbaseFilter));
//                CheckDSError(RenderStream(@PIN_CATEGORY_PREVIEW , nil, vFilter as IBaseFilter, nil, VideoWindow as IbaseFilter));
              end;
              FilterGraph.Play();
              Caption      := Caption + ' [Audio Only]';
              Result       := True;
            except
              Caption      := FOriginCap;
              Result       := False;
            end;
           end;
    22..23:begin       // Video Only Profile
            try
              with FilterGraph as ICaptureGraphBuilder2 do
              begin
                CheckDSError(RenderStream(@PIN_CATEGORY_CAPTURE , nil, vFilter as IBaseFilter, nil, ASFWriter as IbaseFilter));
//                CheckDSError(RenderStream(@PIN_CATEGORY_CAPTURE , nil, aFilter as IBaseFilter, nil, ASFWriter as IbaseFilter));
                CheckDSError(RenderStream(@PIN_CATEGORY_PREVIEW , nil, vFilter as IBaseFilter, nil, VideoWindow as IbaseFilter));
              end;
              FilterGraph.Play();
              Caption      := Caption + ' [Video Only]';
              Result       := True;
            except
              Caption      := FOriginCap;
              Result       := False;
            end;
           end;
  else
    try
      with FilterGraph as ICaptureGraphBuilder2 do
      begin
        CheckDSError(RenderStream(@PIN_CATEGORY_CAPTURE , nil, vFilter as IBaseFilter, nil, ASFWriter as IbaseFilter));
        CheckDSError(RenderStream(@PIN_CATEGORY_CAPTURE , nil, aFilter as IBaseFilter, nil, ASFWriter as IbaseFilter));
        CheckDSError(RenderStream(@PIN_CATEGORY_PREVIEW , nil, vFilter as IBaseFilter, nil, VideoWindow as IbaseFilter));
      end;
      FilterGraph.Play();
      Caption := FOriginCap;
      Result  := True;
    except
      Caption := FOriginCap;
      Result  := False;
    end;
  end;
end;

function TVideoForm.StopCapture() : Boolean;
begin
  FilterGraph.ClearGraph();
  FilterGraph.Active := False;

  Caption := FOriginCap;
  Result  := True;
end;

function TVideoForm.TakeSanpshot(FileName : String) : Boolean;
begin

  Result := True;
end;

end.
