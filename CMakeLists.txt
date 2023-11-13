CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
project(Poker)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(poker
    main.cpp
    lib/Pot.cpp
    lib/Player.cpp
    lib/handRank.cpp
    lib/Card.cpp
    lib/Deck.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
    lib/Pot.cpp
    lib/Player.cpp
    lib/handRank.cpp
    lib/Card.cpp
    lib/Deck.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
# target_link_libraries(test gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)