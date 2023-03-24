set(CastXML_EXE      $ENV{CASTXML} CACHE PATH  "")
set(CastXML_VERSION  "1.4.0"       CACHE PATH  "")
set(CastXML_CC       "msvc"        CACHE PATH  "")
set(CastXML_CC_TOOL  "cl"          CACHE PATH  "")


function(extract_source OUT SRC_DIR)
    file(GLOB  SOURCE_FILES  ${SRC_DIR}/*.cpp)


    set(TEMP_RES )
    foreach(SRC ${SOURCE_FILES})
        get_filename_component(SRC_ABS ${SRC} ABSOLUTE)
        list(APPEND TEMP_RES ${SRC_ABS})
    endforeach()


    list(APPEND SRC ${TEMP_RES})
    set(${OUT} ${SRC} PARENT_SCOPE)
endfunction()

function(compile_and_transfer RESULT TRANSFER_TO_DIR CSV)
    set(TEMP_RES )
    foreach(SRC ${ARGN})
        get_filename_component(SRC_NAME ${SRC} NAME_WE)

        set(OUTPUT_SRC  "${CMAKE_CURRENT_BINARY_DIR}/${SRC_NAME}.xml")
        set(TRANSFR_SRC  "${TRANSFER_TO_DIR}/${SRC_NAME}.xml")

        set_source_files_properties(${OUTPUT_SRC} PROPERTIES GENERATED TRUE )
        set_source_files_properties(${TRANSFR_SRC} PROPERTIES GENERATED TRUE )
                
        add_custom_command(
	        OUTPUT  ${OUTPUT_SRC}
	        COMMENT "${SRC_NAME}.xml"
	        COMMAND ${CastXML_EXE} 
                               --castxml-start "${CSV}"
                               --castxml-output=${CastXML_VERSION} 
                               --castxml-cc-${CastXML_CC} ${CastXML_CC_TOOL}
                               -o ${OUTPUT_SRC} 
                               "${SRC}"

            DEPENDS ${SRC}
	    )

        add_custom_command(
	        OUTPUT  ${TRANSFR_SRC}
	        COMMENT "Transfer ${SRC_NAME}.xml"
	        COMMAND ${CMAKE_COMMAND} -E copy
                    ${OUTPUT_SRC}
                    ${TRANSFR_SRC}
            DEPENDS ${OUTPUT_SRC}
	    )


        set(TEMP_RES ${TRANSFR_SRC} ${TEMP_RES})
    endforeach()

    set(${RESULT} ${TEMP_RES} PARENT_SCOPE)
endfunction()
