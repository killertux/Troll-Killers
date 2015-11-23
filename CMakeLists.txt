cmake_minimum_required(VERSION 2.6)
project(MapEditor)

add_executable(MapEditor editorMain.cpp MapEditor.cpp Map.cpp CMap.cpp Cursor.cpp)

target_link_libraries(MapEditor -lallegro -lallegro_primitives)

install(TARGETS MapEditor RUNTIME DESTINATION bin)



project(Server)

add_executable(Server mainServer.cpp Map.cpp Server.cpp Connection.cpp SCharacter.cpp SMap.cpp Configuration.cpp)

target_link_libraries(Server -lenet  -pthread -lboost_system -lboost_thread)


install(TARGETS Server RUNTIME DESTINATION bin)



project(Client)

add_executable(Client mainClient.cpp CMap.cpp Map.cpp Client.cpp Configuration.cpp Connection.cpp CCharacter.cpp Weapons.cpp Rifle.cpp Pistol.cpp Projectile.cpp CProjectile.cpp Menu.cpp MenuManager.cpp)

target_link_libraries(Client -lallegro -lallegro_primitives -lallegro_image -lallegro_audio -lallegro_acodec -lenet -lm)

SET_TARGET_PROPERTIES(Server PROPERTIES COMPILE_FLAGS "-std=c++11")

install(TARGETS Client RUNTIME DESTINATION bin)