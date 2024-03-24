file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/ClockWidget/*.h")
#message(WARNING "-----${CMAKE_SOURCE_DIR}----")
source_group("Header Files" FILES ${HEADER_FILES})

aux_source_directory(. cplusplus)

add_library(ClockWidget SHARED ${cplusplus} ${HEADER_FILES})

target_link_libraries(ClockWidget Qt5::Widgets Qt5::Core Qt5::Gui)