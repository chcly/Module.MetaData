cmake_minimum_required(VERSION 3.15)
project(CastXmlParser)

# Use C++-17 by default.
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Set the module path to include scripts
# CMake - Contains project local modules.
#
# CMake/Modules - Contains project independent modules.
#   GitUpdate.cmake invokes python ${CastXmlParser_SOURCE_DIR}/gitupdate.py
#   to pull all submodules and update to head.
#   If this fails, it will attempt to invoke git directly to pull 
#   submodules. 
list(APPEND CMAKE_MODULE_PATH 
  ${CastXmlParser_SOURCE_DIR}/CMake 
  ${CastXmlParser_SOURCE_DIR}/CMake/Modules
)
include(Configure)
if (NOT Configure_SUCCEEDED)
   return()
endif()



if (CastXmlParser_ExternalTarget)
    set(TargetFolders ${CastXmlParser_TargetFolders})
    set(TargetName    ${CastXmlParser_TargetName})
    set(TargetGroup   ${CastXmlParser_TargetGroup})
else()
    add_subdirectory(CMake)

    set(TargetFolders TRUE)
    set(TargetName CastXmlParser)
    set(TargetGroup )

    set(CastXmlParser_INCLUDE  ${CastXmlParser_SOURCE_DIR})
    set(CastXmlParser_LIBRARY  ${TargetName})
endif()

add_subdirectory(Source)

if (CastXmlParser_BUILD_TEST)
    if (NOT CastXmlParser_ExternalTarget)
        add_gtest_source(Extern/ThirdParty)
    endif()

    set(TargetGroup Units)
    add_subdirectory(Test)
endif()
