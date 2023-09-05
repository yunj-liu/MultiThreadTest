cmake_minimum_required(VERSION 3.5)

project(
  09MultiThreadTest
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\include"
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\include\\win64"
  "F:\\MatlabTest\\SemiCL6Func_vc19\\SemiCL6Func\\for_redistribution_files_only"
)

link_directories(
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\lib\\win64\\microsoft"
  "F:\\MatlabTest\\SemiCL6Func_vc19\\SemiCL6Func\\for_redistribution_files_only"
)

set(PROJECT_SOURCES main.cpp mainwidget.cpp mainwidget.h mainwidget.ui
                    commontype.h)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(09MultiThreadTest MANUAL_FINALIZATION ${PROJECT_SOURCES}
                    workthread.h workthread.cpp)
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # 09MultiThreadTest APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(09MultiThreadTest SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(09MultiThreadTest ${PROJECT_SOURCES})
  endif()
endif()

set(LIB_PROJ
    "libmex.lib"
    "libmx.lib"
    "libmat.lib"
    "libeng.lib"
    "mclmcr.lib"
    "mclmcrrt.lib"
    "SemiCL6Func.lib")

target_link_libraries(09MultiThreadTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                                ${LIB_PROJ})

set_target_properties(
  09MultiThreadTest
  PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
             MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
             MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

install(
  TARGETS 09MultiThreadTest
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(09MultiThreadTest)
endif()
