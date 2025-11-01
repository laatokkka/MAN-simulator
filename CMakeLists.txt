cmake_minimum_required(VERSION 3.16)
project(MANSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SRCS
    server/Server.cpp

    server/gui/Menu.cpp

    server/gui/scene/GameField.cpp
    server/gui/scene/AddPlayerDialog.cpp
)

set(HDRS
    server/Server.h

    server/gui/Menu.h

    server/gui/scene/GameField.h
    server/gui/scene/AddPlayerDialog.h
)

# Создание исполняемого файла
qt_add_executable(MANSimulator 
    ${SRCS}
    ${HDRS}
)

target_include_directories(MANSimulator PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/server
    ${CMAKE_CURRENT_SOURCE_DIR}/server/gui
    ${CMAKE_CURRENT_SOURCE_DIR}/server/gui/scene
    ${CMAKE_CURRENT_SOURCE_DIR}/player
)

target_link_libraries(MANSimulator PRIVATE Qt6::Widgets)
