cmake_minimum_required(VERSION 3.0)

project(wxCalc)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

add_executable(wxCalc src/MyApp.h src/MyApp.cpp src/Calc.h src/Calc.cpp)
target_link_libraries(wxCalc ${wxWidgets_LIBRARIES})