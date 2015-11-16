cmake_minimum_required(VERSION 2.6)
project(MapEditor)

add_executable(MapEditor editorMain.cpp MapEditor.cpp Map.cpp CMap.cpp Cursor.cpp Data.cpp)

target_link_libraries(MapEditor -lallegro -lallegro_primitives)

install(TARGETS MapEditor RUNTIME DESTINATION bin)



project(Server)

add_executable(Server mainServer.cpp Map.cpp Server.cpp Connection.cpp SCharacter.cpp Data.cpp)

target_link_libraries(Server -lenet  -pthread)

SET_TARGET_PROPERTIES(Server PROPERTIES COMPILE_FLAGS "-std=c++11")

install(TARGETS Server RUNTIME DESTINATION bin)



project(Client)

add_executable(Client mainClient.cpp CMap.cpp Map.cpp Client.cpp Connection.cpp CCharacter.cpp Data.cpp)

target_link_libraries(Client -lallegro -lallegro_primitives -lenet)

SET_TARGET_PROPERTIES(Server PROPERTIES COMPILE_FLAGS "-std=c++11")

install(TARGETS Client RUNTIME DESTINATION bin)