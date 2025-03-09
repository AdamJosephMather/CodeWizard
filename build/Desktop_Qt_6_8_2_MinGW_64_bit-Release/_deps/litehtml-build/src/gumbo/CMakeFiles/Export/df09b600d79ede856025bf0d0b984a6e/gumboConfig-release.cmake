#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gumbo" for configuration "Release"
set_property(TARGET gumbo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gumbo PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libgumbo.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libgumbo.dll"
  )

list(APPEND _cmake_import_check_targets gumbo )
list(APPEND _cmake_import_check_files_for_gumbo "${_IMPORT_PREFIX}/lib/libgumbo.dll.a" "${_IMPORT_PREFIX}/bin/libgumbo.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
