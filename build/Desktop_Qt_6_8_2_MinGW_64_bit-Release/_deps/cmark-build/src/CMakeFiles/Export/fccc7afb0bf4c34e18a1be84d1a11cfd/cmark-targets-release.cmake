#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cmark::cmark_exe" for configuration "Release"
set_property(TARGET cmark::cmark_exe APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(cmark::cmark_exe PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/cmark.exe"
  )

list(APPEND _cmake_import_check_targets cmark::cmark_exe )
list(APPEND _cmake_import_check_files_for_cmark::cmark_exe "${_IMPORT_PREFIX}/bin/cmark.exe" )

# Import target "cmark::cmark" for configuration "Release"
set_property(TARGET cmark::cmark APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(cmark::cmark PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libcmark.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libcmark.dll"
  )

list(APPEND _cmake_import_check_targets cmark::cmark )
list(APPEND _cmake_import_check_files_for_cmark::cmark "${_IMPORT_PREFIX}/lib/libcmark.dll.a" "${_IMPORT_PREFIX}/bin/libcmark.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
