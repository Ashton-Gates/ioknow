cmake_minimum_required(VERSION 3.25)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
project(ioknow)

set(SOURCES
        main.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})

# Include Windows SDK
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}wx/include/wx)
include_directories(${CMAKE_SOURCE_DIR}/wx)


# Add SQLite
set(SQLITE_DIR ${CMAKE_SOURCE_DIR}/libraries)  # Update the directory path accordingly
target_sources(${PROJECT_NAME} PRIVATE ${SQLITE_DIR}/sqlite3.dll)
target_include_directories(${PROJECT_NAME} PRIVATE ${SQLITE_DIR})

# Link with Windows Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Comctl32)

# Set the entry point to WinMain for Windows
set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "/ENTRY:WinMainCRTStartup"
        )
