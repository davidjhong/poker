CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
project(Poker)

set(CMAKE_CXX_FLAGS --coverage)
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
    src/Utility.cpp
    src/Bot.cpp
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
    src/Utility.cpp
    src/Bot.cpp
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
    src/Utility.cpp
    src/Bot.cpp
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

ADD_EXECUTABLE(roundHandlerTests
    tests/roundHandlerTests.cpp
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
    src/Utility.cpp
    src/Bot.cpp
)

ADD_EXECUTABLE(gameHandlerTests
    tests/gameHandlerTests.cpp
    src/GameHandler.cpp
    src/Player.cpp
    src/RoundHandler.cpp
    src/Settings.cpp
    src/Pot.cpp
    src/Display.cpp
    src/Hand.cpp
    src/Bot.cpp
    src/Card.cpp
    src/Deck.cpp
    src/Utility.cpp
    src/handRank.cpp
)




# target_compile_options(poker PRIVATE --coverage)
# target_compile_options(test PRIVATE --coverage)
# target_compile_options(deckTests PRIVATE --coverage)
# target_compile_options(displayTests PRIVATE --coverage)
# target_compile_options(handTests PRIVATE --coverage)
# target_compile_options(playerTests PRIVATE --coverage)
# target_compile_options(potTests PRIVATE --coverage)
# target_compile_options(settingsTests PRIVATE --coverage)

TARGET_LINK_LIBRARIES(test PRIVATE --coverage gtest)
target_link_libraries(test PRIVATE --coverage gtest_main)
target_link_libraries(deckTests PRIVATE --coverage gtest_main)
target_link_libraries(settingsTests PRIVATE --coverage gtest_main)
target_link_libraries(displayTests PRIVATE --coverage gtest_main)
target_link_libraries(handTests PRIVATE --coverage gtest_main)
target_link_libraries(playerTests PRIVATE --coverage gtest_main)
target_link_libraries(potTests PRIVATE --coverage gtest_main)
target_link_libraries(roundHandlerTests PRIVATE --coverage gtest_main)
target_link_libraries(gameHandlerTests PRIVATE --coverage gtest_main)




TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)