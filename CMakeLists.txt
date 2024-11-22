cmake_minimum_required(VERSION 3.11)

set(MINGW_PATH "C:/Program Files/MinGW-w64/bin")
set(CMAKE_CXX_COMPILER "${MINGW_PATH}/g++.exe")
set(CMAKE_MAKE_PROGRAM "${MINGW_PATH}/mingw32-make.exe")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
project (
    1week-RT
    LANGUAGES CXX
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/headers
)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp")

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${SRC_FILES}
)

target_compile_options(
	${PROJECT_NAME}

	PRIVATE
		-std=c++17
)