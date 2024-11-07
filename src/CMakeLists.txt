
# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

project(yurOTS)

set(CMAKE_CXX_STANDARD 11)

# Adicione os diretórios onde os cabeçalhos estão localizados
include_directories(include)

# Adicione suas fontes aqui
set(SOURCES
    src/actions.cpp
    src/ban.cpp
    src/baseevents.cpp
    src/bed.cpp
    src/behaviourdatabase.cpp
    # Adicione o Player.cpp se existir
)

add_executable(${PROJECT_NAME} ${SOURCES})
