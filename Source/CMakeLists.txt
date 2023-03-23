# -----------------------------------------------------------------------------
#   Copyright (c) 2019 Charles Carley.
#
#   This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
#   Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgment in the product documentation would be
#    appreciated but is not required.
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.
# ------------------------------------------------------------------------------
set(TargetName_SOURCE 
    Main.cpp)

set(CastEXE "H:/SysBin/castxml-windows/castxml/bin/castxml.exe")




add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Main.xml
	COMMAND ${CastEXE} --castxml-start Blarg --castxml-output=1.4.0 --castxml-cc-msvc cl -o ${CMAKE_CURRENT_BINARY_DIR}/Main.xml ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
	COMMENT "Converting Main.cpp"
	)

add_executable(
    ${TargetName} 
    ${TargetName_SOURCE}
    ${CMAKE_CURRENT_BINARY_DIR}/Main.xml
)

if (TargetFolders)
    set_target_properties(${TargetName} PROPERTIES FOLDER "${TargetGroup}")
endif()
