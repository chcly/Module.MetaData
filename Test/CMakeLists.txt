set(TestTargetName ${TargetName}Test)
include(TestDirectory)
include(${CMAKE_CURRENT_SOURCE_DIR}/Transformer.cmake)


gen_path_to_here()

set(TestTarget_SRC
    Test1.cpp
    Transformer.cmake

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
endif()
