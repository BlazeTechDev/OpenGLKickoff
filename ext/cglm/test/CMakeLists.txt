cmake_minimum_required(VERSION 3.8.2)

# List all files containing tests. (Change as needed)
set(TESTFILES
<<<<<<< HEAD
  runner.c
  src/test_euler.c
  src/test_bezier.c
  src/test_struct.c
  src/test_clamp.c
  src/test_common.c
  src/tests.c
=======
        runner.c
        src/test_euler.c
        src/test_bezier.c
        src/test_struct.c
        src/test_clamp.c
        src/test_common.c
        src/tests.c
>>>>>>> 4444ec811213deaab9c566168cdc16ae99d6bf09
  )

set(TEST_MAIN tests)
set(TEST_RUNNER_PARAMS "")

add_executable(${TEST_MAIN} ${TESTFILES})
target_compile_definitions(${TEST_MAIN} PRIVATE CGLM_DEFINE_PRINTS=1)

if(CMAKE_SYSTEM_NAME STREQUAL WASI)
  target_compile_definitions(${TEST_MAIN} PRIVATE _WASI_EMULATED_PROCESS_CLOCKS=1)
  target_link_options(${TEST_MAIN} PRIVATE "-lwasi-emulated-process-clocks")
endif()

if(NOT MSVC)
  target_link_libraries(${TEST_MAIN} PRIVATE m)
endif()

target_link_libraries(${TEST_MAIN} PRIVATE cglm)
target_include_directories(${TEST_MAIN} PRIVATE
<<<<<<< HEAD
  ${CMAKE_CURRENT_LIST_DIR}/include
  ${CMAKE_CURRENT_LIST_DIR}/src
=======
        include
        src
>>>>>>> 4444ec811213deaab9c566168cdc16ae99d6bf09
  )

set_target_properties(${TEST_MAIN} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

if(LDFLAGS)
  target_compile_options(${TEST_MAIN} PRIVATE ${LDFLAGS})
endif()

add_test(
    NAME cglm.${TEST_MAIN}
    COMMAND ${TEST_MAIN} ${TEST_RUNNER_PARAMS})

add_custom_target(check
  make
  COMMAND ${CMAKE_CTEST_COMMAND} -V
  DEPENDS cglm)
