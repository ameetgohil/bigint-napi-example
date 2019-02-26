cmake_minimum_required(VERSION 3.9)
set (CMAKE_CXX_STANDARD 11)
project (dut)

file(GLOB SOURCE_FILES "cppsrc/*.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
add_definitions(-DNAPI_EXPERIMENTAL) # -DSRC_NAPI_INL_H_)
target_include_directories(${PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api
  PRIVATE ${CMAKE_JS_INC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} ${VERLIBS})

