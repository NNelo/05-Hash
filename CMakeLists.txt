cmake_minimum_required(VERSION 3.2)
project(05_Hash)

set(CMAKE_CXX_STANDARD 14)

# Agrego todos los test.
add_subdirectory(test)

set(SOURCE_FILES_01 Ej-01/main.cpp HashMap/HashMap.h HashMap/HashEntry.h)
add_executable(Ej-01 ${SOURCE_FILES_01})

set(SOURCE_FILES_02 Ej-02/main.cpp Ej-02/OpenHashMap.h Ej-02/Lista.h)
add_executable(Ej-02 ${SOURCE_FILES_02})

set(SOURCE_FILES_03 Ej-03/main.cpp Ej-03/ReHashMap.h)
add_executable(Ej-03 ${SOURCE_FILES_03})
