include(GroupSet)

set_group(TargetName_SRC
    Source:*.cpp
    Header:*.h
)

include_directories(.)

add_library(
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
