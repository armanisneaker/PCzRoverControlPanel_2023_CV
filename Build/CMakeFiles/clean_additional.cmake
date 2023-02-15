# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TestTwo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TestTwo_autogen.dir\\ParseCache.txt"
  "TestTwo_autogen"
  )
endif()
