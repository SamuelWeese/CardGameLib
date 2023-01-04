cmake_minimum_required(VERSION 3.5)

project(CardLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

find_package(SFML 2.5
  COMPONENTS
    system window graphics REQUIRED
    )

set ( TEMP_CPP_TESTING_SOURCES
  main.cpp
  )

Set( PROJECT_CPP_SOURCES
    card.cpp
    deck.cpp
    hand.cpp
)

SET ( PROJECT_CPP_HEADERS
    card.h
    deck.h
    hand.h
)

add_executable(
    ${PROJECT_NAME}
    ${PROJECT_CPP_SOURCES}
    ${TEMP_CPP_TESTING_SOURCES}
    ${PROJECT_CPP_HEADERS}
)

target_link_libraries(
 ${PROJECT_NAME}
 sfml-graphics
)

