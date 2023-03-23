include(GroupSet)
include(CastXmlConfig)

set(From_CSV "ClassA,File1")
extract_source(SRC ${CMAKE_CURRENT_SOURCE_DIR}/../Source)
compile_and_transfer(XML ${CMAKE_CURRENT_SOURCE_DIR} ${From_CSV} ${SRC})

set_group(TargetName_SRC
    Source:*.cpp
    Header:*.h
    Resources:${XML}
)

include_directories(.)

add_executable(
    ${TargetName}
    ${TargetName_SRC}
)

#target_link_libraries(
#    ${TargetName} 
#)

set_target_properties(
    ${TargetName} 
    PROPERTIES FOLDER "${TargetGroup}"
)
