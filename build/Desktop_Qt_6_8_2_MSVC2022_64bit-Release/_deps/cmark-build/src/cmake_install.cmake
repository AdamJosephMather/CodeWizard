# Install script for directory: C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-src/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/CodeWizard")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/cmark.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/cmark.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/cmark.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/libcmark.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-src/src/cmark.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/cmark_export.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/cmark_version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cmark" TYPE FILE FILES
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/generated/cmark-config.cmake"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/generated/cmark-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cmark/cmark-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cmark/cmark-targets.cmake"
         "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/CMakeFiles/Export/fccc7afb0bf4c34e18a1be84d1a11cfd/cmark-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cmark/cmark-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cmark/cmark-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cmark" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/CMakeFiles/Export/fccc7afb0bf4c34e18a1be84d1a11cfd/cmark-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cmark" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MSVC2022_64bit-Release/_deps/cmark-build/src/CMakeFiles/Export/fccc7afb0bf4c34e18a1be84d1a11cfd/cmark-targets-release.cmake")
  endif()
endif()

