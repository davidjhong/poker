CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
project(Poker)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(poker
    main.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)