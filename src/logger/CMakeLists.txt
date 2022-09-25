file(GLOB SOURCES "*cpp")
add_library(logger STATIC ${SOURCES})
target_include_directories(logger PUBLIC)
target_link_libraries(logger)