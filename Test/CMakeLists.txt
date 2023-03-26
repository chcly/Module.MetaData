set(TestTargetName ${TargetName}Test)
include(TestDirectory)
include(CastXmlConfig)
include(TargetDebugOptions)

set(From_CSV "ClassA,File1,LinkOrder,Integers,Module")
extract_source(SRC ${CMAKE_CURRENT_SOURCE_DIR}/Source/)
compile_and_transfer(XML ${CMAKE_CURRENT_SOURCE_DIR} ${From_CSV} ${SRC})

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

TARGET_DEBUG(${TestTargetName} ${CMAKE_CURRENT_SOURCE_DIR})

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
endif()
