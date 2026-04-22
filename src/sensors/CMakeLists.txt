cmake_minimum_required(VERSION 3.16)

add_library(sensors INTERFACE)

# Usamos CMAKE_CURRENT_SOURCE_DIR para que tome la ruta exacta de esta carpeta
target_include_directories(sensors INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})