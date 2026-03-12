# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\Servers_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Servers_autogen.dir\\ParseCache.txt"
  "Servers_autogen"
  )
endif()
