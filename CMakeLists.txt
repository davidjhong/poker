CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
project(Poker)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(poker
    main.cpp
    src/Pot.cpp
    src/Player.cpp
    src/handRank.cpp
    src/Card.cpp
    src/Deck.cpp
    src/Hand.cpp
    src/RoundHandler.cpp
    src/GameHandler.cpp
    src/Settings.cpp
    src/Display.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
    src/Pot.cpp
    src/Player.cpp
    src/handRank.cpp
    src/Card.cpp
    src/Deck.cpp
    src/Hand.cpp
    src/RoundHandler.cpp
    src/GameHandler.cpp
    src/Settings.cpp
    src/Display.cpp
)

ADD_EXECUTABLE(playerPotTest
    main.cpp
    src/Pot.cpp
    src/Player.cpp
    src/handRank.cpp
    src/Card.cpp
    src/Deck.cpp
    src/Hand.cpp
    src/RoundHandler.cpp
    src/GameHandler.cpp
    src/Settings.cpp
    src/Display.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
# target_link_libraries(test gtest_main)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)