CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
project(Poker)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

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

ADD_EXECUTABLE(deckTests
    tests/deckTests.cpp
    src/Deck.cpp
    src/Card.cpp
)

ADD_EXECUTABLE(displayTests
    tests/displayTests.cpp
    src/Display.cpp
    src/Deck.cpp
    src/Hand.cpp 
    src/handRank.cpp
    src/Player.cpp
    src/Pot.cpp
    src/Card.cpp
    src/Deck.cpp
    src/GameHandler.cpp
    src/RoundHandler.cpp
    src/Settings.cpp

)

ADD_EXECUTABLE(handTests
    tests/handTests.cpp
    src/Hand.cpp
    src/Card.cpp
    src/Deck.cpp
    src/handRank.cpp
)

ADD_EXECUTABLE(playerTests
    tests/playerTests.cpp
    src/Player.cpp
    src/Hand.cpp
    src/handRank.cpp
    src/Card.cpp
)

ADD_EXECUTABLE(potTests
    tests/potTests.cpp
    src/Pot.cpp
)

ADD_EXECUTABLE(settingsTests
    tests/settingsTests.cpp
    src/Settings.cpp
)

ADD_EXECUTABLE(saveTest
    tests/saveTest.cpp
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
target_link_libraries(test gtest_main)
target_link_libraries(deckTests gtest_main)
target_link_libraries(settingsTests gtest_main)
target_link_libraries(displayTests gtest_main)
target_link_libraries(handTests gtest_main)
target_link_libraries(playerTests gtest_main)
target_link_libraries(potTests gtest_main)
target_link_libraries(saveTest gtest_main)




TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)