cmake_minimum_required(VERSION 3.21)
project(Antrenament)

set(CMAKE_CXX_STANDARD 14)

add_executable(Antrenament main.cpp ListaParagrafe.h ListaParagrafe.cpp Procesator.h Procesator.cpp ProcesatorNumaraCuvinte.h ProcesatorNumaraPropozitii.h ProcesatorNumaraCuvinte.cpp ProcesatorNumaraPropozitii.cpp)
