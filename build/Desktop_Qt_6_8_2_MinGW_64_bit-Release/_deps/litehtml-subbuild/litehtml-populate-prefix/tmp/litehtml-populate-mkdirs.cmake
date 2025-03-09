# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src")
  file(MAKE_DIRECTORY "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build"
  "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-subbuild/litehtml-populate-prefix"
  "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-subbuild/litehtml-populate-prefix/tmp"
  "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-subbuild/litehtml-populate-prefix/src/litehtml-populate-stamp"
  "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-subbuild/litehtml-populate-prefix/src"
  "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-subbuild/litehtml-populate-prefix/src/litehtml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-subbuild/litehtml-populate-prefix/src/litehtml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-subbuild/litehtml-populate-prefix/src/litehtml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
