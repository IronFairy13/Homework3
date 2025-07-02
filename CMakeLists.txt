cmake_minimum_required(VERSION 3.12)

project(homework_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(homework_3 main.cpp)


target_include_directories(homework_3
    PRIVATE "${CMAKE_BINARY_DIR}"
)



if (MSVC)
    
    target_compile_options(homework_3 PRIVATE
        /W4
    )

else ()
    target_compile_options(homework_3 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

endif()

install(TARGETS homework_3 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "homework_3")
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 1)
set(CPACK_PACKAGE_VERSION_PATCH ${PATCH_VERSION})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Savchenko")  

include(CPack)




