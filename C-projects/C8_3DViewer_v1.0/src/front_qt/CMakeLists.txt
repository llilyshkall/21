cmake_minimum_required(VERSION 3.5)

project(3D_Viewer VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGLWidgets)

add_subdirectory(QtGifImage)

set(PROJECT_HEADERS
    window.h
    opengl.h
#    ../back/shape.h
)

set(PROJECT_SOURCES
    main.cpp
    window.cpp
    opengl.cpp
#    ../back/shape.c
)

set(PROJECT_UI window.ui)

set(PROJECT_LIB viewer.a)

set(PROJECT_FILES ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_UI})

# Add files to the application
add_executable(${PROJECT_NAME} ${PROJECT_BUILD_ARGS} ${PROJECT_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${PROJECT_LIB})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

# QtGIF Library
target_link_libraries(${PROJECT_NAME} PRIVATE qtgiflibrary)

# Compile needed definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE QTGIF_USE_LIBRARY)

set_target_properties(${PROJECT_NAME} PROPERTIES
                VERSION ${PROJECT_VERSION}
                SOVERSION ${PROJECT_VERSION_MAJOR}
)

set_target_properties(3D_Viewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    C_STANDARD 11
    CXX_STANDARD 11
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3D_Viewer)
endif()
