cmake_minimum_required(VERSION 3.12)

project(homework_3 LANGUAGES CXX)

option(WITH_GTEST "Whether to build GTest test" OFF)


add_executable(homework_3 main.cpp)

set_target_properties( homework_3 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(homework_3
    PRIVATE "${CMAKE_BINARY_DIR}"
)


if(WITH_GTEST)
    find_package(GTest REQUIRED)
    add_executable(test test.cpp)

    set_target_properties(test PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
    )

    target_link_libraries(test
        GTest::gtest
        GTest::gtest_main
        homework_3
    )
endif()

if (MSVC)
    
    target_compile_options(homework_3 PRIVATE
        /W4
    )
    if(WITH_GTEST)
        target_compile_options(test PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(homework_3 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(WITH_GTEST)
        target_compile_options(test PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS homework_3 RUNTIME DESTINATION bin)

include(CPack)

if(WITH_GTEST)
    enable_testing()
    add_test(NAME test COMMAND test)
endif()

find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.generated)

    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Генерация документации Doxygen"
        VERBATIM
    )
endif()
