cmake_minimum_required(VERSION 3.16)

project(cpp_lectures LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(add_cpp_lecture lecture_dir)
    file(GLOB lecture_sources CONFIGURE_DEPENDS
        "${lecture_dir}/src/*.cpp"
    )

    add_executable(${lecture_dir} ${lecture_sources})
    target_compile_options(${lecture_dir} PRIVATE -Wpedantic)

    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${lecture_dir}/include")
        target_include_directories(${lecture_dir}
            PRIVATE
            "${lecture_dir}/include"
        )
    endif()

    set_target_properties(${lecture_dir} PROPERTIES
        OUTPUT_NAME out
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${lecture_dir}"
    )
endfunction()

add_executable(lecture00_c lecture00_c/src/main.c)
set_target_properties(lecture00_c PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
    OUTPUT_NAME out
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lecture00_c"
)

add_cpp_lecture(lecture00_cpp)
add_cpp_lecture(lecture01)
add_cpp_lecture(lecture02)
add_cpp_lecture(lecture03)
add_cpp_lecture(lecture04)
add_cpp_lecture(lecture05)
add_cpp_lecture(lecture06)
add_cpp_lecture(lecture07)
add_cpp_lecture(lecture08)
add_cpp_lecture(lecture09)
add_cpp_lecture(lecture10)
add_cpp_lecture(lecture11)
add_cpp_lecture(lecture12)
add_cpp_lecture(lecture13)
add_cpp_lecture(lecture14)
add_cpp_lecture(lecture15)
add_cpp_lecture(lecture16)
add_cpp_lecture(lecture17)
add_cpp_lecture(lecture18)
add_cpp_lecture(lecture19)
add_cpp_lecture(lecture20)
add_cpp_lecture(lecture21)
add_cpp_lecture(lecture22)
add_cpp_lecture(lecture23)
