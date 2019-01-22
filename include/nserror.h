/*++

  Microsoft Windows Media Technology
  Copyright (C) Microsoft Corporation.  All Rights Reserved.

Module Name:

    nserror.mc

Abstract:

    Definitions for Windows Media events.

Author:


Revision History:

Notes:

    This file is used by the MC tool to generate the nserror.h file

**************************** READ ME ******************************************

 Here are the commented error ranges for the Windows Media Technologies Group


 LEGACY RANGES

     0  -  199 = General NetShow errors

   200  -  399 = NetShow error events

   400  -  599 = NetShow monitor events

   600  -  799 = NetShow IMmsAutoServer errors

  1000  - 1199 = NetShow MCMADM errors


 NEW RANGES

  2000 -  2999 = ASF (defined in ASFERR.MC)

  3000 -  3999 = Windows Media SDK

  4000 -  4999 = Windows Media Player

  5000 -  5999 = Windows Media Server

  6000 -  6999 = Windows Media HTTP/RTSP result codes (defined in NETERROR.MC)

  7000 -  7999 = Windows Media Tools

  8000 -  8999 = Windows Media Content Discovery

  9000 -  9999 = Windows Media Real Time Collaboration

 10000 - 10999 = Windows Media Digital Rights Management

 11000 - 11999 = Windows Media Setup

 12000 - 12999 = Windows Media Networking

 13000 - 13999 = Windows Media Client Media Services

**************************** READ ME ******************************************

--*/

#ifndef _NSERROR_H
#define _NSERROR_H


#define STATUS_SEVERITY(hr)  (((hr) >> 30) & 0x3)

#ifdef RC_INVOKED
#define _HRESULT_TYPEDEF_(_sc) _sc
#else // RC_INVOKED
#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#endif // RC_INVOKED


/////////////////////////////////////////////////////////////////////////
//
// NETSHOW Success Events
//
/////////////////////////////////////////////////////////////////////////

//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_NS_WIN32                0x7
#define FACILITY_NS                      0xD


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: NS_S_CALLPENDING
//
// MessageText:
//
//  The requested operation is pending completion.%0
//
#define NS_S_CALLPENDING                 _HRESULT_TYPEDEF_(0x000D0000L)

//
// MessageId: NS_S_CALLABORTED
//
// MessageText:
//
//  The requested operation was aborted by the client.%0
//
#define NS_S_CALLABORTED                 _HRESULT_TYPEDEF_(0x000D0001L)

//
// MessageId: NS_S_STREAM_TRUNCATED
//
// MessageText:
//
//  The stream was purposefully stopped before completion.%0
//
#define NS_S_STREAM_TRUNCATED            _HRESULT_TYPEDEF_(0x000D0002L)


/////////////////////////////////////////////////////////////////////////
//
// NETSHOW Warning Events
//
/////////////////////////////////////////////////////////////////////////

//
// MessageId: NS_W_SERVER_BANDWIDTH_LIMIT
//
// MessageText:
//
//  The maximum filebitrate value specified is greater than the server's configured maximum bandwidth.%0
//
#define NS_W_SERVER_BANDWIDTH_LIMIT      _HRESULT_TYPEDEF_(0x800D0003L)

//
// MessageId: NS_W_FILE_BANDWIDTH_LIMIT
//
// MessageText:
//
//  The maximum bandwidth value specified is less than the maximum filebitrate.%0
//
#define NS_W_FILE_BANDWIDTH_LIMIT        _HRESULT_TYPEDEF_(0x800D0004L)


/////////////////////////////////////////////////////////////////////////
//
// NETSHOW Error Events
//
/////////////////////////////////////////////////////////////////////////

//
// MessageId: NS_E_NOCONNECTION
//
// MessageText:
//
//  There is no connection established with the Windows Media server. The operation failed.%0
//
#define NS_E_NOCONNECTION                _HRESULT_TYPEDEF_(0xC00D0005L)

//
// MessageId: NS_E_CANNOTCONNECT
//
// MessageText:
//
//  Unable to establish a connection to the server.%0
//
#define NS_E_CANNOTCONNECT               _HRESULT_TYPEDEF_(0xC00D0006L)

//
// MessageId: NS_E_CANNOTDESTROYTITLE
//
// MessageText:
//
//  Unable to destroy the title.%0
//
#define NS_E_CANNOTDESTROYTITLE          _HRESULT_TYPEDEF_(0xC00D0007L)

//
// MessageId: NS_E_CANNOTRENAMETITLE
//
// MessageText:
//
//  Unable to rename the title.%0
//
#define NS_E_CANNOTRENAMETITLE           _HRESULT_TYPEDEF_(0xC00D0008L)

//
// MessageId: NS_E_CANNOTOFFLINEDISK
//
// MessageText:
//
//  Unable to offline disk.%0
//
#define NS_E_CANNOTOFFLINEDISK           _HRESULT_TYPEDEF_(0xC00D0009L)

//
// MessageId: NS_E_CANNOTONLINEDISK
//
// MessageText:
//
//  Unable to online disk.%0
//
#define NS_E_CANNOTONLINEDISK            _HRESULT_TYPEDEF_(0xC00D000AL)

//
// MessageId: NS_E_NOREGISTEREDWALKER
//
// MessageText:
//
//  There is no file parser registered for this type of file.%0
//
#define NS_E_NOREGISTEREDWALKER          _HRESULT_TYPEDEF_(0xC00D000BL)

//
// MessageId: NS_E_NOFUNNEL
//
// MessageText:
//
//  There is no data connection established.%0
//
#define NS_E_NOFUNNEL                    _HRESULT_TYPEDEF_(0xC00D000CL)

//
// MessageId: NS_E_NO_LOCALPLAY
//
// MessageText:
//
//  Failed to load the local play DLL.%0
//
#define NS_E_NO_LOCALPLAY                _HRESULT_TYPEDEF_(0xC00D000DL)

//
// MessageId: NS_E_NETWORK_BUSY
//
// MessageText:
//
//  The network is busy.%0
//
#define NS_E_NETWORK_BUSY                _HRESULT_TYPEDEF_(0xC00D000EL)

//
// MessageId: NS_E_TOO_MANY_SESS
//
// MessageText:
//
//  The server session limit was exceeded.%0
//
#define NS_E_TOO_MANY_SESS               _HRESULT_TYPEDEF_(0xC00D000FL)

//
// MessageId: NS_E_ALREADY_CONNECTED
//
// MessageText:
//
//  The network connection already exists.%0
//
#define NS_E_ALREADY_CONNECTED           _HRESULT_TYPEDEF_(0xC00D0010L)

//
// MessageId: NS_E_INVALID_INDEX
//
// MessageText:
//
//  Index %1 is invalid.%0
//
#define NS_E_INVALID_INDEX               _HRESULT_TYPEDEF_(0xC00D0011L)

//
// MessageId: NS_E_PROTOCOL_MISMATCH
//
// MessageText:
//
//  There is no protocol or protocol version supported by both the client and the server.%0
//
#define NS_E_PROTOCOL_MISMATCH           _HRESULT_TYPEDEF_(0xC00D0012L)

//
// MessageId: NS_E_TIMEOUT
//
// MessageText:
//
//  The server, a computer set up to offer multimedia content to other computers, could not handle your request for multimedia content in a timely manner.  Please try again later.%0
//
#define NS_E_TIMEOUT                     _HRESULT_TYPEDEF_(0xC00D0013L)

//
// MessageId: NS_E_NET_WRITE
//
// MessageText:
//
//  Error writing to the network.%0
//
#define NS_E_NET_WRITE                   _HRESULT_TYPEDEF_(0xC00D0014L)

//
// MessageId: NS_E_NET_READ
//
// MessageText:
//
//  Error reading from the network.%0
//
#define NS_E_NET_READ                    _HRESULT_TYPEDEF_(0xC00D0015L)

//
// MessageId: NS_E_DISK_WRITE
//
// MessageText:
//
//  Error writing to a disk.%0
//
#define NS_E_DISK_WRITE                  _HRESULT_TYPEDEF_(0xC00D0016L)

//
// MessageId: NS_E_DISK_READ
//
// MessageText:
//
//  Error reading from a disk.%0
//
#define NS_E_DISK_READ                   _HRESULT_TYPEDEF_(0xC00D0017L)

//
// MessageId: NS_E_FILE_WRITE
//
// MessageText:
//
//  Error writing to a file.%0
//
#define NS_E_FILE_WRITE                  _HRESULT_TYPEDEF_(0xC00D0018L)

//
// MessageId: NS_E_FILE_READ
//
// MessageText:
//
//  Error reading from a file.%0
//
#define NS_E_FILE_READ                   _HRESULT_TYPEDEF_(0xC00D0019L)

//
// MessageId: NS_E_FILE_NOT_FOUND
//
// MessageText:
//
//  The system cannot find the file specified.%0
//
#define NS_E_FILE_NOT_FOUND              _HRESULT_TYPEDEF_(0xC00D001AL)

//
// MessageId: NS_E_FILE_EXISTS
//
// MessageText:
//
//  The file already exists.%0
//
#define NS_E_FILE_EXISTS                 _HRESULT_TYPEDEF_(0xC00D001BL)

//
// MessageId: NS_E_INVALID_NAME
//
// MessageText:
//
//  The file name, directory name, or volume label syntax is incorrect.%0
//
#define NS_E_INVALID_NAME                _HRESULT_TYPEDEF_(0xC00D001CL)

//
// MessageId: NS_E_FILE_OPEN_FAILED
//
// MessageText:
//
//  Failed to open a file.%0
//
#define NS_E_FILE_OPEN_FAILED            _HRESULT_TYPEDEF_(0xC00D001DL)

//
// MessageId: NS_E_FILE_ALLOCATION_FAILED
//
// MessageText:
//
//  Unable to allocate a file.%0
//
#define NS_E_FILE_ALLOCATION_FAILED      _HRESULT_TYPEDEF_(0xC00D001EL)

//
// MessageId: NS_E_FILE_INIT_FAILED
//
// MessageText:
//
//  Unable to initialize a file.%0
//
#define NS_E_FILE_INIT_FAILED            _HRESULT_TYPEDEF_(0xC00D001FL)

//
// MessageId: NS_E_FILE_PLAY_FAILED
//
// MessageText:
//
//  Unable to play a file.%0
//
#define NS_E_FILE_PLAY_FAILED            _HRESULT_TYPEDEF_(0xC00D0020L)

//
// MessageId: NS_E_SET_DISK_UID_FAILED
//
// MessageText:
//
//  Could not set the disk UID.%0
//
#define NS_E_SET_DISK_UID_FAILED         _HRESULT_TYPEDEF_(0xC00D0021L)

//
// MessageId: NS_E_INDUCED
//
// MessageText:
//
//  An error was induced for testing purposes.%0
//
#define NS_E_INDUCED                     _HRESULT_TYPEDEF_(0xC00D0022L)

//
// MessageId: NS_E_CCLINK_DOWN
//
// MessageText:
//
//  Two Content Servers failed to communicate.%0
//
#define NS_E_CCLINK_DOWN                 _HRESULT_TYPEDEF_(0xC00D0023L)

//
// MessageId: NS_E_INTERNAL
//
// MessageText:
//
//  An unknown error occurred.%0
//
#define NS_E_INTERNAL                    _HRESULT_TYPEDEF_(0xC00D0024L)

//
// MessageId: NS_E_BUSY
//
// MessageText:
//
//  The requested resource is in use.%0
//
#define NS_E_BUSY                        _HRESULT_TYPEDEF_(0xC00D0025L)

//
// MessageId: NS_E_UNRECOGNIZED_STREAM_TYPE
//
// MessageText:
//
//  The specified protocol is not recognized. Be sure that the file name and syntax, such as slashes, are correct for the protocol.%0
//
#define NS_E_UNRECOGNIZED_STREAM_TYPE    _HRESULT_TYPEDEF_(0xC00D0026L)

//
// MessageId: NS_E_NETWORK_SERVICE_FAILURE
//
// MessageText:
//
//  The network service provider failed.%0
//
#define NS_E_NETWORK_SERVICE_FAILURE     _HRESULT_TYPEDEF_(0xC00D0027L)

//
// MessageId: NS_E_NETWORK_RESOURCE_FAILURE
//
// MessageText:
//
//  An attempt to acquire a network resource failed.%0
//
#define NS_E_NETWORK_RESOURCE_FAILURE    _HRESULT_TYPEDEF_(0xC00D0028L)

//
// MessageId: NS_E_CONNECTION_FAILURE
//
// MessageText:
//
//  The network connection has failed.%0
//
#define NS_E_CONNECTION_FAILURE          _HRESULT_TYPEDEF_(0xC00D0029L)

//
// MessageId: NS_E_SHUTDOWN
//
// MessageText:
//
//  The session is being terminated locally.%0
//
#define NS_E_SHUTDOWN                    _HRESULT_TYPEDEF_(0xC00D002AL)

//
// MessageId: NS_E_INVALID_REQUEST
//
// MessageText:
//
//  The request is invalid in the current state.%0
//
#define NS_E_INVALID_REQUEST             _HRESULT_TYPEDEF_(0xC00D002BL)

//
// MessageId: NS_E_INSUFFICIENT_BANDWIDTH
//
// MessageText:
//
//  There is insufficient bandwidth available to fulfill the request.%0
//
#define NS_E_INSUFFICIENT_BANDWIDTH      _HRESULT_TYPEDEF_(0xC00D002CL)

//
// MessageId: NS_E_NOT_REBUILDING
//
// MessageText:
//
//  The disk is not rebuilding.%0
//
#define NS_E_NOT_REBUILDING              _HRESULT_TYPEDEF_(0xC00D002DL)

//
// MessageId: NS_E_LATE_OPERATION
//
// MessageText:
//
//  An operation requested for a particular time could not be carried out on schedule.%0
//
#define NS_E_LATE_OPERATION              _HRESULT_TYPEDEF_(0xC00D002EL)

//
// MessageId: NS_E_INVALID_DATA
//
// MessageText:
//
//  Invalid or corrupt data was encountered.%0
//
#define NS_E_INVALID_DATA                _HRESULT_TYPEDEF_(0xC00D002FL)

//
// MessageId: NS_E_FILE_BANDWIDTH_LIMIT
//
// MessageText:
//
//  The bandwidth required to stream a file is higher than the maximum file bandwidth allowed on the server.%0
//
#define NS_E_FILE_BANDWIDTH_LIMIT        _HRESULT_TYPEDEF_(0xC00D0030L)

//
// MessageId: NS_E_OPEN_FILE_LIMIT
//
// MessageText:
//
//  The client cannot have any more files open simultaneously.%0
//
#define NS_E_OPEN_FILE_LIMIT             _HRESULT_TYPEDEF_(0xC00D0031L)

//
// MessageId: NS_E_BAD_CONTROL_DATA
//
// MessageText:
//
//  The server received invalid data from the client on the control connection.%0
//
#define NS_E_BAD_CONTROL_DATA            _HRESULT_TYPEDEF_(0xC00D0032L)

//
// MessageId: NS_E_NO_STREAM
//
// MessageText:
//
//  There is no stream available.%0
//
#define NS_E_NO_STREAM                   _HRESULT_TYPEDEF_(0xC00D0033L)

//
// MessageId: NS_E_STREAM_END
//
// MessageText:
//
//  There is no more data in the stream.%0
//
#define NS_E_STREAM_END                  _HRESULT_TYPEDEF_(0xC00D0034L)

//
// MessageId: NS_E_SERVER_NOT_FOUND
//
// MessageText:
//
//  The specified server could not be found.%0
//
#define NS_E_SERVER_NOT_FOUND            _HRESULT_TYPEDEF_(0xC00D0035L)

//
// MessageId: NS_E_DUPLICATE_NAME
//
// MessageText:
//
//  The specified name is already in use.
//
#define NS_E_DUPLICATE_NAME              _HRESULT_TYPEDEF_(0xC00D0036L)

//
// MessageId: NS_E_DUPLICATE_ADDRESS
//
// MessageText:
//
//  The specified address is already in use.
//
#define NS_E_DUPLICATE_ADDRESS           _HRESULT_TYPEDEF_(0xC00D0037L)

//
// MessageId: NS_E_BAD_MULTICAST_ADDRESS
//
// MessageText:
//
//  The specified address is not a valid multicast address.
//
#define NS_E_BAD_MULTICAST_ADDRESS       _HRESULT_TYPEDEF_(0xC00D0038L)

//
// MessageId: NS_E_BAD_ADAPTER_ADDRESS
//
// MessageText:
//
//  The specified adapter address is invalid.
//
#define NS_E_BAD_ADAPTER_ADDRESS         _HRESULT_TYPEDEF_(0xC00D0039L)

//
// MessageId: NS_E_BAD_DELIVERY_MODE
//
// MessageText:
//
//  The specified delivery mode is invalid.
//
#define NS_E_BAD_DELIVERY_MODE           _HRESULT_TYPEDEF_(0xC00D003AL)

//
// MessageId: NS_E_INVALID_CHANNEL
//
// MessageText:
//
//  The specified station does not exist.
//
#define NS_E_INVALID_CHANNEL             _HRESULT_TYPEDEF_(0xC00D003BL)

//
// MessageId: NS_E_INVALID_STREAM
//
// MessageText:
//
//  The specified stream does not exist.
//
#define NS_E_INVALID_STREAM              _HRESULT_TYPEDEF_(0xC00D003CL)

//
// MessageId: NS_E_INVALID_ARCHIVE
//
// MessageText:
//
//  The specified archive could not be opened.
//
#define NS_E_INVALID_ARCHIVE             _HRESULT_TYPEDEF_(0xC00D003DL)

//
// MessageId: NS_E_NOTITLES
//
// MessageText:
//
//  The system cannot find any titles on the server.%0
//
#define NS_E_NOTITLES                    _HRESULT_TYPEDEF_(0xC00D003EL)

//
// MessageId: NS_E_INVALID_CLIENT
//
// MessageText:
//
//  The system cannot find the client specified.%0
//
#define NS_E_INVALID_CLIENT              _HRESULT_TYPEDEF_(0xC00D003FL)

//
// MessageId: NS_E_INVALID_BLACKHOLE_ADDRESS
//
// MessageText:
//
//  The Blackhole Address is not initialized.%0
//
#define NS_E_INVALID_BLACKHOLE_ADDRESS   _HRESULT_TYPEDEF_(0xC00D0040L)

//
// MessageId: NS_E_INCOMPATIBLE_FORMAT
//
// MessageText:
//
//  The station does not support the stream format.
//
#define NS_E_INCOMPATIBLE_FORMAT         _HRESULT_TYPEDEF_(0xC00D0041L)

//
// MessageId: NS_E_INVALID_KEY
//
// MessageText:
//
//  The specified key is not valid.
//
#define NS_E_INVALID_KEY                 _HRESULT_TYPEDEF_(0xC00D0042L)

//
// MessageId: NS_E_INVALID_PORT
//
// MessageText:
//
//  The specified port is not valid.
//
#define NS_E_INVALID_PORT                _HRESULT_TYPEDEF_(0xC00D0043L)

//
// MessageId: NS_E_INVALID_TTL
//
// MessageText:
//
//  The specified TTL is not valid.
//
#define NS_E_INVALID_TTL                 _HRESULT_TYPEDEF_(0xC00D0044L)

//
// MessageId: NS_E_STRIDE_REFUSED
//
// MessageText:
//
//  The request to fast forward or rewind could not be fulfilled.
//
#define NS_E_STRIDE_REFUSED              _HRESULT_TYPEDEF_(0xC00D0045L)

//
// IMmsAutoServer Errors
//
//
// MessageId: NS_E_MMSAUTOSERVER_CANTFINDWALKER
//
// MessageText:
//
//  Unable to load the appropriate file parser.%0
//
#define NS_E_MMSAUTOSERVER_CANTFINDWALKER _HRESULT_TYPEDEF_(0xC00D0046L)

//
// MessageId: NS_E_MAX_BITRATE
//
// MessageText:
//
//  Cannot exceed the maximum bandwidth limit.%0
//
#define NS_E_MAX_BITRATE                 _HRESULT_TYPEDEF_(0xC00D0047L)

//
// MessageId: NS_E_LOGFILEPERIOD
//
// MessageText:
//
//  Invalid value for LogFilePeriod.%0
//
#define NS_E_LOGFILEPERIOD               _HRESULT_TYPEDEF_(0xC00D0048L)

//
// MessageId: NS_E_MAX_CLIENTS
//
// MessageText:
//
//  Cannot exceed the maximum client limit.%0
//  
//
#define NS_E_MAX_CLIENTS                 _HRESULT_TYPEDEF_(0xC00D0049L)

//
// MessageId: NS_E_LOG_FILE_SIZE
//
// MessageText:
//
//  The maximum log file size has been reached.%0
//  
//
#define NS_E_LOG_FILE_SIZE               _HRESULT_TYPEDEF_(0xC00D004AL)

//
// MessageId: NS_E_MAX_FILERATE
//
// MessageText:
//
//  Cannot exceed the maximum file rate.%0
//
#define NS_E_MAX_FILERATE                _HRESULT_TYPEDEF_(0xC00D004BL)

//
// File Walker Errors
//
//
// MessageId: NS_E_WALKER_UNKNOWN
//
// MessageText:
//
//  Unknown file type.%0
//
#define NS_E_WALKER_UNKNOWN              _HRESULT_TYPEDEF_(0xC00D004CL)

//
// MessageId: NS_E_WALKER_SERVER
//
// MessageText:
//
//  The specified file, %1, cannot be loaded onto the specified server, %2.%0
//
#define NS_E_WALKER_SERVER               _HRESULT_TYPEDEF_(0xC00D004DL)

//
// MessageId: NS_E_WALKER_USAGE
//
// MessageText:
//
//  There was a usage error with file parser.%0
//
#define NS_E_WALKER_USAGE                _HRESULT_TYPEDEF_(0xC00D004EL)


/////////////////////////////////////////////////////////////////////////
//
// NETSHOW Monitor Events
//
/////////////////////////////////////////////////////////////////////////


 // Tiger Events

 // %1 is the tiger name

//
// MessageId: NS_I_TIGER_START
//
// MessageText:
//
//  The Title Server %1 is running.%0
//
#define NS_I_TIGER_START                 _HRESULT_TYPEDEF_(0x400D004FL)

//
// MessageId: NS_E_TIGER_FAIL
//
// MessageText:
//
//  The Title Server %1 has failed.%0
//
#define NS_E_TIGER_FAIL                  _HRESULT_TYPEDEF_(0xC00D0050L)


 // Cub Events

 // %1 is the cub ID
 // %2 is the cub name

//
// MessageId: NS_I_CUB_START
//
// MessageText:
//
//  Content Server %1 (%2) is starting.%0
//
#define NS_I_CUB_START                   _HRESULT_TYPEDEF_(0x400D0051L)

//
// MessageId: NS_I_CUB_RUNNING
//
// MessageText:
//
//  Content Server %1 (%2) is running.%0
//
#define NS_I_CUB_RUNNING                 _HRESULT_TYPEDEF_(0x400D0052L)

//
// MessageId: NS_E_CUB_FAIL
//
// MessageText:
//
//  Content Server %1 (%2) has failed.%0
//
#define NS_E_CUB_FAIL                    _HRESULT_TYPEDEF_(0xC00D0053L)


 // Disk Events

 // %1 is the tiger disk ID
 // %2 is the device name
 // %3 is the cub ID
//
// MessageId: NS_I_DISK_START
//
// MessageText:
//
//  Disk %1 ( %2 ) on Content Server %3, is running.%0
//
#define NS_I_DISK_START                  _HRESULT_TYPEDEF_(0x400D0054L)

//
// MessageId: NS_E_DISK_FAIL
//
// MessageText:
//
//  Disk %1 ( %2 ) on Content Server %3, has failed.%0
//
#define NS_E_DISK_FAIL                   _HRESULT_TYPEDEF_(0xC00D0055L)

//
// MessageId: NS_I_DISK_REBUILD_STARTED
//
// MessageText:
//
//  Started rebuilding disk %1 ( %2 ) on Content Server %3.%0
//
#define NS_I_DISK_REBUILD_STARTED        _HRESULT_TYPEDEF_(0x400D0056L)

//
// MessageId: NS_I_DISK_REBUILD_FINISHED
//
// MessageText:
//
//  Finished rebuilding disk %1 ( %2 ) on Content Server %3.%0
//
#define NS_I_DISK_REBUILD_FINISHED       _HRESULT_TYPEDEF_(0x400D0057L)

//
// MessageId: NS_I_DISK_REBUILD_ABORTED
//
// MessageText:
//
//  Aborted rebuilding disk %1 ( %2 ) on Content Server %3.%0
//
#define NS_I_DISK_REBUILD_ABORTED        _HRESULT_TYPEDEF_(0x400D0058L)


 // Admin Events

//
// MessageId: NS_I_LIMIT_FUNNELS
//
// MessageText:
//
//  A NetShow administrator at network location %1 set the data stream limit to %2 streams.%0
//
#define NS_I_LIMIT_FUNNELS               _HRESULT_TYPEDEF_(0x400D0059L)

//
// MessageId: NS_I_START_DISK
//
// MessageText:
//
//  A NetShow administrator at network location %1 started disk %2.%0
//
#define NS_I_START_DISK                  _HRESULT_TYPEDEF_(0x400D005AL)

//
// MessageId: NS_I_STOP_DISK
//
// MessageText:
//
//  A NetShow administrator at network location %1 stopped disk %2.%0
//
#define NS_I_STOP_DISK                   _HRESULT_TYPEDEF_(0x400D005BL)

//
// MessageId: NS_I_STOP_CUB
//
// MessageText:
//
//  A NetShow administrator at network location %1 stopped Content Server %2.%0
//
#define NS_I_STOP_CUB                    _HRESULT_TYPEDEF_(0x400D005CL)

//
// MessageId: NS_I_KILL_USERSESSION
//
// MessageText:
//
//  A NetShow administrator at network location %1 aborted user session %2 from the system.%0
//
#define NS_I_KILL_USERSESSION            _HRESULT_TYPEDEF_(0x400D005DL)

//
// MessageId: NS_I_KILL_CONNECTION
//
// MessageText:
//
//  A NetShow administrator at network location %1 aborted obsolete connection %2 from the system.%0
//
#define NS_I_KILL_CONNECTION             _HRESULT_TYPEDEF_(0x400D005EL)

//
// MessageId: NS_I_REBUILD_DISK
//
// MessageText:
//
//  A NetShow administrator at network location %1 started rebuilding disk %2.%0
//
#define NS_I_REBUILD_DISK                _HRESULT_TYPEDEF_(0x400D005FL)

//
// MessageId: NS_W_UNKNOWN_EVENT
//
// MessageText:
//
//  Unknown %1 event encountered.%0
//
#define NS_W_UNKNOWN_EVENT               _HRESULT_TYPEDEF_(0x800D0060L)


 // Alerts

//
// MessageId: NS_E_MAX_FUNNELS_ALERT
//
// MessageText:
//
//  The NetShow data stream limit of %1 streams was reached.%0
//
#define NS_E_MAX_FUNNELS_ALERT           _HRESULT_TYPEDEF_(0xC00D0060L)

//
// MessageId: NS_E_ALLOCATE_FILE_FAIL
//
// MessageText:
//
//  The NetShow Video Server was unable to allocate a %1 block file named %2.%0
//
#define NS_E_ALLOCATE_FILE_FAIL          _HRESULT_TYPEDEF_(0xC00D0061L)

//
// MessageId: NS_E_PAGING_ERROR
//
// MessageText:
//
//  A Content Server was unable to page a block.%0
//
#define NS_E_PAGING_ERROR                _HRESULT_TYPEDEF_(0xC00D0062L)

//
// MessageId: NS_E_BAD_BLOCK0_VERSION
//
// MessageText:
//
//  Disk %1 has unrecognized control block version %2.%0
//
#define NS_E_BAD_BLOCK0_VERSION          _HRESULT_TYPEDEF_(0xC00D0063L)

//
// MessageId: NS_E_BAD_DISK_UID
//
// MessageText:
//
//  Disk %1 has incorrect uid %2.%0
//
#define NS_E_BAD_DISK_UID                _HRESULT_TYPEDEF_(0xC00D0064L)

//
// MessageId: NS_E_BAD_FSMAJOR_VERSION
//
// MessageText:
//
//  Disk %1 has unsupported file system major version %2.%0
//
#define NS_E_BAD_FSMAJOR_VERSION         _HRESULT_TYPEDEF_(0xC00D0065L)

//
// MessageId: NS_E_BAD_STAMPNUMBER
//
// MessageText:
//
//  Disk %1 has bad stamp number in control block.%0
//
#define NS_E_BAD_STAMPNUMBER             _HRESULT_TYPEDEF_(0xC00D0066L)

//
// MessageId: NS_E_PARTIALLY_REBUILT_DISK
//
// MessageText:
//
//  Disk %1 is partially reconstructed.%0
//
#define NS_E_PARTIALLY_REBUILT_DISK      _HRESULT_TYPEDEF_(0xC00D0067L)

//
// MessageId: NS_E_ENACTPLAN_GIVEUP
//
// MessageText:
//
//  EnactPlan gives up.%0
//
#define NS_E_ENACTPLAN_GIVEUP            _HRESULT_TYPEDEF_(0xC00D0068L)


 // MCMADM warnings/errors

//
// MessageId: MCMADM_I_NO_EVENTS
//
// MessageText:
//
//  Event initialization failed, there will be no MCM events.%0
//
#define MCMADM_I_NO_EVENTS               _HRESULT_TYPEDEF_(0x400D0069L)

//
// MessageId: MCMADM_E_REGKEY_NOT_FOUND
//
// MessageText:
//
//  The key was not found in the registry.%0
//
#define MCMADM_E_REGKEY_NOT_FOUND        _HRESULT_TYPEDEF_(0xC00D006AL)

//
// MessageId: NS_E_NO_FORMATS
//
// MessageText:
//
//  The publishing point cannot be started because the server does not have the appropriate stream formats. Use the Multicast Announcement Wizard to create a new announcement for this publishing point.%0
//
#define NS_E_NO_FORMATS                  _HRESULT_TYPEDEF_(0xC00D006BL)

//
// MessageId: NS_E_NO_REFERENCES
//
// MessageText:
//
//  No reference URLs were found in an ASX file.%0
//
#define NS_E_NO_REFERENCES               _HRESULT_TYPEDEF_(0xC00D006CL)

//
// MessageId: NS_E_WAVE_OPEN
//
// MessageText:
//
//  Error opening wave device, the device might be in use.%0
//
#define NS_E_WAVE_OPEN                   _HRESULT_TYPEDEF_(0xC00D006DL)

//
// MessageId: NS_I_LOGGING_FAILED
//
// MessageText:
//
//  The logging operation failed.
//
#define NS_I_LOGGING_FAILED              _HRESULT_TYPEDEF_(0x400D006EL)

//
// MessageId: NS_E_CANNOTCONNECTEVENTS
//
// MessageText:
//
//  Unable to establish a connection to the NetShow event monitor service.%0
//
#define NS_E_CANNOTCONNECTEVENTS         _HRESULT_TYPEDEF_(0xC00D006FL)

//
// MessageId: NS_I_LIMIT_BANDWIDTH
//
// MessageText:
//
//  A NetShow administrator at network location %1 set the maximum bandwidth limit to %2 bps.%0
//
#define NS_I_LIMIT_BANDWIDTH             _HRESULT_TYPEDEF_(0x400D0070L)

//
// MessageId: NS_E_NO_DEVICE
//
// MessageText:
//
//  No device driver is present on the system.%0
//
#define NS_E_NO_DEVICE                   _HRESULT_TYPEDEF_(0xC00D0071L)

//
// MessageId: NS_E_NO_SPECIFIED_DEVICE
//
// MessageText:
//
//  No specified device driver is present.%0
//
#define NS_E_NO_SPECIFIED_DEVICE         _HRESULT_TYPEDEF_(0xC00D0072L)


// NOTENOTE!!!
//
// Due to legacy problems these error codes live inside the ASF error code range
//
//
// MessageId: NS_E_NOTHING_TO_DO
//
// MessageText:
//
//  NS_E_NOTHING_TO_DO
//
#define NS_E_NOTHING_TO_DO               _HRESULT_TYPEDEF_(0xC00D07F1L)

//
// MessageId: NS_E_NO_MULTICAST
//
// MessageText:
//
//  Not receiving data from the server.%0
//
#define NS_E_NO_MULTICAST                _HRESULT_TYPEDEF_(0xC00D07F2L)


/////////////////////////////////////////////////////////////////////////
//
// NETSHOW Error Events
//
// IdRange = 200..399
//
/////////////////////////////////////////////////////////////////////////

//
// MessageId: NS_E_MONITOR_GIVEUP
//
// MessageText:
//
//  Netshow Events Monitor is not operational and has been disconnected.%0
//
#define NS_E_MONITOR_GIVEUP              _HRESULT_TYPEDEF_(0xC00D00C8L)

//
// MessageId: NS_E_REMIRRORED_DISK
//
// MessageText:
//
//  Disk %1 is remirrored.%0
//
#define NS_E_REMIRRORED_DISK             _HRESULT_TYPEDEF_(0xC00D00C9L)

//
// MessageId: NS_E_INSUFFICIENT_DATA
//
// MessageText:
//
//  Insufficient data found.%0
//
#define NS_E_INSUFFICIENT_DATA           _HRESULT_TYPEDEF_(0xC00D00CAL)

//
// MessageId: NS_E_ASSERT
//
// MessageText:
//
//  %1 failed in file %2 line %3.%0
//
#define NS_E_ASSERT                      _HRESULT_TYPEDEF_(0xC00D00CBL)

//
// MessageId: NS_E_BAD_ADAPTER_NAME
//
// MessageText:
//
//  The specified adapter name is invalid.%0
//
#define NS_E_BAD_ADAPTER_NAME            _HRESULT_TYPEDEF_(0xC00D00CCL)

//
// MessageId: NS_E_NOT_LICENSED
//
// MessageText:
//
//  The application is not licensed for this feature.%0
//
#define NS_E_NOT_LICENSED                _HRESULT_TYPEDEF_(0xC00D00CDL)

//
// MessageId: NS_E_NO_SERVER_CONTACT
//
// MessageText:
//
//  Unable to contact the server.%0
//
#define NS_E_NO_SERVER_CONTACT           _HRESULT_TYPEDEF_(0xC00D00CEL)

//
// MessageId: NS_E_TOO_MANY_TITLES
//
// MessageText:
//
//  Maximum number of titles exceeded.%0
//
#define NS_E_TOO_MANY_TITLES             _HRESULT_TYPEDEF_(0xC00D00CFL)

//
// MessageId: NS_E_TITLE_SIZE_EXCEEDED
//
// MessageText:
//
//  Maximum size of a title exceeded.%0
//
#define NS_E_TITLE_SIZE_EXCEEDED         _HRESULT_TYPEDEF_(0xC00D00D0L)

//
// MessageId: NS_E_UDP_DISABLED
//
// MessageText:
//
//  UDP protocol not enabled. Not trying %1!ls!.%0
//
#define NS_E_UDP_DISABLED                _HRESULT_TYPEDEF_(0xC00D00D1L)

//
// MessageId: NS_E_TCP_DISABLED
//
// MessageText:
//
//  TCP protocol not enabled. Not trying %1!ls!.%0
//
#define NS_E_TCP_DISABLED                _HRESULT_TYPEDEF_(0xC00D00D2L)

//
// MessageId: NS_E_HTTP_DISABLED
//
// MessageText:
//
//  HTTP protocol not enabled. Not trying %1!ls!.%0
//
#define NS_E_HTTP_DISABLED               _HRESULT_TYPEDEF_(0xC00D00D3L)

//
// MessageId: NS_E_LICENSE_EXPIRED
//
// MessageText:
//
//  The product license has expired.%0
//
#define NS_E_LICENSE_EXPIRED             _HRESULT_TYPEDEF_(0xC00D00D4L)

//
// MessageId: NS_E_TITLE_BITRATE
//
// MessageText:
//
//  Source file exceeds the per title maximum bitrate. See NetShow Theater documentation for more information.%0
//
#define NS_E_TITLE_BITRATE               _HRESULT_TYPEDEF_(0xC00D00D5L)

//
// MessageId: NS_E_EMPTY_PROGRAM_NAME
//
// MessageText:
//
//  The program name cannot be empty.%0
//
#define NS_E_EMPTY_PROGRAM_NAME          _HRESULT_TYPEDEF_(0xC00D00D6L)

//
// MessageId: NS_E_MISSING_CHANNEL
//
// MessageText:
//
//  Station %1 does not exist.%0
//
#define NS_E_MISSING_CHANNEL             _HRESULT_TYPEDEF_(0xC00D00D7L)

//
// MessageId: NS_E_NO_CHANNELS
//
// MessageText:
//
//  You need to define at least one station before this operation can complete.%0
//
#define NS_E_NO_CHANNELS                 _HRESULT_TYPEDEF_(0xC00D00D8L)


/////////////////////////////////////////////////////////////////////
// This error message is to replace previous NS_E_INVALID_INDEX which
// takes an index value for the error message string.  For some application
// obtain the idex value at reporting error time is very difficult, so we
// use this string to avoid the problem.
//////////////////////////////////////////////////////////////////////

//
// MessageId: NS_E_INVALID_INDEX2
//
// MessageText:
//
//  The index specified is invalid.%0
//
#define NS_E_INVALID_INDEX2              _HRESULT_TYPEDEF_(0xC00D00D9L)


/////////////////////////////////////////////////////////////////////////
//
// NETSHOW Monitor Events
//
// IdRange = 400..599
//
// Admin Events:
//
// Alerts:
//
// Title Server:
//      %1 is the Title Server name
//
// Content Server:
//      %1 is the Content Server ID
//      %2 is the Content Server name
//      %3 is the Peer Content Server name (optional)
//
// Disks:
//      %1 is the Title Server disk ID
//      %2 is the device name
//      %3 is the Content Server ID
//
/////////////////////////////////////////////////////////////////////////

//
// MessageId: NS_E_CUB_FAIL_LINK
//
// MessageText:
//
//  Content Server %1 (%2) has failed its link to Content Server %3.%0
//
#define NS_E_CUB_FAIL_LINK               _HRESULT_TYPEDEF_(0xC00D0190L)

//
// MessageId: NS_I_CUB_UNFAIL_LINK
//
// MessageText:
//
//  Content Server %1 (%2) has established its link to Content Server %3.%0
//
#define NS_I_CUB_UNFAIL_LINK             _HRESULT_TYPEDEF_(0x400D0191L)

//
// MessageId: NS_E_BAD_CUB_UID
//
// MessageText:
//
//  Content Server %1 (%2) has incorrect uid %3.%0
//
#define NS_E_BAD_CUB_UID                 _HRESULT_TYPEDEF_(0xC00D0192L)

//
// MessageId: NS_I_RESTRIPE_START
//
// MessageText:
//
//  Restripe operation has started.%0
//
#define NS_I_RESTRIPE_START              _HRESULT_TYPEDEF_(0x400D0193L)

//
// MessageId: NS_I_RESTRIPE_DONE
//
// MessageText:
//
//  Restripe operation has completed.%0
//
#define NS_I_RESTRIPE_DONE               _HRESULT_TYPEDEF_(0x400D0194L)

//
// MessageId: NS_E_GLITCH_MODE
//
// MessageText:
//
//  Server unreliable because multiple components failed.%0
//
#define NS_E_GLITCH_MODE                 _HRESULT_TYPEDEF_(0xC00D0195L)

//
// MessageId: NS_I_RESTRIPE_DISK_OUT
//
// MessageText:
//
//  Content disk %1 (%2) on Content Server %3 has been restriped out.%0
//
#define NS_I_RESTRIPE_DISK_OUT           _HRESULT_TYPEDEF_(0x400D0196L)

//
// MessageId: NS_I_RESTRIPE_CUB_OUT
//
// MessageText:
//
//  Content server %1 (%2) has been restriped out.%0
//
#define NS_I_RESTRIPE_CUB_OUT            _HRESULT_TYPEDEF_(0x400D0197L)

//
// MessageId: NS_I_DISK_STOP
//
// MessageText:
//
//  Disk %1 ( %2 ) on Content Server %3, has been offlined.%0
//
#define NS_I_DISK_STOP                   _HRESULT_TYPEDEF_(0x400D0198L)

//
// MessageId: NS_I_CATATONIC_FAILURE
//
// MessageText:
//
//  Disk %1 ( %2 ) on Content Server %3, will be failed because it is catatonic.%0
//
#define NS_I_CATATONIC_FAILURE           _HRESULT_TYPEDEF_(0x800D0199L)

//
// MessageId: NS_I_CATATONIC_AUTO_UNFAIL
//
// MessageText:
//
//  Disk %1 ( %2 ) on Content Server %3, auto online from catatonic state.%0
//
#define NS_I_CATATONIC_AUTO_UNFAIL       _HRESULT_TYPEDEF_(0x800D019AL)

//
// MessageId: NS_E_NO_MEDIA_PROTOCOL
//
// MessageText:
//
//  Content Server %1 (%2) is unable to communicate with the Media System Network Protocol.%0
//
#define NS_E_NO_MEDIA_PROTOCOL           _HRESULT_TYPEDEF_(0xC00D019BL)


//
// Advanced Streaming Format (ASF) codes occupy MessageIds 2000-2999
//
// See ASFErr.mc for more details - please do not define any symbols
// in that range in this file.
//


/////////////////////////////////////////////////////////////////////////
//
// Windows Media SDK Errors
//
// IdRange = 3000-3199
//
/////////////////////////////////////////////////////////////////////////

//
// MessageId: NS_E_INVALID_INPUT_FORMAT
//
// MessageText:
//
//  The input media format is invalid.%0
//
#define NS_E_INVALID_INPUT_FORMAT        _HRESULT_TYPEDEF_(0xC00D0BB8L)

//
// MessageId: NS_E_MSAUDIO_NOT_INSTALLED
//
// MessageText:
//
//  The MSAudio codec is not installed on this system.%0
//
#define NS_E_MSAUDIO_NOT_INSTALLED       _HRESULT_TYPEDEF_(0xC00D0BB9L)

//
// MessageId: NS_E_UNEXPECTED_MSAUDIO_ERROR
//
// MessageText:
//
//  An unexpected error occurred with the MSAudio codec.%0
//
#define NS_E_UNEXPECTED_MSAUDIO_ERROR    _HRESULT_TYPEDEF_(0xC00D0BBAL)

//
// MessageId: NS_E_INVALID_OUTPUT_FORMAT
//
// MessageText:
//
//  The output media format is invalid.%0
//
#define NS_E_INVALID_OUTPUT_FORMAT       _HRESULT_TYPEDEF_(0xC00D0BBBL)

//
// MessageId: NS_E_NOT_CONFIGURED
//
// MessageText:
//
//  The object must be fully configured before audio samples can be processed.%0
//
#define NS_E_NOT_CONFIGURED              _HRESULT_TYPEDEF_(0xC00D0BBCL)

//
// MessageId: NS_E_PROTECTED_CONTENT
//
// MessageText:
//
//  You need a license to perform the requested operation on this media file.%0
//
#define NS_E_PROTECTED_CONTENT           _HRESULT_TYPEDEF_(0xC00D0BBDL)

//
// MessageId: NS_E_LICENSE_REQUIRED
//
// MessageText:
//
//  You need a license to perform the requested operation on this media file.%0
//
#define NS_E_LICENSE_REQUIRED            _HRESULT_TYPEDEF_(0xC00D0BBEL)

//
// MessageId: NS_E_TAMPERED_CONTENT
//
// MessageText:
//
//  This media file is corrupted or invalid. Contact the content provider for a new file.%0
//
#define NS_E_TAMPERED_CONTENT            _HRESULT_TYPEDEF_(0xC00D0BBFL)

//
// MessageId: NS_E_LICENSE_OUTOFDATE
//
// MessageText:
//
//  The license for this media file has expired. Get a new license or contact the content provider for further assistance.%0
//
#define NS_E_LICENSE_OUTOFDATE           _HRESULT_TYPEDEF_(0xC00D0BC0L)

//
// MessageId: NS_E_LICENSE_INCORRECT_RIGHTS
//
// MessageText:
//
//  You are not allowed to open this file. Contact the content provider for further assistance.%0
//
#define NS_E_LICENSE_INCORRECT_RIGHTS    _HRESULT_TYPEDEF_(0xC00D0BC1L)

//
// MessageId: NS_E_AUDIO_CODEC_NOT_INSTALLED
//
// MessageText:
//
//  The requested audio codec is not installed on this system.%0
//
#define NS_E_AUDIO_CODEC_NOT_INSTALLED   _HRESULT_TYPEDEF_(0xC00D0BC2L)

//
// MessageId: NS_E_AUDIO_CODEC_ERROR
//
// MessageText:
//
//  An unexpected error occurred with the audio codec.%0
//
#define NS_E_AUDIO_CODEC_ERROR           _HRESULT_TYPEDEF_(0xC00D0BC3L)

//
// MessageId: NS_E_VIDEO_CODEC_NOT_INSTALLED
//
// MessageText:
//
//  The requested video codec is not installed on this system.%0
//
#define NS_E_VIDEO_CODEC_NOT_INSTALLED   _HRESULT_TYPEDEF_(0xC00D0BC4L)

//
// MessageId: NS_E_VIDEO_CODEC_ERROR
//
// MessageText:
//
//  An unexpected error occurred with the video codec.%0
//
#define NS_E_VIDEO_CODEC_ERROR           _HRESULT_TYPEDEF_(0xC00D0BC5L)

//
// MessageId: NS_E_INVALIDPROFILE
//
// MessageText:
//
//  The Profile is invalid.%0
//
#define NS_E_INVALIDPROFILE              _HRESULT_TYPEDEF_(0xC00D0BC6L)

//
// MessageId: NS_E_INCOMPATIBLE_VERSION
//
// MessageText:
//
//  A new version of the SDK is needed to play the requested content.%0
//
#define NS_E_INCOMPATIBLE_VERSION        _HRESULT_TYPEDEF_(0xC00D0BC7L)

//
// MessageId: NS_S_REBUFFERING
//
// MessageText:
//
//  The requested operation has caused the source to rebuffer.%0
//
#define NS_S_REBUFFERING                 _HRESULT_TYPEDEF_(0x000D0BC8L)

//
// MessageId: NS_S_DEGRADING_QUALITY
//
// MessageText:
//
//  The requested operation has caused the source to degrade codec quality.%0
//
#define NS_S_DEGRADING_QUALITY           _HRESULT_TYPEDEF_(0x000D0BC9L)

//
// MessageId: NS_E_OFFLINE_MODE
//
// MessageText:
//
//  The requested URL is not available in offline mode.%0
//
#define NS_E_OFFLINE_MODE                _HRESULT_TYPEDEF_(0xC00D0BCAL)

//
// MessageId: NS_E_NOT_CONNECTED
//
// MessageText:
//
//  The requested URL cannot be accessed because there is no network connection.%0
//
#define NS_E_NOT_CONNECTED               _HRESULT_TYPEDEF_(0xC00D0BCBL)

//
// MessageId: NS_E_TOO_MUCH_DATA
//
// MessageText:
//
//  The encoding process was unable to keep up with the amount of supplied data.%0
//
#define NS_E_TOO_MUCH_DATA               _HRESULT_TYPEDEF_(0xC00D0BCCL)

//
// MessageId: NS_E_UNSUPPORTED_PROPERTY
//
// MessageText:
//
//  The given property is not supported.%0
//
#define NS_E_UNSUPPORTED_PROPERTY        _HRESULT_TYPEDEF_(0xC00D0BCDL)

//
// MessageId: NS_E_8BIT_WAVE_UNSUPPORTED
//
// MessageText:
//
//  Windows Media Player cannot copy the files to the CD because they are 8-bit. Convert the files to 16-bit, 44-kHz stereo files by using Sound Recorder or another audio-processing program, and then try again.%0
//
#define NS_E_8BIT_WAVE_UNSUPPORTED       _HRESULT_TYPEDEF_(0xC00D0BCEL)

//
// MessageId: NS_E_NO_MORE_SAMPLES
//
// MessageText:
//
//  There are no more samples in the current range.%0
//
#define NS_E_NO_MORE_SAMPLES             _HRESULT_TYPEDEF_(0xC00D0BCFL)

//
// MessageId: NS_E_INVALID_SAMPLING_RATE
//
// MessageText:
//
//  The given sampling rate is invalid.%0
//
#define NS_E_INVALID_SAMPLING_RATE       _HRESULT_TYPEDEF_(0xC00D0BD0L)

//
// MessageId: NS_E_MAX_PACKET_SIZE_TOO_SMALL
//
// MessageText:
//
//  The given maximum packet size is too small to accommodate this profile
//
#define NS_E_MAX_PACKET_SIZE_TOO_SMALL   _HRESULT_TYPEDEF_(0xC00D0BD1L)

//
// MessageId: NS_E_LATE_PACKET
//
// MessageText:
//
//  The packet arrived too late to be of use
//
#define NS_E_LATE_PACKET                 _HRESULT_TYPEDEF_(0xC00D0BD2L)

//
// MessageId: NS_E_DUPLICATE_PACKET
//
// MessageText:
//
//  The packet is a duplicate of one received before
//
#define NS_E_DUPLICATE_PACKET            _HRESULT_TYPEDEF_(0xC00D0BD3L)

//
// MessageId: NS_E_SDK_BUFFERTOOSMALL
//
// MessageText:
//
//  Supplied buffer is too small
//
#define NS_E_SDK_BUFFERTOOSMALL          _HRESULT_TYPEDEF_(0xC00D0BD4L)

//
// MessageId: NS_E_INVALID_NUM_PASSES
//
// MessageText:
//
//  The wrong number of preprocessing passes was used for the stream's output type
//
#define NS_E_INVALID_NUM_PASSES          _HRESULT_TYPEDEF_(0xC00D0BD5L)

//
// MessageId: NS_E_ATTRIBUTE_READ_ONLY
//
// MessageText:
//
//  An attempt was made to add, modify, or delete a read only attribute
//
#define NS_E_ATTRIBUTE_READ_ONLY         _HRESULT_TYPEDEF_(0xC00D0BD6L)

//
// MessageId: NS_E_ATTRIBUTE_NOT_ALLOWED
//
// MessageText:
//
//  An attempt was made to add attribute that is not allowed for the given media type
//
#define NS_E_ATTRIBUTE_NOT_ALLOWED       _HRESULT_TYPEDEF_(0xC00D0BD7L)

//
// MessageId: NS_E_INVALID_EDL
//
// MessageText:
//
//  The EDL provided is invalid
//
#define NS_E_INVALID_EDL                 _HRESULT_TYPEDEF_(0xC00D0BD8L)

//
// MessageId: NS_E_DATA_UNIT_EXTENSION_TOO_LARGE
//
// MessageText:
//
//  The Data Unit Extension data was too large to be used.%0
//
#define NS_E_DATA_UNIT_EXTENSION_TOO_LARGE _HRESULT_TYPEDEF_(0xC00D0BD9L)

//
// MessageId: NS_E_CODEC_DMO_ERROR
//
// MessageText:
//
//  An unexpected error occurred with a DMO codec.%0
//
#define NS_E_CODEC_DMO_ERROR             _HRESULT_TYPEDEF_(0xC00D0BDAL)



/////////////////////////////////////////////////////////////////////////
//
// Windows Media Player Errors
//
// IdRange = 4000 - 4999
//
/////////////////////////////////////////////////////////////////////////

//
// WMP CD Filter Error codes
//
//
// MessageId: NS_E_NO_CD
//
// MessageText:
//
//  There is no CD in the CD-ROM drive. Insert a CD, and try again.%0
//
#define NS_E_NO_CD                       _HRESULT_TYPEDEF_(0xC00D0FA0L)

//
// MessageId: NS_E_CANT_READ_DIGITAL
//
// MessageText:
//
//  Unable to perform digital reads on this compact disc drive.  Please try analog playback via the Tools Options menu.%0
//
#define NS_E_CANT_READ_DIGITAL           _HRESULT_TYPEDEF_(0xC00D0FA1L)

//
// MessageId: NS_E_DEVICE_DISCONNECTED
//
// MessageText:
//
//  Windows Media Player no longer detects a connected portable device. Reconnect your portable device, and then try copying the file again.%0
//
#define NS_E_DEVICE_DISCONNECTED         _HRESULT_TYPEDEF_(0xC00D0FA2L)

//
// MessageId: NS_E_DEVICE_NOT_SUPPORT_FORMAT
//
// MessageText:
//
//  Windows Media Player cannot play the file. The portable device does not support the specified format.%0
//
#define NS_E_DEVICE_NOT_SUPPORT_FORMAT   _HRESULT_TYPEDEF_(0xC00D0FA3L)

//
// MessageId: NS_E_SLOW_READ_DIGITAL
//
// MessageText:
//
//  Windows Media Player encountered a problem while attempting to play the CD using digital playback. The Player has automatically switched the CD-ROM drive to analog playback. To switch back to digital CD playback, use the Devices tab.%0
//
#define NS_E_SLOW_READ_DIGITAL           _HRESULT_TYPEDEF_(0xC00D0FA4L)

//
// MessageId: NS_E_MIXER_INVALID_LINE
//
// MessageText:
//
//  An invalid line error occurred in the mixer.%0
//
#define NS_E_MIXER_INVALID_LINE          _HRESULT_TYPEDEF_(0xC00D0FA5L)

//
// MessageId: NS_E_MIXER_INVALID_CONTROL
//
// MessageText:
//
//  An invalid control error occurred in the mixer.%0
//
#define NS_E_MIXER_INVALID_CONTROL       _HRESULT_TYPEDEF_(0xC00D0FA6L)

//
// MessageId: NS_E_MIXER_INVALID_VALUE
//
// MessageText:
//
//  An invalid value error occurred in the mixer.%0
//
#define NS_E_MIXER_INVALID_VALUE         _HRESULT_TYPEDEF_(0xC00D0FA7L)

//
// MessageId: NS_E_MIXER_UNKNOWN_MMRESULT
//
// MessageText:
//
//  An unrecognized MMRESULT occurred in the mixer.%0
//
#define NS_E_MIXER_UNKNOWN_MMRESULT      _HRESULT_TYPEDEF_(0xC00D0FA8L)

//
// MessageId: NS_E_USER_STOP
//
// MessageText:
//
//  User has stopped the operation.%0
//
#define NS_E_USER_STOP                   _HRESULT_TYPEDEF_(0xC00D0FA9L)

//
// MessageId: NS_E_MP3_FORMAT_NOT_FOUND
//
// MessageText:
//
//  Windows Media Player cannot copy the file because a compatible MP3 encoder is not installed on your computer. Install a compatible MP3 encoder, or choose a different format to copy to (such as Windows Media Audio).%0
//
#define NS_E_MP3_FORMAT_NOT_FOUND        _HRESULT_TYPEDEF_(0xC00D0FAAL)

//
// MessageId: NS_E_CD_READ_ERROR_NO_CORRECTION
//
// MessageText:
//
//  Windows Media Player cannot read the CD. It may contain flaws. Turn on error correction and try again.%0
//
#define NS_E_CD_READ_ERROR_NO_CORRECTION _HRESULT_TYPEDEF_(0xC00D0FABL)

//
// MessageId: NS_E_CD_READ_ERROR
//
// MessageText:
//
//  Windows Media Player cannot read the CD. Be sure the CD is free of dirt and scratches and the CD-ROM drive is functioning properly.%0
//
#define NS_E_CD_READ_ERROR               _HRESULT_TYPEDEF_(0xC00D0FACL)

//
// MessageId: NS_E_CD_SLOW_COPY
//
// MessageText:
//
//  To speed up the copy process, do not play CD tracks while copying.%0
//
#define NS_E_CD_SLOW_COPY                _HRESULT_TYPEDEF_(0xC00D0FADL)

//
// MessageId: NS_E_CD_COPYTO_CD
//
// MessageText:
//
//  Cannot copy directly from a CDROM to a CD drive.%0
//
#define NS_E_CD_COPYTO_CD                _HRESULT_TYPEDEF_(0xC00D0FAEL)

//
// MessageId: NS_E_MIXER_NODRIVER
//
// MessageText:
//
//  Could not open a sound mixer driver.%0
//
#define NS_E_MIXER_NODRIVER              _HRESULT_TYPEDEF_(0xC00D0FAFL)

//
// MessageId: NS_E_REDBOOK_ENABLED_WHILE_COPYING
//
// MessageText:
//
//  Windows Media Player has detected that a setting for the CD-ROM drive will cause audio CDs to copy incorrectly; no audio is copied. Change the CD-ROM drive setting in Device Manager, and then try again.%0
//
#define NS_E_REDBOOK_ENABLED_WHILE_COPYING _HRESULT_TYPEDEF_(0xC00D0FB0L)

//
// MessageId: NS_E_CD_REFRESH
//
// MessageText:
//
//  Trying to refresh the CD playlist.%0
//
#define NS_E_CD_REFRESH                  _HRESULT_TYPEDEF_(0xC00D0FB1L)

//
// MessageId: NS_E_CD_DRIVER_PROBLEM
//
// MessageText:
//
//  Windows Media Player must switch to analog  mode  because there is a problem reading the CD-ROM drive in digital mode. Verify that the CD-ROM drive is installed correctly or try to update the drivers for the CD-ROM drive, and then try to use digital mode again.%0
//
#define NS_E_CD_DRIVER_PROBLEM           _HRESULT_TYPEDEF_(0xC00D0FB2L)

//
// MessageId: NS_E_WONT_DO_DIGITAL
//
// MessageText:
//
//  Windows Media Player must switch to analog mode because there is a problem reading the CD-ROM drive  in digital mode.%0
//
#define NS_E_WONT_DO_DIGITAL             _HRESULT_TYPEDEF_(0xC00D0FB3L)

//
// WMP IWMPXMLParser Error codes
//
//
// MessageId: NS_E_WMPXML_NOERROR
//
// MessageText:
//
//  A call was made to GetParseError on the XML parser but there was no error to retrieve.%0
//
#define NS_E_WMPXML_NOERROR              _HRESULT_TYPEDEF_(0xC00D0FB4L)

//
// MessageId: NS_E_WMPXML_ENDOFDATA
//
// MessageText:
//
//  The XML Parser ran out of data while parsing.%0
//
#define NS_E_WMPXML_ENDOFDATA            _HRESULT_TYPEDEF_(0xC00D0FB5L)

//
// MessageId: NS_E_WMPXML_PARSEERROR
//
// MessageText:
//
//  A generic parse error occurred in the XML parser but no information is available.%0
//
#define NS_E_WMPXML_PARSEERROR           _HRESULT_TYPEDEF_(0xC00D0FB6L)

//
// MessageId: NS_E_WMPXML_ATTRIBUTENOTFOUND
//
// MessageText:
//
//  A call get GetNamedAttribute or GetNamedAttributeIndex on the XML parser resulted in the index not being found.%0
//
#define NS_E_WMPXML_ATTRIBUTENOTFOUND    _HRESULT_TYPEDEF_(0xC00D0FB7L)

//
// MessageId: NS_E_WMPXML_PINOTFOUND
//
// MessageText:
//
//  A call was made go GetNamedPI on the XML parser, but the requested Processing Instruction was not found.%0
//
#define NS_E_WMPXML_PINOTFOUND           _HRESULT_TYPEDEF_(0xC00D0FB8L)

//
// MessageId: NS_E_WMPXML_EMPTYDOC
//
// MessageText:
//
//  Persist was called on the XML parser, but the parser has no data to persist.%0
//
#define NS_E_WMPXML_EMPTYDOC             _HRESULT_TYPEDEF_(0xC00D0FB9L)

//
// Miscellaneous Media Player Error codes
//
//
// MessageId: NS_E_WMP_WINDOWSAPIFAILURE
//
// MessageText:
//
//  A Windows API call failed but no error information was available.%0
//
#define NS_E_WMP_WINDOWSAPIFAILURE       _HRESULT_TYPEDEF_(0xC00D0FC8L)

//
// MessageId: NS_E_WMP_RECORDING_NOT_ALLOWED
//
// MessageText:
//
//  Windows Media Player cannot copy the file. Either the license restricts copying, or you must obtain a license to copy the file.%0
//
#define NS_E_WMP_RECORDING_NOT_ALLOWED   _HRESULT_TYPEDEF_(0xC00D0FC9L)

//
// MessageId: NS_E_DEVICE_NOT_READY
//
// MessageText:
//
//  Windows Media Player no longer detects a connected portable device. Reconnect your portable device, and try again.%0
//
#define NS_E_DEVICE_NOT_READY            _HRESULT_TYPEDEF_(0xC00D0FCAL)

//
// MessageId: NS_E_DAMAGED_FILE
//
// MessageText:
//
//  Windows Media Player cannot play the file because it is either damaged or corrupt.%0
//
#define NS_E_DAMAGED_FILE                _HRESULT_TYPEDEF_(0xC00D0FCBL)

//
// MessageId: NS_E_MPDB_GENERIC
//
// MessageText:
//
//  An error occurred when the Player was attempting to access information in your media library. Try closing and then reopening the Player.%0
//
#define NS_E_MPDB_GENERIC                _HRESULT_TYPEDEF_(0xC00D0FCCL)

//
// MessageId: NS_E_FILE_FAILED_CHECKS
//
// MessageText:
//
//  The file cannot be added to Media Library because it is smaller than the minimum-size requirement. Adjust the size requirements, and then try again.%0
//
#define NS_E_FILE_FAILED_CHECKS          _HRESULT_TYPEDEF_(0xC00D0FCDL)

//
// MessageId: NS_E_MEDIA_LIBRARY_FAILED
//
// MessageText:
//
//  Windows Media Player could not create Media Library. Check with your system administrator to get the necessary permissions to create Media Library on your computer, and then try installing the Player again.%0
//
#define NS_E_MEDIA_LIBRARY_FAILED        _HRESULT_TYPEDEF_(0xC00D0FCEL)

//
// MessageId: NS_E_SHARING_VIOLATION
//
// MessageText:
//
//  The file is already in use. Close other programs that may be using the file, or stop playing the file, and try again.%0
//
#define NS_E_SHARING_VIOLATION           _HRESULT_TYPEDEF_(0xC00D0FCFL)

//
// MessageId: NS_E_NO_ERROR_STRING_FOUND
//
// MessageText:
//
//  Windows Media Player has encountered an unknown error.%0
//
#define NS_E_NO_ERROR_STRING_FOUND       _HRESULT_TYPEDEF_(0xC00D0FD0L)

//
// MessageId: NS_E_WMPOCX_NO_REMOTE_CORE
//
// MessageText:
//
//  The Windows Media Player control was unable to connect to remote media services, but will continue with local media services.%0
//
#define NS_E_WMPOCX_NO_REMOTE_CORE       _HRESULT_TYPEDEF_(0xC00D0FD1L)

//
// MessageId: NS_E_WMPOCX_NO_ACTIVE_CORE
//
// MessageText:
//
//  The requested method or property is not available because the Windows Media Player control has not been properly activated.%0
//
#define NS_E_WMPOCX_NO_ACTIVE_CORE       _HRESULT_TYPEDEF_(0xC00D0FD2L)

//
// MessageId: NS_E_WMPOCX_NOT_RUNNING_REMOTELY
//
// MessageText:
//
//  Windows Media Player ActiveX control is not running in remote mode.%0
//
#define NS_E_WMPOCX_NOT_RUNNING_REMOTELY _HRESULT_TYPEDEF_(0xC00D0FD3L)

//
// MessageId: NS_E_WMPOCX_NO_REMOTE_WINDOW
//
// MessageText:
//
//  An error occurred when trying to get remote Windows Media Player window.%0
//
#define NS_E_WMPOCX_NO_REMOTE_WINDOW     _HRESULT_TYPEDEF_(0xC00D0FD4L)

//
// MessageId: NS_E_WMPOCX_ERRORMANAGERNOTAVAILABLE
//
// MessageText:
//
//  Windows Media Player has encountered an unknown error.%0
//
#define NS_E_WMPOCX_ERRORMANAGERNOTAVAILABLE _HRESULT_TYPEDEF_(0xC00D0FD5L)

//
// MessageId: NS_E_PLUGIN_NOTSHUTDOWN
//
// MessageText:
//
//  Windows Media Player was not closed properly. A damaged or incompatible plug-in may have caused the problem to occur. As a precaution, all third-party plug-ins have been disabled.%0
//
#define NS_E_PLUGIN_NOTSHUTDOWN          _HRESULT_TYPEDEF_(0xC00D0FD6L)

//
// MessageId: NS_E_WMP_CANNOT_FIND_FOLDER
//
// MessageText:
//
//  Windows Media Player cannot find the specified path. Be sure the path is typed correctly. If it is, the path does not exist in the specified location, or the computer where the path is located is offline.%0
//
#define NS_E_WMP_CANNOT_FIND_FOLDER      _HRESULT_TYPEDEF_(0xC00D0FD7L)

//
// MessageId: NS_E_WMP_STREAMING_RECORDING_NOT_ALLOWED
//
// MessageText:
//
//  Windows Media Player cannot copy streaming media.%0
//
#define NS_E_WMP_STREAMING_RECORDING_NOT_ALLOWED _HRESULT_TYPEDEF_(0xC00D0FD8L)

//
// MessageId: NS_E_WMP_PLUGINDLL_NOTFOUND
//
// MessageText:
//
//  Windows Media Player cannot find the selected plug-in. The Player will try to remove it from the menu. To use this plug-in, install it again.%0
//
#define NS_E_WMP_PLUGINDLL_NOTFOUND      _HRESULT_TYPEDEF_(0xC00D0FD9L)

//
// MessageId: NS_E_NEED_TO_ASK_USER
//
// MessageText:
//
//  Action requires input from the user.%0
//
#define NS_E_NEED_TO_ASK_USER            _HRESULT_TYPEDEF_(0xC00D0FDAL)

//
// MessageId: NS_E_WMPOCX_PLAYER_NOT_DOCKED
//
// MessageText:
//
//  The Windows Media Player control must be in a docked state for this action to succeed.%0
//
#define NS_E_WMPOCX_PLAYER_NOT_DOCKED    _HRESULT_TYPEDEF_(0xC00D0FDBL)

//
// MessageId: NS_E_WMP_EXTERNAL_NOTREADY
//
// MessageText:
//
//  Media Player external object is not ready.%0
//
#define NS_E_WMP_EXTERNAL_NOTREADY       _HRESULT_TYPEDEF_(0xC00D0FDCL)

//
// MessageId: NS_E_WMP_MLS_STALE_DATA
//
// MessageText:
//
//  Metadata is stale. The operation failed.%0
//
#define NS_E_WMP_MLS_STALE_DATA          _HRESULT_TYPEDEF_(0xC00D0FDDL)    

//
// Generic Media PlayerUI error codes
//
//
// MessageId: NS_E_WMP_UI_SUBCONTROLSNOTSUPPORTED
//
// MessageText:
//
//  The control (%s) does not support creation of sub-controls, yet (%d) sub-controls have been specified.%0
//
#define NS_E_WMP_UI_SUBCONTROLSNOTSUPPORTED _HRESULT_TYPEDEF_(0xC00D0FDEL)

//
// MessageId: NS_E_WMP_UI_VERSIONMISMATCH
//
// MessageText:
//
//  Version mismatch: (%.1f required, %.1f found).%0
//
#define NS_E_WMP_UI_VERSIONMISMATCH      _HRESULT_TYPEDEF_(0xC00D0FDFL)

//
// MessageId: NS_E_WMP_UI_NOTATHEMEFILE
//
// MessageText:
//
//  The layout manager was given valid XML that wasn't a theme file.%0
//
#define NS_E_WMP_UI_NOTATHEMEFILE        _HRESULT_TYPEDEF_(0xC00D0FE0L)

//
// MessageId: NS_E_WMP_UI_SUBELEMENTNOTFOUND
//
// MessageText:
//
//  The %s subelement could not be found on the %s object.%0
//
#define NS_E_WMP_UI_SUBELEMENTNOTFOUND   _HRESULT_TYPEDEF_(0xC00D0FE1L)

//
// MessageId: NS_E_WMP_UI_VERSIONPARSE
//
// MessageText:
//
//  An error occurred parsing the version tag.\nValid version tags are of the form:\n\n\t<?wmp version='1.0'?>.%0
//
#define NS_E_WMP_UI_VERSIONPARSE         _HRESULT_TYPEDEF_(0xC00D0FE2L)

//
// MessageId: NS_E_WMP_UI_VIEWIDNOTFOUND
//
// MessageText:
//
//  The view specified in for the 'currentViewID' property (%s) was not found in this theme file.%0
//
#define NS_E_WMP_UI_VIEWIDNOTFOUND       _HRESULT_TYPEDEF_(0xC00D0FE3L)

//
// MessageId: NS_E_WMP_UI_PASSTHROUGH
//
// MessageText:
//
//  This error used internally for hit testing.%0
//
#define NS_E_WMP_UI_PASSTHROUGH          _HRESULT_TYPEDEF_(0xC00D0FE4L)

//
// MessageId: NS_E_WMP_UI_OBJECTNOTFOUND
//
// MessageText:
//
//  Attributes were specified for the %s object, but the object was not available to send them to.%0
//
#define NS_E_WMP_UI_OBJECTNOTFOUND       _HRESULT_TYPEDEF_(0xC00D0FE5L)

//
// MessageId: NS_E_WMP_UI_SECONDHANDLER
//
// MessageText:
//
//  The %s event already has a handler, the second handler was ignored.%0
//
#define NS_E_WMP_UI_SECONDHANDLER        _HRESULT_TYPEDEF_(0xC00D0FE6L)

//
// MessageId: NS_E_WMP_UI_NOSKININZIP
//
// MessageText:
//
//  No .wms file found in skin archive.%0
//
#define NS_E_WMP_UI_NOSKININZIP          _HRESULT_TYPEDEF_(0xC00D0FE7L)

//
// MessageId: NS_S_WMP_UI_VERSIONMISMATCH
//
// MessageText:
//
//  An upgrade may be needed for the theme manager to correctly show this skin. Skin reports version: %.1f.%0
//
#define NS_S_WMP_UI_VERSIONMISMATCH      _HRESULT_TYPEDEF_(0x000D0FE8L)

//
// MessageId: NS_S_WMP_EXCEPTION
//
// MessageText:
//
//  An error occurred in one of the UI components.%0
//
#define NS_S_WMP_EXCEPTION               _HRESULT_TYPEDEF_(0x000D0FE9L)

//
// MessageId: NS_E_WMP_URLDOWNLOADFAILED
//
// MessageText:
//
//  Windows Media Player cannot save the file.%0
//
#define NS_E_WMP_URLDOWNLOADFAILED       _HRESULT_TYPEDEF_(0xC00D0FEAL)

//
// MessageId: NS_E_WMPOCX_UNABLE_TO_LOAD_SKIN
//
// MessageText:
//
//  The Windows Media Player Control was unable to load the requested uiMode and could not successfully roll back to the existing uiMode.%0
//
#define NS_E_WMPOCX_UNABLE_TO_LOAD_SKIN  _HRESULT_TYPEDEF_(0xC00D0FEBL)

//
// MessageId: NS_E_WMP_INVALID_SKIN
//
// MessageText:
//
//  The skin file is invalid.%0
//
#define NS_E_WMP_INVALID_SKIN            _HRESULT_TYPEDEF_(0xC00D0FECL)

//
// MessageId: NS_E_WMP_SENDMAILFAILED
//
// MessageText:
//
//  Windows Media Player cannot send the link because your e-mail program is not responding. Verify that your e-mail program is configured properly, and then try again. For more information about e-mail, see Windows Help%0
//
#define NS_E_WMP_SENDMAILFAILED          _HRESULT_TYPEDEF_(0xC00D0FEDL)

//Save As
//
// MessageId: NS_E_WMP_SAVEAS_READONLY
//
// MessageText:
//
//  The Windows Media Player cannot overwrite a read only file. Choose another file to save as or change the file attributes.%0
//
#define NS_E_WMP_SAVEAS_READONLY         _HRESULT_TYPEDEF_(0xC00D0FF0L)

//
// WMP Regional button control
//
//
// MessageId: NS_E_WMP_RBC_JPGMAPPINGIMAGE
//
// MessageText:
//
//  JPG Images are not recommended for use as a mappingImage.%0
//
#define NS_E_WMP_RBC_JPGMAPPINGIMAGE     _HRESULT_TYPEDEF_(0xC00D1004L)

//
// MessageId: NS_E_WMP_JPGTRANSPARENCY
//
// MessageText:
//
//  JPG Images are not recommended when using a transparencyColor.%0
//
#define NS_E_WMP_JPGTRANSPARENCY         _HRESULT_TYPEDEF_(0xC00D1005L)

//
// WMP Slider control
//
//
// MessageId: NS_E_WMP_INVALID_MAX_VAL
//
// MessageText:
//
//  The Max property cannot be less than Min property.%0
//
#define NS_E_WMP_INVALID_MAX_VAL         _HRESULT_TYPEDEF_(0xC00D1009L)

//
// MessageId: NS_E_WMP_INVALID_MIN_VAL
//
// MessageText:
//
//  The Min property cannot be greater than Max property.%0
//
#define NS_E_WMP_INVALID_MIN_VAL         _HRESULT_TYPEDEF_(0xC00D100AL)

//
// WMP CustomSlider control
//
//
// MessageId: NS_E_WMP_CS_JPGPOSITIONIMAGE
//
// MessageText:
//
//  JPG Images are not recommended for use as a positionImage.%0
//
#define NS_E_WMP_CS_JPGPOSITIONIMAGE     _HRESULT_TYPEDEF_(0xC00D100EL)

//
// MessageId: NS_E_WMP_CS_NOTEVENLYDIVISIBLE
//
// MessageText:
//
//  The (%s) image's size is not evenly divisible by the positionImage's size.%0
//
#define NS_E_WMP_CS_NOTEVENLYDIVISIBLE   _HRESULT_TYPEDEF_(0xC00D100FL)

//
// WMP ZIP Decoder
//
//
// MessageId: NS_E_WMPZIP_NOTAZIPFILE
//
// MessageText:
//
//  The ZIP reader opened a file and its signature didn't match that of ZIP files.%0
//
#define NS_E_WMPZIP_NOTAZIPFILE          _HRESULT_TYPEDEF_(0xC00D1018L)

//
// MessageId: NS_E_WMPZIP_CORRUPT
//
// MessageText:
//
//  The ZIP reader has detected that the file is corrupt.%0
//
#define NS_E_WMPZIP_CORRUPT              _HRESULT_TYPEDEF_(0xC00D1019L)

//
// MessageId: NS_E_WMPZIP_FILENOTFOUND
//
// MessageText:
//
//  GetFileStream, SaveToFile, or SaveTemp file was called on the ZIP reader with a filename that was not found in the zip file.%0
//
#define NS_E_WMPZIP_FILENOTFOUND         _HRESULT_TYPEDEF_(0xC00D101AL)

//
// WMP Image Decoding Error codes
//
//
// MessageId: NS_E_WMP_IMAGE_FILETYPE_UNSUPPORTED
//
// MessageText:
//
//  Image type not supported.%0
//
#define NS_E_WMP_IMAGE_FILETYPE_UNSUPPORTED _HRESULT_TYPEDEF_(0xC00D1022L)

//
// MessageId: NS_E_WMP_IMAGE_INVALID_FORMAT
//
// MessageText:
//
//  Image file may be corrupt.%0
//
#define NS_E_WMP_IMAGE_INVALID_FORMAT    _HRESULT_TYPEDEF_(0xC00D1023L)

//
// MessageId: NS_E_WMP_GIF_UNEXPECTED_ENDOFFILE
//
// MessageText:
//
//  Unexpected end of file. GIF file may be corrupt.%0
//
#define NS_E_WMP_GIF_UNEXPECTED_ENDOFFILE _HRESULT_TYPEDEF_(0xC00D1024L)

//
// MessageId: NS_E_WMP_GIF_INVALID_FORMAT
//
// MessageText:
//
//  Invalid GIF file.%0
//
#define NS_E_WMP_GIF_INVALID_FORMAT      _HRESULT_TYPEDEF_(0xC00D1025L)

//
// MessageId: NS_E_WMP_GIF_BAD_VERSION_NUMBER
//
// MessageText:
//
//  Invalid GIF version. Only 87a or 89a supported.%0
//
#define NS_E_WMP_GIF_BAD_VERSION_NUMBER  _HRESULT_TYPEDEF_(0xC00D1026L)

//
// MessageId: NS_E_WMP_GIF_NO_IMAGE_IN_FILE
//
// MessageText:
//
//  No images found in GIF file.%0
//
#define NS_E_WMP_GIF_NO_IMAGE_IN_FILE    _HRESULT_TYPEDEF_(0xC00D1027L)

//
// MessageId: NS_E_WMP_PNG_INVALIDFORMAT
//
// MessageText:
//
//  Invalid PNG image file format.%0
//
#define NS_E_WMP_PNG_INVALIDFORMAT       _HRESULT_TYPEDEF_(0xC00D1028L)

//
// MessageId: NS_E_WMP_PNG_UNSUPPORTED_BITDEPTH
//
// MessageText:
//
//  PNG bitdepth not supported.%0
//
#define NS_E_WMP_PNG_UNSUPPORTED_BITDEPTH _HRESULT_TYPEDEF_(0xC00D1029L)

//
// MessageId: NS_E_WMP_PNG_UNSUPPORTED_COMPRESSION
//
// MessageText:
//
//  Compression format defined in PNG file not supported,%0
//
#define NS_E_WMP_PNG_UNSUPPORTED_COMPRESSION _HRESULT_TYPEDEF_(0xC00D102AL)

//
// MessageId: NS_E_WMP_PNG_UNSUPPORTED_FILTER
//
// MessageText:
//
//  Filter method defined in PNG file not supported.%0
//
#define NS_E_WMP_PNG_UNSUPPORTED_FILTER  _HRESULT_TYPEDEF_(0xC00D102BL)

//
// MessageId: NS_E_WMP_PNG_UNSUPPORTED_INTERLACE
//
// MessageText:
//
//  Interlace method defined in PNG file not supported.%0
//
#define NS_E_WMP_PNG_UNSUPPORTED_INTERLACE _HRESULT_TYPEDEF_(0xC00D102CL)

//
// MessageId: NS_E_WMP_PNG_UNSUPPORTED_BAD_CRC
//
// MessageText:
//
//  Bad CRC in PNG file.%0
//
#define NS_E_WMP_PNG_UNSUPPORTED_BAD_CRC _HRESULT_TYPEDEF_(0xC00D102DL)

//
// MessageId: NS_E_WMP_BMP_INVALID_BITMASK
//
// MessageText:
//
//  Invalid bitmask in BMP file.%0
//
#define NS_E_WMP_BMP_INVALID_BITMASK     _HRESULT_TYPEDEF_(0xC00D102EL)

//
// MessageId: NS_E_WMP_BMP_TOPDOWN_DIB_UNSUPPORTED
//
// MessageText:
//
//  Topdown DIB not supported.%0
//
#define NS_E_WMP_BMP_TOPDOWN_DIB_UNSUPPORTED _HRESULT_TYPEDEF_(0xC00D102FL)

//
// MessageId: NS_E_WMP_BMP_BITMAP_NOT_CREATED
//
// MessageText:
//
//  Bitmap could not be created.%0
//
#define NS_E_WMP_BMP_BITMAP_NOT_CREATED  _HRESULT_TYPEDEF_(0xC00D1030L)

//
// MessageId: NS_E_WMP_BMP_COMPRESSION_UNSUPPORTED
//
// MessageText:
//
//  Compression format defined in BMP not supported.%0
//
#define NS_E_WMP_BMP_COMPRESSION_UNSUPPORTED _HRESULT_TYPEDEF_(0xC00D1031L)

//
// MessageId: NS_E_WMP_BMP_INVALID_FORMAT
//
// MessageText:
//
//  Invalid Bitmap format.%0
//
#define NS_E_WMP_BMP_INVALID_FORMAT      _HRESULT_TYPEDEF_(0xC00D1032L)

//
// MessageId: NS_E_WMP_JPG_JERR_ARITHCODING_NOTIMPL
//
// MessageText:
//
//  JPEG Arithmetic coding not supported.%0
//
#define NS_E_WMP_JPG_JERR_ARITHCODING_NOTIMPL _HRESULT_TYPEDEF_(0xC00D1033L)

//
// MessageId: NS_E_WMP_JPG_INVALID_FORMAT
//
// MessageText:
//
//  Invalid JPEG format.%0
//
#define NS_E_WMP_JPG_INVALID_FORMAT      _HRESULT_TYPEDEF_(0xC00D1034L)

//
// MessageId: NS_E_WMP_JPG_BAD_DCTSIZE
//
// MessageText:
//
//  Invalid JPEG format.%0
//
#define NS_E_WMP_JPG_BAD_DCTSIZE         _HRESULT_TYPEDEF_(0xC00D1035L)

//
// MessageId: NS_E_WMP_JPG_BAD_VERSION_NUMBER
//
// MessageText:
//
//  Internal version error. Unexpected JPEG library version.%0
//
#define NS_E_WMP_JPG_BAD_VERSION_NUMBER  _HRESULT_TYPEDEF_(0xC00D1036L)

//
// MessageId: NS_E_WMP_JPG_BAD_PRECISION
//
// MessageText:
//
//  Internal JPEG Library error. Unsupported JPEG data precision.%0
//
#define NS_E_WMP_JPG_BAD_PRECISION       _HRESULT_TYPEDEF_(0xC00D1037L)

//
// MessageId: NS_E_WMP_JPG_CCIR601_NOTIMPL
//
// MessageText:
//
//  JPEG CCIR601 not supported.%0
//
#define NS_E_WMP_JPG_CCIR601_NOTIMPL     _HRESULT_TYPEDEF_(0xC00D1038L)

//
// MessageId: NS_E_WMP_JPG_NO_IMAGE_IN_FILE
//
// MessageText:
//
//  No image found in JPEG file.%0
//
#define NS_E_WMP_JPG_NO_IMAGE_IN_FILE    _HRESULT_TYPEDEF_(0xC00D1039L)

//
// MessageId: NS_E_WMP_JPG_READ_ERROR
//
// MessageText:
//
//  Could not read JPEG file.%0
//
#define NS_E_WMP_JPG_READ_ERROR          _HRESULT_TYPEDEF_(0xC00D103AL)

//
// MessageId: NS_E_WMP_JPG_FRACT_SAMPLE_NOTIMPL
//
// MessageText:
//
//  JPEG Fractional sampling not supported.%0
//
#define NS_E_WMP_JPG_FRACT_SAMPLE_NOTIMPL _HRESULT_TYPEDEF_(0xC00D103BL)

//
// MessageId: NS_E_WMP_JPG_IMAGE_TOO_BIG
//
// MessageText:
//
//  JPEG image too large. Maximum image size supported is 65500 X 65500.%0
//
#define NS_E_WMP_JPG_IMAGE_TOO_BIG       _HRESULT_TYPEDEF_(0xC00D103CL)

//
// MessageId: NS_E_WMP_JPG_UNEXPECTED_ENDOFFILE
//
// MessageText:
//
//  Unexpected end of file reached in JPEG file.%0
//
#define NS_E_WMP_JPG_UNEXPECTED_ENDOFFILE _HRESULT_TYPEDEF_(0xC00D103DL)

//
// MessageId: NS_E_WMP_JPG_SOF_UNSUPPORTED
//
// MessageText:
//
//  Unsupported JPEG SOF marker found.%0
//
#define NS_E_WMP_JPG_SOF_UNSUPPORTED     _HRESULT_TYPEDEF_(0xC00D103EL)

//
// MessageId: NS_E_WMP_JPG_UNKNOWN_MARKER
//
// MessageText:
//
//  Unknown JPEG marker found.%0
//
#define NS_E_WMP_JPG_UNKNOWN_MARKER      _HRESULT_TYPEDEF_(0xC00D103FL)

//
// MessageId: NS_S_WMP_LOADED_GIF_IMAGE
//
// MessageText:
//
//  Successfully loaded a GIF file.%0
//
#define NS_S_WMP_LOADED_GIF_IMAGE        _HRESULT_TYPEDEF_(0x000D1040L)

//
// MessageId: NS_S_WMP_LOADED_PNG_IMAGE
//
// MessageText:
//
//  Successfully loaded a PNG file.%0
//
#define NS_S_WMP_LOADED_PNG_IMAGE        _HRESULT_TYPEDEF_(0x000D1041L)

//
// MessageId: NS_S_WMP_LOADED_BMP_IMAGE
//
// MessageText:
//
//  Successfully loaded a BMP file.%0
//
#define NS_S_WMP_LOADED_BMP_IMAGE        _HRESULT_TYPEDEF_(0x000D1042L)

//
// MessageId: NS_S_WMP_LOADED_JPG_IMAGE
//
// MessageText:
//
//  Successfully loaded a JPG file.%0
//
#define NS_S_WMP_LOADED_JPG_IMAGE        _HRESULT_TYPEDEF_(0x000D1043L)

//
// WMP WM Runtime Error codes
//
//
// MessageId: NS_E_WMG_RATEUNAVAILABLE
//
// MessageText:
//
//  The requested playback rate is unavailable on this content.%0
//
#define NS_E_WMG_RATEUNAVAILABLE         _HRESULT_TYPEDEF_(0xC00D104AL)

//
// MessageId: NS_E_WMG_PLUGINUNAVAILABLE
//
// MessageText:
//
//  The rendering or digital signal processing plugin could not be instantiated.%0
//
#define NS_E_WMG_PLUGINUNAVAILABLE       _HRESULT_TYPEDEF_(0xC00D104BL)

//
// MessageId: NS_E_WMG_CANNOTQUEUE
//
// MessageText:
//
//  The file cannot be queued for seamless playback.%0
//
#define NS_E_WMG_CANNOTQUEUE             _HRESULT_TYPEDEF_(0xC00D104CL)

//
// MessageId: NS_E_WMG_PREROLLLICENSEACQUISITIONNOTALLOWED
//
// MessageText:
//
//  Windows Media Player cannot acquire the license for a file that is being prerolled.%0
//
#define NS_E_WMG_PREROLLLICENSEACQUISITIONNOTALLOWED _HRESULT_TYPEDEF_(0xC00D104DL)

//
// MessageId: NS_E_WMG_UNEXPECTEDPREROLLSTATUS
//
// MessageText:
//
//  Windows Media Player received an unexpected message while attempting to preroll a file.%0
//
#define NS_E_WMG_UNEXPECTEDPREROLLSTATUS _HRESULT_TYPEDEF_(0xC00D104EL)

//
// MessageId: NS_E_WMG_INVALIDSTATE
//
// MessageText:
//
//  Operation attempted in an invalid graph state.%0
//
#define NS_E_WMG_INVALIDSTATE            _HRESULT_TYPEDEF_(0xC00D1054L)

//
// MessageId: NS_E_WMG_SINKALREADYEXISTS
//
// MessageText:
//
//  A renderer cannot be inserted in a stream while one already exists.%0
//
#define NS_E_WMG_SINKALREADYEXISTS       _HRESULT_TYPEDEF_(0xC00D1055L)

//
// MessageId: NS_E_WMG_NOSDKINTERFACE
//
// MessageText:
//
//  A necessary WM SDK interface to complete the operation doesn't exist at this time.%0
//
#define NS_E_WMG_NOSDKINTERFACE          _HRESULT_TYPEDEF_(0xC00D1056L)

//
// MessageId: NS_E_WMG_NOTALLOUTPUTSRENDERED
//
// MessageText:
//
//  Windows Media Player cannot play the file. The file may be formatted with an unsupported codec, or the Player could not download the codec.%0
//
#define NS_E_WMG_NOTALLOUTPUTSRENDERED   _HRESULT_TYPEDEF_(0xC00D1057L)

//
// MessageId: NS_E_WMG_FILETRANSFERNOTALLOWED
//
// MessageText:
//
//  File transfer streams are not allowed in the stand alone player.%0
//
#define NS_E_WMG_FILETRANSFERNOTALLOWED  _HRESULT_TYPEDEF_(0xC00D1058L)

//
// MessageId: NS_E_WMR_UNSUPPORTEDSTREAM
//
// MessageText:
//
//  Windows Media Player cannot play the file. The Player does not support the format you are trying to play.%0
//
#define NS_E_WMR_UNSUPPORTEDSTREAM       _HRESULT_TYPEDEF_(0xC00D1059L)

//
// MessageId: NS_E_WMR_PINNOTFOUND
//
// MessageText:
//
//  An operation was attempted on a pin that doesn't exist in the DirectShow filter graph.%0
//
#define NS_E_WMR_PINNOTFOUND             _HRESULT_TYPEDEF_(0xC00D105AL)

//
// MessageId: NS_E_WMR_WAITINGONFORMATSWITCH
//
// MessageText:
//
//  Specified operation cannot be completed while waiting for a media format change from the SDK.%0
//
#define NS_E_WMR_WAITINGONFORMATSWITCH   _HRESULT_TYPEDEF_(0xC00D105BL)

//
// MessageId: NS_E_WMR_NOSOURCEFILTER
//
// MessageText:
//
//  Specified operation cannot be completed because the source filter does not exist.%0
//
#define NS_E_WMR_NOSOURCEFILTER          _HRESULT_TYPEDEF_(0xC00D105CL)

//
// MessageId: NS_E_WMR_PINTYPENOMATCH
//
// MessageText:
//
//  The specified type does not match this pin.%0
//
#define NS_E_WMR_PINTYPENOMATCH          _HRESULT_TYPEDEF_(0xC00D105DL)

//
// MessageId: NS_E_WMR_NOCALLBACKAVAILABLE
//
// MessageText:
//
//  The WMR Source Filter does not have a callback available.%0
//
#define NS_E_WMR_NOCALLBACKAVAILABLE     _HRESULT_TYPEDEF_(0xC00D105EL)

//
// MessageId: NS_S_WMR_ALREADYRENDERED
//
// MessageText:
//
//  The specified stream has already been rendered.%0
//
#define NS_S_WMR_ALREADYRENDERED         _HRESULT_TYPEDEF_(0x000D105FL)

//
// MessageId: NS_S_WMR_PINTYPEPARTIALMATCH
//
// MessageText:
//
//  The specified type partially matches this pin type.%0
//
#define NS_S_WMR_PINTYPEPARTIALMATCH     _HRESULT_TYPEDEF_(0x000D1060L)

//
// MessageId: NS_S_WMR_PINTYPEFULLMATCH
//
// MessageText:
//
//  The specified type fully matches this pin type.%0
//
#define NS_S_WMR_PINTYPEFULLMATCH        _HRESULT_TYPEDEF_(0x000D1061L)

//
// MessageId: NS_E_WMR_SAMPLEPROPERTYNOTSET
//
// MessageText:
//
//  The specified property has not been set on this sample.%0
//
#define NS_E_WMR_SAMPLEPROPERTYNOTSET    _HRESULT_TYPEDEF_(0xC00D1062L)

//
// MessageId: NS_E_WMR_CANNOT_RENDER_BINARY_STREAM
//
// MessageText:
//
//  A plugin is required to correctly play this file. To determine if this plugin is available to download from the Web, click Web Help.%0
//
#define NS_E_WMR_CANNOT_RENDER_BINARY_STREAM _HRESULT_TYPEDEF_(0xC00D1063L)

//
// MessageId: NS_E_WMG_LICENSE_TAMPERED
//
// MessageText:
//
//  The file cannot be played, the content has been tampered.%0
//
#define NS_E_WMG_LICENSE_TAMPERED        _HRESULT_TYPEDEF_(0xC00D1064L)

//
// MessageId: NS_E_WMR_WILLNOT_RENDER_BINARY_STREAM
//
// MessageText:
//
//  The content you are trying to play is protected content and the player will not render binary streams from protected content.%0
//
#define NS_E_WMR_WILLNOT_RENDER_BINARY_STREAM _HRESULT_TYPEDEF_(0xC00D1065L)

//
// WMP Playlist Error codes
//
//
// MessageId: NS_E_WMX_UNRECOGNIZED_PLAYLIST_FORMAT
//
// MessageText:
//
//  The format of this file was not recognized as a valid playlist format.%0
//
#define NS_E_WMX_UNRECOGNIZED_PLAYLIST_FORMAT _HRESULT_TYPEDEF_(0xC00D1068L)

//
// MessageId: NS_E_ASX_INVALIDFORMAT
//
// MessageText:
//
//  This file was believed to be an ASX playlist, but the format was not recognized.%0
//
#define NS_E_ASX_INVALIDFORMAT           _HRESULT_TYPEDEF_(0xC00D1069L)

//
// MessageId: NS_E_ASX_INVALIDVERSION
//
// MessageText:
//
//  The version of this playlist is not supported. Click More Information to go to the Microsoft web site and see if there is a newer version of the player to install.%0
//
#define NS_E_ASX_INVALIDVERSION          _HRESULT_TYPEDEF_(0xC00D106AL)

//
// MessageId: NS_E_ASX_INVALID_REPEAT_BLOCK
//
// MessageText:
//
//  Format of a REPEAT loop within the current playlist file is invalid.%0
//
#define NS_E_ASX_INVALID_REPEAT_BLOCK    _HRESULT_TYPEDEF_(0xC00D106BL)

//
// MessageId: NS_E_ASX_NOTHING_TO_WRITE
//
// MessageText:
//
//  Windows Media Player cannot export the playlist because it is empty.%0
//
#define NS_E_ASX_NOTHING_TO_WRITE        _HRESULT_TYPEDEF_(0xC00D106CL)

//
// MessageId: NS_E_URLLIST_INVALIDFORMAT
//
// MessageText:
//
//  Windows Media Player does not recognize this file as a supported playlist.%0
//
#define NS_E_URLLIST_INVALIDFORMAT       _HRESULT_TYPEDEF_(0xC00D106DL)

//
// MessageId: NS_E_WMX_ATTRIBUTE_DOES_NOT_EXIST
//
// MessageText:
//
//  The specified attribute does not exist.%0
//
#define NS_E_WMX_ATTRIBUTE_DOES_NOT_EXIST _HRESULT_TYPEDEF_(0xC00D106EL)

//
// MessageId: NS_E_WMX_ATTRIBUTE_ALREADY_EXISTS
//
// MessageText:
//
//  The specified attribute already exists.%0
//
#define NS_E_WMX_ATTRIBUTE_ALREADY_EXISTS _HRESULT_TYPEDEF_(0xC00D106FL)

//
// MessageId: NS_E_WMX_ATTRIBUTE_UNRETRIEVABLE
//
// MessageText:
//
//  Can not retrieve the specified attribute.%0
//
#define NS_E_WMX_ATTRIBUTE_UNRETRIEVABLE _HRESULT_TYPEDEF_(0xC00D1070L)

//
// MessageId: NS_E_WMX_ITEM_DOES_NOT_EXIST
//
// MessageText:
//
//  The specified item does not exist in the current playlist.%0
//
#define NS_E_WMX_ITEM_DOES_NOT_EXIST     _HRESULT_TYPEDEF_(0xC00D1071L)

//
// MessageId: NS_E_WMX_ITEM_TYPE_ILLEGAL
//
// MessageText:
//
//  Items of the specified type can not be created within the current playlist.%0
//
#define NS_E_WMX_ITEM_TYPE_ILLEGAL       _HRESULT_TYPEDEF_(0xC00D1072L)

//
// MessageId: NS_E_WMX_ITEM_UNSETTABLE
//
// MessageText:
//
//  The specified item can not be set in the current playlist.%0
//
#define NS_E_WMX_ITEM_UNSETTABLE         _HRESULT_TYPEDEF_(0xC00D1073L)

//
// MessageId: NS_E_WMX_PLAYLIST_EMPTY
//
// MessageText:
//
//  The specified playlist is empty.%0
//
#define NS_E_WMX_PLAYLIST_EMPTY          _HRESULT_TYPEDEF_(0xC00D1074L)

//
// MessageId: NS_E_MLS_SMARTPLAYLIST_FILTER_NOT_REGISTERED
//
// MessageText:
//
//  Playlist load error: The specified autoplaylist contains a filter type which is either invalid or is not installed on this computer%0
//
#define NS_E_MLS_SMARTPLAYLIST_FILTER_NOT_REGISTERED _HRESULT_TYPEDEF_(0xC00D1075L)

//
// MessageId: NS_E_WMX_INVALID_FORMAT_OVER_NESTING
//
// MessageText:
//
//  Windows Media Player cannot play the file because the associated Windows Media metafile playlist is not valid.%0
//
#define NS_E_WMX_INVALID_FORMAT_OVER_NESTING _HRESULT_TYPEDEF_(0xC00D1076L)

//
// WMP Core  Error codes
//
//
// MessageId: NS_E_WMPCORE_NOSOURCEURLSTRING
//
// MessageText:
//
//  Windows Media Player cannot find the file. Be sure the path is typed correctly. If it is, the file may not exist in the specified location, or the computer where the file is stored may be offline.%0
//
#define NS_E_WMPCORE_NOSOURCEURLSTRING   _HRESULT_TYPEDEF_(0xC00D107CL)

//
// MessageId: NS_E_WMPCORE_COCREATEFAILEDFORGITOBJECT
//
// MessageText:
//
//  Failed to create the Global Interface Table.%0
//
#define NS_E_WMPCORE_COCREATEFAILEDFORGITOBJECT _HRESULT_TYPEDEF_(0xC00D107DL)

//
// MessageId: NS_E_WMPCORE_FAILEDTOGETMARSHALLEDEVENTHANDLERINTERFACE
//
// MessageText:
//
//  Failed to get the marshaled graph event handler interface.%0
//
#define NS_E_WMPCORE_FAILEDTOGETMARSHALLEDEVENTHANDLERINTERFACE _HRESULT_TYPEDEF_(0xC00D107EL)

//
// MessageId: NS_E_WMPCORE_BUFFERTOOSMALL
//
// MessageText:
//
//  Buffer is too small for copying media type.%0
//
#define NS_E_WMPCORE_BUFFERTOOSMALL      _HRESULT_TYPEDEF_(0xC00D107FL)

//
// MessageId: NS_E_WMPCORE_UNAVAILABLE
//
// MessageText:
//
//  Current state of the player does not allow the operation.%0
//
#define NS_E_WMPCORE_UNAVAILABLE         _HRESULT_TYPEDEF_(0xC00D1080L)

//
// MessageId: NS_E_WMPCORE_INVALIDPLAYLISTMODE
//
// MessageText:
//
//  Playlist manager does not understand the current play mode (shuffle, normal etc).%0
//
#define NS_E_WMPCORE_INVALIDPLAYLISTMODE _HRESULT_TYPEDEF_(0xC00D1081L)

//
// MessageId: NS_E_WMPCORE_ITEMNOTINPLAYLIST
//
// MessageText:
//
//  The item is not in the playlist.%0
//
#define NS_E_WMPCORE_ITEMNOTINPLAYLIST   _HRESULT_TYPEDEF_(0xC00D1086L)

//
// MessageId: NS_E_WMPCORE_PLAYLISTEMPTY
//
// MessageText:
//
//  There are no items in this playlist. Add items to the playlist, and try again.%0
//
#define NS_E_WMPCORE_PLAYLISTEMPTY       _HRESULT_TYPEDEF_(0xC00D1087L)

//
// MessageId: NS_E_WMPCORE_NOBROWSER
//
// MessageText:
//
//  The Web site cannot be accessed. A Web browser is not detected on your computer.%0
//
#define NS_E_WMPCORE_NOBROWSER           _HRESULT_TYPEDEF_(0xC00D1088L)

//
// MessageId: NS_E_WMPCORE_UNRECOGNIZED_MEDIA_URL
//
// MessageText:
//
//  Windows Media Player cannot find the specified file. Be sure the path is typed correctly. If it is, the file does not exist in the specified location, or the computer where the file is stored is offline.%0
//
#define NS_E_WMPCORE_UNRECOGNIZED_MEDIA_URL _HRESULT_TYPEDEF_(0xC00D1089L)

//
// MessageId: NS_E_WMPCORE_GRAPH_NOT_IN_LIST
//
// MessageText:
//
//  Graph with the specified URL was not found in the prerolled graph list.%0
//
#define NS_E_WMPCORE_GRAPH_NOT_IN_LIST   _HRESULT_TYPEDEF_(0xC00D108AL)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_EMPTY_OR_SINGLE_MEDIA
//
// MessageText:
//
//  There is only one item in the playlist.%0
//
#define NS_E_WMPCORE_PLAYLIST_EMPTY_OR_SINGLE_MEDIA _HRESULT_TYPEDEF_(0xC00D108BL)

//
// MessageId: NS_E_WMPCORE_ERRORSINKNOTREGISTERED
//
// MessageText:
//
//  An error sink was never registered for the calling object.%0
//
#define NS_E_WMPCORE_ERRORSINKNOTREGISTERED _HRESULT_TYPEDEF_(0xC00D108CL)

//
// MessageId: NS_E_WMPCORE_ERRORMANAGERNOTAVAILABLE
//
// MessageText:
//
//  The error manager is not available to respond to errors.%0
//
#define NS_E_WMPCORE_ERRORMANAGERNOTAVAILABLE _HRESULT_TYPEDEF_(0xC00D108DL)

//
// MessageId: NS_E_WMPCORE_WEBHELPFAILED
//
// MessageText:
//
//  Failed launching WebHelp URL.%0
//
#define NS_E_WMPCORE_WEBHELPFAILED       _HRESULT_TYPEDEF_(0xC00D108EL)

//
// MessageId: NS_E_WMPCORE_MEDIA_ERROR_RESUME_FAILED
//
// MessageText:
//
//  Could not resume playing next item in playlist.%0
//
#define NS_E_WMPCORE_MEDIA_ERROR_RESUME_FAILED _HRESULT_TYPEDEF_(0xC00D108FL)

//
// MessageId: NS_E_WMPCORE_NO_REF_IN_ENTRY
//
// MessageText:
//
//  Windows Media Player cannot play the file because the associated Windows Media metafile playlist is not valid.%0
//
#define NS_E_WMPCORE_NO_REF_IN_ENTRY     _HRESULT_TYPEDEF_(0xC00D1090L)

//
// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_EMPTY
//
// MessageText:
//
//  An empty string for playlist attribute name was found.%0
//
#define NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_EMPTY _HRESULT_TYPEDEF_(0xC00D1091L)

//
// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_ILLEGAL
//
// MessageText:
//
//  An invalid playlist attribute name was found.%0
//
#define NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_ILLEGAL _HRESULT_TYPEDEF_(0xC00D1092L)

//
// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_EMPTY
//
// MessageText:
//
//  An empty string for a playlist attribute value was found.%0
//
#define NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_EMPTY _HRESULT_TYPEDEF_(0xC00D1093L)

//
// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_ILLEGAL
//
// MessageText:
//
//  An illegal value for a playlist attribute was found.%0
//
#define NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_ILLEGAL _HRESULT_TYPEDEF_(0xC00D1094L)

//
// MessageId: NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_EMPTY
//
// MessageText:
//
//  An empty string for a playlist item attribute name was found.%0
//
#define NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_EMPTY _HRESULT_TYPEDEF_(0xC00D1095L)

//
// MessageId: NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_ILLEGAL
//
// MessageText:
//
//  An illegal value for a playlist item attribute name was found.%0
//
#define NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_ILLEGAL _HRESULT_TYPEDEF_(0xC00D1096L)

//
// MessageId: NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_VALUE_EMPTY
//
// MessageText:
//
//  An illegal value for a playlist item attribute was found.%0
//
#define NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_VALUE_EMPTY _HRESULT_TYPEDEF_(0xC00D1097L)

//
// MessageId: NS_E_WMPCORE_LIST_ENTRY_NO_REF
//
// MessageText:
//
//  No entries found in the playlist file.%0
//
#define NS_E_WMPCORE_LIST_ENTRY_NO_REF   _HRESULT_TYPEDEF_(0xC00D1098L)

//
// MessageId: NS_E_WMPCORE_MISNAMED_FILE
//
// MessageText:
//
//  Windows Media Player cannot play the file. The file is either corrupt or the Player does not support the format you are trying to play.%0
//
#define NS_E_WMPCORE_MISNAMED_FILE       _HRESULT_TYPEDEF_(0xC00D1099L)

//
// MessageId: NS_E_WMPCORE_CODEC_NOT_TRUSTED
//
// MessageText:
//
//  The codec downloaded for this media does not appear to be properly signed. Installation is not possible.%0
//
#define NS_E_WMPCORE_CODEC_NOT_TRUSTED   _HRESULT_TYPEDEF_(0xC00D109AL)

//
// MessageId: NS_E_WMPCORE_CODEC_NOT_FOUND
//
// MessageText:
//
//  Windows Media Player cannot play the file. One or more codecs required to play the file could not be found.%0
//
#define NS_E_WMPCORE_CODEC_NOT_FOUND     _HRESULT_TYPEDEF_(0xC00D109BL)

//
// MessageId: NS_E_WMPCORE_CODEC_DOWNLOAD_NOT_ALLOWED
//
// MessageText:
//
//  Some of the codecs required by this media are not installed on your system. Since the option for automatic codec acquisition is disabled, no codecs will be downloaded.%0
//
#define NS_E_WMPCORE_CODEC_DOWNLOAD_NOT_ALLOWED _HRESULT_TYPEDEF_(0xC00D109CL)

//
// MessageId: NS_E_WMPCORE_ERROR_DOWNLOADING_PLAYLIST
//
// MessageText:
//
//  Failed to download the playlist file.%0
//
#define NS_E_WMPCORE_ERROR_DOWNLOADING_PLAYLIST _HRESULT_TYPEDEF_(0xC00D109DL)

//
// MessageId: NS_E_WMPCORE_FAILED_TO_BUILD_PLAYLIST
//
// MessageText:
//
//  Failed to build the playlist.%0
//
#define NS_E_WMPCORE_FAILED_TO_BUILD_PLAYLIST _HRESULT_TYPEDEF_(0xC00D109EL)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NONE
//
// MessageText:
//
//  Playlist has no alternates to switch into.%0
//
#define NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NONE _HRESULT_TYPEDEF_(0xC00D109FL)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_EXHAUSTED
//
// MessageText:
//
//  No more playlist alternates available to switch to.%0
//
#define NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_EXHAUSTED _HRESULT_TYPEDEF_(0xC00D10A0L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NAME_NOT_FOUND
//
// MessageText:
//
//  Could not find the name of the alternate playlist to switch into.%0
//
#define NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NAME_NOT_FOUND _HRESULT_TYPEDEF_(0xC00D10A1L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_MORPH_FAILED
//
// MessageText:
//
//  Failed to switch to an alternate for this media.%0
//
#define NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_MORPH_FAILED _HRESULT_TYPEDEF_(0xC00D10A2L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_INIT_FAILED
//
// MessageText:
//
//  Failed to initialize an alternate for the media.%0
//
#define NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_INIT_FAILED _HRESULT_TYPEDEF_(0xC00D10A3L)

//
// MessageId: NS_E_WMPCORE_MEDIA_ALTERNATE_REF_EMPTY
//
// MessageText:
//
//  No URL specified for the roll over Refs in the playlist file.%0
//
#define NS_E_WMPCORE_MEDIA_ALTERNATE_REF_EMPTY _HRESULT_TYPEDEF_(0xC00D10A4L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_NO_EVENT_NAME
//
// MessageText:
//
//  Encountered a playlist with no name.%0
//
#define NS_E_WMPCORE_PLAYLIST_NO_EVENT_NAME _HRESULT_TYPEDEF_(0xC00D10A5L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_EVENT_ATTRIBUTE_ABSENT
//
// MessageText:
//
//  A required attribute in the event block of the playlist was not found.%0
//
#define NS_E_WMPCORE_PLAYLIST_EVENT_ATTRIBUTE_ABSENT _HRESULT_TYPEDEF_(0xC00D10A6L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_EVENT_EMPTY
//
// MessageText:
//
//  No items were found in the event block of the playlist.%0
//
#define NS_E_WMPCORE_PLAYLIST_EVENT_EMPTY _HRESULT_TYPEDEF_(0xC00D10A7L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_STACK_EMPTY
//
// MessageText:
//
//  No playlist was found while returning from a nested playlist.%0
//
#define NS_E_WMPCORE_PLAYLIST_STACK_EMPTY _HRESULT_TYPEDEF_(0xC00D10A8L)

//
// MessageId: NS_E_WMPCORE_CURRENT_MEDIA_NOT_ACTIVE
//
// MessageText:
//
//  The media item is not active currently.%0
//
#define NS_E_WMPCORE_CURRENT_MEDIA_NOT_ACTIVE _HRESULT_TYPEDEF_(0xC00D10A9L)

//
// MessageId: NS_E_WMPCORE_USER_CANCEL
//
// MessageText:
//
//  Open was aborted by user.%0
//
#define NS_E_WMPCORE_USER_CANCEL         _HRESULT_TYPEDEF_(0xC00D10ABL)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_REPEAT_EMPTY
//
// MessageText:
//
//  No items were found inside the playlist repeat block.%0
//
#define NS_E_WMPCORE_PLAYLIST_REPEAT_EMPTY _HRESULT_TYPEDEF_(0xC00D10ACL)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_REPEAT_START_MEDIA_NONE
//
// MessageText:
//
//  Media object corresponding to start of a playlist repeat block was not found.%0
//
#define NS_E_WMPCORE_PLAYLIST_REPEAT_START_MEDIA_NONE _HRESULT_TYPEDEF_(0xC00D10ADL)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_REPEAT_END_MEDIA_NONE
//
// MessageText:
//
//  Media object corresponding to the end of a playlist repeat block was not found.%0
//
#define NS_E_WMPCORE_PLAYLIST_REPEAT_END_MEDIA_NONE _HRESULT_TYPEDEF_(0xC00D10AEL)

//
// MessageId: NS_E_WMPCORE_INVALID_PLAYLIST_URL
//
// MessageText:
//
//  Playlist URL supplied to the playlist manager is invalid.%0
//
#define NS_E_WMPCORE_INVALID_PLAYLIST_URL _HRESULT_TYPEDEF_(0xC00D10AFL)

//
// MessageId: NS_E_WMPCORE_MISMATCHED_RUNTIME
//
// MessageText:
//
//  Windows Media Player cannot play the file because it is corrupted.%0
//
#define NS_E_WMPCORE_MISMATCHED_RUNTIME  _HRESULT_TYPEDEF_(0xC00D10B0L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_IMPORT_FAILED_NO_ITEMS
//
// MessageText:
//
//  Windows Media Player cannot import the playlist to Media Library because the playlist is empty.%0
//
#define NS_E_WMPCORE_PLAYLIST_IMPORT_FAILED_NO_ITEMS _HRESULT_TYPEDEF_(0xC00D10B1L)

//
// MessageId: NS_E_WMPCORE_VIDEO_TRANSFORM_FILTER_INSERTION
//
// MessageText:
//
//  An error has occurred that could prevent the changing of the video contrast on this media.%0
//
#define NS_E_WMPCORE_VIDEO_TRANSFORM_FILTER_INSERTION _HRESULT_TYPEDEF_(0xC00D10B2L)

//
// MessageId: NS_E_WMPCORE_MEDIA_UNAVAILABLE
//
// MessageText:
//
//  Windows Media Player cannot play this file. Connect to the Internet or insert the removable media on which the file is located, and then try to play the file again.%0
//
#define NS_E_WMPCORE_MEDIA_UNAVAILABLE   _HRESULT_TYPEDEF_(0xC00D10B3L)

//
// MessageId: NS_E_WMPCORE_WMX_ENTRYREF_NO_REF
//
// MessageText:
//
//  The playlist contains an ENTRYREF for which no href was parsed. Check the syntax of playlist file.%0
//
#define NS_E_WMPCORE_WMX_ENTRYREF_NO_REF _HRESULT_TYPEDEF_(0xC00D10B4L)

//
// MessageId: NS_E_WMPCORE_NO_PLAYABLE_MEDIA_IN_PLAYLIST
//
// MessageText:
//
//  Windows Media Player cannot play any items in this playlist. For additional information, right-click an item that cannot be played, and then click Error Details.%0
//
#define NS_E_WMPCORE_NO_PLAYABLE_MEDIA_IN_PLAYLIST _HRESULT_TYPEDEF_(0xC00D10B5L)

//
// MessageId: NS_E_WMPCORE_PLAYLIST_EMPTY_NESTED_PLAYLIST_SKIPPED_ITEMS
//
// MessageText:
//
//  Windows Media Player cannot play some or all of the playlist items.%0
//
#define NS_E_WMPCORE_PLAYLIST_EMPTY_NESTED_PLAYLIST_SKIPPED_ITEMS _HRESULT_TYPEDEF_(0xC00D10B6L)

//
// MessageId: NS_E_WMPCORE_BUSY
//
// MessageText:
//
//  Windows Media Player cannot play the file at this time. Try again later.%0
//
#define NS_E_WMPCORE_BUSY                _HRESULT_TYPEDEF_(0xC00D10B7L)

//
// MessageId: NS_E_WMPCORE_MEDIA_CHILD_PLAYLIST_UNAVAILABLE
//
// MessageText:
//
//  There is no child playlist available for this media item at this time.%0
//
#define NS_E_WMPCORE_MEDIA_CHILD_PLAYLIST_UNAVAILABLE _HRESULT_TYPEDEF_(0xC00D10B8L)

//
// MessageId: NS_E_WMPCORE_MEDIA_NO_CHILD_PLAYLIST
//
// MessageText:
//
//  There is no child playlist for this media item.%0
//
#define NS_E_WMPCORE_MEDIA_NO_CHILD_PLAYLIST _HRESULT_TYPEDEF_(0xC00D10B9L)

//
// MessageId: NS_E_WMPCORE_FILE_NOT_FOUND
//
// MessageText:
//
//  Windows Media Player cannot play one or more files. Right-click the file, and then click Error Details to view information about the error.%0
//
#define NS_E_WMPCORE_FILE_NOT_FOUND      _HRESULT_TYPEDEF_(0xC00D10BAL)

//
// MessageId: NS_E_WMPCORE_TEMP_FILE_NOT_FOUND
//
// MessageText:
//
//  The temporary file was not found.%0
//
#define NS_E_WMPCORE_TEMP_FILE_NOT_FOUND _HRESULT_TYPEDEF_(0xC00D10BBL)

//
// MessageId: NS_E_WMDM_REVOKED
//
// MessageText:
//
//  Windows Media Player cannot transfer media to the portable device without an update.  Please click More Information to find out how to update your device.%0
//
#define NS_E_WMDM_REVOKED                _HRESULT_TYPEDEF_(0xC00D10BCL)

//
// MessageId: NS_E_DDRAW_GENERIC
//
// MessageText:
//
//  Windows Media Player cannot play the video stream because of a problem with your video card.%0
//
#define NS_E_DDRAW_GENERIC               _HRESULT_TYPEDEF_(0xC00D10BDL)

//
// MessageId: NS_E_DISPLAY_MODE_CHANGE_FAILED
//
// MessageText:
//
//  Windows Media Player failed to change the screen mode for fullscreen video playback.%0
//
#define NS_E_DISPLAY_MODE_CHANGE_FAILED  _HRESULT_TYPEDEF_(0xC00D10BEL)

//
// MessageId: NS_E_PLAYLIST_CONTAINS_ERRORS
//
// MessageText:
//
//  One or more items in the playlist cannot be played. For more details, right-click an item in the playlist, and then click Error Details.%0
//
#define NS_E_PLAYLIST_CONTAINS_ERRORS    _HRESULT_TYPEDEF_(0xC00D10BFL)

//
// MessageId: NS_E_CHANGING_PROXY_NAME
//
// MessageText:
//
//  Can't change proxy name if the proxy setting is not set to custom.%0
//
#define NS_E_CHANGING_PROXY_NAME         _HRESULT_TYPEDEF_(0xC00D10C0L)

//
// MessageId: NS_E_CHANGING_PROXY_PORT
//
// MessageText:
//
//  Can't change proxy port if the proxy setting is not set to custom.%0
//
#define NS_E_CHANGING_PROXY_PORT         _HRESULT_TYPEDEF_(0xC00D10C1L)

//
// MessageId: NS_E_CHANGING_PROXY_EXCEPTIONLIST
//
// MessageText:
//
//  Can't change proxy exception list if the proxy setting is not set to custom.%0
//
#define NS_E_CHANGING_PROXY_EXCEPTIONLIST _HRESULT_TYPEDEF_(0xC00D10C2L)

//
// MessageId: NS_E_CHANGING_PROXYBYPASS
//
// MessageText:
//
//  Can't change proxy bypass flag if the proxy setting is not set to custom.%0
//
#define NS_E_CHANGING_PROXYBYPASS        _HRESULT_TYPEDEF_(0xC00D10C3L)

//
// MessageId: NS_E_CHANGING_PROXY_PROTOCOL_NOT_FOUND
//
// MessageText:
//
//  Can't find specified protocol.%0
//
#define NS_E_CHANGING_PROXY_PROTOCOL_NOT_FOUND _HRESULT_TYPEDEF_(0xC00D10C4L)

//
// MessageId: NS_E_GRAPH_NOAUDIOLANGUAGE
//
// MessageText:
//
//  Can't change language settings.  Either the graph has no audio, or the audio only supports one language.%0
//
#define NS_E_GRAPH_NOAUDIOLANGUAGE       _HRESULT_TYPEDEF_(0xC00D10C5L)

//
// MessageId: NS_E_GRAPH_NOAUDIOLANGUAGESELECTED
//
// MessageText:
//
//  The graph has no audio language selected.%0
//
#define NS_E_GRAPH_NOAUDIOLANGUAGESELECTED _HRESULT_TYPEDEF_(0xC00D10C6L)

//
// MessageId: NS_E_CORECD_NOTAMEDIACD
//
// MessageText:
//
//  This is not a media CD.%0
//
#define NS_E_CORECD_NOTAMEDIACD          _HRESULT_TYPEDEF_(0xC00D10C7L)

//
// MessageId: NS_E_WMPCORE_MEDIA_URL_TOO_LONG
//
// MessageText:
//
//  Windows Media Player cannot play this file because the URL is too long.%0
//
#define NS_E_WMPCORE_MEDIA_URL_TOO_LONG  _HRESULT_TYPEDEF_(0xC00D10C8L)

//
// MessageId: NS_E_WMPFLASH_CANT_FIND_COM_SERVER
//
// MessageText:
//
//  Windows Media Player needs the Macromedia Flash Player to play this content. Windows Media Player was not able to detect the Flash player on your system. To play the selected item, you must install the Macromedia Flash Player from the Macromedia Web site, and then try to play the item again.%0
//
#define NS_E_WMPFLASH_CANT_FIND_COM_SERVER _HRESULT_TYPEDEF_(0xC00D10C9L)

//
// MessageId: NS_E_WMPFLASH_INCOMPATIBLEVERSION
//
// MessageText:
//
//  To play the selected item, you must install an updated version of the Macromedia Flash Player from the Macromedia Web site, and then try to play the item again.%0
//
#define NS_E_WMPFLASH_INCOMPATIBLEVERSION _HRESULT_TYPEDEF_(0xC00D10CAL)

//
// MessageId: NS_E_WMPOCXGRAPH_IE_DISALLOWS_ACTIVEX_CONTROLS
//
// MessageText:
//
//  The use of ActiveX controls has been turned off in Internet Explorer. As a result Windows Media Player will not be able to playback this content.%0
//
#define NS_E_WMPOCXGRAPH_IE_DISALLOWS_ACTIVEX_CONTROLS _HRESULT_TYPEDEF_(0xC00D10CBL)

//
// MessageId: NS_E_NEED_CORE_REFERENCE
//
// MessageText:
//
//  The use of this method requires an existing reference to the Player object.%0
//
#define NS_E_NEED_CORE_REFERENCE         _HRESULT_TYPEDEF_(0xC00D10CCL)

//
// MessageId: NS_E_MEDIACD_READ_ERROR
//
// MessageText:
//
//  There was an error reading from the CD-ROM.%0
//
#define NS_E_MEDIACD_READ_ERROR          _HRESULT_TYPEDEF_(0xC00D10CDL)

//
// MessageId: NS_E_IE_DISALLOWS_ACTIVEX_CONTROLS
//
// MessageText:
//
//  Internet Explorer is set to disallow ActiveX controls.%0
//
#define NS_E_IE_DISALLOWS_ACTIVEX_CONTROLS _HRESULT_TYPEDEF_(0xC00D10CEL)

//
// MessageId: NS_E_FLASH_PLAYBACK_NOT_ALLOWED
//
// MessageText:
//
//  Flash playback has been turned off in Windows Media Player.%0
//
#define NS_E_FLASH_PLAYBACK_NOT_ALLOWED  _HRESULT_TYPEDEF_(0xC00D10CFL)

//
// MessageId: NS_E_UNABLE_TO_CREATE_RIP_LOCATION
//
// MessageText:
//
//  Media Player was unable to create a valid location to copy the CD track.%0
//
#define NS_E_UNABLE_TO_CREATE_RIP_LOCATION _HRESULT_TYPEDEF_(0xC00D10D0L)

//
// MessageId: NS_E_WMPCORE_SOME_CODECS_MISSING
//
// MessageText:
//
//  One or more codecs required to open this content could not be found.%0
//
#define NS_E_WMPCORE_SOME_CODECS_MISSING _HRESULT_TYPEDEF_(0xC00D10D1L)

//
// WMP Core  Success codes
//
//
// MessageId: NS_S_WMPCORE_PLAYLISTCLEARABORT
//
// MessageText:
//
//  Failed to clear playlist because it was aborted by user.%0
//
#define NS_S_WMPCORE_PLAYLISTCLEARABORT  _HRESULT_TYPEDEF_(0x000D10FEL)

//
// MessageId: NS_S_WMPCORE_PLAYLISTREMOVEITEMABORT
//
// MessageText:
//
//  Failed to remove item in the playlist since it was aborted by user.%0
//
#define NS_S_WMPCORE_PLAYLISTREMOVEITEMABORT _HRESULT_TYPEDEF_(0x000D10FFL)

//
// MessageId: NS_S_WMPCORE_PLAYLIST_CREATION_PENDING
//
// MessageText:
//
//  Playlist is being generated asynchronously.%0
//
#define NS_S_WMPCORE_PLAYLIST_CREATION_PENDING _HRESULT_TYPEDEF_(0x000D1102L)

//
// MessageId: NS_S_WMPCORE_MEDIA_VALIDATION_PENDING
//
// MessageText:
//
//  Validation of the media is pending...%0
//
#define NS_S_WMPCORE_MEDIA_VALIDATION_PENDING _HRESULT_TYPEDEF_(0x000D1103L)

//
// MessageId: NS_S_WMPCORE_PLAYLIST_REPEAT_SECONDARY_SEGMENTS_IGNORED
//
// MessageText:
//
//  Encountered more than one Repeat block during ASX processing.%0
//
#define NS_S_WMPCORE_PLAYLIST_REPEAT_SECONDARY_SEGMENTS_IGNORED _HRESULT_TYPEDEF_(0x000D1104L)

//
// MessageId: NS_S_WMPCORE_COMMAND_NOT_AVAILABLE
//
// MessageText:
//
//  Current state of WMP disallows calling this method or property.%0
//
#define NS_S_WMPCORE_COMMAND_NOT_AVAILABLE _HRESULT_TYPEDEF_(0x000D1105L)

//
// MessageId: NS_S_WMPCORE_PLAYLIST_NAME_AUTO_GENERATED
//
// MessageText:
//
//  Name for the playlist has been auto generated.%0
//
#define NS_S_WMPCORE_PLAYLIST_NAME_AUTO_GENERATED _HRESULT_TYPEDEF_(0x000D1106L)

//
// MessageId: NS_S_WMPCORE_PLAYLIST_IMPORT_MISSING_ITEMS
//
// MessageText:
//
//  The imported playlist does not contain all items from the original.%0
//
#define NS_S_WMPCORE_PLAYLIST_IMPORT_MISSING_ITEMS _HRESULT_TYPEDEF_(0x000D1107L)

//
// MessageId: NS_S_WMPCORE_PLAYLIST_COLLAPSED_TO_SINGLE_MEDIA
//
// MessageText:
//
//  The M3U playlist has been ignored because it only contains one item.%0
//
#define NS_S_WMPCORE_PLAYLIST_COLLAPSED_TO_SINGLE_MEDIA _HRESULT_TYPEDEF_(0x000D1108L)

//
// MessageId: NS_S_WMPCORE_MEDIA_CHILD_PLAYLIST_OPEN_PENDING
//
// MessageText:
//
//  The open for the child playlist associated with this media is pending.%0
//
#define NS_S_WMPCORE_MEDIA_CHILD_PLAYLIST_OPEN_PENDING _HRESULT_TYPEDEF_(0x000D1109L)

//
// MessageId: NS_S_WMPCORE_MORE_NODES_AVAIABLE
//
// MessageText:
//
//  More nodes support the interface requested, but the array for returning them is full.%0
//
#define NS_S_WMPCORE_MORE_NODES_AVAIABLE _HRESULT_TYPEDEF_(0x000D110AL)

//
// WMP Internet Manager error codes
//
//
// MessageId: NS_E_WMPIM_USEROFFLINE
//
// MessageText:
//
//  Windows Media Player has detected that you are not connected to the Internet. Connect to the Internet, and then try again.%0
//
#define NS_E_WMPIM_USEROFFLINE           _HRESULT_TYPEDEF_(0xC00D1126L)

//
// MessageId: NS_E_WMPIM_USERCANCELED
//
// MessageText:
//
//  User cancelled attempt to connect to the Internet.%0
//
#define NS_E_WMPIM_USERCANCELED          _HRESULT_TYPEDEF_(0xC00D1127L)

//
// MessageId: NS_E_WMPIM_DIALUPFAILED
//
// MessageText:
//
//  Attempt to dial connection to the Internet failed.%0
//
#define NS_E_WMPIM_DIALUPFAILED          _HRESULT_TYPEDEF_(0xC00D1128L)

//
// MessageId: NS_E_WINSOCK_ERROR_STRING
//
// MessageText:
//
//  Windows Media Player has encountered an unknown network error.%0
//
#define NS_E_WINSOCK_ERROR_STRING        _HRESULT_TYPEDEF_(0xC00D1129L)

//
// WMP Backup and restore error and success codes
//
//
// MessageId: NS_E_WMPBR_NOLISTENER
//
// MessageText:
//
//  No window is currently listening to Backup and Restore events.%0
//
#define NS_E_WMPBR_NOLISTENER            _HRESULT_TYPEDEF_(0xC00D1130L)

//
// MessageId: NS_E_WMPBR_BACKUPCANCEL
//
// MessageText:
//
//  Backup of your licenses has been cancelled.  Please try again to ensure license backup.%0
//
#define NS_E_WMPBR_BACKUPCANCEL          _HRESULT_TYPEDEF_(0xC00D1131L)

//
// MessageId: NS_E_WMPBR_RESTORECANCEL
//
// MessageText:
//
//  The licenses were not restored because the restoration was cancelled.%0
//
#define NS_E_WMPBR_RESTORECANCEL         _HRESULT_TYPEDEF_(0xC00D1132L)

//
// MessageId: NS_E_WMPBR_ERRORWITHURL
//
// MessageText:
//
//  An error occurred during the backup or restore operation that requires a web page be displayed to the user.%0
//
#define NS_E_WMPBR_ERRORWITHURL          _HRESULT_TYPEDEF_(0xC00D1133L)

//
// MessageId: NS_E_WMPBR_NAMECOLLISION
//
// MessageText:
//
//  The licenses were not backed up because the backup was cancelled.%0
//
#define NS_E_WMPBR_NAMECOLLISION         _HRESULT_TYPEDEF_(0xC00D1134L)

//
// MessageId: NS_S_WMPBR_SUCCESS
//
// MessageText:
//
//  Backup or Restore successful!.%0
//
#define NS_S_WMPBR_SUCCESS               _HRESULT_TYPEDEF_(0x000D1135L)

//
// MessageId: NS_S_WMPBR_PARTIALSUCCESS
//
// MessageText:
//
//  Transfer complete with limitations.%0
//
#define NS_S_WMPBR_PARTIALSUCCESS        _HRESULT_TYPEDEF_(0x000D1136L)

//
// MessageId: NS_E_WMPBR_DRIVE_INVALID
//
// MessageText:
//
//  The location specified for restoring licenses is not valid. Choose another location, and then try again.%0
//
#define NS_E_WMPBR_DRIVE_INVALID         _HRESULT_TYPEDEF_(0xC00D1137L)

//
// WMP Effects Success codes
//
//
// MessageId: NS_S_WMPEFFECT_TRANSPARENT
//
// MessageText:
//
//  Request to the effects control to change transparency status to transparent.%0
//
#define NS_S_WMPEFFECT_TRANSPARENT       _HRESULT_TYPEDEF_(0x000D1144L)

//
// MessageId: NS_S_WMPEFFECT_OPAQUE
//
// MessageText:
//
//  Request to the effects control to change transparency status to opaque.%0
//
#define NS_S_WMPEFFECT_OPAQUE            _HRESULT_TYPEDEF_(0x000D1145L)

//
// WMP Application Success codes
//
//
// MessageId: NS_S_OPERATION_PENDING
//
// MessageText:
//
//  The requested application pane is performing an operation and will not be relased.%0
//
#define NS_S_OPERATION_PENDING           _HRESULT_TYPEDEF_(0x000D114EL)

//
// WMP DVD Error Codes
//
//
// MessageId: NS_E_DVD_NO_SUBPICTURE_STREAM
//
// MessageText:
//
//  Windows Media Player cannot display subtitles or highlights in menus. Reinstall the DVD decoder or contact your device manufacturer to obtain an updated decoder, and then try again.%0
//
#define NS_E_DVD_NO_SUBPICTURE_STREAM    _HRESULT_TYPEDEF_(0xC00D1162L)

//
// MessageId: NS_E_DVD_COPY_PROTECT
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because a problem occurred with digital copyright protection.%0
//
#define NS_E_DVD_COPY_PROTECT            _HRESULT_TYPEDEF_(0xC00D1163L)

//
// MessageId: NS_E_DVD_AUTHORING_PROBLEM
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because the disc is incompatible with the Player.%0
//
#define NS_E_DVD_AUTHORING_PROBLEM       _HRESULT_TYPEDEF_(0xC00D1164L)

//
// MessageId: NS_E_DVD_INVALID_DISC_REGION
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because the disc prohibits playback in your region of the world. You must obtain a disc that is intended for your geographic region.%0
//
#define NS_E_DVD_INVALID_DISC_REGION     _HRESULT_TYPEDEF_(0xC00D1165L)

//
// MessageId: NS_E_DVD_COMPATIBLE_VIDEO_CARD
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because your video card does not support DVD playback.%0
//
#define NS_E_DVD_COMPATIBLE_VIDEO_CARD   _HRESULT_TYPEDEF_(0xC00D1166L)

//
// MessageId: NS_E_DVD_MACROVISION
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because a problem occurred with copyright protection.%0
//
#define NS_E_DVD_MACROVISION             _HRESULT_TYPEDEF_(0xC00D1167L)

//
// MessageId: NS_E_DVD_SYSTEM_DECODER_REGION
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because the region assigned to your DVD drive does not match the region assigned to your DVD decoder.%0
//
#define NS_E_DVD_SYSTEM_DECODER_REGION   _HRESULT_TYPEDEF_(0xC00D1168L)

//
// MessageId: NS_E_DVD_DISC_DECODER_REGION
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because the disc prohibits playback in your region of the world. To play the disc by using the Player, you must obtain a disc that is intended for your geographic region.%0
//
#define NS_E_DVD_DISC_DECODER_REGION     _HRESULT_TYPEDEF_(0xC00D1169L)

//
// MessageId: NS_E_DVD_NO_VIDEO_STREAM
//
// MessageText:
//
//  Windows Media Player is currently unable to play DVD video. Try decreasing the number of colors displayed on your monitor or decreasing the screen resolution. For additional solutions, click More Information to access the DVD Troubleshooter.%0
//
#define NS_E_DVD_NO_VIDEO_STREAM         _HRESULT_TYPEDEF_(0xC00D116AL)

//
// MessageId: NS_E_DVD_NO_AUDIO_STREAM
//
// MessageText:
//
//  Windows Media Player cannot play DVD audio. Verify that your sound card is set up correctly, and then try again.%0
//
#define NS_E_DVD_NO_AUDIO_STREAM         _HRESULT_TYPEDEF_(0xC00D116BL)

//
// MessageId: NS_E_DVD_GRAPH_BUILDING
//
// MessageText:
//
//  Windows Media Player cannot play DVD video. Close any open files and quit any other running programs, and then try again. If the problem continues, restart your computer.%0
//
#define NS_E_DVD_GRAPH_BUILDING          _HRESULT_TYPEDEF_(0xC00D116CL)

//
// MessageId: NS_E_DVD_NO_DECODER
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because a compatible DVD decoder is not installed on your computer.%0
//
#define NS_E_DVD_NO_DECODER              _HRESULT_TYPEDEF_(0xC00D116DL)

//
// MessageId: NS_E_DVD_PARENTAL
//
// MessageText:
//
//  Windows Media Player cannot play this DVD segment because the segment has a parental rating higher than the rating you are authorized to view.%0
//
#define NS_E_DVD_PARENTAL                _HRESULT_TYPEDEF_(0xC00D116EL)

//
// MessageId: NS_E_DVD_CANNOT_JUMP
//
// MessageText:
//
//  Windows Media Player cannot skip to the requested location in the DVD at this time.%0
//
#define NS_E_DVD_CANNOT_JUMP             _HRESULT_TYPEDEF_(0xC00D116FL)

//
// MessageId: NS_E_DVD_DEVICE_CONTENTION
//
// MessageText:
//
//  Windows Media Player cannot play this DVD because it is currently in use by another program. Quit the other program that is using the DVD, and then try to play it again.%0
//
#define NS_E_DVD_DEVICE_CONTENTION       _HRESULT_TYPEDEF_(0xC00D1170L)

//
// MessageId: NS_E_DVD_NO_VIDEO_MEMORY
//
// MessageText:
//
//  Windows Media Player cannot play DVD video. Double-click Display in Control Panel to lower your screen resolution and color quality settings.%0
//
#define NS_E_DVD_NO_VIDEO_MEMORY         _HRESULT_TYPEDEF_(0xC00D1171L)

//
// MessageId: NS_E_DVD_CANNOT_COPY_PROTECTED
//
// MessageText:
//
//  Windows Media Player cannot copy this DVD because it is copy protected.%0
//
#define NS_E_DVD_CANNOT_COPY_PROTECTED   _HRESULT_TYPEDEF_(0xC00D1172L)

//
// MessageId: NS_E_DVD_REQUIRED_PROPERTY_NOT_SET
//
// MessageText:
//
//  One of more of the required properties has not been set.%0
//
#define NS_E_DVD_REQUIRED_PROPERTY_NOT_SET _HRESULT_TYPEDEF_(0xC00D1173L)

//
// MessageId: NS_E_DVD_INVALID_TITLE_CHAPTER
//
// MessageText:
//
//  The specified title and/or chapter number does not exist on this DVD.%0
//
#define NS_E_DVD_INVALID_TITLE_CHAPTER   _HRESULT_TYPEDEF_(0xC00D1174L)

//
// WMP PDA Error codes
//
//
// MessageId: NS_E_NO_CD_BURNER
//
// MessageText:
//
//  A CD recorder (burner) was not detected. Connect a CD recorder, and try copying again.%0
//
#define NS_E_NO_CD_BURNER                _HRESULT_TYPEDEF_(0xC00D1176L)

//
// MessageId: NS_E_DEVICE_IS_NOT_READY
//
// MessageText:
//
//  Windows Media Player does not detect any storage media in the selected device. Insert media into the device.%0
//
#define NS_E_DEVICE_IS_NOT_READY         _HRESULT_TYPEDEF_(0xC00D1177L)

//
// MessageId: NS_E_PDA_UNSUPPORTED_FORMAT
//
// MessageText:
//
//  Windows Media Player cannot play the specified file. Your portable device does not support the specified format.%0
//
#define NS_E_PDA_UNSUPPORTED_FORMAT      _HRESULT_TYPEDEF_(0xC00D1178L)

//
// MessageId: NS_E_NO_PDA
//
// MessageText:
//
//  Windows Media Player cannot detect a connected portable device. Connect your portable device, and try again.%0
//
#define NS_E_NO_PDA                      _HRESULT_TYPEDEF_(0xC00D1179L)

//
// MessageId: NS_E_PDA_UNSPECIFIED_ERROR
//
// MessageText:
//
//  Windows Media Player has encountered an error on the portable device.%0
//
#define NS_E_PDA_UNSPECIFIED_ERROR       _HRESULT_TYPEDEF_(0xC00D117AL)

//
// MessageId: NS_E_MEMSTORAGE_BAD_DATA
//
// MessageText:
//
//  Windows Media Player encountered an internal error in accessing a memory-based storage during a CD burning task.%0
//
#define NS_E_MEMSTORAGE_BAD_DATA         _HRESULT_TYPEDEF_(0xC00D117BL)

//
// MessageId: NS_E_PDA_FAIL_SELECT_DEVICE
//
// MessageText:
//
//  Windows Media Player encountered an internal error when selecting a PDA or CD device.%0
//
#define NS_E_PDA_FAIL_SELECT_DEVICE      _HRESULT_TYPEDEF_(0xC00D117CL)

//
// MessageId: NS_E_PDA_FAIL_READ_WAVE_FILE
//
// MessageText:
//
//  Windows Media Player failed to open or read data from a wave file.%0
//
#define NS_E_PDA_FAIL_READ_WAVE_FILE     _HRESULT_TYPEDEF_(0xC00D117DL)

//
// MessageId: NS_E_IMAPI_LOSSOFSTREAMING
//
// MessageText:
//
//  Windows Media Player did not copy all the selected items. The Player has reduced the recording speed of your CD drive to solve the problem. To copy all the selected items, insert a blank CD in the drive, and try again.%0
//
#define NS_E_IMAPI_LOSSOFSTREAMING       _HRESULT_TYPEDEF_(0xC00D117EL)

//
// MessageId: NS_E_PDA_DEVICE_FULL
//
// MessageText:
//
//  There is not enough storage space on the portable device to complete this operation. Delete some unneeded files on the portable device, and then try again.%0
//
#define NS_E_PDA_DEVICE_FULL             _HRESULT_TYPEDEF_(0xC00D117FL)

//
// MessageId: NS_E_FAIL_LAUNCH_ROXIO_PLUGIN
//
// MessageText:
//
//  Windows Media Player cannot copy the files to the CD. Verify that a CD-R or CD-RW drive is connected to your computer, and then try again. If the problem continues, reinstall the Player.%0
//
#define NS_E_FAIL_LAUNCH_ROXIO_PLUGIN    _HRESULT_TYPEDEF_(0xC00D1180L)

//
// MessageId: NS_E_PDA_DEVICE_FULL_IN_SESSION
//
// MessageText:
//
//  Windows Media Player failed to copy some files to device because the device is out of space.%0
//
#define NS_E_PDA_DEVICE_FULL_IN_SESSION  _HRESULT_TYPEDEF_(0xC00D1181L)

//
// MessageId: NS_E_IMAPI_MEDIUM_INVALIDTYPE
//
// MessageText:
//
//  The medium in the drive is invalid. Please insert a blank CD-R or a CD-RW into the drive, and then try again.%0
//
#define NS_E_IMAPI_MEDIUM_INVALIDTYPE    _HRESULT_TYPEDEF_(0xC00D1182L)

//
// General Remapped Error codes in WMP
//
//
// MessageId: NS_E_WMP_PROTOCOL_PROBLEM
//
// MessageText:
//
//  Windows Media Player could not open the specified URL. Be sure Windows Media Player is configured to use all available protocols, and then try again.%0
//
#define NS_E_WMP_PROTOCOL_PROBLEM        _HRESULT_TYPEDEF_(0xC00D1194L)

//
// MessageId: NS_E_WMP_NO_DISK_SPACE
//
// MessageText:
//
//  Windows Media Player cannot open the file because there is not enough disk space on your computer. Delete some unneeded files on your hard disk, and then try again.%0
//
#define NS_E_WMP_NO_DISK_SPACE           _HRESULT_TYPEDEF_(0xC00D1195L)

//
// MessageId: NS_E_WMP_LOGON_FAILURE
//
// MessageText:
//
//  Windows Media Player cannot copy or play the file because the server denied access to it. Verify that you have access rights to the file, and then try again.%0
//
#define NS_E_WMP_LOGON_FAILURE           _HRESULT_TYPEDEF_(0xC00D1196L)

//
// MessageId: NS_E_WMP_CANNOT_FIND_FILE
//
// MessageText:
//
//  Windows Media Player cannot find the specified file. Be sure the path is typed correctly. If it is, the file does not exist at the specified location, or the computer where the file is stored is offline.%0
//
#define NS_E_WMP_CANNOT_FIND_FILE        _HRESULT_TYPEDEF_(0xC00D1197L)

//
// MessageId: NS_E_WMP_SERVER_INACCESSIBLE
//
// MessageText:
//
//  Windows Media Player cannot connect to the server. The server name may be incorrect or the server is busy. Try again later.%0
//
#define NS_E_WMP_SERVER_INACCESSIBLE     _HRESULT_TYPEDEF_(0xC00D1198L)

//
// MessageId: NS_E_WMP_UNSUPPORTED_FORMAT
//
// MessageText:
//
//  Windows Media Player cannot play the file. The file is either corrupt or the Player does not support the format you are trying to play.%0
//
#define NS_E_WMP_UNSUPPORTED_FORMAT      _HRESULT_TYPEDEF_(0xC00D1199L)

//
// MessageId: NS_E_WMP_DSHOW_UNSUPPORTED_FORMAT
//
// MessageText:
//
//  Windows Media Player cannot play the file. The file may be formatted with an unsupported codec, or the Internet security setting on your computer is set too high. Lower your browser's security setting, and then try again.%0
//
#define NS_E_WMP_DSHOW_UNSUPPORTED_FORMAT _HRESULT_TYPEDEF_(0xC00D119AL)

//
// MessageId: NS_E_WMP_PLAYLIST_EXISTS
//
// MessageText:
//
//  Windows Media Player cannot create the playlist because the name already exists. Type a different playlist name.%0
//
#define NS_E_WMP_PLAYLIST_EXISTS         _HRESULT_TYPEDEF_(0xC00D119BL)

//
// MessageId: NS_E_WMP_NONMEDIA_FILES
//
// MessageText:
//
//  Windows Media Player could not delete the playlist because it contains non-digital media files. Any digital media files in the playlist were deleted. Use Windows Explorer to delete non-digital media files, and then try deleting the playlist again.%0
//
#define NS_E_WMP_NONMEDIA_FILES          _HRESULT_TYPEDEF_(0xC00D119CL)

//
// MessageId: NS_E_WMP_INVALID_ASX
//
// MessageText:
//
//  Windows Media Player cannot play the file because the associated playlist is not valid.%0
//
#define NS_E_WMP_INVALID_ASX             _HRESULT_TYPEDEF_(0xC00D119DL)

//
// MessageId: NS_E_WMP_ALREADY_IN_USE
//
// MessageText:
//
//  Windows Media Player is already in use. Stop playing any content and close all Player dialog boxes and then try again.%0
//
#define NS_E_WMP_ALREADY_IN_USE          _HRESULT_TYPEDEF_(0xC00D119EL)

//
// MessageId: NS_E_WMP_IMAPI_FAILURE
//
// MessageText:
//
//  Windows Media Player has encountered an unknown error with your recordable disc.%0
//
#define NS_E_WMP_IMAPI_FAILURE           _HRESULT_TYPEDEF_(0xC00D119FL)

//
// MessageId: NS_E_WMP_WMDM_FAILURE
//
// MessageText:
//
//  Windows Media Player has encountered an unknown error with your portable device.  Reconnect your portable device and try again.%0
//
#define NS_E_WMP_WMDM_FAILURE            _HRESULT_TYPEDEF_(0xC00D11A0L)

//
// MessageId: NS_E_WMP_CODEC_NEEDED_WITH_4CC
//
// MessageText:
//
//  The %s codec is required to play this file. To determine if this codec is available to download from the Web, click Web Help.%0
//
#define NS_E_WMP_CODEC_NEEDED_WITH_4CC   _HRESULT_TYPEDEF_(0xC00D11A1L)

//
// MessageId: NS_E_WMP_CODEC_NEEDED_WITH_FORMATTAG
//
// MessageText:
//
//  The audio codec identified by the format tag %s is required to play this file. To determine if this codec is available to download from the Web, click Web Help.%0
//
#define NS_E_WMP_CODEC_NEEDED_WITH_FORMATTAG _HRESULT_TYPEDEF_(0xC00D11A2L)

//
// MessageId: NS_E_WMP_MSSAP_NOT_AVAILABLE
//
// MessageText:
//
//  To play this file, you must install the latest Windows XP service pack.  To install the service pack from the Windows Update Web site, click Web Help.%0
//
#define NS_E_WMP_MSSAP_NOT_AVAILABLE     _HRESULT_TYPEDEF_(0xC00D11A3L)

//
// MessageId: NS_E_WMP_WMDM_INTERFACEDEAD
//
// MessageText:
//
//  Windows Media Player no longer detects a portable device. Reconnect your portable device, and try again.%0
//
#define NS_E_WMP_WMDM_INTERFACEDEAD      _HRESULT_TYPEDEF_(0xC00D11A4L)

//
// MessageId: NS_E_WMP_WMDM_NOTCERTIFIED
//
// MessageText:
//
//  Windows Media Player cannot copy the file because the portable device does not support protected files.%0
//
#define NS_E_WMP_WMDM_NOTCERTIFIED       _HRESULT_TYPEDEF_(0xC00D11A5L)

//
// MessageId: NS_E_WMP_WMDM_LICENSE_NOTEXIST
//
// MessageText:
//
//  Windows Media Player cannot copy the file because a license for this file could not be found on your computer. If you obtained this file from a Web site, return to the site, and try downloading the file again.%0
//
#define NS_E_WMP_WMDM_LICENSE_NOTEXIST   _HRESULT_TYPEDEF_(0xC00D11A6L)

//
// MessageId: NS_E_WMP_WMDM_LICENSE_EXPIRED
//
// MessageText:
//
//  Windows Media Player cannot copy the file because the license for this file has expired. If you obtained this file from a Web site, return to the site, and try downloading the file again.%0
//
#define NS_E_WMP_WMDM_LICENSE_EXPIRED    _HRESULT_TYPEDEF_(0xC00D11A7L)

//
// MessageId: NS_E_WMP_WMDM_BUSY
//
// MessageText:
//
//  The portable device is already in use. Wait until the current process finishes or quit other programs that may be using the portable device, and then try again.%0
//
#define NS_E_WMP_WMDM_BUSY               _HRESULT_TYPEDEF_(0xC00D11A8L)

//
// MessageId: NS_E_WMP_WMDM_NORIGHTS
//
// MessageText:
//
//  Windows Media Player cannot copy the file because the license or device restricts it.%0
//
#define NS_E_WMP_WMDM_NORIGHTS           _HRESULT_TYPEDEF_(0xC00D11A9L)

//
// MessageId: NS_E_WMP_WMDM_INCORRECT_RIGHTS
//
// MessageText:
//
//  Windows Media Player cannot copy the file because the license associated with the file restricts it.%0
//
#define NS_E_WMP_WMDM_INCORRECT_RIGHTS   _HRESULT_TYPEDEF_(0xC00D11AAL)

//
// MessageId: NS_E_WMP_IMAPI_GENERIC
//
// MessageText:
//
//  Windows Media Player cannot copy files to the recordable disc.%0
//
#define NS_E_WMP_IMAPI_GENERIC           _HRESULT_TYPEDEF_(0xC00D11ABL)

//
// MessageId: NS_E_WMP_IMAPI_DEVICE_NOTPRESENT
//
// MessageText:
//
//  Windows Media Player cannot copy files to the recordable disc. Verify that the CD-R or CD-RW drive is connected, and then try again.%0
//
#define NS_E_WMP_IMAPI_DEVICE_NOTPRESENT _HRESULT_TYPEDEF_(0xC00D11ADL)

//
// MessageId: NS_E_WMP_IMAPI_STASHINUSE
//
// MessageText:
//
//  The CD-R or CD-RW drive may already be in use. Wait until the current process finishes or quit other programs that may be using the CD-R or CD-RW drive, and then try again.%0
//
#define NS_E_WMP_IMAPI_STASHINUSE        _HRESULT_TYPEDEF_(0xC00D11AEL)

//
// MessageId: NS_E_WMP_IMAPI_LOSS_OF_STREAMING
//
// MessageText:
//
//  Windows Media Player cannot copy files to the recordable disc.%0
//
#define NS_E_WMP_IMAPI_LOSS_OF_STREAMING _HRESULT_TYPEDEF_(0xC00D11AFL)

//
// MessageId: NS_E_WMP_SERVER_UNAVAILABLE
//
// MessageText:
//
//  Windows Media Player cannot play the file because the server is busy. Try again later.%0
//
#define NS_E_WMP_SERVER_UNAVAILABLE      _HRESULT_TYPEDEF_(0xC00D11B0L)

//
// MessageId: NS_E_WMP_FILE_OPEN_FAILED
//
// MessageText:
//
//  Windows Media Player cannot open the file.%0
//
#define NS_E_WMP_FILE_OPEN_FAILED        _HRESULT_TYPEDEF_(0xC00D11B1L)

//
// MessageId: NS_E_WMP_VERIFY_ONLINE
//
// MessageText:
//
//  To play the file, Windows Media Player must obtain a license from the Internet. Connect to the Internet, and then try again.%0
//
#define NS_E_WMP_VERIFY_ONLINE           _HRESULT_TYPEDEF_(0xC00D11B2L)

//
// MessageId: NS_E_WMP_SERVER_NOT_RESPONDING
//
// MessageText:
//
//  Windows Media Player cannot play the file because the server is not responding. If you entered a URL or path to play the file, verify that it is correct. If you clicked a link to play the file, the link may not be valid.%0
//
#define NS_E_WMP_SERVER_NOT_RESPONDING   _HRESULT_TYPEDEF_(0xC00D11B3L)

//
// MessageId: NS_E_WMP_DRM_CORRUPT_BACKUP
//
// MessageText:
//
//  Windows Media Player cannot restore your licenses because no backed up licenses were found on your computer.%0
//
#define NS_E_WMP_DRM_CORRUPT_BACKUP      _HRESULT_TYPEDEF_(0xC00D11B4L)

//
// MessageId: NS_E_WMP_DRM_LICENSE_SERVER_UNAVAILABLE
//
// MessageText:
//
//  To play the file, Windows Media Player must obtain a license from the Internet. However, the license server is currently not available. Try again later.%0
//
#define NS_E_WMP_DRM_LICENSE_SERVER_UNAVAILABLE _HRESULT_TYPEDEF_(0xC00D11B5L)

//
// MessageId: NS_E_WMP_NETWORK_FIREWALL
//
// MessageText:
//
//  Windows Media Player cannot play the file. A network firewall may be preventing the Player from opening the file by using the UDP transport protocol. To play this file, try opening the file without specifying UDP.%0
//
#define NS_E_WMP_NETWORK_FIREWALL        _HRESULT_TYPEDEF_(0xC00D11B6L)

//
// MessageId: NS_E_WMP_NO_REMOVABLE_MEDIA
//
// MessageText:
//
//  Insert the removable media, and then try again.%0
//
#define NS_E_WMP_NO_REMOVABLE_MEDIA      _HRESULT_TYPEDEF_(0xC00D11B7L)

//
// MessageId: NS_E_WMP_PROXY_CONNECT_TIMEOUT
//
// MessageText:
//
//  Windows Media Player cannot play the file because the proxy server is not responding. The proxy server may be temporarily unavailable or your Player proxy settings may not be valid.%0
//
#define NS_E_WMP_PROXY_CONNECT_TIMEOUT   _HRESULT_TYPEDEF_(0xC00D11B8L)

//
// MessageId: NS_E_WMP_NEED_UPGRADE
//
// MessageText:
//
//  To play this file, you must upgrade to the latest version of Windows Media Player. To upgrade the Player, on the Help menu, click Check For Player Updates, and then follow the instructions.%0
//
#define NS_E_WMP_NEED_UPGRADE            _HRESULT_TYPEDEF_(0xC00D11B9L)

//
// MessageId: NS_E_WMP_AUDIO_HW_PROBLEM
//
// MessageText:
//
//  Windows Media Player cannot play the file because there is a problem with your sound device. There may not be a sound device installed on your computer, it may be in use by another program, or it may not be functioning properly.%0
//
#define NS_E_WMP_AUDIO_HW_PROBLEM        _HRESULT_TYPEDEF_(0xC00D11BAL)

//
// MessageId: NS_E_WMP_INVALID_PROTOCOL
//
// MessageText:
//
//  Windows Media Player cannot play the file because the specified protocol is not supported. In the Open URL dialog, try opening the file using a different transport protocol (for example, "http:" or "rtsp:").%0
//
#define NS_E_WMP_INVALID_PROTOCOL        _HRESULT_TYPEDEF_(0xC00D11BBL)

//
// MessageId: NS_E_WMP_INVALID_LIBRARY_ADD
//
// MessageText:
//
//  Windows Media Player cannot add the file to Media Library because the file format is not supported.%0
//
#define NS_E_WMP_INVALID_LIBRARY_ADD     _HRESULT_TYPEDEF_(0xC00D11BCL)

//
// MessageId: NS_E_WMP_MMS_NOT_SUPPORTED
//
// MessageText:
//
//  Windows Media Player cannot play the file because the specified protocol is not supported. In the Open URL dialog, try opening the file using a different transport protocol (for example, "mms:").%0
//
#define NS_E_WMP_MMS_NOT_SUPPORTED       _HRESULT_TYPEDEF_(0xC00D11BDL)

//
// MessageId: NS_E_WMP_NO_PROTOCOLS_SELECTED
//
// MessageText:
//
//  Windows Media Player cannot play the file because there are no streaming protocols selected. Select one or more protocols, and then try again.%0
//
#define NS_E_WMP_NO_PROTOCOLS_SELECTED   _HRESULT_TYPEDEF_(0xC00D11BEL)

//
// MessageId: NS_E_WMP_GOFULLSCREEN_FAILED
//
// MessageText:
//
//  To use the Full Screen command, you may need to adjust your Windows display settings. Open Display in Control Panel, and try setting Hardware acceleration to Full.%0
//
#define NS_E_WMP_GOFULLSCREEN_FAILED     _HRESULT_TYPEDEF_(0xC00D11BFL)

//
// MessageId: NS_E_WMP_NETWORK_ERROR
//
// MessageText:
//
//  Windows Media Player cannot play the file because a network error occurred.%0
//
#define NS_E_WMP_NETWORK_ERROR           _HRESULT_TYPEDEF_(0xC00D11C0L)

//
// MessageId: NS_E_WMP_CONNECT_TIMEOUT
//
// MessageText:
//
//  Windows Media Player cannot play the file because the server is not responding. Verify that you are connected to the network, and then try again later.%0
//
#define NS_E_WMP_CONNECT_TIMEOUT         _HRESULT_TYPEDEF_(0xC00D11C1L)

//
// MessageId: NS_E_WMP_MULTICAST_DISABLED
//
// MessageText:
//
//  Windows Media Player cannot play the file because the multicast protocol is not enabled. On the Tools menu, click Options, click the Network tab, and then select the Multicast check box.%0
//
#define NS_E_WMP_MULTICAST_DISABLED      _HRESULT_TYPEDEF_(0xC00D11C2L)

//
// MessageId: NS_E_WMP_SERVER_DNS_TIMEOUT
//
// MessageText:
//
//  Windows Media Player cannot play the file because a network problem occurred. Verify that you are connected to the network, and then try again later.%0
//
#define NS_E_WMP_SERVER_DNS_TIMEOUT      _HRESULT_TYPEDEF_(0xC00D11C3L)

//
// MessageId: NS_E_WMP_PROXY_NOT_FOUND
//
// MessageText:
//
//  Windows Media Player cannot play the file because the network proxy server could not be found. Verify your proxy settings, and then try again.%0
//
#define NS_E_WMP_PROXY_NOT_FOUND         _HRESULT_TYPEDEF_(0xC00D11C4L)

//
// MessageId: NS_E_WMP_TAMPERED_CONTENT
//
// MessageText:
//
//  Windows Media Player cannot play the file because it is damaged or corrupted.%0
//
#define NS_E_WMP_TAMPERED_CONTENT        _HRESULT_TYPEDEF_(0xC00D11C5L)

//
// MessageId: NS_E_WMP_OUTOFMEMORY
//
// MessageText:
//
//  Your computer is running low on memory. Quit other programs, and then try again.%0
//
#define NS_E_WMP_OUTOFMEMORY             _HRESULT_TYPEDEF_(0xC00D11C6L)

//
// MessageId: NS_E_WMP_AUDIO_CODEC_NOT_INSTALLED
//
// MessageText:
//
//  Windows Media Player cannot play the file because the required audio codec is not installed on your computer.%0
//
#define NS_E_WMP_AUDIO_CODEC_NOT_INSTALLED _HRESULT_TYPEDEF_(0xC00D11C7L)

//
// MessageId: NS_E_WMP_VIDEO_CODEC_NOT_INSTALLED
//
// MessageText:
//
//  Windows Media Player cannot play the file because the required video codec is not installed on your computer.%0
//
#define NS_E_WMP_VIDEO_CODEC_NOT_INSTALLED _HRESULT_TYPEDEF_(0xC00D11C8L)

//
// MessageId: NS_E_WMP_IMAPI_DEVICE_INVALIDTYPE
//
// MessageText:
//
//  Windows Media Player cannot copy the files to the recordable disc.%0
//
#define NS_E_WMP_IMAPI_DEVICE_INVALIDTYPE _HRESULT_TYPEDEF_(0xC00D11C9L)

//
// MessageId: NS_E_WMP_DRM_DRIVER_AUTH_FAILURE
//
// MessageText:
//
//  Windows Media Player cannot play the licensed file because there is a problem with your sound device. Try installing a new device driver or use a different sound device.%0
//
#define NS_E_WMP_DRM_DRIVER_AUTH_FAILURE _HRESULT_TYPEDEF_(0xC00D11CAL)

//
// MessageId: NS_E_WMP_NETWORK_RESOURCE_FAILURE
//
// MessageText:
//
//  Windows Media Player encountered a network problem. Restart the Player.%0
//
#define NS_E_WMP_NETWORK_RESOURCE_FAILURE _HRESULT_TYPEDEF_(0xC00D11CBL)

//
// MessageId: NS_E_WMP_UPGRADE_APPLICATION
//
// MessageText:
//
//  Windows Media Player is not installed properly. Reinstall the Player.%0
//
#define NS_E_WMP_UPGRADE_APPLICATION     _HRESULT_TYPEDEF_(0xC00D11CCL)

//
// MessageId: NS_E_WMP_UNKNOWN_ERROR
//
// MessageText:
//
//  Windows Media Player encountered an unknown error.%0
//
#define NS_E_WMP_UNKNOWN_ERROR           _HRESULT_TYPEDEF_(0xC00D11CDL)

//
// MessageId: NS_E_WMP_INVALID_KEY
//
// MessageText:
//
//  Windows Media Player cannot play the file because the required codec is not valid.%0
//
#define NS_E_WMP_INVALID_KEY             _HRESULT_TYPEDEF_(0xC00D11CEL)

//
// MessageId: NS_E_WMP_CD_ANOTHER_USER
//
// MessageText:
//
//  The CD drive is in use by another user. Wait for the operation to complete, and then try again.%0
//
#define NS_E_WMP_CD_ANOTHER_USER         _HRESULT_TYPEDEF_(0xC00D11CFL)

//
// MessageId: NS_E_WMP_DRM_NEEDS_AUTHORIZATION
//
// MessageText:
//
//  Windows Media Player cannot play the licensed file because the required security upgrade is not available for download.%0
//
#define NS_E_WMP_DRM_NEEDS_AUTHORIZATION _HRESULT_TYPEDEF_(0xC00D11D0L)

//
// MessageId: NS_E_WMP_BAD_DRIVER
//
// MessageText:
//
//  Windows Media Player cannot play the file because there may be a problem with your sound or video device. Try installing a new device driver.%0
//
#define NS_E_WMP_BAD_DRIVER              _HRESULT_TYPEDEF_(0xC00D11D1L)

//
// MessageId: NS_E_WMP_ACCESS_DENIED
//
// MessageText:
//
//  Windows Media Player cannot access the file.%0
//
#define NS_E_WMP_ACCESS_DENIED           _HRESULT_TYPEDEF_(0xC00D11D2L)

//
// MessageId: NS_E_WMP_LICENSE_RESTRICTS
//
// MessageText:
//
//  Windows Media Player cannot copy the file to the device because the license restricts it.%0
//
#define NS_E_WMP_LICENSE_RESTRICTS       _HRESULT_TYPEDEF_(0xC00D11D3L)

//
// MessageId: NS_E_WMP_INVALID_REQUEST
//
// MessageText:
//
//  Windows Media Player cannot perform the requested action at this time.%0
//
#define NS_E_WMP_INVALID_REQUEST         _HRESULT_TYPEDEF_(0xC00D11D4L)

//
// MessageId: NS_E_WMP_CD_STASH_NO_SPACE
//
// MessageText:
//
//  Windows Media Player cannot copy the files because there is not enough free disk space to store the temporary files. Delete some unneeded files on your hard disk, and then try again.%0
//
#define NS_E_WMP_CD_STASH_NO_SPACE       _HRESULT_TYPEDEF_(0xC00D11D5L)

//
// MessageId: NS_E_WMP_DRM_NEW_HARDWARE
//
// MessageText:
//
//  Windows Media Player cannot play the file because the associated license is either corrupted or not valid. The license may no longer be valid if you have replaced hardware components in your computer.%0
//
#define NS_E_WMP_DRM_NEW_HARDWARE        _HRESULT_TYPEDEF_(0xC00D11D6L)

//
// MessageId: NS_E_WMP_DRM_INVALID_SIG
//
// MessageText:
//
//  The required security upgrade cannot be validated. Try installing the latest Internet Explorer service pack. To install the service pack from the Windows Update Web site, click Web Help.%0
//
#define NS_E_WMP_DRM_INVALID_SIG         _HRESULT_TYPEDEF_(0xC00D11D7L)

//
// MessageId: NS_E_WMP_DRM_CANNOT_RESTORE
//
// MessageText:
//
//  Windows Media Player cannot restore your licenses because you have exceeded the restore limit for the day. Try again tomorrow.%0
//
#define NS_E_WMP_DRM_CANNOT_RESTORE      _HRESULT_TYPEDEF_(0xC00D11D8L)

//
// WMP CD Filter Error codes extension
//
//
// MessageId: NS_E_CD_NO_BUFFERS_READ
//
// MessageText:
//
//  Windows Media Player encountered an error when reading the CD-ROM drive in digital mode. You can try to use digital mode again, or you can switch the Player to analog mode.%0
//
#define NS_E_CD_NO_BUFFERS_READ          _HRESULT_TYPEDEF_(0xC00D11F8L)

//
// MessageId: NS_E_CD_EMPTY_TRACK_QUEUE
//
// MessageText:
//
//  No CD track was specified for playback.%0
//
#define NS_E_CD_EMPTY_TRACK_QUEUE        _HRESULT_TYPEDEF_(0xC00D11F9L)

//
// MessageId: NS_E_CD_NO_READER
//
// MessageText:
//
//  The CD filter was not able to create the CD reader.%0
//
#define NS_E_CD_NO_READER                _HRESULT_TYPEDEF_(0xC00D11FAL)

//
// MessageId: NS_E_CD_ISRC_INVALID
//
// MessageText:
//
//  Invalid ISRC code.%0
//
#define NS_E_CD_ISRC_INVALID             _HRESULT_TYPEDEF_(0xC00D11FBL)

//
// MessageId: NS_E_CD_MEDIA_CATALOG_NUMBER_INVALID
//
// MessageText:
//
//  Invalid Media Catalog Number.%0
//
#define NS_E_CD_MEDIA_CATALOG_NUMBER_INVALID _HRESULT_TYPEDEF_(0xC00D11FCL)

//
// MessageId: NS_E_SLOW_READ_DIGITAL_WITH_ERRORCORRECTION
//
// MessageText:
//
//  Media Player has detected that your CD drive cannot play back audio CDs correctly because the drive is too slow with error correction turned on. Please turn off error correction for this drive.%0
//
#define NS_E_SLOW_READ_DIGITAL_WITH_ERRORCORRECTION _HRESULT_TYPEDEF_(0xC00D11FDL)

//
// MessageId: NS_E_CD_SPEEDDETECT_NOT_ENOUGH_READS
//
// MessageText:
//
//  The CD track is too small to make a good estimate of the CD's speed.%0
//
#define NS_E_CD_SPEEDDETECT_NOT_ENOUGH_READS _HRESULT_TYPEDEF_(0xC00D11FEL)

//
// MessageId: NS_E_CD_QUEUEING_DISABLED
//
// MessageText:
//
//  Cannot queue the given CD track as queuing is disabled.%0
//
#define NS_E_CD_QUEUEING_DISABLED        _HRESULT_TYPEDEF_(0xC00D11FFL)

//
// WMP Policy error codes
//
//
// MessageId: NS_E_WMP_POLICY_VALUE_NOT_CONFIGURED
//
// MessageText:
//
//  Media Player failed to read a policy. This can happen when the policy is not present in the registry or when there is a failure to read from the registry.%0
//
#define NS_E_WMP_POLICY_VALUE_NOT_CONFIGURED _HRESULT_TYPEDEF_(0xC00D122AL)

//
//Background download plugin
//
//
// MessageId: NS_E_WMP_HWND_NOTFOUND
//
// MessageText:
//
//  Windows Media Player main window not found. The download manager needs to find it to work properly. Please try to run Windows Media Player again.%0
//
#define NS_E_WMP_HWND_NOTFOUND           _HRESULT_TYPEDEF_(0xC00D125CL)

//
// MessageId: NS_E_BKGDOWNLOAD_WRONG_NO_FILES
//
// MessageText:
//
//  Windows media player encountered a download with wrong number of files. This may happen if some other application is trying to create jobs with same signature as Windows Media Player.%0
//
#define NS_E_BKGDOWNLOAD_WRONG_NO_FILES  _HRESULT_TYPEDEF_(0xC00D125DL)

//
// MessageId: NS_E_BKGDOWNLOAD_COMPLETECANCELLEDJOB
//
// MessageText:
//
//  Windows Media Player tried to complete a download that was already cancelled. The file will not be available.%0
//
#define NS_E_BKGDOWNLOAD_COMPLETECANCELLEDJOB _HRESULT_TYPEDEF_(0xC00D125EL)

//
// MessageId: NS_E_BKGDOWNLOAD_CANCELCOMPLETEDJOB
//
// MessageText:
//
//  Windows Media Player tried to cancel a download that was already completed. The file will not be removed.%0
//
#define NS_E_BKGDOWNLOAD_CANCELCOMPLETEDJOB _HRESULT_TYPEDEF_(0xC00D125FL)

//
// MessageId: NS_E_BKGDOWNLOAD_NOJOBPOINTER
//
// MessageText:
//
//  Windows Media Player is trying to access an invalid download.%0
//
#define NS_E_BKGDOWNLOAD_NOJOBPOINTER    _HRESULT_TYPEDEF_(0xC00D1260L)

//
// MessageId: NS_E_BKGDOWNLOAD_INVALIDJOBSIGNATURE
//
// MessageText:
//
//  This download was not created by Windows Media Player.%0
//
#define NS_E_BKGDOWNLOAD_INVALIDJOBSIGNATURE _HRESULT_TYPEDEF_(0xC00D1261L)

//
// MessageId: NS_E_BKGDOWNLOAD_FAILED_TO_CREATE_TEMPFILE
//
// MessageText:
//
//  The Windows Media Player download manager failed to create a temporary file name. This may happen if the path in invalid or if the disk is full. Please check your system and try again.%0
//
#define NS_E_BKGDOWNLOAD_FAILED_TO_CREATE_TEMPFILE _HRESULT_TYPEDEF_(0xC00D1262L)

//
// MessageId: NS_E_BKGDOWNLOAD_PLUGIN_FAILEDINITIALIZE
//
// MessageText:
//
//  The Windows Media Player download manager plugin failed to initialize. This may happen if the system is out of resources. Please check your system and try again.%0
//
#define NS_E_BKGDOWNLOAD_PLUGIN_FAILEDINITIALIZE _HRESULT_TYPEDEF_(0xC00D1263L)

//
// MessageId: NS_E_BKGDOWNLOAD_PLUGIN_FAILEDTOMOVEFILE
//
// MessageText:
//
//  The Windows Media Player download manager failed to move the file.%0
//
#define NS_E_BKGDOWNLOAD_PLUGIN_FAILEDTOMOVEFILE _HRESULT_TYPEDEF_(0xC00D1264L)

//
// MessageId: NS_E_BKGDOWNLOAD_CALLFUNCFAILED
//
// MessageText:
//
//  Download manager failed to accomplish a task. This happened because the system has no resources to allocate.%0
//
#define NS_E_BKGDOWNLOAD_CALLFUNCFAILED  _HRESULT_TYPEDEF_(0xC00D1265L)

//
// MessageId: NS_E_BKGDOWNLOAD_CALLFUNCTIMEOUT
//
// MessageText:
//
//  The Windows Media Player download manager failed to accomplish a task because the task took too long to execute.%0
//
#define NS_E_BKGDOWNLOAD_CALLFUNCTIMEOUT _HRESULT_TYPEDEF_(0xC00D1266L)

//
// MessageId: NS_E_BKGDOWNLOAD_CALLFUNCENDED
//
// MessageText:
//
//  The Windows Media Player download manager failed to accomplish a task because Windows Media Player is terminating the service. The task will be recovered when Windows Media Player starts again.%0
//
#define NS_E_BKGDOWNLOAD_CALLFUNCENDED   _HRESULT_TYPEDEF_(0xC00D1267L)

//
// MessageId: NS_E_BKGDOWNLOAD_WMDUNPACKFAILED
//
// MessageText:
//
//  The Windows Media Player download manager failed to unpack a WMD package that was transferred. The file will be deleted and the operation will not be successfully completed.%0
//
#define NS_E_BKGDOWNLOAD_WMDUNPACKFAILED _HRESULT_TYPEDEF_(0xC00D1268L)

//
// MessageId: NS_E_BKGDOWNLOAD_FAILEDINITIALIZE
//
// MessageText:
//
//  The Windows Media Player download manager failed to initialize. This may happen if the system is out of resources. Please check your system and try again.%0
//
#define NS_E_BKGDOWNLOAD_FAILEDINITIALIZE _HRESULT_TYPEDEF_(0xC00D1269L)

//
// MessageId: NS_E_INTERFACE_NOT_REGISTERED_IN_GIT
//
// MessageText:
//
//  Windows Media Player failed to access a required functionality. This could be caused by wrong system or media player dlls being loaded.%0
//
#define NS_E_INTERFACE_NOT_REGISTERED_IN_GIT _HRESULT_TYPEDEF_(0xC00D126AL)

//
// MessageId: NS_E_BKGDOWNLOAD_INVALID_FILE_NAME
//
// MessageText:
//
//  Windows Media Player failed to get the file name of the requested download. The requested download will be canceled.%0
//
#define NS_E_BKGDOWNLOAD_INVALID_FILE_NAME _HRESULT_TYPEDEF_(0xC00D126BL)

//
//Image Graph Errors 4750 -- 4800
//
//
// MessageId: NS_E_IMAGE_DOWNLOAD_FAILED
//
// MessageText:
//
//  An error was encountered downloading the image.%0
//
#define NS_E_IMAGE_DOWNLOAD_FAILED       _HRESULT_TYPEDEF_(0xC00D128EL)

//
// UDRM errors
//
//
// MessageId: NS_E_WMP_UDRM_NOUSERLIST
//
// MessageText:
//
//  There was a problem while trying to get the list of activated users for this machine. The License acquisition process will be stopped.%0
//
#define NS_E_WMP_UDRM_NOUSERLIST         _HRESULT_TYPEDEF_(0xC00D12C0L)

//
// MessageId: NS_E_WMP_DRM_NOT_ACQUIRING
//
// MessageText:
//
//  The Windows Media Player is trying to acquire a license for a file that is not being used anymore. The License acquisition process will stop.%0
//
#define NS_E_WMP_DRM_NOT_ACQUIRING       _HRESULT_TYPEDEF_(0xC00D12C1L)

//
// String is too large
//
//
// MessageId: NS_E_WMP_BSTR_TOO_LONG
//
// MessageText:
//
//  The parameter is invalid.%0
//
#define NS_E_WMP_BSTR_TOO_LONG           _HRESULT_TYPEDEF_(0xC00D12F2L)

//
// Autoplay errors 4860 --- 4870
//
//
// MessageId: NS_E_WMP_AUTOPLAY_INVALID_STATE
//
// MessageText:
//
//  Invalid state for this request.%0
//
#define NS_E_WMP_AUTOPLAY_INVALID_STATE  _HRESULT_TYPEDEF_(0xC00D12FCL)

//
// CURL Errors 4900 -- 4949
//
//
// MessageId: NS_E_CURL_NOTSAFE
//
// MessageText:
//
//  The URL is not safe for the operation specified.%0
//
#define NS_E_CURL_NOTSAFE                _HRESULT_TYPEDEF_(0xC00D1324L)

//
// MessageId: NS_E_CURL_INVALIDCHAR
//
// MessageText:
//
//  The URL contains one or more invalid characters.%0
//
#define NS_E_CURL_INVALIDCHAR            _HRESULT_TYPEDEF_(0xC00D1325L)

//
// MessageId: NS_E_CURL_INVALIDHOSTNAME
//
// MessageText:
//
//  The URL contains an invalid hostname.%0
//
#define NS_E_CURL_INVALIDHOSTNAME        _HRESULT_TYPEDEF_(0xC00D1326L)

//
// MessageId: NS_E_CURL_INVALIDPATH
//
// MessageText:
//
//  The URL contains an invalid path.%0
//
#define NS_E_CURL_INVALIDPATH            _HRESULT_TYPEDEF_(0xC00D1327L)

//
// MessageId: NS_E_CURL_INVALIDSCHEME
//
// MessageText:
//
//  The URL contains an invalid scheme.%0
//
#define NS_E_CURL_INVALIDSCHEME          _HRESULT_TYPEDEF_(0xC00D1328L)

//
// MessageId: NS_E_CURL_INVALIDURL
//
// MessageText:
//
//  The URL is invalid.%0
//
#define NS_E_CURL_INVALIDURL             _HRESULT_TYPEDEF_(0xC00D1329L)

//
// MessageId: NS_E_CURL_CANTWALK
//
// MessageText:
//
//  The URL would change the root.%0
//
#define NS_E_CURL_CANTWALK               _HRESULT_TYPEDEF_(0xC00D132BL)

//
// MessageId: NS_E_CURL_INVALIDPORT
//
// MessageText:
//
//  The URL port is invalid.%0
//
#define NS_E_CURL_INVALIDPORT            _HRESULT_TYPEDEF_(0xC00D132CL)

//
// MessageId: NS_E_CURLHELPER_NOTADIRECTORY
//
// MessageText:
//
//  The URL is not a directory.%0
//
#define NS_E_CURLHELPER_NOTADIRECTORY    _HRESULT_TYPEDEF_(0xC00D132DL)

//
// MessageId: NS_E_CURLHELPER_NOTAFILE
//
// MessageText:
//
//  The URL is not a file.%0
//
#define NS_E_CURLHELPER_NOTAFILE         _HRESULT_TYPEDEF_(0xC00D132EL)

//
// MessageId: NS_E_CURL_CANTDECODE
//
// MessageText:
//
//  The URL contains characters that could not be decoded.  The URL may be truncated or incomplete.%0
//
#define NS_E_CURL_CANTDECODE             _HRESULT_TYPEDEF_(0xC00D132FL)

//
// MessageId: NS_E_CURLHELPER_NOTRELATIVE
//
// MessageText:
//
//  The specified relative URL is actually not a relative URL.%0
//
#define NS_E_CURLHELPER_NOTRELATIVE      _HRESULT_TYPEDEF_(0xC00D1330L)

//
// MessageId: NS_E_CURL_INVALIDBUFFERSIZE
//
// MessageText:
//
//  The buffer is smaller than the size specified.%0
//
#define NS_E_CURL_INVALIDBUFFERSIZE      _HRESULT_TYPEDEF_(0xC00D1355L)

//
// Subscription Service Errors 4950 -- 4969
//
//
// MessageId: NS_E_SUBSCRIPTIONSERVICE_PLAYBACK_DISALLOWED
//
// MessageText:
//
//  This content is provided by a music service. The content cannot be played, possibly because a valid license does not exist. Please contact the music service with questions.%0
//
#define NS_E_SUBSCRIPTIONSERVICE_PLAYBACK_DISALLOWED _HRESULT_TYPEDEF_(0xC00D1356L)

//
// Advanced Edit Dialog Errors 4970 -- 4989
//
//
// MessageId: NS_E_ADVANCEDEDIT_TOO_MANY_PICTURES
//
// MessageText:
//
//  Not all your images were saved to the file. Only 7MB of images may be saved to a media file.%0
//
#define NS_E_ADVANCEDEDIT_TOO_MANY_PICTURES _HRESULT_TYPEDEF_(0xC00D136AL)



/////////////////////////////////////////////////////////////////////////
//
// Windows Media Server Errors
//
// IdRange = 5000 - 5999
//
/////////////////////////////////////////////////////////////////////////

//
// MessageId: NS_E_REDIRECT
//
// MessageText:
//
//  The client redirected to another server.%0
//
#define NS_E_REDIRECT                    _HRESULT_TYPEDEF_(0xC00D1388L)

//
// MessageId: NS_E_STALE_PRESENTATION
//
// MessageText:
//
//  The streaming media description is no longer current.%0
//
#define NS_E_STALE_PRESENTATION          _HRESULT_TYPEDEF_(0xC00D1389L)


 // Namespace Errors

//
// MessageId: NS_E_NAMESPACE_WRONG_PERSIST
//
// MessageText:
//
//  It is not possible to create a persistent namespace node under a transient parent node.%0
//
#define NS_E_NAMESPACE_WRONG_PERSIST     _HRESULT_TYPEDEF_(0xC00D138AL)

//
// MessageId: NS_E_NAMESPACE_WRONG_TYPE
//
// MessageText:
//
//  It is not possible to store a value in a namespace node that has a different value type.%0
//
#define NS_E_NAMESPACE_WRONG_TYPE        _HRESULT_TYPEDEF_(0xC00D138BL)

//
// MessageId: NS_E_NAMESPACE_NODE_CONFLICT
//
// MessageText:
//
//  It is not possible to remove the root namespace node.%0
//
#define NS_E_NAMESPACE_NODE_CONFLICT     _HRESULT_TYPEDEF_(0xC00D138CL)

//
// MessageId: NS_E_NAMESPACE_NODE_NOT_FOUND
//
// MessageText:
//
//  The specified namespace node could not be found.%0
//
#define NS_E_NAMESPACE_NODE_NOT_FOUND    _HRESULT_TYPEDEF_(0xC00D138DL)

//
// MessageId: NS_E_NAMESPACE_BUFFER_TOO_SMALL
//
// MessageText:
//
//  The buffer supplied to hold namespace node string is too small.%0
//
#define NS_E_NAMESPACE_BUFFER_TOO_SMALL  _HRESULT_TYPEDEF_(0xC00D138EL)

//
// MessageId: NS_E_NAMESPACE_TOO_MANY_CALLBACKS
//
// MessageText:
//
//  The callback list on a namespace node is at the maximum size.%0
//
#define NS_E_NAMESPACE_TOO_MANY_CALLBACKS _HRESULT_TYPEDEF_(0xC00D138FL)

//
// MessageId: NS_E_NAMESPACE_DUPLICATE_CALLBACK
//
// MessageText:
//
//  It is not possible to register an already-registered callback on a namespace node.%0
//
#define NS_E_NAMESPACE_DUPLICATE_CALLBACK _HRESULT_TYPEDEF_(0xC00D1390L)

//
// MessageId: NS_E_NAMESPACE_CALLBACK_NOT_FOUND
//
// MessageText:
//
//  Cannot find the callback in the namespace when attempting to remove the callback.%0
//
#define NS_E_NAMESPACE_CALLBACK_NOT_FOUND _HRESULT_TYPEDEF_(0xC00D1391L)

//
// MessageId: NS_E_NAMESPACE_NAME_TOO_LONG
//
// MessageText:
//
//  The namespace node name exceeds the allowed maximum length.%0
//
#define NS_E_NAMESPACE_NAME_TOO_LONG     _HRESULT_TYPEDEF_(0xC00D1392L)

//
// MessageId: NS_E_NAMESPACE_DUPLICATE_NAME
//
// MessageText:
//
//  Cannot create a namespace node that already exists.%0
//
#define NS_E_NAMESPACE_DUPLICATE_NAME    _HRESULT_TYPEDEF_(0xC00D1393L)

//
// MessageId: NS_E_NAMESPACE_EMPTY_NAME
//
// MessageText:
//
//  The namespace node name cannot be a null string.%0
//
#define NS_E_NAMESPACE_EMPTY_NAME        _HRESULT_TYPEDEF_(0xC00D1394L)

//
// MessageId: NS_E_NAMESPACE_INDEX_TOO_LARGE
//
// MessageText:
//
//  Finding a child namespace node by index failed because the index exceeded the number of children.%0
//
#define NS_E_NAMESPACE_INDEX_TOO_LARGE   _HRESULT_TYPEDEF_(0xC00D1395L)

//
// MessageId: NS_E_NAMESPACE_BAD_NAME
//
// MessageText:
//
//  The namespace node name is invalid.%0
//
#define NS_E_NAMESPACE_BAD_NAME          _HRESULT_TYPEDEF_(0xC00D1396L)

//
// MessageId: NS_E_NAMESPACE_WRONG_SECURITY
//
// MessageText:
//
//  It is not possible to store a value in a namespace node that has a different security type.%0
//
#define NS_E_NAMESPACE_WRONG_SECURITY    _HRESULT_TYPEDEF_(0xC00D1397L)


 // Cache Errors 5100-5199

//
// MessageId: NS_E_CACHE_ARCHIVE_CONFLICT
//
// MessageText:
//
//  The archive request conflicts with other requests in progress.%0
//
#define NS_E_CACHE_ARCHIVE_CONFLICT      _HRESULT_TYPEDEF_(0xC00D13ECL)

//
// MessageId: NS_E_CACHE_ORIGIN_SERVER_NOT_FOUND
//
// MessageText:
//
//  The specified origin server cannot be found.%0
//
#define NS_E_CACHE_ORIGIN_SERVER_NOT_FOUND _HRESULT_TYPEDEF_(0xC00D13EDL)

//
// MessageId: NS_E_CACHE_ORIGIN_SERVER_TIMEOUT
//
// MessageText:
//
//  The specified origin server is not responding.%0
//
#define NS_E_CACHE_ORIGIN_SERVER_TIMEOUT _HRESULT_TYPEDEF_(0xC00D13EEL)

//
// MessageId: NS_E_CACHE_NOT_BROADCAST
//
// MessageText:
//
//  The internal code for HTTP status code 412 Precondition Failed due to not broadcast type.%0
//
#define NS_E_CACHE_NOT_BROADCAST         _HRESULT_TYPEDEF_(0xC00D13EFL)

//
// MessageId: NS_E_CACHE_CANNOT_BE_CACHED
//
// MessageText:
//
//  The internal code for HTTP status code 403 Forbidden due to not cacheable.%0
//
#define NS_E_CACHE_CANNOT_BE_CACHED      _HRESULT_TYPEDEF_(0xC00D13F0L)

//
// MessageId: NS_E_CACHE_NOT_MODIFIED
//
// MessageText:
//
//  The internal code for HTTP status code 304 Not Modified.%0
//
#define NS_E_CACHE_NOT_MODIFIED          _HRESULT_TYPEDEF_(0xC00D13F1L)


// Object Model Errors 5200-5299

//
// MessageId: NS_E_CANNOT_REMOVE_PUBLISHING_POINT
//
// MessageText:
//
//  It is not possible to remove a cache or proxy publishing point.%0
//
#define NS_E_CANNOT_REMOVE_PUBLISHING_POINT _HRESULT_TYPEDEF_(0xC00D1450L)

//
// MessageId: NS_E_CANNOT_REMOVE_PLUGIN
//
// MessageText:
//
//  It is not possible to remove the last instance of a type of plug-in.%0
//
#define NS_E_CANNOT_REMOVE_PLUGIN        _HRESULT_TYPEDEF_(0xC00D1451L)

//
// MessageId: NS_E_WRONG_PUBLISHING_POINT_TYPE
//
// MessageText:
//
//  Cache and proxy publishing points do not support this property or method.%0
//
#define NS_E_WRONG_PUBLISHING_POINT_TYPE _HRESULT_TYPEDEF_(0xC00D1452L)

//
// MessageId: NS_E_UNSUPPORTED_LOAD_TYPE
//
// MessageText:
//
//  The plug-in does not support the specified load type.%0
//
#define NS_E_UNSUPPORTED_LOAD_TYPE       _HRESULT_TYPEDEF_(0xC00D1453L)

//
// MessageId: NS_E_INVALID_PLUGIN_LOAD_TYPE_CONFIGURATION
//
// MessageText:
//
//  The plug-in does not support any load types. The plug-in must support at least one load type.%0
//
#define NS_E_INVALID_PLUGIN_LOAD_TYPE_CONFIGURATION _HRESULT_TYPEDEF_(0xC00D1454L)

//
// MessageId: NS_E_INVALID_PUBLISHING_POINT_NAME
//
// MessageText:
//
//  The publishing point name is invalid.%0
//
#define NS_E_INVALID_PUBLISHING_POINT_NAME _HRESULT_TYPEDEF_(0xC00D1455L)

//
// MessageId: NS_E_TOO_MANY_MULTICAST_SINKS
//
// MessageText:
//
//  Only one multicast data writer plug-in can be enabled for a publishing point.%0
//
#define NS_E_TOO_MANY_MULTICAST_SINKS    _HRESULT_TYPEDEF_(0xC00D1456L)

//
// MessageId: NS_E_PUBLISHING_POINT_INVALID_REQUEST_WHILE_STARTED
//
// MessageText:
//
//  The requested operation cannot be completed while the publishing point is started.%0
//
#define NS_E_PUBLISHING_POINT_INVALID_REQUEST_WHILE_STARTED _HRESULT_TYPEDEF_(0xC00D1457L)

//
// MessageId: NS_E_MULTICAST_PLUGIN_NOT_ENABLED
//
// MessageText:
//
//  A multicast data writer plug-in must be enabled in order for this operation to be completed.%0
//
#define NS_E_MULTICAST_PLUGIN_NOT_ENABLED _HRESULT_TYPEDEF_(0xC00D1458L)

//
// MessageId: NS_E_INVALID_OPERATING_SYSTEM_VERSION
//
// MessageText:
//
//  This feature requires Windows .NET Enterprise Server.%0
//
#define NS_E_INVALID_OPERATING_SYSTEM_VERSION _HRESULT_TYPEDEF_(0xC00D1459L)

//
// MessageId: NS_E_PUBLISHING_POINT_REMOVED
//
// MessageText:
//
//  The requested operation cannot be completed because the specified publishing point has been removed.%0
//
#define NS_E_PUBLISHING_POINT_REMOVED    _HRESULT_TYPEDEF_(0xC00D145AL)

//
// MessageId: NS_E_INVALID_PUSH_PUBLISHING_POINT_START_REQUEST
//
// MessageText:
//
//  Push publishing points are started when the encoder starts pushing the stream. This publishing point cannot be started by the server administrator.%0
//
#define NS_E_INVALID_PUSH_PUBLISHING_POINT_START_REQUEST _HRESULT_TYPEDEF_(0xC00D145BL)

//
// MessageId: NS_E_UNSUPPORTED_LANGUAGE
//
// MessageText:
//
//  The specified language is not supported.%0
//
#define NS_E_UNSUPPORTED_LANGUAGE        _HRESULT_TYPEDEF_(0xC00D145CL)

//
// MessageId: NS_E_WRONG_OS_VERSION
//
// MessageText:
//
//  Windows Media Services will only run on Windows .NET Server and Windows .NET Enterprise Server.%0
//
#define NS_E_WRONG_OS_VERSION            _HRESULT_TYPEDEF_(0xC00D145DL)

//
// MessageId: NS_E_PUBLISHING_POINT_STOPPED
//
// MessageText:
//
//  The operation cannot be completed because the publishing point has been stopped.%0
//
#define NS_E_PUBLISHING_POINT_STOPPED    _HRESULT_TYPEDEF_(0xC00D145EL)


// Playlist Errors 5300-5399

//
// MessageId: NS_E_PLAYLIST_ENTRY_ALREADY_PLAYING
//
// MessageText:
//
//  The playlist entry is already playing.%0
//
#define NS_E_PLAYLIST_ENTRY_ALREADY_PLAYING _HRESULT_TYPEDEF_(0xC00D14B4L)

//
// MessageId: NS_E_EMPTY_PLAYLIST
//
// MessageText:
//
//  The playlist or directory you are requesting does not contain content.%0
//
#define NS_E_EMPTY_PLAYLIST              _HRESULT_TYPEDEF_(0xC00D14B5L)

//
// MessageId: NS_E_PLAYLIST_PARSE_FAILURE
//
// MessageText:
//
//  The server was unable to parse the requested playlist file.%0
//
#define NS_E_PLAYLIST_PARSE_FAILURE      _HRESULT_TYPEDEF_(0xC00D14B6L)

//
// MessageId: NS_E_PLAYLIST_UNSUPPORTED_ENTRY
//
// MessageText:
//
//  The requested operation is not supported for this type of playlist entry.%0
//
#define NS_E_PLAYLIST_UNSUPPORTED_ENTRY  _HRESULT_TYPEDEF_(0xC00D14B7L)

//
// MessageId: NS_E_PLAYLIST_ENTRY_NOT_IN_PLAYLIST
//
// MessageText:
//
//  Cannot jump to a playlist entry that is not inserted in the playlist.%0
//
#define NS_E_PLAYLIST_ENTRY_NOT_IN_PLAYLIST _HRESULT_TYPEDEF_(0xC00D14B8L)

//
// MessageId: NS_E_PLAYLIST_ENTRY_SEEK
//
// MessageText:
//
//  Cannot seek to the desired playlist entry.%0
//
#define NS_E_PLAYLIST_ENTRY_SEEK         _HRESULT_TYPEDEF_(0xC00D14B9L)

//
// MessageId: NS_E_PLAYLIST_RECURSIVE_PLAYLISTS
//
// MessageText:
//
//  Cannot play recursive playlist.%0
//
#define NS_E_PLAYLIST_RECURSIVE_PLAYLISTS _HRESULT_TYPEDEF_(0xC00D14BAL)

//
// MessageId: NS_E_PLAYLIST_TOO_MANY_NESTED_PLAYLISTS
//
// MessageText:
//
//  The number of nested playlists exceeded the limit the server can handle.%0
//
#define NS_E_PLAYLIST_TOO_MANY_NESTED_PLAYLISTS _HRESULT_TYPEDEF_(0xC00D14BBL)

//
// MessageId: NS_E_PLAYLIST_SHUTDOWN
//
// MessageText:
//
//  Cannot execute the requested operation because the playlist has been shut down by the Media Server.%0
//
#define NS_E_PLAYLIST_SHUTDOWN           _HRESULT_TYPEDEF_(0xC00D14BCL)

//
// MessageId: NS_E_PLAYLIST_END_RECEDING
//
// MessageText:
//
//  The playlist has ended while receding.%0
//
#define NS_E_PLAYLIST_END_RECEDING       _HRESULT_TYPEDEF_(0xC00D14BDL)

//
// MessageId: NS_I_PLAYLIST_CHANGE_RECEDING
//
// MessageText:
//
//  The playlist change occurred while receding.%0
//
#define NS_I_PLAYLIST_CHANGE_RECEDING    _HRESULT_TYPEDEF_(0x400D14BEL)


// Datapath Errors -- 5400 - 5499

//
// MessageId: NS_E_DATAPATH_NO_SINK
//
// MessageText:
//
//  The data path does not have an associated data writer plug-in.%0
//
#define NS_E_DATAPATH_NO_SINK            _HRESULT_TYPEDEF_(0xC00D1518L)

//
// MessageId: NS_S_PUBLISHING_POINT_STARTED_WITH_FAILED_SINKS
//
// MessageText:
//
//  The publishing point successfully started, but one or more of the requested data writer plug-ins failed.%0
//
#define NS_S_PUBLISHING_POINT_STARTED_WITH_FAILED_SINKS _HRESULT_TYPEDEF_(0x000D1519L)

//
// MessageId: NS_E_INVALID_PUSH_TEMPLATE
//
// MessageText:
//
//  The specified push template is invalid.%0
//
#define NS_E_INVALID_PUSH_TEMPLATE       _HRESULT_TYPEDEF_(0xC00D151AL)

//
// MessageId: NS_E_INVALID_PUSH_PUBLISHING_POINT
//
// MessageText:
//
//  The specified push publishing point is invalid.%0
//
#define NS_E_INVALID_PUSH_PUBLISHING_POINT _HRESULT_TYPEDEF_(0xC00D151BL)

//
// MessageId: NS_E_CRITICAL_ERROR
//
// MessageText:
//
//  The requested operation cannot be performed because the server or publishing point is in a critical error state.%0
//
#define NS_E_CRITICAL_ERROR              _HRESULT_TYPEDEF_(0xC00D151CL)

//
// MessageId: NS_E_NO_NEW_CONNECTIONS
//
// MessageText:
//
//  The content can not be played because the server is not currently accepting connections. Try connecting at a later time.%0
//
#define NS_E_NO_NEW_CONNECTIONS          _HRESULT_TYPEDEF_(0xC00D151DL)

//
// MessageId: NS_E_WSX_INVALID_VERSION
//
// MessageText:
//
//  The version of this playlist is not supported by the server.%0
//
#define NS_E_WSX_INVALID_VERSION         _HRESULT_TYPEDEF_(0xC00D151EL)

//
// MessageId: NS_E_HEADER_MISMATCH
//
// MessageText:
//
//  The command does not apply to the current media header user by a server component.%0
//
#define NS_E_HEADER_MISMATCH             _HRESULT_TYPEDEF_(0xC00D151FL)

//
// MessageId: NS_E_PUSH_DUPLICATE_PUBLISHING_POINT_NAME
//
// MessageText:
//
//  The specified publishing point name is already in use.%0
//
#define NS_E_PUSH_DUPLICATE_PUBLISHING_POINT_NAME _HRESULT_TYPEDEF_(0xC00D1520L)


// Plugin Errors -- 5500 - 5599

//
// MessageId: NS_E_NO_SCRIPT_ENGINE
//
// MessageText:
//
//  There is no script engine available for this file.%0
//
#define NS_E_NO_SCRIPT_ENGINE            _HRESULT_TYPEDEF_(0xC00D157CL)

//
// MessageId: NS_E_PLUGIN_ERROR_REPORTED
//
// MessageText:
//
//  The plug-in has reported an error. See the Troubleshooting tab or the NT Application Event Log for details.%0
//
#define NS_E_PLUGIN_ERROR_REPORTED       _HRESULT_TYPEDEF_(0xC00D157DL)

//
// MessageId: NS_E_SOURCE_PLUGIN_NOT_FOUND
//
// MessageText:
//
//  No enabled data source plug-in is available to access the requested content.%0
//
#define NS_E_SOURCE_PLUGIN_NOT_FOUND     _HRESULT_TYPEDEF_(0xC00D157EL)

//
// MessageId: NS_E_PLAYLIST_PLUGIN_NOT_FOUND
//
// MessageText:
//
//  No enabled playlist parser plug-in is available to access the requested content.%0
//
#define NS_E_PLAYLIST_PLUGIN_NOT_FOUND   _HRESULT_TYPEDEF_(0xC00D157FL)

//
// MessageId: NS_E_DATA_SOURCE_ENUMERATION_NOT_SUPPORTED
//
// MessageText:
//
//  The data source plug-in does not support enumeration.%0
//
#define NS_E_DATA_SOURCE_ENUMERATION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC00D1580L)

//
// MessageId: NS_E_MEDIA_PARSER_INVALID_FORMAT
//
// MessageText:
//
//  The server cannot stream the selected file because it is either damaged or corrupt. Select a different file.%0
//
#define NS_E_MEDIA_PARSER_INVALID_FORMAT _HRESULT_TYPEDEF_(0xC00D1581L)

//
// MessageId: NS_E_SCRIPT_DEBUGGER_NOT_INSTALLED
//
// MessageText:
//
//  The plug-in cannot be enabled because a compatible script debugger is not installed on this system.  Install a script debugger, or disable the script debugger option on the general tab of the plug-in's properties page and try again.%0
//
#define NS_E_SCRIPT_DEBUGGER_NOT_INSTALLED _HRESULT_TYPEDEF_(0xC00D1582L)

//
// MessageId: NS_E_FEATURE_REQUIRES_ENTERPRISE_SERVER
//
// MessageText:
//
//  The plug-in cannot be loaded because it requires Windows .NET Enterprise Server.%0
//
#define NS_E_FEATURE_REQUIRES_ENTERPRISE_SERVER _HRESULT_TYPEDEF_(0xC00D1583L)

//
// MessageId: NS_E_WIZARD_RUNNING
//
// MessageText:
//
//  Another wizard is currently running. Please close the other wizard or wait until it finishes before attempting to run this wizard again.%0
//
#define NS_E_WIZARD_RUNNING              _HRESULT_TYPEDEF_(0xC00D1584L)

//
// MessageId: NS_E_INVALID_LOG_URL
//
// MessageText:
//
//  Invalid log URL. Multicast logging URL must look like "http://servername/isapibackend.dll" .%0
//
#define NS_E_INVALID_LOG_URL             _HRESULT_TYPEDEF_(0xC00D1585L)

//
// MessageId: NS_E_INVALID_MTU_RANGE
//
// MessageText:
//
//  Invalid MTU specified. The valid range for maximum packet size is between 36  and 65507 bytes .%0
//
#define NS_E_INVALID_MTU_RANGE           _HRESULT_TYPEDEF_(0xC00D1586L)

//
// MessageId: NS_E_INVALID_PLAY_STATISTICS
//
// MessageText:
//
//  Invalid play statistics for logging .%0
//
#define NS_E_INVALID_PLAY_STATISTICS     _HRESULT_TYPEDEF_(0xC00D1587L)

//
// MessageId: NS_E_LOG_NEED_TO_BE_SKIPPED
//
// MessageText:
//
//  The log needs to be skipped .%0
//
#define NS_E_LOG_NEED_TO_BE_SKIPPED      _HRESULT_TYPEDEF_(0xC00D1588L)

//
// MessageId: NS_E_HTTP_TEXT_DATACONTAINER_SIZE_LIMIT_EXCEEDED
//
// MessageText:
//
//  The size of the data exceeded the limit the WMS HTTP Download Data Source plugin can handle.%0
//
#define NS_E_HTTP_TEXT_DATACONTAINER_SIZE_LIMIT_EXCEEDED _HRESULT_TYPEDEF_(0xC00D1589L)

//
// MessageId: NS_E_PORT_IN_USE
//
// MessageText:
//
//  One usage of each socket address (protocol/network address/port) is permitted. Verify that other services or applications are not attempting to use the same port and then try to enable the plug-in again.%0
//
#define NS_E_PORT_IN_USE                 _HRESULT_TYPEDEF_(0xC00D158AL)

//
// MessageId: NS_E_PORT_IN_USE_HTTP
//
// MessageText:
//
//  One usage of each socket address (protocol/network address/port) is permitted. Verify that other services (such as IIS) or applications are not attempting to use the same port and then try to enable the plug-in again.%0
//
#define NS_E_PORT_IN_USE_HTTP            _HRESULT_TYPEDEF_(0xC00D158BL)

//
// MessageId: NS_E_HTTP_TEXT_DATACONTAINER_INVALID_SERVER_RESPONSE
//
// MessageText:
//
//  The WMS HTTP Download Data Source plugin was unable to receive the remote server's response.%0
//
#define NS_E_HTTP_TEXT_DATACONTAINER_INVALID_SERVER_RESPONSE _HRESULT_TYPEDEF_(0xC00D158CL)

//
// MessageId: NS_E_ARCHIVE_REACH_QUOTA
//
// MessageText:
//
//  The archive plug-in has reached its quota.%0
//
#define NS_E_ARCHIVE_REACH_QUOTA         _HRESULT_TYPEDEF_(0xC00D158DL)

//
// MessageId: NS_E_ARCHIVE_ABORT_DUE_TO_BCAST
//
// MessageText:
//
//  The archive plug-in aborted because the source was from broadcast.%0
//
#define NS_E_ARCHIVE_ABORT_DUE_TO_BCAST  _HRESULT_TYPEDEF_(0xC00D158EL)

//
// MessageId: NS_E_ARCHIVE_GAP_DETECTED
//
// MessageText:
//
//  The archive plug-in detected an interrupt in the source.%0
//
#define NS_E_ARCHIVE_GAP_DETECTED        _HRESULT_TYPEDEF_(0xC00D158FL)



/////////////////////////////////////////////////////////////////////////
//
// Windows Media Tools Errors
//
// IdRange = 7000 - 7999
//
/////////////////////////////////////////////////////////////////////////

//
// MessageId: NS_E_BAD_MARKIN
//
// MessageText:
//
//  The mark-in time should be greater than 0 and less than the mark-out time.%0
//
#define NS_E_BAD_MARKIN                  _HRESULT_TYPEDEF_(0xC00D1B58L)

//
// MessageId: NS_E_BAD_MARKOUT
//
// MessageText:
//
//  The mark-out time should be greater than the mark-in time and less than the file duration.%0
//
#define NS_E_BAD_MARKOUT                 _HRESULT_TYPEDEF_(0xC00D1B59L)

//
// MessageId: NS_E_NOMATCHING_MEDIASOURCE
//
// MessageText:
//
//  No matching media type is found in the source %1.%0
//
#define NS_E_NOMATCHING_MEDIASOURCE      _HRESULT_TYPEDEF_(0xC00D1B5AL)

//
// MessageId: NS_E_UNSUPPORTED_SOURCETYPE
//
// MessageText:
//
//  The specified source type is not supported.%0
//
#define NS_E_UNSUPPORTED_SOURCETYPE      _HRESULT_TYPEDEF_(0xC00D1B5BL)

//
// MessageId: NS_E_TOO_MANY_AUDIO
//
// MessageText:
//
//  It is not possible to specify more than one audio input.%0
//
#define NS_E_TOO_MANY_AUDIO              _HRESULT_TYPEDEF_(0xC00D1B5CL)

//
// MessageId: NS_E_TOO_MANY_VIDEO
//
// MessageText:
//
//  It is not possible to specify more than two video inputs.%0
//
#define NS_E_TOO_MANY_VIDEO              _HRESULT_TYPEDEF_(0xC00D1B5DL)

//
// MessageId: NS_E_NOMATCHING_ELEMENT
//
// MessageText:
//
//  No matching element is found in the list.%0
//
#define NS_E_NOMATCHING_ELEMENT          _HRESULT_TYPEDEF_(0xC00D1B5EL)

//
// MessageId: NS_E_MISMATCHED_MEDIACONTENT
//
// MessageText:
//
//  The profile's media types must match the media types defined for the session.%0
//
#define NS_E_MISMATCHED_MEDIACONTENT     _HRESULT_TYPEDEF_(0xC00D1B5FL)

//
// MessageId: NS_E_CANNOT_DELETE_ACTIVE_SOURCEGROUP
//
// MessageText:
//
//  It is not possible to remove an active source while encoding.%0
//
#define NS_E_CANNOT_DELETE_ACTIVE_SOURCEGROUP _HRESULT_TYPEDEF_(0xC00D1B60L)

//
// MessageId: NS_E_AUDIODEVICE_BUSY
//
// MessageText:
//
//  It is not possible to open the specified audio capture device because it is currently in use.%0
//
#define NS_E_AUDIODEVICE_BUSY            _HRESULT_TYPEDEF_(0xC00D1B61L)

//
// MessageId: NS_E_AUDIODEVICE_UNEXPECTED
//
// MessageText:
//
//  It is not possible to open the specified audio capture device because an unexpected error has occurred.%0
//
#define NS_E_AUDIODEVICE_UNEXPECTED      _HRESULT_TYPEDEF_(0xC00D1B62L)

//
// MessageId: NS_E_AUDIODEVICE_BADFORMAT
//
// MessageText:
//
//  The audio capture device does not support the specified audio format.%0
//
#define NS_E_AUDIODEVICE_BADFORMAT       _HRESULT_TYPEDEF_(0xC00D1B63L)

//
// MessageId: NS_E_VIDEODEVICE_BUSY
//
// MessageText:
//
//  It is not possible to open the specified video capture device because it is currently in use.%0
//
#define NS_E_VIDEODEVICE_BUSY            _HRESULT_TYPEDEF_(0xC00D1B64L)

//
// MessageId: NS_E_VIDEODEVICE_UNEXPECTED
//
// MessageText:
//
//  It is not possible to open the specified video capture device because an unexpected error has occurred.%0
//
#define NS_E_VIDEODEVICE_UNEXPECTED      _HRESULT_TYPEDEF_(0xC00D1B65L)

//
// MessageId: NS_E_INVALIDCALL_WHILE_ENCODER_RUNNING
//
// MessageText:
//
//  This operation is not allowed while encoding.%0
//
#define NS_E_INVALIDCALL_WHILE_ENCODER_RUNNING _HRESULT_TYPEDEF_(0xC00D1B66L)

//
// MessageId: NS_E_NO_PROFILE_IN_SOURCEGROUP
//
// MessageText:
//
//  No profile is set for the source.%0
//
#define NS_E_NO_PROFILE_IN_SOURCEGROUP   _HRESULT_TYPEDEF_(0xC00D1B67L)

//
// MessageId: NS_E_VIDEODRIVER_UNSTABLE
//
// MessageText:
//
//  The video capture driver returned an unrecoverable error.  It is now in an unstable state.%0
//
#define NS_E_VIDEODRIVER_UNSTABLE        _HRESULT_TYPEDEF_(0xC00D1B68L)

//
// MessageId: NS_E_VIDCAPSTARTFAILED
//
// MessageText:
//
//  It was not possible to start the video device.%0
//
#define NS_E_VIDCAPSTARTFAILED           _HRESULT_TYPEDEF_(0xC00D1B69L)

//
// MessageId: NS_E_VIDSOURCECOMPRESSION
//
// MessageText:
//
//  The video source does not support the requested output format or color depth.%0
//
#define NS_E_VIDSOURCECOMPRESSION        _HRESULT_TYPEDEF_(0xC00D1B6AL)

//
// MessageId: NS_E_VIDSOURCESIZE
//
// MessageText:
//
//  The video source does not support the requested capture size.%0
//
#define NS_E_VIDSOURCESIZE               _HRESULT_TYPEDEF_(0xC00D1B6BL)

//
// MessageId: NS_E_ICMQUERYFORMAT
//
// MessageText:
//
//  It was not possible to obtain output information from the video compressor.%0
//
#define NS_E_ICMQUERYFORMAT              _HRESULT_TYPEDEF_(0xC00D1B6CL)

//
// MessageId: NS_E_VIDCAPCREATEWINDOW
//
// MessageText:
//
//  It was not possible to create a video capture window.%0
//
#define NS_E_VIDCAPCREATEWINDOW          _HRESULT_TYPEDEF_(0xC00D1B6DL)

//
// MessageId: NS_E_VIDCAPDRVINUSE
//
// MessageText:
//
//  There is already a stream active on this video device.%0
//
#define NS_E_VIDCAPDRVINUSE              _HRESULT_TYPEDEF_(0xC00D1B6EL)

//
// MessageId: NS_E_NO_MEDIAFORMAT_IN_SOURCE
//
// MessageText:
//
//  No media format is set in source.%0
//
#define NS_E_NO_MEDIAFORMAT_IN_SOURCE    _HRESULT_TYPEDEF_(0xC00D1B6FL)

//
// MessageId: NS_E_NO_VALID_OUTPUT_STREAM
//
// MessageText:
//
//  Cannot find a valid output stream from the source.%0
//
#define NS_E_NO_VALID_OUTPUT_STREAM      _HRESULT_TYPEDEF_(0xC00D1B70L)

//
// MessageId: NS_E_NO_VALID_SOURCE_PLUGIN
//
// MessageText:
//
//  It was not possible to find a valid source plug-in for the specified source.%0
//
#define NS_E_NO_VALID_SOURCE_PLUGIN      _HRESULT_TYPEDEF_(0xC00D1B71L)

//
// MessageId: NS_E_NO_ACTIVE_SOURCEGROUP
//
// MessageText:
//
//  No source is currently active.%0
//
#define NS_E_NO_ACTIVE_SOURCEGROUP       _HRESULT_TYPEDEF_(0xC00D1B72L)

//
// MessageId: NS_E_NO_SCRIPT_STREAM
//
// MessageText:
//
//  No script stream is set in the current source.%0
//
#define NS_E_NO_SCRIPT_STREAM            _HRESULT_TYPEDEF_(0xC00D1B73L)

//
// MessageId: NS_E_INVALIDCALL_WHILE_ARCHIVAL_RUNNING
//
// MessageText:
//
//  This operation is not allowed while archiving.%0
//
#define NS_E_INVALIDCALL_WHILE_ARCHIVAL_RUNNING _HRESULT_TYPEDEF_(0xC00D1B74L)

//
// MessageId: NS_E_INVALIDPACKETSIZE
//
// MessageText:
//
//  The setting for the maximum packet size is not valid.%0
//
#define NS_E_INVALIDPACKETSIZE           _HRESULT_TYPEDEF_(0xC00D1B75L)

//
// MessageId: NS_E_PLUGIN_CLSID_INVALID
//
// MessageText:
//
//  The plug-in CLSID specified is not valid.%0
//
#define NS_E_PLUGIN_CLSID_INVALID        _HRESULT_TYPEDEF_(0xC00D1B76L)

//
// MessageId: NS_E_UNSUPPORTED_ARCHIVETYPE
//
// MessageText:
//
//  This archive type is not supported.%0
//
#define NS_E_UNSUPPORTED_ARCHIVETYPE     _HRESULT_TYPEDEF_(0xC00D1B77L)

//
// MessageId: NS_E_UNSUPPORTED_ARCHIVEOPERATION
//
// MessageText:
//
//  This archive operation is not supported.%0
//
#define NS_E_UNSUPPORTED_ARCHIVEOPERATION _HRESULT_TYPEDEF_(0xC00D1B78L)

//
// MessageId: NS_E_ARCHIVE_FILENAME_NOTSET
//
// MessageText:
//
//  The local archive file name was not set.%0
//
#define NS_E_ARCHIVE_FILENAME_NOTSET     _HRESULT_TYPEDEF_(0xC00D1B79L)

//
// MessageId: NS_E_SOURCEGROUP_NOTPREPARED
//
// MessageText:
//
//  The source is not yet prepared.%0
//
#define NS_E_SOURCEGROUP_NOTPREPARED     _HRESULT_TYPEDEF_(0xC00D1B7AL)

//
// MessageId: NS_E_PROFILE_MISMATCH
//
// MessageText:
//
//  Profiles on the sources do not match.%0
//
#define NS_E_PROFILE_MISMATCH            _HRESULT_TYPEDEF_(0xC00D1B7BL)

//
// MessageId: NS_E_INCORRECTCLIPSETTINGS
//
// MessageText:
//
//  The specified crop values are not valid.%0
//
#define NS_E_INCORRECTCLIPSETTINGS       _HRESULT_TYPEDEF_(0xC00D1B7CL)

//
// MessageId: NS_E_NOSTATSAVAILABLE
//
// MessageText:
//
//  No statistics are available at this time.%0
//
#define NS_E_NOSTATSAVAILABLE            _HRESULT_TYPEDEF_(0xC00D1B7DL)

//
// MessageId: NS_E_NOTARCHIVING
//
// MessageText:
//
//  The encoder is not archiving.%0
//
#define NS_E_NOTARCHIVING                _HRESULT_TYPEDEF_(0xC00D1B7EL)

//
// MessageId: NS_E_INVALIDCALL_WHILE_ENCODER_STOPPED
//
// MessageText:
//
//  This operation is only allowed during encoding.%0
//
#define NS_E_INVALIDCALL_WHILE_ENCODER_STOPPED _HRESULT_TYPEDEF_(0xC00D1B7FL)

//
// MessageId: NS_E_NOSOURCEGROUPS
//
// MessageText:
//
//  This SourceGroupCollection doesn't contain any SourceGroups.%0
//
#define NS_E_NOSOURCEGROUPS              _HRESULT_TYPEDEF_(0xC00D1B80L)

//
// MessageId: NS_E_INVALIDINPUTFPS
//
// MessageText:
//
//  This source does not have a frame rate of 30 fps. Therefore, it is not possible to apply the inverse telecine filter to the source.%0
//
#define NS_E_INVALIDINPUTFPS             _HRESULT_TYPEDEF_(0xC00D1B81L)

//
// MessageId: NS_E_NO_DATAVIEW_SUPPORT
//
// MessageText:
//
//  It is not possible to display your source or output video in the Video panel.%0
//
#define NS_E_NO_DATAVIEW_SUPPORT         _HRESULT_TYPEDEF_(0xC00D1B82L)

//
// MessageId: NS_E_CODEC_UNAVAILABLE
//
// MessageText:
//
//  One or more codecs required to open this content could not be found.%0
//
#define NS_E_CODEC_UNAVAILABLE           _HRESULT_TYPEDEF_(0xC00D1B83L)

//
// MessageId: NS_E_ARCHIVE_SAME_AS_INPUT
//
// MessageText:
//
//  The archive file has the same name as an input file. Change one of the names before continuing.%0
//
#define NS_E_ARCHIVE_SAME_AS_INPUT       _HRESULT_TYPEDEF_(0xC00D1B84L)

//
// MessageId: NS_E_SOURCE_NOTSPECIFIED
//
// MessageText:
//
//  The source has not been set up completely.%0
//
#define NS_E_SOURCE_NOTSPECIFIED         _HRESULT_TYPEDEF_(0xC00D1B85L)

//
// MessageId: NS_E_NO_REALTIME_TIMECOMPRESSION
//
// MessageText:
//
//  It is not possible to apply time compression to a broadcast session.%0
//
#define NS_E_NO_REALTIME_TIMECOMPRESSION _HRESULT_TYPEDEF_(0xC00D1B86L)

//
// MessageId: NS_E_UNSUPPORTED_ENCODER_DEVICE
//
// MessageText:
//
//  It is not possible to open this device.%0
//
#define NS_E_UNSUPPORTED_ENCODER_DEVICE  _HRESULT_TYPEDEF_(0xC00D1B87L)

//
// MessageId: NS_E_UNEXPECTED_DISPLAY_SETTINGS
//
// MessageText:
//
//  It is not possible to start encoding because the display size or color has changed since the current session was defined. Restore the previous settings or create a new session.%0
//
#define NS_E_UNEXPECTED_DISPLAY_SETTINGS _HRESULT_TYPEDEF_(0xC00D1B88L)

//
// MessageId: NS_E_NO_AUDIODATA
//
// MessageText:
//
//  No audio data has been received for several seconds. Check the audio source and restart the encoder.%0
//
#define NS_E_NO_AUDIODATA                _HRESULT_TYPEDEF_(0xC00D1B89L)

//
// MessageId: NS_E_INPUTSOURCE_PROBLEM
//
// MessageText:
//
//  One or all of the specified sources are not working properly. Check that the sources are configured correctly.%0
//
#define NS_E_INPUTSOURCE_PROBLEM         _HRESULT_TYPEDEF_(0xC00D1B8AL)

//
// MessageId: NS_E_WME_VERSION_MISMATCH
//
// MessageText:
//
//  The supplied configuration file is not supported by this version of the encoder.%0
//
#define NS_E_WME_VERSION_MISMATCH        _HRESULT_TYPEDEF_(0xC00D1B8BL)

//
// MessageId: NS_E_NO_REALTIME_PREPROCESS
//
// MessageText:
//
//  It is not possible to use image preprocessing with live encoding.%0
//
#define NS_E_NO_REALTIME_PREPROCESS      _HRESULT_TYPEDEF_(0xC00D1B8CL)

//
// MessageId: NS_E_NO_REPEAT_PREPROCESS
//
// MessageText:
//
//  It is not possible to use two-pass encoding when the source is set to loop.%0
//
#define NS_E_NO_REPEAT_PREPROCESS        _HRESULT_TYPEDEF_(0xC00D1B8DL)

//
// MessageId: NS_E_CANNOT_PAUSE_LIVEBROADCAST
//
// MessageText:
//
//  It is not possible to pause encoding during a broadcast.%0
//
#define NS_E_CANNOT_PAUSE_LIVEBROADCAST  _HRESULT_TYPEDEF_(0xC00D1B8EL)

//
// MessageId: NS_E_DRM_PROFILE_NOT_SET
//
// MessageText:
//
//  A DRM profile has not been set for the current session.%0
//
#define NS_E_DRM_PROFILE_NOT_SET         _HRESULT_TYPEDEF_(0xC00D1B8FL)

//
// MessageId: NS_E_DUPLICATE_DRMPROFILE
//
// MessageText:
//
//  The profile ID is already used by a DRM profile. Specify a different profile ID.%0
//
#define NS_E_DUPLICATE_DRMPROFILE        _HRESULT_TYPEDEF_(0xC00D1B90L)

//
// MessageId: NS_E_INVALID_DEVICE
//
// MessageText:
//
//  The setting of the selected device does not support control for playing back tapes.%0
//
#define NS_E_INVALID_DEVICE              _HRESULT_TYPEDEF_(0xC00D1B91L)

//
// MessageId: NS_E_SPEECHEDL_ON_NON_MIXEDMODE
//
// MessageText:
//
//  You must specify a mixed voice and audio mode in order to use an optimization definition file.%0
//
#define NS_E_SPEECHEDL_ON_NON_MIXEDMODE  _HRESULT_TYPEDEF_(0xC00D1B92L)

//
// MessageId: NS_E_DRM_PASSWORD_TOO_LONG
//
// MessageText:
//
//  The specified password is too long. Type a password with fewer than 8 characters.%0
//
#define NS_E_DRM_PASSWORD_TOO_LONG       _HRESULT_TYPEDEF_(0xC00D1B93L)

//
// MessageId: NS_E_DEVCONTROL_FAILED_SEEK
//
// MessageText:
//
//  It is not possible to seek to the specified mark-in point.%0
//
#define NS_E_DEVCONTROL_FAILED_SEEK      _HRESULT_TYPEDEF_(0xC00D1B94L)

//
// MessageId: NS_E_INTERLACE_REQUIRE_SAMESIZE
//
// MessageText:
//
//  When you choose to maintain the interlacing in your video, the output video size must match the input video size.%0
//
#define NS_E_INTERLACE_REQUIRE_SAMESIZE  _HRESULT_TYPEDEF_(0xC00D1B95L)

//
// MessageId: NS_E_TOO_MANY_DEVICECONTROL
//
// MessageText:
//
//  Only one device control plug-in can control a device.%0
//
#define NS_E_TOO_MANY_DEVICECONTROL      _HRESULT_TYPEDEF_(0xC00D1B96L)

//
// MessageId: NS_E_NO_MULTIPASS_FOR_LIVEDEVICE
//
// MessageText:
//
//  You must also enable storing content to hard disk temporarily in order to use two-pass encoding with the input device.%0
//
#define NS_E_NO_MULTIPASS_FOR_LIVEDEVICE _HRESULT_TYPEDEF_(0xC00D1B97L)

//
// MessageId: NS_E_MISSING_AUDIENCE
//
// MessageText:
//
//  An audience is missing from the output stream configuration.%0
//
#define NS_E_MISSING_AUDIENCE            _HRESULT_TYPEDEF_(0xC00D1B98L)

//
// MessageId: NS_E_AUDIENCE_CONTENTTYPE_MISMATCH
//
// MessageText:
//
//  All audiences in the output tree must have the same content type.%0
//
#define NS_E_AUDIENCE_CONTENTTYPE_MISMATCH _HRESULT_TYPEDEF_(0xC00D1B99L)

//
// MessageId: NS_E_MISSING_SOURCE_INDEX
//
// MessageText:
//
//  A source index is missing from the output stream configuration.%0
//
#define NS_E_MISSING_SOURCE_INDEX        _HRESULT_TYPEDEF_(0xC00D1B9AL)

//
// MessageId: NS_E_NUM_LANGUAGE_MISMATCH
//
// MessageText:
//
//  The same source index in different audiences should have the same number of languages.%0
//
#define NS_E_NUM_LANGUAGE_MISMATCH       _HRESULT_TYPEDEF_(0xC00D1B9BL)

//
// MessageId: NS_E_LANGUAGE_MISMATCH
//
// MessageText:
//
//  The same source index in different audiences should have the same languages.%0
//
#define NS_E_LANGUAGE_MISMATCH           _HRESULT_TYPEDEF_(0xC00D1B9CL)

//
// MessageId: NS_E_VBRMODE_MISMATCH
//
// MessageText:
//
//  The same source index in different audiences should use the same VBR encoding mode.%0
//
#define NS_E_VBRMODE_MISMATCH            _HRESULT_TYPEDEF_(0xC00D1B9DL)

//
// MessageId: NS_E_INVALID_INPUT_AUDIENCE_INDEX
//
// MessageText:
//
//  The bit rate index specified is not valid.%0
//
#define NS_E_INVALID_INPUT_AUDIENCE_INDEX _HRESULT_TYPEDEF_(0xC00D1B9EL)

//
// MessageId: NS_E_INVALID_INPUT_LANGUAGE
//
// MessageText:
//
//  The specified language is not valid.%0
//
#define NS_E_INVALID_INPUT_LANGUAGE      _HRESULT_TYPEDEF_(0xC00D1B9FL)

//
// MessageId: NS_E_INVALID_INPUT_STREAM
//
// MessageText:
//
//  The specified source type is not valid.%0
//
#define NS_E_INVALID_INPUT_STREAM        _HRESULT_TYPEDEF_(0xC00D1BA0L)

//
// MessageId: NS_E_EXPECT_MONO_WAV_INPUT
//
// MessageText:
//
//  The source must be a mono channel .wav file.%0
//
#define NS_E_EXPECT_MONO_WAV_INPUT       _HRESULT_TYPEDEF_(0xC00D1BA1L)

//
// MessageId: NS_E_INPUT_WAVFORMAT_MISMATCH
//
// MessageText:
//
//  All the source .wav files must have the same format.%0
//
#define NS_E_INPUT_WAVFORMAT_MISMATCH    _HRESULT_TYPEDEF_(0xC00D1BA2L)

//
// MessageId: NS_E_RECORDQ_DISK_FULL
//
// MessageText:
//
//  The hard disk being used for temporary storage of content has reached the minimum allowed disk space. Create more space on the hard disk and restart encoding.%0
//
#define NS_E_RECORDQ_DISK_FULL           _HRESULT_TYPEDEF_(0xC00D1BA3L)

//
// MessageId: NS_E_NO_PAL_INVERSE_TELECINE
//
// MessageText:
//
//  It is not possible to apply the inverse telecine feature to PAL content.%0
//
#define NS_E_NO_PAL_INVERSE_TELECINE     _HRESULT_TYPEDEF_(0xC00D1BA4L)

//
// MessageId: NS_E_ACTIVE_SG_DEVICE_DISCONNECTED
//
// MessageText:
//
//  A capture device in the current active source is no longer available.%0
//
#define NS_E_ACTIVE_SG_DEVICE_DISCONNECTED _HRESULT_TYPEDEF_(0xC00D1BA5L)

//
// MessageId: NS_E_ACTIVE_SG_DEVICE_CONTROL_DISCONNECTED
//
// MessageText:
//
//  A device used in the current active source for device control is no longer available.%0
//
#define NS_E_ACTIVE_SG_DEVICE_CONTROL_DISCONNECTED _HRESULT_TYPEDEF_(0xC00D1BA6L)

//
// MessageId: NS_E_NO_FRAMES_SUBMITTED_TO_ANALYZER
//
// MessageText:
//
//  No frames have been submitted to the analyzer for analysis.%0
//
#define NS_E_NO_FRAMES_SUBMITTED_TO_ANALYZER _HRESULT_TYPEDEF_(0xC00D1BA7L)

//
// MessageId: NS_E_INPUT_DOESNOT_SUPPORT_SMPTE
//
// MessageText:
//
//  The source video does not support time codes.%0
//
#define NS_E_INPUT_DOESNOT_SUPPORT_SMPTE _HRESULT_TYPEDEF_(0xC00D1BA8L)

//
// MessageId: NS_E_NO_SMPTE_WITH_MULTIPLE_SOURCEGROUPS
//
// MessageText:
//
//  It is not possible to generate a time code when there are multiple sources in a session.%0
//
#define NS_E_NO_SMPTE_WITH_MULTIPLE_SOURCEGROUPS _HRESULT_TYPEDEF_(0xC00D1BA9L)

//
// MessageId: NS_E_BAD_CONTENTEDL
//
// MessageText:
//
//  The voice codec optimization definition file can not be found or is corrupted.%0
//
#define NS_E_BAD_CONTENTEDL              _HRESULT_TYPEDEF_(0xC00D1BAAL)

//
// MessageId: NS_E_INTERLACEMODE_MISMATCH
//
// MessageText:
//
//  The same source index in different audiences should have the same interlace mode.%0
//
#define NS_E_INTERLACEMODE_MISMATCH      _HRESULT_TYPEDEF_(0xC00D1BABL)

//
// MessageId: NS_E_NONSQUAREPIXELMODE_MISMATCH
//
// MessageText:
//
//  The same source index in different audiences should have the same nonsquare pixel mode.%0
//
#define NS_E_NONSQUAREPIXELMODE_MISMATCH _HRESULT_TYPEDEF_(0xC00D1BACL)

//
// MessageId: NS_E_SMPTEMODE_MISMATCH
//
// MessageText:
//
//  The same source index in different audiences should have the same time code mode.%0
//
#define NS_E_SMPTEMODE_MISMATCH          _HRESULT_TYPEDEF_(0xC00D1BADL)

//
// MessageId: NS_E_END_OF_TAPE
//
// MessageText:
//
//  Either the end of the tape has been reached or there is no tape. Check the device and tape.%0
//
#define NS_E_END_OF_TAPE                 _HRESULT_TYPEDEF_(0xC00D1BAEL)

//
// MessageId: NS_E_NO_MEDIA_IN_AUDIENCE
//
// MessageText:
//
//  No audio or video input has been specified.%0
//
#define NS_E_NO_MEDIA_IN_AUDIENCE        _HRESULT_TYPEDEF_(0xC00D1BAFL)

//
// MessageId: NS_E_NO_AUDIENCES
//
// MessageText:
//
//  The profile must contain a bit rate.%0
//
#define NS_E_NO_AUDIENCES                _HRESULT_TYPEDEF_(0xC00D1BB0L)

//
// MessageId: NS_E_NO_AUDIO_COMPAT
//
// MessageText:
//
//  You must specify at least one audio stream to be compatible with Windows Media Player 7.1.%0
//
#define NS_E_NO_AUDIO_COMPAT             _HRESULT_TYPEDEF_(0xC00D1BB1L)

//
// MessageId: NS_E_INVALID_VBR_COMPAT
//
// MessageText:
//
//  Using a VBR encoding mode is not compatible with Windows Media Player 7.1.%0
//
#define NS_E_INVALID_VBR_COMPAT          _HRESULT_TYPEDEF_(0xC00D1BB2L)

//
// MessageId: NS_E_NO_PROFILE_NAME
//
// MessageText:
//
//  You must specify a profile name.%0
//
#define NS_E_NO_PROFILE_NAME             _HRESULT_TYPEDEF_(0xC00D1BB3L)

//
// MessageId: NS_E_INVALID_VBR_WITH_UNCOMP
//
// MessageText:
//
//  It is not possible to use a VBR encoding mode with uncompressed audio or video.%0
//
#define NS_E_INVALID_VBR_WITH_UNCOMP     _HRESULT_TYPEDEF_(0xC00D1BB4L)

//
// MessageId: NS_E_MULTIPLE_VBR_AUDIENCES
//
// MessageText:
//
//  It is not possible to use MBR encoding with VBR encoding.%0
//
#define NS_E_MULTIPLE_VBR_AUDIENCES      _HRESULT_TYPEDEF_(0xC00D1BB5L)

//
// MessageId: NS_E_UNCOMP_COMP_COMBINATION
//
// MessageText:
//
//  It is not possible to mix uncompressed and compressed content in a session.%0
//
#define NS_E_UNCOMP_COMP_COMBINATION     _HRESULT_TYPEDEF_(0xC00D1BB6L)

//
// MessageId: NS_E_MULTIPLE_AUDIO_CODECS
//
// MessageText:
//
//  All audiences must use the same audio codec.%0
//
#define NS_E_MULTIPLE_AUDIO_CODECS       _HRESULT_TYPEDEF_(0xC00D1BB7L)

//
// MessageId: NS_E_MULTIPLE_AUDIO_FORMATS
//
// MessageText:
//
//  All audiences should use the same audio format to be compatible with Windows Media Player 7.1.%0
//
#define NS_E_MULTIPLE_AUDIO_FORMATS      _HRESULT_TYPEDEF_(0xC00D1BB8L)

//
// MessageId: NS_E_AUDIO_BITRATE_STEPDOWN
//
// MessageText:
//
//  The audio bit rate for an audience with a higher total bit rate must be greater than one with a lower total bit rate.%0
//
#define NS_E_AUDIO_BITRATE_STEPDOWN      _HRESULT_TYPEDEF_(0xC00D1BB9L)

//
// MessageId: NS_E_INVALID_AUDIO_PEAKRATE
//
// MessageText:
//
//  The audio peak bit rate setting is not valid.%0
//
#define NS_E_INVALID_AUDIO_PEAKRATE      _HRESULT_TYPEDEF_(0xC00D1BBAL)

//
// MessageId: NS_E_INVALID_AUDIO_PEAKRATE_2
//
// MessageText:
//
//  The audio peak bit rate setting must be greater than the audio bit rate setting.%0
//
#define NS_E_INVALID_AUDIO_PEAKRATE_2    _HRESULT_TYPEDEF_(0xC00D1BBBL)

//
// MessageId: NS_E_INVALID_AUDIO_BUFFERMAX
//
// MessageText:
//
//  The setting for the maximum buffer size for audio is not valid.%0
//
#define NS_E_INVALID_AUDIO_BUFFERMAX     _HRESULT_TYPEDEF_(0xC00D1BBCL)

//
// MessageId: NS_E_MULTIPLE_VIDEO_CODECS
//
// MessageText:
//
//  All audiences must use the same video codec.%0
//
#define NS_E_MULTIPLE_VIDEO_CODECS       _HRESULT_TYPEDEF_(0xC00D1BBDL)

//
// MessageId: NS_E_MULTIPLE_VIDEO_SIZES
//
// MessageText:
//
//  All audiences should use the same video size to be compatible with Windows Media Player 7.1.%0
//
#define NS_E_MULTIPLE_VIDEO_SIZES        _HRESULT_TYPEDEF_(0xC00D1BBEL)

//
// MessageId: NS_E_INVALID_VIDEO_BITRATE
//
// MessageText:
//
//  The video bit rate setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_BITRATE       _HRESULT_TYPEDEF_(0xC00D1BBFL)

//
// MessageId: NS_E_VIDEO_BITRATE_STEPDOWN
//
// MessageText:
//
//  The video bit rate for an audience with a higher total bit rate must be greater than one with a lower total bit rate.%0
//
#define NS_E_VIDEO_BITRATE_STEPDOWN      _HRESULT_TYPEDEF_(0xC00D1BC0L)

//
// MessageId: NS_E_INVALID_VIDEO_PEAKRATE
//
// MessageText:
//
//  The video peak bit rate setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_PEAKRATE      _HRESULT_TYPEDEF_(0xC00D1BC1L)

//
// MessageId: NS_E_INVALID_VIDEO_PEAKRATE_2
//
// MessageText:
//
//  The video peak bit rate setting must be greater than the video bit rate setting.%0
//
#define NS_E_INVALID_VIDEO_PEAKRATE_2    _HRESULT_TYPEDEF_(0xC00D1BC2L)

//
// MessageId: NS_E_INVALID_VIDEO_WIDTH
//
// MessageText:
//
//  The video width setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_WIDTH         _HRESULT_TYPEDEF_(0xC00D1BC3L)

//
// MessageId: NS_E_INVALID_VIDEO_HEIGHT
//
// MessageText:
//
//  The video height setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_HEIGHT        _HRESULT_TYPEDEF_(0xC00D1BC4L)

//
// MessageId: NS_E_INVALID_VIDEO_FPS
//
// MessageText:
//
//  The video frame rate setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_FPS           _HRESULT_TYPEDEF_(0xC00D1BC5L)

//
// MessageId: NS_E_INVALID_VIDEO_KEYFRAME
//
// MessageText:
//
//  The video key frame setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_KEYFRAME      _HRESULT_TYPEDEF_(0xC00D1BC6L)

//
// MessageId: NS_E_INVALID_VIDEO_IQUALITY
//
// MessageText:
//
//  The video image quality setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_IQUALITY      _HRESULT_TYPEDEF_(0xC00D1BC7L)

//
// MessageId: NS_E_INVALID_VIDEO_CQUALITY
//
// MessageText:
//
//  The video codec quality setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_CQUALITY      _HRESULT_TYPEDEF_(0xC00D1BC8L)

//
// MessageId: NS_E_INVALID_VIDEO_BUFFER
//
// MessageText:
//
//  The video buffer setting is not valid.%0
//
#define NS_E_INVALID_VIDEO_BUFFER        _HRESULT_TYPEDEF_(0xC00D1BC9L)

//
// MessageId: NS_E_INVALID_VIDEO_BUFFERMAX
//
// MessageText:
//
//  The setting for the maximum buffer size for video is not valid.%0
//
#define NS_E_INVALID_VIDEO_BUFFERMAX     _HRESULT_TYPEDEF_(0xC00D1BCAL)

//
// MessageId: NS_E_INVALID_VIDEO_BUFFERMAX_2
//
// MessageText:
//
//  The value of the video maximum buffer size setting must be greater than the video buffer size setting.%0
//
#define NS_E_INVALID_VIDEO_BUFFERMAX_2   _HRESULT_TYPEDEF_(0xC00D1BCBL)

//
// MessageId: NS_E_INVALID_VIDEO_WIDTH_ALIGN
//
// MessageText:
//
//  The alignment of the video width is not valid.%0
//
#define NS_E_INVALID_VIDEO_WIDTH_ALIGN   _HRESULT_TYPEDEF_(0xC00D1BCCL)

//
// MessageId: NS_E_INVALID_VIDEO_HEIGHT_ALIGN
//
// MessageText:
//
//  The alignment of the video height is not valid.%0
//
#define NS_E_INVALID_VIDEO_HEIGHT_ALIGN  _HRESULT_TYPEDEF_(0xC00D1BCDL)

//
// MessageId: NS_E_MULTIPLE_SCRIPT_BITRATES
//
// MessageText:
//
//  All bit rates must have the same script bit rate.%0
//
#define NS_E_MULTIPLE_SCRIPT_BITRATES    _HRESULT_TYPEDEF_(0xC00D1BCEL)

//
// MessageId: NS_E_INVALID_SCRIPT_BITRATE
//
// MessageText:
//
//  The script bit rate specified is not valid.%0
//
#define NS_E_INVALID_SCRIPT_BITRATE      _HRESULT_TYPEDEF_(0xC00D1BCFL)

//
// MessageId: NS_E_MULTIPLE_FILE_BITRATES
//
// MessageText:
//
//  All bit rates must have the same file transfer bit rate.%0
//
#define NS_E_MULTIPLE_FILE_BITRATES      _HRESULT_TYPEDEF_(0xC00D1BD0L)

//
// MessageId: NS_E_INVALID_FILE_BITRATE
//
// MessageText:
//
//  The file transfer bit rate is not valid.%0
//
#define NS_E_INVALID_FILE_BITRATE        _HRESULT_TYPEDEF_(0xC00D1BD1L)

//
// MessageId: NS_E_SAME_AS_INPUT_COMBINATION
//
// MessageText:
//
//  All audiences in a profile should either be same as input or have video width and height specified.%0
//
#define NS_E_SAME_AS_INPUT_COMBINATION   _HRESULT_TYPEDEF_(0xC00D1BD2L)

//
// MessageId: NS_E_SOURCE_CANNOT_LOOP
//
// MessageText:
//
//  This source type does not support looping.%0
//
#define NS_E_SOURCE_CANNOT_LOOP          _HRESULT_TYPEDEF_(0xC00D1BD3L)

//
// MessageId: NS_E_INVALID_FOLDDOWN_COEFFICIENTS
//
// MessageText:
//
//  The fold-down value needs to be between -144 and 0.%0
//
#define NS_E_INVALID_FOLDDOWN_COEFFICIENTS _HRESULT_TYPEDEF_(0xC00D1BD4L)

//
// MessageId: NS_E_DRMPROFILE_NOTFOUND
//
// MessageText:
//
//  The specified DRM profile does not exist in the system.%0
//
#define NS_E_DRMPROFILE_NOTFOUND         _HRESULT_TYPEDEF_(0xC00D1BD5L)

//
// MessageId: NS_E_INVALID_TIMECODE
//
// MessageText:
//
//  The specified time code is not valid.%0
//
#define NS_E_INVALID_TIMECODE            _HRESULT_TYPEDEF_(0xC00D1BD6L)

//
// MessageId: NS_E_NO_AUDIO_TIMECOMPRESSION
//
// MessageText:
//
//  It is not possible to apply time compression to a video-only session.%0
//
#define NS_E_NO_AUDIO_TIMECOMPRESSION    _HRESULT_TYPEDEF_(0xC00D1BD7L)

//
// MessageId: NS_E_NO_TWOPASS_TIMECOMPRESSION
//
// MessageText:
//
//  It is not possible to apply time compression to a session that is using two-pass encoding.%0
//
#define NS_E_NO_TWOPASS_TIMECOMPRESSION  _HRESULT_TYPEDEF_(0xC00D1BD8L)

//
// MessageId: NS_E_TIMECODE_REQUIRES_VIDEOSTREAM
//
// MessageText:
//
//  It is not possible to generate a time code for an audio-only session.%0
//
#define NS_E_TIMECODE_REQUIRES_VIDEOSTREAM _HRESULT_TYPEDEF_(0xC00D1BD9L)

//
// MessageId: NS_E_NO_MBR_WITH_TIMECODE
//
// MessageText:
//
//  It is not possible to generate a time code when you are encoding content at multiple bit rates.%0
//
#define NS_E_NO_MBR_WITH_TIMECODE        _HRESULT_TYPEDEF_(0xC00D1BDAL)

//
// MessageId: NS_E_INVALID_INTERLACEMODE
//
// MessageText:
//
//  The video codec selected does not support maintaining interlacing in video.%0
//
#define NS_E_INVALID_INTERLACEMODE       _HRESULT_TYPEDEF_(0xC00D1BDBL)

//
// MessageId: NS_E_INVALID_INTERLACE_COMPAT
//
// MessageText:
//
//  Maintaining interlacing in video is not compatible with Windows Media Player 7.1.%0
//
#define NS_E_INVALID_INTERLACE_COMPAT    _HRESULT_TYPEDEF_(0xC00D1BDCL)

//
// MessageId: NS_E_INVALID_NONSQUAREPIXEL_COMPAT
//
// MessageText:
//
//  Allowing nonsquare pixel output is not compatible with Windows Media Player 7.1.%0
//
#define NS_E_INVALID_NONSQUAREPIXEL_COMPAT _HRESULT_TYPEDEF_(0xC00D1BDDL)

//
// MessageId: NS_E_INVALID_SOURCE_WITH_DEVICE_CONTROL
//
// MessageText:
//
//  Only capture devices can be used with device control.%0
//
#define NS_E_INVALID_SOURCE_WITH_DEVICE_CONTROL _HRESULT_TYPEDEF_(0xC00D1BDEL)

//
// MessageId: NS_E_CANNOT_GENERATE_BROADCAST_INFO_FOR_QUALITYVBR
//
// MessageText:
//
//  It is not possible to generate the stream format file if you are using quality-based VBR encoding for the audio or video stream. Instead use the Windows Media file generated after encoding to create the announcement file.%0
//
#define NS_E_CANNOT_GENERATE_BROADCAST_INFO_FOR_QUALITYVBR _HRESULT_TYPEDEF_(0xC00D1BDFL)

//
// MessageId: NS_E_EXCEED_MAX_DRM_PROFILE_LIMIT
//
// MessageText:
//
//  It is not possible to create a DRM profile because the maximum number of profiles has been reached. You must delete some DRM profiles before creating new ones.%0
//
#define NS_E_EXCEED_MAX_DRM_PROFILE_LIMIT _HRESULT_TYPEDEF_(0xC00D1BE0L)

//
// MessageId: NS_E_DEVICECONTROL_UNSTABLE
//
// MessageText:
//
//  The device is in an unstable state. Check that the device is functioning properly and a tape is in place.
//
#define NS_E_DEVICECONTROL_UNSTABLE      _HRESULT_TYPEDEF_(0xC00D1BE1L)

//
// MessageId: NS_E_INVALID_PIXEL_ASPECT_RATIO
//
// MessageText:
//
//  The pixel aspect ratio value must be between 1 and 255.
//
#define NS_E_INVALID_PIXEL_ASPECT_RATIO  _HRESULT_TYPEDEF_(0xC00D1BE2L)

//
// MessageId: NS_E_AUDIENCE__LANGUAGE_CONTENTTYPE_MISMATCH
//
// MessageText:
//
//  All streams with different languages in the same audience must have same properties.%0
//
#define NS_E_AUDIENCE__LANGUAGE_CONTENTTYPE_MISMATCH _HRESULT_TYPEDEF_(0xC00D1BE3L)

//
// MessageId: NS_E_INVALID_PROFILE_CONTENTTYPE
//
// MessageText:
//
//  The profile must contain at least one audio or video stream.%0
//
#define NS_E_INVALID_PROFILE_CONTENTTYPE _HRESULT_TYPEDEF_(0xC00D1BE4L)

//
// MessageId: NS_E_TRANSFORM_PLUGIN_NOT_FOUND
//
// MessageText:
//
//  The transform plug-in could not be found.%0
//
#define NS_E_TRANSFORM_PLUGIN_NOT_FOUND  _HRESULT_TYPEDEF_(0xC00D1BE5L)

//
// MessageId: NS_E_TRANSFORM_PLUGIN_INVALID
//
// MessageText:
//
//  The transform plug-in is not valid. It may be damaged or you may not have the required permissions to access the plug-in.%0
//
#define NS_E_TRANSFORM_PLUGIN_INVALID    _HRESULT_TYPEDEF_(0xC00D1BE6L)

//
// MessageId: NS_E_EDL_REQUIRED_FOR_DEVICE_MULTIPASS
//
// MessageText:
//
//  To use two-pass encoding, you must enable device control and setup an edit decision list (EDL) that has at least one entry.%0
//
#define NS_E_EDL_REQUIRED_FOR_DEVICE_MULTIPASS _HRESULT_TYPEDEF_(0xC00D1BE7L)

//
// MessageId: NS_E_INVALID_VIDEO_WIDTH_FOR_INTERLACED_ENCODING
//
// MessageText:
//
//  When you choose to maintain the interlacing in your video, the output video size must be a multiple of 4.%0
//
#define NS_E_INVALID_VIDEO_WIDTH_FOR_INTERLACED_ENCODING _HRESULT_TYPEDEF_(0xC00D1BE8L)


/////////////////////////////////////////////////////////////////////////
//
// DRM Specific Errors
//
// IdRange = 10000..10999
/////////////////////////////////////////////////////////////////////////
//
// MessageId: NS_E_DRM_INVALID_APPLICATION
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact product support for this application.%0
//
#define NS_E_DRM_INVALID_APPLICATION     _HRESULT_TYPEDEF_(0xC00D2711L)

//
// MessageId: NS_E_DRM_LICENSE_STORE_ERROR
//
// MessageText:
//
//  License storage is not working. Contact Microsoft product support.%0
//
#define NS_E_DRM_LICENSE_STORE_ERROR     _HRESULT_TYPEDEF_(0xC00D2712L)

//
// MessageId: NS_E_DRM_SECURE_STORE_ERROR
//
// MessageText:
//
//  Secure storage is not working. Contact Microsoft product support.%0
//
#define NS_E_DRM_SECURE_STORE_ERROR      _HRESULT_TYPEDEF_(0xC00D2713L)

//
// MessageId: NS_E_DRM_LICENSE_STORE_SAVE_ERROR
//
// MessageText:
//
//  License acquisition did not work. Acquire a new license or contact the content provider for further assistance.%0
//
#define NS_E_DRM_LICENSE_STORE_SAVE_ERROR _HRESULT_TYPEDEF_(0xC00D2714L)

//
// MessageId: NS_E_DRM_SECURE_STORE_UNLOCK_ERROR
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0
//
#define NS_E_DRM_SECURE_STORE_UNLOCK_ERROR _HRESULT_TYPEDEF_(0xC00D2715L)

//
// MessageId: NS_E_DRM_INVALID_CONTENT
//
// MessageText:
//
//  The media file is corrupted. Contact the content provider to get a new file.%0
//
#define NS_E_DRM_INVALID_CONTENT         _HRESULT_TYPEDEF_(0xC00D2716L)

//
// MessageId: NS_E_DRM_UNABLE_TO_OPEN_LICENSE
//
// MessageText:
//
//  The license is corrupted. Acquire a new license.%0
//
#define NS_E_DRM_UNABLE_TO_OPEN_LICENSE  _HRESULT_TYPEDEF_(0xC00D2717L)

//
// MessageId: NS_E_DRM_INVALID_LICENSE
//
// MessageText:
//
//  The license is corrupted or invalid. Acquire a new license%0
//
#define NS_E_DRM_INVALID_LICENSE         _HRESULT_TYPEDEF_(0xC00D2718L)

//
// MessageId: NS_E_DRM_INVALID_MACHINE
//
// MessageText:
//
//  Licenses cannot be copied from one computer to another. Use License Management to transfer licenses, or get a new license for the media file.%0
//
#define NS_E_DRM_INVALID_MACHINE         _HRESULT_TYPEDEF_(0xC00D2719L)

//
// MessageId: NS_E_DRM_ENUM_LICENSE_FAILED
//
// MessageText:
//
//  License storage is not working. Contact Microsoft product support.%0
//
#define NS_E_DRM_ENUM_LICENSE_FAILED     _HRESULT_TYPEDEF_(0xC00D271BL)

//
// MessageId: NS_E_DRM_INVALID_LICENSE_REQUEST
//
// MessageText:
//
//  The media file is corrupted. Contact the content provider to get a new file.%0
//
#define NS_E_DRM_INVALID_LICENSE_REQUEST _HRESULT_TYPEDEF_(0xC00D271CL)

//
// MessageId: NS_E_DRM_UNABLE_TO_INITIALIZE
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0
//
#define NS_E_DRM_UNABLE_TO_INITIALIZE    _HRESULT_TYPEDEF_(0xC00D271DL)

//
// MessageId: NS_E_DRM_UNABLE_TO_ACQUIRE_LICENSE
//
// MessageText:
//
//  The license could not be acquired. Try again later.%0
//
#define NS_E_DRM_UNABLE_TO_ACQUIRE_LICENSE _HRESULT_TYPEDEF_(0xC00D271EL)

//
// MessageId: NS_E_DRM_INVALID_LICENSE_ACQUIRED
//
// MessageText:
//
//  License acquisition did not work. Acquire a new license or contact the content provider for further assistance.%0
//
#define NS_E_DRM_INVALID_LICENSE_ACQUIRED _HRESULT_TYPEDEF_(0xC00D271FL)

//
// MessageId: NS_E_DRM_NO_RIGHTS
//
// MessageText:
//
//  The requested operation cannot be performed on this file.%0
//
#define NS_E_DRM_NO_RIGHTS               _HRESULT_TYPEDEF_(0xC00D2720L)

//
// MessageId: NS_E_DRM_KEY_ERROR
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_KEY_ERROR               _HRESULT_TYPEDEF_(0xC00D2721L)

//
// MessageId: NS_E_DRM_ENCRYPT_ERROR
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0
//
#define NS_E_DRM_ENCRYPT_ERROR           _HRESULT_TYPEDEF_(0xC00D2722L)

//
// MessageId: NS_E_DRM_DECRYPT_ERROR
//
// MessageText:
//
//  The media file is corrupted. Contact the content provider to get a new file.%0
//
#define NS_E_DRM_DECRYPT_ERROR           _HRESULT_TYPEDEF_(0xC00D2723L)

//
// MessageId: NS_E_DRM_LICENSE_INVALID_XML
//
// MessageText:
//
//  The license is corrupted. Acquire a new license.%0
//
#define NS_E_DRM_LICENSE_INVALID_XML     _HRESULT_TYPEDEF_(0xC00D2725L)

//
// MessageId: NS_S_DRM_LICENSE_ACQUIRED
//
// MessageText:
//
//  Status message: The license was acquired.%0
//
#define NS_S_DRM_LICENSE_ACQUIRED        _HRESULT_TYPEDEF_(0x000D2726L)

//
// MessageId: NS_S_DRM_INDIVIDUALIZED
//
// MessageText:
//
//  Status message: The security upgrade has been completed.%0
//
#define NS_S_DRM_INDIVIDUALIZED          _HRESULT_TYPEDEF_(0x000D2727L)

//
// MessageId: NS_E_DRM_NEEDS_INDIVIDUALIZATION
//
// MessageText:
//
//  A security upgrade is required to perform the operation on this media file.%0
//
#define NS_E_DRM_NEEDS_INDIVIDUALIZATION _HRESULT_TYPEDEF_(0xC00D2728L)

//
// MessageId: NS_E_DRM_ALREADY_INDIVIDUALIZED
//
// MessageText:
//
//  You already have the latest security components. No upgrade is necessary at this time.%0
//
#define NS_E_DRM_ALREADY_INDIVIDUALIZED  _HRESULT_TYPEDEF_(0xC00D2729L)

//
// MessageId: NS_E_DRM_ACTION_NOT_QUERIED
//
// MessageText:
//
//  The application cannot perform this action. Contact product support for this application.%0
//
#define NS_E_DRM_ACTION_NOT_QUERIED      _HRESULT_TYPEDEF_(0xC00D272AL)

//
// MessageId: NS_E_DRM_ACQUIRING_LICENSE
//
// MessageText:
//
//  You cannot begin a new license acquisition process until the current one has been completed.%0
//
#define NS_E_DRM_ACQUIRING_LICENSE       _HRESULT_TYPEDEF_(0xC00D272BL)

//
// MessageId: NS_E_DRM_INDIVIDUALIZING
//
// MessageText:
//
//  You cannot begin a new security upgrade until the current one has been completed.%0
//
#define NS_E_DRM_INDIVIDUALIZING         _HRESULT_TYPEDEF_(0xC00D272CL)

//
// MessageId: NS_E_DRM_PARAMETERS_MISMATCHED
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_PARAMETERS_MISMATCHED   _HRESULT_TYPEDEF_(0xC00D272FL)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_LICENSE_OBJECT
//
// MessageText:
//
//  A license cannot be created for this media file. Reinstall the application.%0
//
#define NS_E_DRM_UNABLE_TO_CREATE_LICENSE_OBJECT _HRESULT_TYPEDEF_(0xC00D2730L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_INDI_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_INDI_OBJECT _HRESULT_TYPEDEF_(0xC00D2731L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_ENCRYPT_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_ENCRYPT_OBJECT _HRESULT_TYPEDEF_(0xC00D2732L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_DECRYPT_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_DECRYPT_OBJECT _HRESULT_TYPEDEF_(0xC00D2733L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_PROPERTIES_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_PROPERTIES_OBJECT _HRESULT_TYPEDEF_(0xC00D2734L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_BACKUP_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_BACKUP_OBJECT _HRESULT_TYPEDEF_(0xC00D2735L)

//
// MessageId: NS_E_DRM_INDIVIDUALIZE_ERROR
//
// MessageText:
//
//  The security upgrade failed. Try again later.%0
//
#define NS_E_DRM_INDIVIDUALIZE_ERROR     _HRESULT_TYPEDEF_(0xC00D2736L)

//
// MessageId: NS_E_DRM_LICENSE_OPEN_ERROR
//
// MessageText:
//
//  License storage is not working. Contact Microsoft product support.%0
//
#define NS_E_DRM_LICENSE_OPEN_ERROR      _HRESULT_TYPEDEF_(0xC00D2737L)

//
// MessageId: NS_E_DRM_LICENSE_CLOSE_ERROR
//
// MessageText:
//
//  License storage is not working. Contact Microsoft product support.%0
//
#define NS_E_DRM_LICENSE_CLOSE_ERROR     _HRESULT_TYPEDEF_(0xC00D2738L)

//
// MessageId: NS_E_DRM_GET_LICENSE_ERROR
//
// MessageText:
//
//  License storage is not working. Contact Microsoft product support.%0
//
#define NS_E_DRM_GET_LICENSE_ERROR       _HRESULT_TYPEDEF_(0xC00D2739L)

//
// MessageId: NS_E_DRM_QUERY_ERROR
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_QUERY_ERROR             _HRESULT_TYPEDEF_(0xC00D273AL)

//
// MessageId: NS_E_DRM_REPORT_ERROR
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact product support for this application.%0
//
#define NS_E_DRM_REPORT_ERROR            _HRESULT_TYPEDEF_(0xC00D273BL)

//
// MessageId: NS_E_DRM_GET_LICENSESTRING_ERROR
//
// MessageText:
//
//  License storage is not working. Contact Microsoft product support.%0
//
#define NS_E_DRM_GET_LICENSESTRING_ERROR _HRESULT_TYPEDEF_(0xC00D273CL)

//
// MessageId: NS_E_DRM_GET_CONTENTSTRING_ERROR
//
// MessageText:
//
//  The media file is corrupted. Contact the content provider to get a new file.%0
//
#define NS_E_DRM_GET_CONTENTSTRING_ERROR _HRESULT_TYPEDEF_(0xC00D273DL)

//
// MessageId: NS_E_DRM_MONITOR_ERROR
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Try again later.%0
//
#define NS_E_DRM_MONITOR_ERROR           _HRESULT_TYPEDEF_(0xC00D273EL)

//
// MessageId: NS_E_DRM_UNABLE_TO_SET_PARAMETER
//
// MessageText:
//
//  The application has made an invalid call to the Digital Rights Management component. Contact product support for this application.%0
//
#define NS_E_DRM_UNABLE_TO_SET_PARAMETER _HRESULT_TYPEDEF_(0xC00D273FL)

//
// MessageId: NS_E_DRM_INVALID_APPDATA
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_INVALID_APPDATA         _HRESULT_TYPEDEF_(0xC00D2740L)

//
// MessageId: NS_E_DRM_INVALID_APPDATA_VERSION
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact product support for this application.%0.
//
#define NS_E_DRM_INVALID_APPDATA_VERSION _HRESULT_TYPEDEF_(0xC00D2741L)

//
// MessageId: NS_E_DRM_BACKUP_EXISTS
//
// MessageText:
//
//  Licenses are already backed up in this location.%0
//
#define NS_E_DRM_BACKUP_EXISTS           _HRESULT_TYPEDEF_(0xC00D2742L)

//
// MessageId: NS_E_DRM_BACKUP_CORRUPT
//
// MessageText:
//
//  One or more backed-up licenses are missing or corrupt.%0
//
#define NS_E_DRM_BACKUP_CORRUPT          _HRESULT_TYPEDEF_(0xC00D2743L)

//
// MessageId: NS_E_DRM_BACKUPRESTORE_BUSY
//
// MessageText:
//
//  You cannot begin a new backup process until the current process has been completed.%0
//
#define NS_E_DRM_BACKUPRESTORE_BUSY      _HRESULT_TYPEDEF_(0xC00D2744L)

//
// MessageId: NS_S_DRM_MONITOR_CANCELLED
//
// MessageText:
//
//  Status message: License monitoring has been cancelled.%0
//
#define NS_S_DRM_MONITOR_CANCELLED       _HRESULT_TYPEDEF_(0x000D2746L)

//
// MessageId: NS_S_DRM_ACQUIRE_CANCELLED
//
// MessageText:
//
//  Status message: License acquisition has been cancelled.%0
//
#define NS_S_DRM_ACQUIRE_CANCELLED       _HRESULT_TYPEDEF_(0x000D2747L)

//
// MessageId: NS_E_DRM_LICENSE_UNUSABLE
//
// MessageText:
//
//  The license is invalid. Contact the content provider for further assistance.%0
//
#define NS_E_DRM_LICENSE_UNUSABLE        _HRESULT_TYPEDEF_(0xC00D2748L)

//
// MessageId: NS_E_DRM_INVALID_PROPERTY
//
// MessageText:
//
//  A required property was not set by the application. Contact product support for this application.%0.
//
#define NS_E_DRM_INVALID_PROPERTY        _HRESULT_TYPEDEF_(0xC00D2749L)

//
// MessageId: NS_E_DRM_SECURE_STORE_NOT_FOUND
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component of this application. Try to acquire a license again.%0
//
#define NS_E_DRM_SECURE_STORE_NOT_FOUND  _HRESULT_TYPEDEF_(0xC00D274AL)

//
// MessageId: NS_E_DRM_CACHED_CONTENT_ERROR
//
// MessageText:
//
//  A license cannot be found for this media file. Use License Management to transfer a license for this file from the original computer, or acquire a new license.%0
//
#define NS_E_DRM_CACHED_CONTENT_ERROR    _HRESULT_TYPEDEF_(0xC00D274BL)

//
// MessageId: NS_E_DRM_INDIVIDUALIZATION_INCOMPLETE
//
// MessageText:
//
//  A problem occurred during the security upgrade. Try again later.%0
//
#define NS_E_DRM_INDIVIDUALIZATION_INCOMPLETE _HRESULT_TYPEDEF_(0xC00D274CL)

//
// MessageId: NS_E_DRM_DRIVER_AUTH_FAILURE
//
// MessageText:
//
//  Certified driver components are required to play this media file. Contact Windows Update to see whether updated drivers are available for your hardware.%0
//
#define NS_E_DRM_DRIVER_AUTH_FAILURE     _HRESULT_TYPEDEF_(0xC00D274DL)

//
// MessageId: NS_E_DRM_NEED_UPGRADE_MSSAP
//
// MessageText:
//
//  One or more of the Secure Audio Path components were not found or an entry point in those components was not found.%0
//
#define NS_E_DRM_NEED_UPGRADE_MSSAP      _HRESULT_TYPEDEF_(0xC00D274EL)

//
// MessageId: NS_E_DRM_REOPEN_CONTENT
//
// MessageText:
//
//  Status message: Reopen the file.%0
//
#define NS_E_DRM_REOPEN_CONTENT          _HRESULT_TYPEDEF_(0xC00D274FL)

//
// MessageId: NS_E_DRM_DRIVER_DIGIOUT_FAILURE
//
// MessageText:
//
//  Certain driver functionality is required to play this media file. Contact Windows Update to see whether updated drivers are available for your hardware.%0
//
#define NS_E_DRM_DRIVER_DIGIOUT_FAILURE  _HRESULT_TYPEDEF_(0xC00D2750L)

//
// MessageId: NS_E_DRM_INVALID_SECURESTORE_PASSWORD
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_INVALID_SECURESTORE_PASSWORD _HRESULT_TYPEDEF_(0xC00D2751L)

//
// MessageId: NS_E_DRM_APPCERT_REVOKED
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_APPCERT_REVOKED         _HRESULT_TYPEDEF_(0xC00D2752L)

//
// MessageId: NS_E_DRM_RESTORE_FRAUD
//
// MessageText:
//
//  You cannot restore your license(s).%0
//
#define NS_E_DRM_RESTORE_FRAUD           _HRESULT_TYPEDEF_(0xC00D2753L)

//
// MessageId: NS_E_DRM_HARDWARE_INCONSISTENT
//
// MessageText:
//
//  The licenses for your media files are corrupted. Contact Microsoft product support.%0
//
#define NS_E_DRM_HARDWARE_INCONSISTENT   _HRESULT_TYPEDEF_(0xC00D2754L)

//
// MessageId: NS_E_DRM_SDMI_TRIGGER
//
// MessageText:
//
//  To transfer this media file, you must upgrade the application.%0
//
#define NS_E_DRM_SDMI_TRIGGER            _HRESULT_TYPEDEF_(0xC00D2755L)

//
// MessageId: NS_E_DRM_SDMI_NOMORECOPIES
//
// MessageText:
//
//  You cannot make any more copies of this media file.%0
//
#define NS_E_DRM_SDMI_NOMORECOPIES       _HRESULT_TYPEDEF_(0xC00D2756L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_HEADER_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_HEADER_OBJECT _HRESULT_TYPEDEF_(0xC00D2757L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_KEYS_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_KEYS_OBJECT _HRESULT_TYPEDEF_(0xC00D2758L)

;// This error is never shown to user but needed for program logic.
//
// MessageId: NS_E_DRM_LICENSE_NOTACQUIRED
//
// MessageText:
//
//  Unable to obtain license.%0
//
#define NS_E_DRM_LICENSE_NOTACQUIRED     _HRESULT_TYPEDEF_(0xC00D2759L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_CODING_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_CODING_OBJECT _HRESULT_TYPEDEF_(0xC00D275AL)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_STATE_DATA_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_STATE_DATA_OBJECT _HRESULT_TYPEDEF_(0xC00D275BL)

//
// MessageId: NS_E_DRM_BUFFER_TOO_SMALL
//
// MessageText:
//
//  The buffer supplied is not sufficient.%0.
//
#define NS_E_DRM_BUFFER_TOO_SMALL        _HRESULT_TYPEDEF_(0xC00D275CL)

//
// MessageId: NS_E_DRM_UNSUPPORTED_PROPERTY
//
// MessageText:
//
//  The property requested is not supported.%0.
//
#define NS_E_DRM_UNSUPPORTED_PROPERTY    _HRESULT_TYPEDEF_(0xC00D275DL)

//
// MessageId: NS_E_DRM_ERROR_BAD_NET_RESP
//
// MessageText:
//
//  The specified server cannot perform the requested operation.%0.
//
#define NS_E_DRM_ERROR_BAD_NET_RESP      _HRESULT_TYPEDEF_(0xC00D275EL)

//
// MessageId: NS_E_DRM_STORE_NOTALLSTORED
//
// MessageText:
//
//  Some of the licenses could not be stored.%0.
//
#define NS_E_DRM_STORE_NOTALLSTORED      _HRESULT_TYPEDEF_(0xC00D275FL)

//
// MessageId: NS_E_DRM_SECURITY_COMPONENT_SIGNATURE_INVALID
//
// MessageText:
//
//  The Digital Rights Management security upgrade component could not be validated. Contact Microsoft product support.%0
//
#define NS_E_DRM_SECURITY_COMPONENT_SIGNATURE_INVALID _HRESULT_TYPEDEF_(0xC00D2760L)

//
// MessageId: NS_E_DRM_INVALID_DATA
//
// MessageText:
//
//  Invalid or corrupt data was encountered.%0
//
#define NS_E_DRM_INVALID_DATA            _HRESULT_TYPEDEF_(0xC00D2761L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CONTACT_SERVER
//
// MessageText:
//
//  Unable to contact the server for the requested operation.%0
//
#define NS_E_DRM_UNABLE_TO_CONTACT_SERVER _HRESULT_TYPEDEF_(0xC00D2762L)

//
// MessageId: NS_E_DRM_UNABLE_TO_CREATE_AUTHENTICATION_OBJECT
//
// MessageText:
//
//  A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
//
#define NS_E_DRM_UNABLE_TO_CREATE_AUTHENTICATION_OBJECT _HRESULT_TYPEDEF_(0xC00D2763L)

//
// MessageId: NS_E_DRM_NOT_CONFIGURED
//
// MessageText:
//
//  Not all of the necessary properties for DRM have been set.%0
//
#define NS_E_DRM_NOT_CONFIGURED          _HRESULT_TYPEDEF_(0xC00D2764L)

//
// MessageId: NS_E_DRM_DEVICE_ACTIVATION_CANCELED
//
// MessageText:
//
//  The portable device does not have the security required to copy protected files to it. To obtain the additional security, try to copy the file to your portable device again. When a message appears, click OK.%0
//
#define NS_E_DRM_DEVICE_ACTIVATION_CANCELED _HRESULT_TYPEDEF_(0xC00D2765L)


//
// License Reasons Section
// Error Codes why a license is not usable. Reserve 10200..10300 for this purpose.
// 10200..10249 is for license reported reasons. 10250..10300 is for client detected reasons.
//

//
// MessageId: NS_E_DRM_LICENSE_EXPIRED
//
// MessageText:
//
//  The license for this file has expired and is no longer valid. Contact your content provider for further assistance.%0
//
#define NS_E_DRM_LICENSE_EXPIRED         _HRESULT_TYPEDEF_(0xC00D27D8L)

//
// MessageId: NS_E_DRM_LICENSE_NOTENABLED
//
// MessageText:
//
//  The license for this file is not valid yet, but will be at a future date.%0
//
#define NS_E_DRM_LICENSE_NOTENABLED      _HRESULT_TYPEDEF_(0xC00D27D9L)

//
// MessageId: NS_E_DRM_LICENSE_APPSECLOW
//
// MessageText:
//
//  The license for this file requires a higher level of security than the player you are currently using has. Try using a different player or download a newer version of your current player.%0
//
#define NS_E_DRM_LICENSE_APPSECLOW       _HRESULT_TYPEDEF_(0xC00D27DAL)

//
// MessageId: NS_E_DRM_STORE_NEEDINDI
//
// MessageText:
//
//  The license cannot be stored as it requires security upgrade of Digital Rights Management component.%0.
//
#define NS_E_DRM_STORE_NEEDINDI          _HRESULT_TYPEDEF_(0xC00D27DBL)

//
// MessageId: NS_E_DRM_STORE_NOTALLOWED
//
// MessageText:
//
//  Your machine does not meet the requirements for storing the license.%0.
//
#define NS_E_DRM_STORE_NOTALLOWED        _HRESULT_TYPEDEF_(0xC00D27DCL)

//
// MessageId: NS_E_DRM_LICENSE_APP_NOTALLOWED
//
// MessageText:
//
//  The license for this file requires an upgraded version of your player or a different player.%0.
//
#define NS_E_DRM_LICENSE_APP_NOTALLOWED  _HRESULT_TYPEDEF_(0xC00D27DDL)

//
// MessageId: NS_S_DRM_NEEDS_INDIVIDUALIZATION
//
// MessageText:
//
//  A security upgrade is required to perform the operation on this media file.%0
//
#define NS_S_DRM_NEEDS_INDIVIDUALIZATION _HRESULT_TYPEDEF_(0x000D27DEL)

//
// MessageId: NS_E_DRM_LICENSE_CERT_EXPIRED
//
// MessageText:
//
//  The license server's certificate expired. Make sure your system clock is set correctly. Contact your content provider for further assistance. %0.
//
#define NS_E_DRM_LICENSE_CERT_EXPIRED    _HRESULT_TYPEDEF_(0xC00D27DFL)

//
// MessageId: NS_E_DRM_LICENSE_SECLOW
//
// MessageText:
//
//  The license for this file requires a higher level of security than the player you are currently using has. Try using a different player or download a newer version of your current player.%0
//
#define NS_E_DRM_LICENSE_SECLOW          _HRESULT_TYPEDEF_(0xC00D27E0L)

//
// MessageId: NS_E_DRM_LICENSE_CONTENT_REVOKED
//
// MessageText:
//
//  The content owner for the license you just acquired is no longer supporting their content. Contact the content owner for a newer version of the content.%0
//
#define NS_E_DRM_LICENSE_CONTENT_REVOKED _HRESULT_TYPEDEF_(0xC00D27E1L)

//
// MessageId: NS_E_DRM_LICENSE_NOSAP
//
// MessageText:
//
//  The license for this file requires a feature that is not supported in your current player or operating system. You can try with newer version of your current player or contact your content provider for further assistance.%0
//
#define NS_E_DRM_LICENSE_NOSAP           _HRESULT_TYPEDEF_(0xC00D280AL)

//
// MessageId: NS_E_DRM_LICENSE_NOSVP
//
// MessageText:
//
//  The license for this file requires a feature that is not supported in your current player or operating system. You can try with newer version of your current player or contact your content provider for further assistance.%0
//
#define NS_E_DRM_LICENSE_NOSVP           _HRESULT_TYPEDEF_(0xC00D280BL)

//
// MessageId: NS_E_DRM_LICENSE_NOWDM
//
// MessageText:
//
//  The license for this file requires Windows Driver Model (WDM) audio drivers. Contact your sound card manufacturer for further assistance.%0
//
#define NS_E_DRM_LICENSE_NOWDM           _HRESULT_TYPEDEF_(0xC00D280CL)

//
// MessageId: NS_E_DRM_LICENSE_NOTRUSTEDCODEC
//
// MessageText:
//
//  The license for this file requires a higher level of security than the player you are currently using has. Try using a different player or download a newer version of your current player.%0
//
#define NS_E_DRM_LICENSE_NOTRUSTEDCODEC  _HRESULT_TYPEDEF_(0xC00D280DL)


//
// End of License Reasons Section
//

//
// MessageId: NS_E_DRM_NEEDS_UPGRADE_TEMPFILE
//
// MessageText:
//
//  An updated version of your media player is required to play the selected content.%0
//
#define NS_E_DRM_NEEDS_UPGRADE_TEMPFILE  _HRESULT_TYPEDEF_(0xC00D283DL)

//
// MessageId: NS_E_DRM_NEED_UPGRADE_PD
//
// MessageText:
//
//  A new version of the Digital Rights Management component is required. Contact product support for this application to get the latest version.%0
//
#define NS_E_DRM_NEED_UPGRADE_PD         _HRESULT_TYPEDEF_(0xC00D283EL)

//
// MessageId: NS_E_DRM_SIGNATURE_FAILURE
//
// MessageText:
//
//  Failed to either create or verify the content header.%0
//
#define NS_E_DRM_SIGNATURE_FAILURE       _HRESULT_TYPEDEF_(0xC00D283FL)

//
// MessageId: NS_E_DRM_LICENSE_SERVER_INFO_MISSING
//
// MessageText:
//
//  Could not read the necessary information from the system registry.%0
//
#define NS_E_DRM_LICENSE_SERVER_INFO_MISSING _HRESULT_TYPEDEF_(0xC00D2840L)

//
// MessageId: NS_E_DRM_BUSY
//
// MessageText:
//
//  The DRM subsystem is currently locked by another application or user.  Try again later.%0
//
#define NS_E_DRM_BUSY                    _HRESULT_TYPEDEF_(0xC00D2841L)

//
// MessageId: NS_E_DRM_PD_TOO_MANY_DEVICES
//
// MessageText:
//
//  There are too many target devices registered on the portable media.%0
//
#define NS_E_DRM_PD_TOO_MANY_DEVICES     _HRESULT_TYPEDEF_(0xC00D2842L)

//
// MessageId: NS_E_DRM_INDIV_FRAUD
//
// MessageText:
//
//  The security upgrade cannot be completed because the allowed number of daily upgrades has been exceeded. Try again tomorrow.%0
//
#define NS_E_DRM_INDIV_FRAUD             _HRESULT_TYPEDEF_(0xC00D2843L)

//
// MessageId: NS_E_DRM_INDIV_NO_CABS
//
// MessageText:
//
//  The security upgrade cannot be completed because the server is unable to perform the operation. Try again later.%0
//
#define NS_E_DRM_INDIV_NO_CABS           _HRESULT_TYPEDEF_(0xC00D2844L)

//
// MessageId: NS_E_DRM_INDIV_SERVICE_UNAVAILABLE
//
// MessageText:
//
//  The security upgrade cannot be performed because the server is not available. Try again later.%0
//
#define NS_E_DRM_INDIV_SERVICE_UNAVAILABLE _HRESULT_TYPEDEF_(0xC00D2845L)

//
// MessageId: NS_E_DRM_RESTORE_SERVICE_UNAVAILABLE
//
// MessageText:
//
//  Windows Media Player cannot restore your licenses because the server is not available. Try again later.%0
//
#define NS_E_DRM_RESTORE_SERVICE_UNAVAILABLE _HRESULT_TYPEDEF_(0xC00D2846L)



/////////////////////////////////////////////////////////////////////////
//
// Windows Media Setup Specific Errors
//
// IdRange = 11000..11999
/////////////////////////////////////////////////////////////////////////
//
// MessageId: NS_S_REBOOT_RECOMMENDED
//
// MessageText:
//
//  The requested operation is successful.  Some cleanup will not be complete until the system is rebooted.%0
//
#define NS_S_REBOOT_RECOMMENDED          _HRESULT_TYPEDEF_(0x000D2AF8L)

//
// MessageId: NS_S_REBOOT_REQUIRED
//
// MessageText:
//
//  The requested operation is successful.  The system will not function correctly until the system is rebooted.%0
//
#define NS_S_REBOOT_REQUIRED             _HRESULT_TYPEDEF_(0x000D2AF9L)

//
// MessageId: NS_E_REBOOT_RECOMMENDED
//
// MessageText:
//
//  The requested operation failed.  Some cleanup will not be complete until the system is rebooted.%0
//
#define NS_E_REBOOT_RECOMMENDED          _HRESULT_TYPEDEF_(0xC00D2AFAL)

//
// MessageId: NS_E_REBOOT_REQUIRED
//
// MessageText:
//
//  The requested operation failed.  The system will not function correctly until the system is rebooted.%0
//
#define NS_E_REBOOT_REQUIRED             _HRESULT_TYPEDEF_(0xC00D2AFBL)


/////////////////////////////////////////////////////////////////////////
//
// Windows Media Networking Errors
//
// IdRange = 12000..12999
/////////////////////////////////////////////////////////////////////////
//
// MessageId: NS_E_UNKNOWN_PROTOCOL
//
// MessageText:
//
//  The specified protocol is not supported.%0
//
#define NS_E_UNKNOWN_PROTOCOL            _HRESULT_TYPEDEF_(0xC00D2EE0L)

//
// MessageId: NS_E_REDIRECT_TO_PROXY
//
// MessageText:
//
//  The client is redirected to a proxy server.%0
//
#define NS_E_REDIRECT_TO_PROXY           _HRESULT_TYPEDEF_(0xC00D2EE1L)

//
// MessageId: NS_E_INTERNAL_SERVER_ERROR
//
// MessageText:
//
//  The server encountered an unexpected condition which prevented it from fulfilling the request.%0
//
#define NS_E_INTERNAL_SERVER_ERROR       _HRESULT_TYPEDEF_(0xC00D2EE2L)

//
// MessageId: NS_E_BAD_REQUEST
//
// MessageText:
//
//  The request could not be understood by the server.%0
//
#define NS_E_BAD_REQUEST                 _HRESULT_TYPEDEF_(0xC00D2EE3L)

//
// MessageId: NS_E_ERROR_FROM_PROXY
//
// MessageText:
//
//  The proxy experienced an error while attempting to contact the media server.%0
//
#define NS_E_ERROR_FROM_PROXY            _HRESULT_TYPEDEF_(0xC00D2EE4L)

//
// MessageId: NS_E_PROXY_TIMEOUT
//
// MessageText:
//
//  The proxy did not receive a timely response while attempting to contact the media server.%0
//
#define NS_E_PROXY_TIMEOUT               _HRESULT_TYPEDEF_(0xC00D2EE5L)

//
// MessageId: NS_E_SERVER_UNAVAILABLE
//
// MessageText:
//
//  The server is currently unable to handle the request due to a temporary overloading or maintenance of the server.%0
//
#define NS_E_SERVER_UNAVAILABLE          _HRESULT_TYPEDEF_(0xC00D2EE6L)

//
// MessageId: NS_E_REFUSED_BY_SERVER
//
// MessageText:
//
//  The server is refusing to fulfill the requested operation.%0
//
#define NS_E_REFUSED_BY_SERVER           _HRESULT_TYPEDEF_(0xC00D2EE7L)

//
// MessageId: NS_E_INCOMPATIBLE_SERVER
//
// MessageText:
//
//  The server is not a compatible streaming media server.%0
//
#define NS_E_INCOMPATIBLE_SERVER         _HRESULT_TYPEDEF_(0xC00D2EE8L)

//
// MessageId: NS_E_MULTICAST_DISABLED
//
// MessageText:
//
//  The content cannot be streamed because the Multicast protocol has been disabled.%0
//
#define NS_E_MULTICAST_DISABLED          _HRESULT_TYPEDEF_(0xC00D2EE9L)

//
// MessageId: NS_E_INVALID_REDIRECT
//
// MessageText:
//
//  The server redirected the player to an invalid location.%0
//
#define NS_E_INVALID_REDIRECT            _HRESULT_TYPEDEF_(0xC00D2EEAL)

//
// MessageId: NS_E_ALL_PROTOCOLS_DISABLED
//
// MessageText:
//
//  The content cannot be streamed because all protocols have been disabled.%0
//
#define NS_E_ALL_PROTOCOLS_DISABLED      _HRESULT_TYPEDEF_(0xC00D2EEBL)

//
// MessageId: NS_E_MSBD_NO_LONGER_SUPPORTED
//
// MessageText:
//
//  The MSBD protocol is no longer supported. Please use HTTP to connect to the Windows Media stream.%0
//
#define NS_E_MSBD_NO_LONGER_SUPPORTED    _HRESULT_TYPEDEF_(0xC00D2EECL)

//
// MessageId: NS_E_PROXY_NOT_FOUND
//
// MessageText:
//
//  The proxy server could not be located. Please check your proxy server configuration.%0
//
#define NS_E_PROXY_NOT_FOUND             _HRESULT_TYPEDEF_(0xC00D2EEDL)

//
// MessageId: NS_E_CANNOT_CONNECT_TO_PROXY
//
// MessageText:
//
//  Unable to establish a connection to the proxy server. Please check your proxy server configuration.%0
//
#define NS_E_CANNOT_CONNECT_TO_PROXY     _HRESULT_TYPEDEF_(0xC00D2EEEL)

//
// MessageId: NS_E_SERVER_DNS_TIMEOUT
//
// MessageText:
//
//  Unable to locate the media server. The operation timed out.%0
//
#define NS_E_SERVER_DNS_TIMEOUT          _HRESULT_TYPEDEF_(0xC00D2EEFL)

//
// MessageId: NS_E_PROXY_DNS_TIMEOUT
//
// MessageText:
//
//  Unable to locate the proxy server. The operation timed out.%0
//
#define NS_E_PROXY_DNS_TIMEOUT           _HRESULT_TYPEDEF_(0xC00D2EF0L)

//
// MessageId: NS_E_CLOSED_ON_SUSPEND
//
// MessageText:
//
//  Media closed because Windows was shut down.%0
//
#define NS_E_CLOSED_ON_SUSPEND           _HRESULT_TYPEDEF_(0xC00D2EF1L)

//
// MessageId: NS_E_CANNOT_READ_PLAYLIST_FROM_MEDIASERVER
//
// MessageText:
//
//  Unable to read the contents of a playlist file from a media server.%0
//
#define NS_E_CANNOT_READ_PLAYLIST_FROM_MEDIASERVER _HRESULT_TYPEDEF_(0xC00D2EF2L)

//
// MessageId: NS_E_SESSION_NOT_FOUND
//
// MessageText:
//
//  Session not found.%0
//
#define NS_E_SESSION_NOT_FOUND           _HRESULT_TYPEDEF_(0xC00D2EF3L)

//
// MessageId: NS_E_REQUIRE_STREAMING_CLIENT
//
// MessageText:
//
//  Content requires a streaming media client.%0
//
#define NS_E_REQUIRE_STREAMING_CLIENT    _HRESULT_TYPEDEF_(0xC00D2EF4L)

//
// MessageId: NS_E_PLAYLIST_ENTRY_HAS_CHANGED
//
// MessageText:
//
//  A command applies to a previous playlist entry.%0
//
#define NS_E_PLAYLIST_ENTRY_HAS_CHANGED  _HRESULT_TYPEDEF_(0xC00D2EF5L)

//
// MessageId: NS_E_PROXY_ACCESSDENIED
//
// MessageText:
//
//  The proxy server is denying access.  The username and/or password might be incorrect.%0
//
#define NS_E_PROXY_ACCESSDENIED          _HRESULT_TYPEDEF_(0xC00D2EF6L)

//
// MessageId: NS_E_PROXY_SOURCE_ACCESSDENIED
//
// MessageText:
//
//  The proxy could not provide valid authentication credentials to the media server.%0
//
#define NS_E_PROXY_SOURCE_ACCESSDENIED   _HRESULT_TYPEDEF_(0xC00D2EF7L)

//
// MessageId: NS_E_NETWORK_SINK_WRITE
//
// MessageText:
//
//  The network sink failed to write data to the network.%0
//
#define NS_E_NETWORK_SINK_WRITE          _HRESULT_TYPEDEF_(0xC00D2EF8L)

//
// MessageId: NS_E_FIREWALL
//
// MessageText:
//
//  Packets are not being received from the server. The packets might be blocked by a filtering device, such as a network firewall.%0
//
#define NS_E_FIREWALL                    _HRESULT_TYPEDEF_(0xC00D2EF9L)

//
// MessageId: NS_E_MMS_NOT_SUPPORTED
//
// MessageText:
//
//  The MMS protocol is not supported. Please use HTTP or RTSP to connect to the Windows Media stream.%0
//
#define NS_E_MMS_NOT_SUPPORTED           _HRESULT_TYPEDEF_(0xC00D2EFAL)

//
// MessageId: NS_E_SERVER_ACCESSDENIED
//
// MessageText:
//
//  The Windows Media server is denying access.  The username and/or password might be incorrect.%0
//
#define NS_E_SERVER_ACCESSDENIED         _HRESULT_TYPEDEF_(0xC00D2EFBL)

//
// MessageId: NS_E_RESOURCE_GONE
//
// MessageText:
//
//  The Publishing Point or file on the Windows Media Server is no longer available.%0
//
#define NS_E_RESOURCE_GONE               _HRESULT_TYPEDEF_(0xC00D2EFCL)

//
// MessageId: NS_E_NO_EXISTING_PACKETIZER
//
// MessageText:
//
//  There is no existing packetizer plugin for a stream.%0
//
#define NS_E_NO_EXISTING_PACKETIZER      _HRESULT_TYPEDEF_(0xC00D2EFDL)

//
// MessageId: NS_E_BAD_SYNTAX_IN_SERVER_RESPONSE
//
// MessageText:
//
//  The response from the media server could not be understood. This might be caused by an incompatible proxy server or media server.%0
//
#define NS_E_BAD_SYNTAX_IN_SERVER_RESPONSE _HRESULT_TYPEDEF_(0xC00D2EFEL)

//
// MessageId: NS_I_RECONNECTED
//
// MessageText:
//
//  The client is reconnected.%0
//
#define NS_I_RECONNECTED                 _HRESULT_TYPEDEF_(0x400D2EFFL)

//
// MessageId: NS_E_RESET_SOCKET_CONNECTION
//
// MessageText:
//
//  The Windows Media Server reset the network connection.%0
//
#define NS_E_RESET_SOCKET_CONNECTION     _HRESULT_TYPEDEF_(0xC00D2F00L)

//
// MessageId: NS_I_NOLOG_STOP
//
// MessageText:
//
//  Forcing a switch to a pending header on start.%0
//
#define NS_I_NOLOG_STOP                  _HRESULT_TYPEDEF_(0x400D2F01L)

//
// MessageId: NS_E_TOO_MANY_HOPS
//
// MessageText:
//
//  The request could not reach the media server (too many hops).%0
//
#define NS_E_TOO_MANY_HOPS               _HRESULT_TYPEDEF_(0xC00D2F02L)

//
// MessageId: NS_I_EXISTING_PACKETIZER
//
// MessageText:
//
//  There is already an existing packetizer plugin for the stream.%0
//
#define NS_I_EXISTING_PACKETIZER         _HRESULT_TYPEDEF_(0x400D2F03L)

//
// MessageId: NS_I_MANUAL_PROXY
//
// MessageText:
//
//  The proxy setting is manual.%0
//
#define NS_I_MANUAL_PROXY                _HRESULT_TYPEDEF_(0x400D2F04L)

//
// MessageId: NS_E_TOO_MUCH_DATA_FROM_SERVER
//
// MessageText:
//
//  The server is sending too much data. The connection has been terminated.%0
//
#define NS_E_TOO_MUCH_DATA_FROM_SERVER   _HRESULT_TYPEDEF_(0xC00D2F05L)

//
// MessageId: NS_E_CONNECT_TIMEOUT
//
// MessageText:
//
//  It was not possible to establish a connection to the media server in a timely manner. The media server may be down for maintenance, or it may be necessary to use a proxy server to access this media server.%0
//
#define NS_E_CONNECT_TIMEOUT             _HRESULT_TYPEDEF_(0xC00D2F06L)

//
// MessageId: NS_E_PROXY_CONNECT_TIMEOUT
//
// MessageText:
//
//  It was not possible to establish a connection to the proxy server in a timely manner. Please check your proxy server configuration.%0
//
#define NS_E_PROXY_CONNECT_TIMEOUT       _HRESULT_TYPEDEF_(0xC00D2F07L)

//
// MessageId: NS_E_SESSION_INVALID
//
// MessageText:
//
//  Session not found.%0
//
#define NS_E_SESSION_INVALID             _HRESULT_TYPEDEF_(0xC00D2F08L)

//
// MessageId: NS_S_EOSRECEDING
//
// MessageText:
//
//  EOS hit during rewinding.%0
//
#define NS_S_EOSRECEDING                 _HRESULT_TYPEDEF_(0x000D2F09L)

//
// MessageId: NS_E_PACKETSINK_UNKNOWN_FEC_STREAM
//
// MessageText:
//
//  Unknown packet sink stream.%0
//
#define NS_E_PACKETSINK_UNKNOWN_FEC_STREAM _HRESULT_TYPEDEF_(0xC00D2F0AL)

//
// MessageId: NS_E_PUSH_CANNOTCONNECT
//
// MessageText:
//
//  Unable to establish a connection to the server. Ensure Windows Media Services is started and the HTTP Server control protocol is properly enabled.%0
//
#define NS_E_PUSH_CANNOTCONNECT          _HRESULT_TYPEDEF_(0xC00D2F0BL)

//
// MessageId: NS_E_INCOMPATIBLE_PUSH_SERVER
//
// MessageText:
//
//  The Server service that received the HTTP push request is not a compatible version of Windows Media Services (WMS).  This error may indicate the push request was received by IIS instead of WMS.  Ensure WMS is started and has the HTTP Server control protocol properly enabled and try again.%0
//
#define NS_E_INCOMPATIBLE_PUSH_SERVER    _HRESULT_TYPEDEF_(0xC00D2F0CL)


/////////////////////////////////////////////////////////////////////////
//
// Windows Media Client Media Services
//
// IdRange = 13000..13999 (0x32C8-0x36AF)
/////////////////////////////////////////////////////////////////////////
//
// MessageId: NS_E_END_OF_PLAYLIST
//
// MessageText:
//
//  The playlist has reached its end.%0
//
#define NS_E_END_OF_PLAYLIST             _HRESULT_TYPEDEF_(0xC00D32C8L)

//
// MessageId: NS_E_USE_FILE_SOURCE
//
// MessageText:
//
//  Use file source.%0
//
#define NS_E_USE_FILE_SOURCE             _HRESULT_TYPEDEF_(0xC00D32C9L)

//
// MessageId: NS_E_PROPERTY_NOT_FOUND
//
// MessageText:
//
//  The property was not found.%0
//
#define NS_E_PROPERTY_NOT_FOUND          _HRESULT_TYPEDEF_(0xC00D32CAL)

//
// MessageId: NS_E_PROPERTY_READ_ONLY
//
// MessageText:
//
//  The property is read only.%0
//
#define NS_E_PROPERTY_READ_ONLY          _HRESULT_TYPEDEF_(0xC00D32CCL)

//
// MessageId: NS_E_TABLE_KEY_NOT_FOUND
//
// MessageText:
//
//  The table key was not found.%0
//
#define NS_E_TABLE_KEY_NOT_FOUND         _HRESULT_TYPEDEF_(0xC00D32CDL)

//
// MessageId: NS_E_INVALID_QUERY_OPERATOR
//
// MessageText:
//
//  Invalid query operator.%0
//
#define NS_E_INVALID_QUERY_OPERATOR      _HRESULT_TYPEDEF_(0xC00D32CFL)

//
// MessageId: NS_E_INVALID_QUERY_PROPERTY
//
// MessageText:
//
//  Invalid query property.%0
//
#define NS_E_INVALID_QUERY_PROPERTY      _HRESULT_TYPEDEF_(0xC00D32D0L)

//
// MessageId: NS_E_PROPERTY_NOT_SUPPORTED
//
// MessageText:
//
//  The property is not supported.%0
//
#define NS_E_PROPERTY_NOT_SUPPORTED      _HRESULT_TYPEDEF_(0xC00D32D2L)

//
// MessageId: NS_E_SCHEMA_CLASSIFY_FAILURE
//
// MessageText:
//
//  Schema classification failure.%0
//
#define NS_E_SCHEMA_CLASSIFY_FAILURE     _HRESULT_TYPEDEF_(0xC00D32D4L)

//
// MessageId: NS_E_METADATA_FORMAT_NOT_SUPPORTED
//
// MessageText:
//
//  The metadata format is not supported.%0
//
#define NS_E_METADATA_FORMAT_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC00D32D5L)

//
// MessageId: NS_E_METADATA_NO_EDITING_CAPABILITY
//
// MessageText:
//
//  Cannot edit the metadata.%0
//
#define NS_E_METADATA_NO_EDITING_CAPABILITY _HRESULT_TYPEDEF_(0xC00D32D6L)

//
// MessageId: NS_E_METADATA_CANNOT_SET_LOCALE
//
// MessageText:
//
//  Cannot set the locale id.%0
//
#define NS_E_METADATA_CANNOT_SET_LOCALE  _HRESULT_TYPEDEF_(0xC00D32D7L)

//
// MessageId: NS_E_METADATA_LANGUAGE_NOT_SUPORTED
//
// MessageText:
//
//  The language is not supported in the format.%0
//
#define NS_E_METADATA_LANGUAGE_NOT_SUPORTED _HRESULT_TYPEDEF_(0xC00D32D8L)

//
// MessageId: NS_E_METADATA_NO_RFC1766_NAME_FOR_LOCALE
//
// MessageText:
//
//  There is no RFC1766 name translation for the supplied locale id.%0
//
#define NS_E_METADATA_NO_RFC1766_NAME_FOR_LOCALE _HRESULT_TYPEDEF_(0xC00D32D9L)

//
// MessageId: NS_E_METADATA_NOT_AVAILABLE
//
// MessageText:
//
//  The metadata (or metadata item) is not available.%0
//
#define NS_E_METADATA_NOT_AVAILABLE      _HRESULT_TYPEDEF_(0xC00D32DAL)

//
// MessageId: NS_E_METADATA_CACHE_DATA_NOT_AVAILABLE
//
// MessageText:
//
//  The cached metadata (or metadata item) is not available.%0
//
#define NS_E_METADATA_CACHE_DATA_NOT_AVAILABLE _HRESULT_TYPEDEF_(0xC00D32DBL)

//
// MessageId: NS_E_METADATA_INVALID_DOCUMENT_TYPE
//
// MessageText:
//
//  The metadata document is invalid.%0
//
#define NS_E_METADATA_INVALID_DOCUMENT_TYPE _HRESULT_TYPEDEF_(0xC00D32DCL)

//
// MessageId: NS_E_METADATA_IDENTIFIER_NOT_AVAILABLE
//
// MessageText:
//
//  The metadata content identifier is not available.%0
//
#define NS_E_METADATA_IDENTIFIER_NOT_AVAILABLE _HRESULT_TYPEDEF_(0xC00D32DDL)

//
// MessageId: NS_E_METADATA_CANNOT_RETRIEVE_FROM_OFFLINE_CACHE
//
// MessageText:
//
//  Cannot retrieve metadata from the offline metadata cache.%0
//
#define NS_E_METADATA_CANNOT_RETRIEVE_FROM_OFFLINE_CACHE _HRESULT_TYPEDEF_(0xC00D32DEL)


#endif // _NSERROR_H

