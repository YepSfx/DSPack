object VideoForm: TVideoForm
  Left = 272
  Top = 197
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'ASF Cam Capture'
  ClientHeight = 240
  ClientWidth = 320
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object VideoWindow: TVideoWindow
    Left = 0
    Top = 0
    Width = 320
    Height = 240
    FilterGraph = FilterGraph
    VMROptions.Mode = vmrWindowed
    Color = clBlack
    Align = alClient
  end
  object FilterGraph: TFilterGraph
    Mode = gmCapture
    GraphEdit = True
    LinearVolume = True
    Left = 8
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 168
    Top = 8
    object vDevices: TMenuItem
      Caption = 'Video Devices'
    end
    object aDevices: TMenuItem
      Caption = 'Audio Devices'
    end
    object Profiles: TMenuItem
      Caption = 'Profiles'
    end
    object Capture: TMenuItem
      Caption = 'Capture'
    end
  end
  object vFilter: TFilter
    BaseFilter.data = {00000000}
    FilterGraph = FilterGraph
    Left = 72
    Top = 8
  end
  object ASFWriter: TASFWriter
    FilterGraph = FilterGraph
    Profile = wmp_V80_384Video
    FileName = 'c:\tmp.asf'
    Port = 3333
    MaxUsers = 8
    Left = 40
    Top = 8
  end
  object aFilter: TFilter
    BaseFilter.data = {00000000}
    FilterGraph = FilterGraph
    Left = 104
    Top = 8
  end
  object SaveDialog: TSaveDialog
    Left = 200
    Top = 8
  end
  object SampleGrabber: TSampleGrabber
    FilterGraph = FilterGraph
    MediaType.data = {
      7669647300001000800000AA00389B717DEB36E44F52CE119F530020AF0BA770
      FFFFFFFF0000000001000000809F580556C3CE11BF0100AA0055595A00000000
      0000000000000000}
    Left = 136
    Top = 8
  end
end
