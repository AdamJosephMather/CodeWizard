cmake_minimum_required(VERSION 3.5)

project(CodeWizard VERSION 0.1 LANGUAGES C CXX)
project(CodeWizard VERSION 0.1 LANGUAGES CXX)

set(BUILD_SHARED_LIBS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(MSVC)
    # Add MSVC-specific compile options
    add_compile_options(/w)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/tree-sitter)

add_library(tree-sitter-cpp STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-cpp/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-cpp/src/scanner.c
)

add_library(tree-sitter-c-sharp STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-c-sharp/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-c-sharp/src/scanner.c
)

add_library(tree-sitter-python STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-python/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-python/src/scanner.c
)

add_library(tree-sitter-rust STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-rust/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-rust/src/scanner.c
)

add_library(tree-sitter-javascript STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-javascript/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-javascript/src/scanner.c
)

add_library(tree-sitter-typescript STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-typescript/typescript/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-typescript/typescript/src/scanner.c
)

add_library(tree-sitter-html STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-html/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-html/src/scanner.c
)

add_library(tree-sitter-lua STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-lua/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-lua/src/scanner.c
)

add_library(tree-sitter-glsl STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-glsl/src/parser.c
)

add_library(tree-sitter-wgsl STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-wgsl/src/parser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-wgsl/src/scanner.c
)

add_library(tree-sitter-go STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-go/src/parser.c
)

add_library(tree-sitter-java STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-java/src/parser.c
)

add_library(tree-sitter-c STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-c/src/parser.c
)

target_include_directories(tree-sitter-cpp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-cpp/src
)

target_include_directories(tree-sitter-c-sharp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-c-sharp/src
)

target_include_directories(tree-sitter-python PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-python/src
)

target_include_directories(tree-sitter-rust PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-rust/src
)

target_include_directories(tree-sitter-javascript PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-javascript/src
)

target_include_directories(tree-sitter-typescript PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-typescript/typescript/src
)

target_include_directories(tree-sitter-html PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-html/src
)

#lua, glsl, wgsl, go, java,
target_include_directories(tree-sitter-lua PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-lua/src
)

target_include_directories(tree-sitter-glsl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-glsl/src
)

target_include_directories(tree-sitter-wgsl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-wgsl/src
)

target_include_directories(tree-sitter-go PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-go/src
)

target_include_directories(tree-sitter-java PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-java/src
)

target_include_directories(tree-sitter-c PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers/tree-sitter-c/src
)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    mytextedit.h
    mytextedit.cpp
    syntaxhighlighter.h
    syntaxhighlighter.cpp
    language.h
    language.cpp
    highlightdata.h
    highlightdata.cpp
    languageserverclient.h
    languageserverclient.cpp
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CodeWizard
        app.o
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mytextedit.h mytextedit.cpp
        resources/Python.ico
        fonts/Courier_New.ttf
        fonts/DroidSansMono.ttf
        fonts/Monaco.ttf
        fonts/Monospace.ttf
        resources.qrc
        fonts/Courier_Prime.ttf
        fonts/SourceCodePro-Regular.ttf
        fonts/UbuntuMono-R.ttf
        language.h language.cpp
        languageserverclient.h languageserverclient.cpp
        syntaxhighlighter.h syntaxhighlighter.cpp
        highlightdata.h highlightdata.cpp


    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CodeWizard APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CodeWizard SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CodeWizard
            app.o
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter/lib/include
)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern/tree-sitter-parsers)

# Update target_link_libraries to include the parsers
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt::Core
    Qt::Widgets
    tree-sitter
    tree-sitter-cpp
    tree-sitter-python
    tree-sitter-rust
    tree-sitter-javascript
    tree-sitter-typescript
    tree-sitter-html
    tree-sitter-lua
    tree-sitter-glsl
    tree-sitter-wgsl
    tree-sitter-java
    tree-sitter-go
    tree-sitter-c
    tree-sitter-c-sharp
)

target_link_libraries(CodeWizard PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CodeWizard)
endif()
set_target_properties(CodeWizard PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CodeWizard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Add this after your existing install commands
if(WIN32)
    # Install tree-sitter and parser DLLs alongside the executable
    install(TARGETS
        tree-sitter
        tree-sitter-cpp
        tree-sitter-python
        tree-sitter-rust
        tree-sitter-javascript
        tree-sitter-typescript
        tree-sitter-html
        tree-sitter-lua
        tree-sitter-glsl
        tree-sitter-wgsl
        tree-sitter-java
        tree-sitter-go
        tree-sitter-c
        tree-sitter-c-sharp
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
    )
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CodeWizard)
endif()
