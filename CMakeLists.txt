cmake_minimum_required(VERSION 2.6)
project(MapEditor)

add_executable(MapEditor editorMain.cpp MapEditor.cpp Map.cpp CMap.cpp Cursor.cpp)

target_link_libraries(MapEditor -lallegro -lallegro_primitives)

install(TARGETS MapEditor RUNTIME DESTINATION bin)

project(Server)

add_executable(Server mainServer.cpp Map.cpp Server.cpp Connection.cpp SCharacter.cpp)

target_link_libraries(Server -lenet)

SET_TARGET_PROPERTIES(Server PROPERTIES COMPILE_FLAGS "-std=c++11")

install(TARGETS Server RUNTIME DESTINATION bin)