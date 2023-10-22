cmake_minimum_required(VERSION 3.5)

# Set project configuration
project(SmartCalc VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_subdirectory(QCustomPlot)

set(PROJECT_HEADERS
    mainwindow.h
)

set(PROJECT_SOURCES
    main.cpp
    window_connection.cpp
    calculator.cpp
    graph.cpp
)

set(PROJECT_LIB calc.a)

set(PROJECT_UI mainwindow.ui)

set(PROJECT_RSC resources.qrc)

set(PROJECT_FILES ${PROJECT_RSC} ${PROJECT_UI} ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Add files to the application
add_executable(${PROJECT_NAME} ${PROJECT_BUILD_ARGS} ${PROJECT_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${PROJECT_LIB})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# QCustomPlot library
target_link_libraries(${PROJECT_NAME} PRIVATE qcustomplot)

# Compile needed definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE QCUSTOMPLOT_USE_LIBRARY)

# Set version of executable
set_target_properties(${PROJECT_NAME} PROPERTIES
                        VERSION ${PROJECT_VERSION}
                        SOVERSION ${PROJECT_VERSION_MAJOR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc)
endif()
