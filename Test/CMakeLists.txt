set(TestTargetName ${TargetName}Test)
include(TestDirectory)
include(CastXmlConfig)
include(TargetDebugOptions)



# include paths to relay to the compiler
cast_xml_include(${Utils_INCLUDE})

# specific symbols to extract
cast_xml_symbols(
    ClassA
    File1
    LinkOrder
    Integers
    Module
)
cast_xml_cxx_flags(-Wall -std=c++17)
cast_transfer_dir(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC Source/*.cpp)
add_cast_xml(XML ${SRC})

gen_path_to_here()

set_group(TestTarget_SRC
    Source:Test1.cpp
    Source/TestLib:Source/*.cpp
    Header/TestLib:Source/*.h
)

include_directories(
    ${GTEST_INCLUDE}
    ${MetaData_INCLUDE}
    ${Utils_INCLUDE}
    ${Xml_INCLUDE}
    ${ParserBase_INCLUDE}
)

add_executable(
    ${TestTargetName}
    ${TestTarget_SRC}
    ${XML}
)

target_link_libraries(
    ${TestTargetName} 
    ${GTEST_LIBRARY}
    ${MetaData_LIBRARY}
    ${Utils_LIBRARY}
    ${Xml_LIBRARY}
    ${ParserBase_LIBRARY}
)

set_target_properties(
    ${TestTargetName} 
    PROPERTIES FOLDER "${TargetGroup}"
)


if (MetaData_AUTO_RUN_TEST)
    run_test(${TestTargetName})
else()
    target_debug(${TestTargetName} ${CMAKE_CURRENT_SOURCE_DIR})
endif()
