cmake_minimum_required(VERSION 2.6)
project(MapEditor)

add_executable(MapEditor editorMain.cpp MapEditor.cpp Map.cpp Cursor.cpp)

target_link_libraries(MapEditor -lallegro -lallegro_primitives)

install(TARGETS MapEditor RUNTIME DESTINATION bin)
