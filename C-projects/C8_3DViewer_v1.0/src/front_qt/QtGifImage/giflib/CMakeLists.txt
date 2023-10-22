cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME qtgiflibrary)
project(${PROJECT_NAME} LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_HEADERS
    gif_lib.h
    gif_lib_private.h

    qgifglobal.h
    qgifimage.h
    qgifimage_p.h
)

set(PROJECT_SOURCES
    dgif_lib.c
    egif_lib.c
    gif_err.c
    gif_font.c
    gif_hash.c
    gifalloc.c
    quantize.c
    qgifimage.cpp
)

set(PROJECT_FILES ${PROJECT_HEADERS} ${PROJECT_SOURCES})

add_library(${PROJECT_NAME} SHARED ${PROJECT_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES 
                        VERSION ${PROJECT_VERSION}
                        SOVERSION ${PROJECT_VERSION_MAJOR})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(${PROJECT_NAME} PRIVATE QTGIF_COMPILE_LIBRARY)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
