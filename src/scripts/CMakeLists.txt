

add_executable(
    ws_example
    ws_example.cpp
)

target_link_libraries(
    ws_example
    ws
    util
    logger
    ${CONAN_LIBS}
)
