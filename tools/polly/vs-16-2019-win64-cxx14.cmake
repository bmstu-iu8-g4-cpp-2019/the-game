# Copyright (c) 2015-2019, Ruslan Baratov
# All rights reserved.

if(DEFINED POLLY_VS_16_2019_WIN64_CXX14_CMAKE_)
  return()
else()
  set(POLLY_VS_16_2019_WIN64_CXX14_CMAKE_ 1)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/utilities/polly_init.cmake")

polly_init(
    "Visual Studio 16 2019 Win64 / C++14"
    "Visual Studio 16 2019"
)

include("${CMAKE_CURRENT_LIST_DIR}/utilities/polly_common.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/flags/vs-cxx14.cmake")

include("${CMAKE_CURRENT_LIST_DIR}/flags/vs-platform-x64.cmake")
