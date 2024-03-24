file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/CircleProgressBar/*.h")

source_group("Header Files" FILES ${HEADER_FILES})

aux_source_directory(. cplusplus)

add_library(CircleProgressBar SHARED ${cplusplus} ${HEADER_FILES})

target_link_libraries(CircleProgressBar Qt5::Widgets Qt5::Core Qt5::Gui)