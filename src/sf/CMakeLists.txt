cmake_minimum_required(VERSION 3.1)

project(smartfox)

set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../cocos2d)

include_directories(
    #${CMAKE_CURRENT_SOURCE_DIR}/../../../boost/include
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    #${COCOS2DX_ROOT_PATH}/external/openssl/include/android
)

set(LIB_SRC
    connection/ConnectionManager.cpp
    connection/GuardedConnection.cpp
    connection/LoginFlow.cpp
    connection/LogoutFlow.cpp
    connection/ServerConnection.cpp
    core/Bridge.cpp
    core/EventDispatcher.cpp
    core/IRequest.cpp
    core/Logger.cpp
    core/LogManager.cpp
    core/RequestHandler.cpp
    data/Data.cpp
    data/DataFetcher.cpp
    data/DataPusher.cpp
    data/DataResolver.cpp
    data/DataSyncer.cpp
    data/Property.cpp
    data/SFGoldObserver.cpp
    data/SFRubyObserver.cpp
    listeners/ConnectionListener.cpp
    listeners/ConnectionLostListener.cpp
    listeners/ConnectionResumeListener.cpp
    listeners/ConnectionRetryListener.cpp
    listeners/ExtensionResponseListener.cpp
    listeners/HandshakeListener.cpp
    listeners/LoginErrorListener.cpp
    listeners/LoginListener.cpp
    listeners/LogoutListener.cpp
    listeners/PingPongListener.cpp
    listeners/RoomAddListener.cpp
    listeners/RoomCreationErrorListener.cpp
    listeners/RoomJoinErrorListener.cpp
    listeners/RoomJoinListener.cpp
    listeners/RoomRemoveListener.cpp
    listeners/SetRoomVariablesListener.cpp
    listeners/SetUserVariablesListener.cpp
    listeners/SocketErrorListener.cpp
    listeners/UserEnterRoomListener.cpp
    listeners/UserExitRoomListener.cpp
    requests/DataRequest.cpp
    requests/KeepAliveRequest.cpp
    requests/RemoveUserRequest.cpp
    requests/SetGoldRequest.cpp
    requests/SetRubyRequest.cpp
    requests/UpdateDataRequest.cpp
    utils/ExponentialBackoff.cpp
    utils/ExponentialBackoffOptions.cpp
    utils/RandomHelper.cpp
)

set(LIB_HEADERS
    connection/ConnectionManager.hpp
    connection/ConnectionState.hpp
    connection/GuardedConnection.hpp
    connection/IConnection.hpp
    connection/IConnectionManager.hpp
    connection/ILoginInfo.hpp
    connection/LoginFlow.hpp
    connection/LogoutFlow.hpp
    connection/ServerConnection.hpp
    core/Bridge.hpp
    core/EventDispatcher.hpp
    core/IBridge.hpp
    core/IEventDispatcher.hpp
    core/IListener.hpp
    core/ILogger.hpp
    core/ILogManager.hpp
    core/IRequest.hpp
    core/IRequestHandler.hpp
    core/Logger.hpp
    core/LogManager.hpp
    core/RequestHandler.hpp
    data/Data.hpp
    data/DataFetcher.hpp
    data/DataPusher.hpp
    data/DataResolver.hpp
    data/DataSyncer.hpp
    data/IData.hpp
    data/IDataResolver.hpp
    data/IDataTransfer.hpp
    data/IProperty.hpp
    data/Property.hpp
    data/SFGoldObserver.hpp
    data/SFRubyObserver.hpp
    Forward.hpp
    listeners/ConnectionListener.hpp
    listeners/ConnectionLostListener.hpp
    listeners/ConnectionResumeListener.hpp
    listeners/ConnectionRetryListener.hpp
    listeners/ExtensionResponseListener.hpp
    listeners/HandshakeListener.hpp
    listeners/LoginErrorListener.hpp
    listeners/LoginListener.hpp
    listeners/LogoutListener.hpp
    listeners/PingPongListener.hpp
    listeners/RoomAddListener.hpp
    listeners/RoomCreationErrorListener.hpp
    listeners/RoomJoinErrorListener.hpp
    listeners/RoomJoinListener.hpp
    listeners/RoomRemoveListener.hpp
    listeners/SetRoomVariablesListener.hpp
    listeners/SetUserVariablesListener.hpp
    listeners/SocketErrorListener.hpp
    listeners/UserEnterRoomListener.hpp
    listeners/UserExitRoomListener.hpp
    Macro.hpp
    requests/DataRequest.hpp
    requests/KeepAliveRequest.hpp
    requests/RemoveUserRequest.hpp
    requests/SetGoldRequest.hpp
    requests/SetRubyRequest.hpp
    requests/UpdateDataRequest.hpp
    utils/AsyncManager.hpp
    utils/BiMap.hpp
    utils/ExponentialBackoff.hpp
    utils/ExponentialBackoffOptions.hpp
    utils/RandomHelper.hpp
)

add_library(${PROJECT_NAME} STATIC ${LIB_SRC} ${LIB_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC
.
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)