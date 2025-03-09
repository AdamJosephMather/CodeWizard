# Install script for directory: C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/liblitehtml.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/liblitehtml.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/liblitehtml.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/liblitehtml.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Qt/Tools/mingw1310_64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/liblitehtml.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/litehtml" TYPE FILE FILES
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/background.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/borders.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/codepoint.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_length.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_margins.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_offsets.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_position.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_selector.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_parser.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_tokenizer.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/document.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/document_container.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_anchor.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_base.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_before_after.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_body.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_break.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_cdata.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_comment.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_div.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_font.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_image.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_link.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_para.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_script.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_space.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_style.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_table.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_td.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_text.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_title.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/el_tr.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/element.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/encodings.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/html.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/html_tag.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/html_microsyntaxes.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/iterators.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/media_query.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/os_types.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/style.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/stylesheet.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/table.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/tstring_view.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/types.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/url.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/url_path.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/utf8_strings.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/web_color.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/num_cvt.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/css_properties.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/line_box.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_item.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_flex.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_image.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_inline.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_table.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_inline_context.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_block_context.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/render_block.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/master_css.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/string_id.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/formatting_context.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/flex_item.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/flex_line.h"
    "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/include/litehtml/gradient.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/litehtml" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-src/cmake/litehtmlConfig.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/litehtml/litehtmlTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/litehtml/litehtmlTargets.cmake"
         "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/CMakeFiles/Export/1858d3296707c77b4f85418fd0121701/litehtmlTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/litehtml/litehtmlTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/litehtml/litehtmlTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/litehtml" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/CMakeFiles/Export/1858d3296707c77b4f85418fd0121701/litehtmlTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/litehtml" TYPE FILE FILES "C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/CMakeFiles/Export/1858d3296707c77b4f85418fd0121701/litehtmlTargets-release.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/adamj/Documents/QtProjects/CodeWizard/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/_deps/litehtml-build/src/gumbo/cmake_install.cmake")

endif()

