//
//  AchievementItem.h
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#ifndef SF_FORWARD_HPP
#define SF_FORWARD_HPP

namespace boost {
template <class T>
class shared_ptr;
} // namespace boost

namespace sf {
class IBridge;
class Bridge;
class IEventDispatcher;
class ILogger;
class ILogManager;
class IRequest;
class IRequestHandler;
class IListener;
class IRoomHelper;
class IRoomManager;
class RoomManager;
class RoomHelper;

template <class... Args>
class AsyncManager;

class IDataSyncer;
class IDataResolver;
class IDataTransfer;
class IDataFetcher;
class IDataPusher;
class IData;
class IProperty;
    
enum class ConnectionState;
    
class LoginFlow;
class LogoutFlow;
class ILoginInfo;
class IConnection;
class IConnectionManager;

class ExponentialBackoff;
class RandomHelper;

template <class T>
class BiMap;

class HandshakeListener;
class SocketErrorListener;
class ConnectionListener;
class ConnectionLostListener;
class ConnectionRetryListener;
class ConnectionResumeListener;
class LoginListener;
class LoginErrorListener;
class LogoutListener;
class PingPongListener;
class RoomAddListener;
class RoomRemoveListener;
class RoomCreationErrorListener;
class RoomJoinListener;
class RoomJoinErrorListener;
class UserEnterRoomListener;
class UserExitRoomListener;
class SetUserVariablesListener;
class SetRoomVariablesListener;
class ExtensionResponseListener;
} // namespace sf

namespace Sfs2X {
class SmartFox;

namespace Core {
class IDispatchable;
} // namespace Core

namespace Entities {
class User;
class Room;

namespace Data {
class ISFSObject;
class ISFSArray;
} // namespace Data

namespace Variables {
class UserVariable;
class RoomVariable;
} // namespace Variables
} // namespace Entities

namespace Requests {
class IRequest;
} // namespace Requests

namespace Utils {
class ByteArray;
} // namespace Utils
} // namespace Sfs2X

#endif /* SF_FORWARD_HPP */
