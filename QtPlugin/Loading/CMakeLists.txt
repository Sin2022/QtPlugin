file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/Loading/*.h")
#message(WARNING "-----${CMAKE_SOURCE_DIR}----")
source_group("Header Files" FILES ${HEADER_FILES})

aux_source_directory(. cplusplus)

add_library(Loading SHARED ${cplusplus} ${HEADER_FILES})

target_link_libraries(Loading Qt5::Widgets Qt5::Core Qt5::Gui)