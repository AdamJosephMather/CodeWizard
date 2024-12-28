# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\CodeWizard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CodeWizard_autogen.dir\\ParseCache.txt"
  "CodeWizard_autogen"
  )
endif()
