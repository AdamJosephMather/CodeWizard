# Install script for directory: C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo

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

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw1310_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/src/gumbo/libgumbo.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/src/gumbo/libgumbo.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libgumbo.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libgumbo.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Qt/Tools/mingw1310_64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libgumbo.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gumbo" TYPE FILE FILES
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/attribute.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/char_ref.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/error.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/insertion_mode.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/parser.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/string_buffer.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/string_piece.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/tag_enum.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/tag_gperf.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/tag_sizes.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/tag_strings.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/token_type.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/tokenizer.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/tokenizer_states.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/utf8.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/util.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/src/gumbo/include/gumbo/vector.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/gumbo/gumboConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/gumbo/gumboConfig.cmake"
         "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/src/gumbo/CMakeFiles/Export/df09b600d79ede856025bf0d0b984a6e/gumboConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/gumbo/gumboConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/gumbo/gumboConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/gumbo" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/src/gumbo/CMakeFiles/Export/df09b600d79ede856025bf0d0b984a6e/gumboConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/gumbo" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/src/gumbo/CMakeFiles/Export/df09b600d79ede856025bf0d0b984a6e/gumboConfig-release.cmake")
  endif()
endif()

