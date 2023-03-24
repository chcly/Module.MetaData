cmake_minimum_required(VERSION 3.15)
project(MetaData)

# Use C++-17 by default.
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Set the module path to include scripts
# CMake - Contains project local modules.
#
# CMake/Modules - Contains project independent modules.
#   GitUpdate.cmake invokes python ${MetaData_SOURCE_DIR}/gitupdate.py
#   to pull all submodules and update to head.
#   If this fails, it will attempt to invoke git directly to pull 
#   submodules. 
list(APPEND CMAKE_MODULE_PATH 
  ${MetaData_SOURCE_DIR}/CMake 
  ${MetaData_SOURCE_DIR}/CMake/Modules
)
include(Configure)
if (NOT Configure_SUCCEEDED)
   return()
endif()



if (MetaData_ExternalTarget)
    set(TargetFolders ${MetaData_TargetFolders})
    set(TargetName    ${MetaData_TargetName})
    set(TargetGroup   ${MetaData_TargetGroup})
else()
    add_subdirectory(CMake)
    add_subdirectory(Internal/Utils)
    add_subdirectory(Internal/ParserBase)
    add_subdirectory(Internal/Xml)

    set(TargetFolders TRUE)
    set(TargetName MetaData)
    set(TargetGroup )

    set(MetaData_INCLUDE  ${MetaData_SOURCE_DIR})
    set(MetaData_LIBRARY  ${TargetName})
endif()

add_subdirectory(MetaData)

if (MetaData_BUILD_TEST)
    if (NOT MetaData_ExternalTarget)
        add_gtest_source(Extern/ThirdParty)
    endif()

    set(TargetGroup Units)
    add_subdirectory(Test)
endif()
