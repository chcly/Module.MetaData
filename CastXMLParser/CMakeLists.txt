include(GroupSet)
set_group(TargetName_SRC 
    Source:*.cpp
    Header:*.h
)

include_directories(
    ${CastXmlParser_INCLUDE}
    ${Utils_INCLUDE}
    ${Xml_INCLUDE}
    ${ParserBase_INCLUDE}
)

add_library(
    ${TargetName}
    ${TargetName_SRC}
)

target_link_libraries(
    ${TargetName}
    ${Utils_LIBRARY}
    ${Xml_LIBRARY}
    ${ParserBase_LIBRARY}
)

set_target_properties(
    ${TargetName} 
    PROPERTIES FOLDER "${TargetGroup}"
)
