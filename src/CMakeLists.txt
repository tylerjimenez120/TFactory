# 1. Primero incluimos la subcarpeta de sensores
# Como ya estamos dentro de 'src', la ruta es solo 'sensors'
add_subdirectory(sensors)

# 2. Definimos el ejecutable principal
add_executable(cxx_app main.cpp)

# 3. Vinculamos las librerías
target_link_libraries(cxx_app 
    PRIVATE 
    sensors
    # config  <-- Solo si aún conservas el Singleton, si no, bórralo
)