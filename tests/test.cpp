#include "gtest/gtest.h"
#include "../header/Player.h"
#include "../header/Card.h"
#include "../header/handRank.h"
#include "../header/Pot.h"
#include "../header/Deck.h"
#include "../header/Hand.h"
#include "../header/Settings.h"
#include "../header/Display.h"
#include "../header/RoundHandler.h"
#include "../header/GameHandler.h"
#include "../header/Bot.h"

// Deck Test Suite

TEST(DeckTests, constructorTest) {
  Deck* testDeck = new Deck();

  Card* firstCard = testDeck->nextCard();
  Card* secondCard = testDeck->nextCard();
  Card* thirdCard = testDeck->nextCard();
  Card* fourthCard = testDeck->nextCard();
  Card* fifthCard = testDeck->nextCard();

  EXPECT_EQ(firstCard->getName(), "Ace of Diamonds");
  EXPECT_EQ(secondCard->getName(), "Ace of Hearts");
  EXPECT_EQ(thirdCard->getName(), "Ace of Clubs");
  EXPECT_EQ(fourthCard->getName(), "Ace of Spades");
  EXPECT_EQ(fifthCard->getName(), "Two of Diamonds");

}

TEST(DeckTests, shuffleDeckTest) {
  Deck* testDeck = new Deck();

  testDeck->shuffleDeck(false);
  
  Card* firstCard = testDeck->nextCard();
  Card* secondCard = testDeck->nextCard();
  Card* thirdCard = testDeck->nextCard();
  Card* fourthCard = testDeck->nextCard();
  Card* fifthCard = testDeck->nextCard();

  EXPECT_EQ(firstCard->getName(), "Two of Diamonds");
  EXPECT_EQ(secondCard->getName(), "King of Spades");
  EXPECT_EQ(thirdCard->getName(), "Three of Spades");
  EXPECT_EQ(fourthCard->getName(), "Four of Spades");
  EXPECT_EQ(fifthCard->getName(), "Seven of Diamonds");
}

// DISPLAY TESTS

TEST(DisplayTest, displayCardsTest)
{
  
  Player* player = new Player();

  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
  vector<Card*> cards = {card1, card2};
  player->getHand()->addCard(card1);
  player->getHand()->addCard(card2);

  ostringstream out; 
  Display* display = new Display();
  display->displayCards(out, cards);
 

  EXPECT_EQ(out.str(),

"-----     -----     \n"     
"| ♠ |     | ♠ |     \n"    
"| A |     | 5 |     \n"     
"-----     -----     \n"); 

  }

TEST(DisplayTest, displayCommunityCardsTest)
{
  
  Player* player = new Player();
  player->setName("chloe");
  Card* card4 = new Card(6, "Diamonds", "Five of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Ten of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Nine of Hearts", "♥");
  Card* card7 = new Card(10, "Clubs", "Eight of Clubs", "♣");
  vector<Card*> CommunityCards = {card4, card5, card6, card7};

  Pot* pot = new Pot();

  ostringstream out; 
  Display* display = new Display();
  display->displayGameStatus(out, CommunityCards, player, pot);
 

  EXPECT_EQ(out.str(),
  "chloe, it's your turn!\n"
  "You have 0 chips\n"
  "Pot: 0\n"
  "Your hand:\n\n\n\n\n"
  "Community cards:\n"
  "-----     -----     -----     -----     -----     \n"     
  "| ♦ |     | ♥ |     | ♥ |     | ♣  |    |   |     \n"     
  "| 6 |     | 3 |     | Q |     | 10 |    | ? |     \n"     
  "-----     -----     -----     -----     -----     \n" 
  "1. call\n"
  "2. raise\n"
  "3. check\n"
  "4. fold\n");   
}


TEST(displayTest, displayCardComboTest)
{
  ostringstream out;

  Display display;
  display.displayCardCombinations(out);

  EXPECT_EQ(out.str(), " ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | royal flush: straight flush from 10 to Ace.\n| 10 ||  J ||  Q ||  K ||  A |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | straight flush: straight, but all cards are the same suit.\n|  5 ||  6 ||  7 ||  8 ||  9 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA7  || \xE2\x99\xA2  | four of a kind: four of the same card, highest value wins in a tie.\n|  A ||  A ||  A ||  A ||  2 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA7  || \xE2\x99\xA2  | full house: 3 of a kind + 2 of a kind, highest 3 of a kind wins in a tie.\n|  A ||  A ||  A ||  K ||  K |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | flush: 5 cards of the same suit, highest card wins in a tie.\n|  2 ||  4 ||  6 ||  8 ||  K |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | straight: 5 cards in order but not of the same suit.\n|  5 ||  6 ||  7 ||  8 ||  9 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | three of a kind: 3 of a kind, highest card wins in a tie.\n|  A ||  A ||  A ||  2 ||  7 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | two pair: 2 sets of pairs.\n|  K ||  K ||  Q ||  Q ||  J |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | pair: 2 of a kind, highest card wins in a tie.\n|  A ||  A ||  9 ||  8 ||  7 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | high card: no combination, only a single high ranked card\n|  A ||  8 ||  6 ||  4 ||  2 |\n ----  ----  ----  ----  ----\nq) back to menu \n");
}

TEST(displayTest, displaySettingsTest)
{
  ostringstream out;
  Display display;
  display.displaySettings(out);
  ASSERT_EQ(out.str(), "-------------- SETTINGS -----------------\n1) Change player count\n2) Change starting chips\n3) Change big blind amount\n4) Change small blind amount\n5) Change number of rounds\nq) Save and exit\n----------------------------------------\n");

}

TEST(displayTest, displayCardRankingsTest)
{
  ostringstream out;
  Display display;
  display.displayCardRankings(out);
  EXPECT_EQ(out.str(), "The card rankings are displayed below, from weakest to strongest: \n2\n3\n4\n5\n6\n7\n8\n9\n10\nJ (jack)\nQ (queen)\nK (king)\nA (ace)\n* Note that in Texas Hold' em, all suits are equally ranked\nq) back to menu \n");
}



TEST(displayTest, displayMenuTest)
{
  ostringstream out; 
  Display display; 
  display.displayMenu(out);
  EXPECT_EQ(out.str(),
    "-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\n7) Load From Save\nq) Quit\nEnter an option\n-------------------------------------------\n");
}

TEST(displayTest, displayGameOverTest)
{
  ostringstream out;

  Display display;
  display.displayGameOver(out);

  EXPECT_EQ(out.str(), "POKER++ \nThanks for playing! \n :3");
}

TEST(displayTest, displayBetweenTurnsTest)
{
  ostringstream out;
  Display display;
  Player* player = new Player();
  player->setName("chloe");
  display.displayBetweenTurns(out, player);
  EXPECT_EQ(out.str(),
    "chloe's turn!\n"
    "Enter anything to continue\n");
}


TEST(displayTest, displayRulesTest)
{
  ostringstream out;
  Display displayru;
  displayru.displayRules(out);
  EXPECT_EQ(out.str(),
    "\nOverview: \n" 
    "Each player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. \n"
    "*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. \n"
    "The objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards\n"
    "\nTexas Hold' em - in depth: \n"
    "At the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will be \nthe small blind, then the player to their left will be the big blind, which is double the value of the small blind. "
    "2 hole cards will be dealt to each player. \nThe starting player may now chooute to fold, call or raise. \n"
    "   fold: discard hand and put no more chips in the pot\n"
    "   call: add the call amount to the pot\n"
    "   raise: increase the call amount for the current round\n"
    "Following this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player \nhas folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. \n"
    "Each player will again chooute to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again chooute \nto fold, call or raise."
    "Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised.\n"
    "At this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest \nranked combination wins the pot.\n"
    "If players tie, the highest hole card that isn't a part of their best hand is used to decide the winner.\n"
    "q) back to menu \n");

}

TEST(DisplayTest, displayGameStatusTest)
{
  Player* player = new Player();
  player -> setName("chloe");
  player -> setBalance(200);

  // set up the hand with some cards
  
  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Two of Spades", "♠");
  Card* card3 = new Card(11, "Diamonds", "Three of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Five of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Ten of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Nine of Hearts", "♥");
  Card* card7 = new Card(10, "Clubs", "Eight of Clubs", "♣");
  
  player->getHand()->addCard(card1);
  player->getHand()->addCard(card2);
 
  vector<Card*> cards = {card1, card2};
  vector<Card*> communityCards = {card3, card4, card5, card6, card7};
  // //set up the pot
  Pot* pot = new Pot();
  pot->addToPot(100);

  ostringstream out; 
  Display displayStats;

  displayStats.displayGameStatus(out, communityCards, player, pot);

  EXPECT_EQ(out.str(),
    "chloe, it's your turn!\n"
    "You have 200 chips\n"
    "Pot: 100\n"
    "Your hand:\n"

    "-----     -----     \n"
    "| ♠ |     | ♠ |     \n"
    "| A |     | 5 |     \n"
    "-----     -----     \n"
    "Community cards:\n"
    "-----     -----     -----     -----     -----     \n"
    "| ♦ |     | ♦ |     | ♥ |     | ♥ |     | ♣  |    \n"
    "| J |     | 6 |     | 3 |     | Q |     | 10 |    \n"
    "-----     -----     -----     -----     -----     \n"
    "1. call\n"
    "2. raise\n"
    "3. check\n"
    "4. fold\n");
}


TEST(displayTest, displayRoundHistory)
{
  ostringstream out;
  Display* displayRoundHist = new Display();
  vector<vector<string>> roundHistory = {
    {"chloe", "$100", "full house"},
    {"david", "$150", "straight"},
    {"kevin", "$200", "royal flush"},
    {"jason", "$300", "four of a kind"}
  };
  displayRoundHist->displayRoundHistory(out, roundHistory);

  EXPECT_EQ(out.str(),
  "ROUND      WINNER NAME      POT SIZE      COMBO NAME\n"  
  "1         chloe         $100         full house\n"
  "2         david         $150         straight\n"
  "3         kevin         $200         royal flush\n"
  "4         jason         $300         four of a kind\n");
  



}


TEST(displayTest, displayWinnerTest)
{
  ostringstream out;
  Display display;

  Player* player1 = new Player("Kevin", 500, false);
  Player* player2 = new Player("Jason", 500, false);

  Card* winningCard1 = new Card(1, "Hearts", "Ace of Hearts", "♥");
  Card* winningCard2 = new Card(5, "Hearts", "Five of Hearts", "♥");

  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");


  Card* card3 = new Card(11, "Diamonds", "Queen of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Three of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "King of Hearts", "♥");
  Card* card7 = new Card(10, "Hearts", "Jack of Hearts", "♥");
  
  player1->getHand()->addCard(winningCard1);
  player1->getHand()->addCard(winningCard2);

  player2->getHand()->addCard(card1);
  player2->getHand()->addCard(card2);
 
  vector<Card*> communityCards{card3, card4, card5, card6, card7};
  // //set up the pot
  Pot* pot = new Pot();
  pot->addToPot(100);

  RoundHandler* roundHandler = new RoundHandler();
  roundHandler->setCards(communityCards);

  vector<Player*> *players = new vector<Player*>{player1, player2};
  vector<Player*> winners = roundHandler->lookForWinner(players);

  display.displayWinner(out, winners, pot);
  EXPECT_EQ(out.str(),
    "Kevin won 100 chips with a Flush!\n");
  EXPECT_EQ(player1->getBalance(), 500);
  EXPECT_EQ(player2->getBalance(), 500);

}

TEST(displayTest, displayTieWinnersTest)
{
  ostringstream out;
  Display display;

  Player* player1 = new Player("Kevin", 500, false);
  Player* player2 = new Player("Jason", 500, false);

  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Two of Spades", "♠");
  Card* card3 = new Card(11, "Diamonds", "Three of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Five of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Ten of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Nine of Hearts", "♥");
  Card* card7 = new Card(10, "Clubs", "Eight of Clubs", "♣");
  
  player1->getHand()->addCard(card1);
  player1->getHand()->addCard(card2);
  player2->getHand()->addCard(card1);
  player2->getHand()->addCard(card2);
 
  vector<Card*> cards = {card1, card2};
  vector<Card*> communityCards = {card3, card4, card5, card6, card7};
  // //set up the pot
  Pot* pot = new Pot();
  pot->addToPot(100);

  player1->getHand()->calculateStrength(communityCards);
  player2->getHand()->calculateStrength(communityCards);


  RoundHandler* roundHandler = new RoundHandler();

  vector<Player*> *playerList = new vector<Player*>();

  playerList->push_back(player1);
  playerList->push_back(player2);

  vector<Player*> winners = roundHandler->lookForWinner(playerList);


  display.displayWinner(out, winners, pot);
  EXPECT_EQ(out.str(),
    "Kevin, and Jason won a split pot of 50 each!\n");
  EXPECT_EQ(player1->getBalance(), 500);
  EXPECT_EQ(player2->getBalance(), 500);

}

TEST(displayTests, botOutputTest)
{
  Bot* testBot = new Bot("Bot Kevin", 500);

  ASSERT_TRUE(testBot->randomAction());

  delete testBot;
}

TEST(utilityTest, clearScreenTest)
{
  Utility::clearScreen();
  
}


// Player Test Suite

TEST(playerTests, playerConstructorTest) {
  Player* testPlayer = new Player("Jason", 100, false);
  EXPECT_EQ(testPlayer->getBalance(), 100);
  EXPECT_EQ(testPlayer->getName(), "Jason");
  EXPECT_FALSE(testPlayer->getIsBot());

  delete testPlayer;
}

TEST(playerTests, playerBalanceTest) {
  Player* testPlayer = new Player("Jason", 1000, false);

  testPlayer->setBalance(800);
  EXPECT_EQ(testPlayer->getBalance(), 800);

  testPlayer->addToBalance(500);
  EXPECT_EQ(testPlayer->getBalance(), 1300);

  delete testPlayer;
}

TEST(playerTests, playerHandConstructorTest) {
  Player* testPlayer = new Player("Kevin", 0, false);
  EXPECT_EQ(testPlayer->getBalance(), 0);
  EXPECT_EQ(testPlayer->getHand()->getStrength(), 0);

  delete testPlayer;
}

TEST(playerTests, isPlayingTest) {
  Player* testPlayer = new Player("Kevin", 0, false);
  EXPECT_TRUE(testPlayer->getIsPlaying());

  testPlayer->setIsPlaying(false);
  EXPECT_FALSE(testPlayer->getIsPlaying());

  delete testPlayer;
}

TEST(playerTests, currentBetTests) {
  Player* testPlayer = new Player("Kevin", 500, false);

  EXPECT_EQ(testPlayer->getBalance(), 500);
  EXPECT_EQ(testPlayer->getCurrentBet(), 0);
  
  testPlayer->setCurrentBet(250);
  EXPECT_EQ(testPlayer->getCurrentBet(), 250);

  testPlayer->clearCurrentBet();
  EXPECT_EQ(testPlayer->getCurrentBet(), 0);

  delete testPlayer;
}


TEST(playerTests, resetHandTest) {
  Player* testPlayer = new Player("Kevin", 500, false);

  Card* card1 = new Card(11, "Hearts", "Jack of Hearts", "♥");
  Card* card2 = new Card(12, "Diamonds", "Queen of Diamonds", "♦");

  testPlayer->getHand()->addCard(card1);
  testPlayer->getHand()->addCard(card2);

  EXPECT_EQ(testPlayer->getHand()->getHand().at(0), card1);
  EXPECT_EQ(testPlayer->getHand()->getHand().at(1), card2);

  testPlayer->resetHand();

  EXPECT_EQ(testPlayer->getHand()->getHand().size(), 0);


  delete testPlayer;
}

// Pot Test Suite

TEST(PotTest, potConstructorTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);

  delete testPot;
}

TEST(PotTest, setHighestBetTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);

  testPot->setHighestBet(300);
  EXPECT_EQ(testPot->getHighestBet(), 300);

  delete testPot;
}

TEST(PotTest, resetPotTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);

  testPot->setHighestBet(300);
  EXPECT_EQ(testPot->getHighestBet(), 300);

  testPot->resetPot();

  ASSERT_EQ(testPot->getHighestBet(), 0);
  ASSERT_EQ(testPot->getPot(), 0);

  delete testPot;
}

TEST(PotTest, addToPotTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);
  testPot->addToPot(100);
  EXPECT_EQ(testPot->getPot(), 100);

  delete testPot;
}

// Settings Test Suite

TEST(settingsTest, defaultSettingsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_EQ(testSettings->getNumPlayers(), 2);
  EXPECT_EQ(testSettings->getStartingChips(), 1000);
  EXPECT_EQ(testSettings->getBigBlindAmt(), 50);
  EXPECT_EQ(testSettings->getLittleBlindAmt(), 25);
  EXPECT_EQ(testSettings->getNumOfRounds(), 5);
  delete testSettings;
}


TEST(settingsTest, setGetNumOfRoundsTest)
{
  Settings* testSettings = new Settings();

  testSettings->setNumOfRounds(35);

  ASSERT_EQ(testSettings->getNumOfRounds(), 35);

  delete testSettings;
}


TEST(settingsTest, setGetLittleBigBlindTest)
{
  Settings* testSettings = new Settings();

  testSettings->setLittleBlindAmt(750);
  testSettings->setBigBlindAmt(1500);

  ASSERT_EQ(testSettings->getLittleBlindAmt(), 750);
  ASSERT_EQ(testSettings->getBigBlindAmt(), 1500);

  delete testSettings;
}

TEST(settingsTest, setGetPlayersTest)
{
  Settings* testSettings = new Settings();

  testSettings->setNumPlayers(4);
  EXPECT_EQ(testSettings->getNumPlayers(), 4);
  delete testSettings;
}

TEST(settingsTest, tooLittlePlayersTest)
{
  Settings* testSettings = new Settings();

  unsigned int playerOverflow = 1;
  EXPECT_DEATH(testSettings->setNumPlayers(playerOverflow), "Tried setting to less than 2 players");
  delete testSettings;
}

TEST(settingsTest, tooManyPlayersTest)
{
  Settings* testSettings = new Settings();

  unsigned int playerOverflow = 8;
  EXPECT_DEATH(testSettings->setNumPlayers(playerOverflow), "Tried setting to more than 7 players");
  delete testSettings;
}

TEST(settingsTest, setGetStartingChipsTest)
{
  Settings* testSettings = new Settings();

  testSettings->setStartingChips(40000);
  EXPECT_EQ(testSettings->getStartingChips(), 40000);
  delete testSettings;
}

TEST(settingsTest, tooManyStartingChipsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_DEATH(testSettings->setStartingChips(50001), "Only up to 50000 starting chips");
  delete testSettings;
}

TEST(settingsTest, tooLittleStartingChipsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_DEATH(testSettings->setStartingChips(0), "Must have at least one starting chip");
  delete testSettings;
}


// Hand Rank Test Suite
class StubHand {
    private: 
      vector<Card*> hand;
    public:
      StubHand(vector<Card*> testCards) {

        for (int i = 0; i < testCards.size(); i++)
        {
          hand.push_back(testCards[i]);
        }
      }
      vector<Card*> getCurrentHand() const {
        return this->hand;
      }
};

TEST(HandRankTests, hasHighCardTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(3, "Spades", "Three of Spades", "♠");
    Card* card3 = new Card(9, "Hearts", "Nine of Hearts", "♥");
    Card* card4 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card5 = new Card(8, "Spades", "Eight of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 9);
}

TEST(HandRankTests, hasHighCardTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};

    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 10);
}

TEST(HandRankTests, hasPairTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card5 = new Card(8, "Spades", "Eight of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 55);
}

TEST(HandRankTests, hasPairTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(9, "Hearts", "Nine of Hearts", "♥");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 59);
}

TEST(HandRankTests, hasTwoPairTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card3 = new Card(1, "Hearts", "One of Hearts", "♥");
    Card* card4 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card5 = new Card(8, "Spades", "Eight of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 105);
}

TEST(HandRankTests, hasTwoPairTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(9, "Hearts", "Nine of Hearts", "♥");
    Card* card3 = new Card(10, "Hearts", "Ten of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 110);
}

TEST(HandRankTests, hasThreeOfKindTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(1, "Clubs", "One of Clubs", "♣");
    Card* card3 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card4 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card5 = new Card(1, "Hearts", "One of Hearts", "♥");

    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 151);
}

TEST(HandRankTests, hasThreeOfKindTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(5, "Hearts", "Five of Hearts", "♥");
    Card* card3 = new Card(9, "Hearts", "Nine of Hearts", "♥");
    Card* card4 = new Card(5, "Clubs", "Five of Clubs", "♣");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 155);
}

TEST(HandRankTests, hasStraightTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(2, "Clubs", "Two of Clubs", "♣");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(4, "Spades", "Four of Spades", "♠");
    Card* card5 = new Card(5, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 205);
}

TEST(HandRankTests, hasStraightTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(6, "Hearts", "Six of Hearts", "♥");
    Card* card3 = new Card(7, "Hearts", "Seven of Hearts", "♥");
    Card* card4 = new Card(8, "Clubs", "Eight of Clubs", "♣");
    Card* card5 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card6 = new Card(11, "Spades", "Jack of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 209);
}

TEST(HandRankTests, hasFullHouse) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(2, "Clubs", "Two of Clubs", "♣");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
    Card* card5 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card6 = new Card(5, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 308);
}

TEST(HandRankTests, hasFullHouseTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(5, "Hearts", "Five of Hearts", "♥");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(5, "Clubs", "Five of Clubs", "♣");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(11, "Spades", "Jack of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 307);
}

TEST(HandRankTests, hasFourOfKind) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(2, "Clubs", "Two of Clubs", "♣");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(2, "Diamonds", "Two of Diamonds", "♦");
    Card* card5 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card6 = new Card(5, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 352);
}

TEST(HandRankTests, hasFourOfKindTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(5, "Hearts", "Five of Hearts", "♥");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(5, "Clubs", "Five of Clubs", "♣");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(5, "Diamonds", "Five of Diamonds", "♦");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    ASSERT_EQ(testHand->getStrength(), 355);
}

TEST(HandRankTests, hasStraightFlushTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(3, "Spades", "Three of Spades", "♠");
    Card* card3 = new Card(4, "Spades", "Four of Spades", "♠");
    Card* card4 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card5 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card6 = new Card(8, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 406);
}


TEST(HandRankTests, hasStraightFlushTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Diamonds", "Five of Diamonds", "♦");
    Card* card2 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
    Card* card3 = new Card(7, "Diamonds", "Seven of Diamonds", "♦");
    Card* card4 = new Card(8, "Diamonds", "Eight of Diamonds", "♦");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(9, "Diamonds", "Nine of Diamonds", "♦");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    ASSERT_EQ(testHand->getStrength(), 409);
}


TEST(HandRankTests, hasRoyalFlushTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(3, "Spades", "Three of Spades", "♠");
    Card* card3 = new Card(10, "Diamonds", "Ten of Diamonds", "♦");
    Card* card4 = new Card(11, "Diamonds", "Jack of Diamonds", "♦");
    Card* card5 = new Card(12, "Diamonds", "Queen of Diamonds", "♦");
    Card* card6 = new Card(13, "Diamonds", "King of Diamonds", "♦");
    Card* card7 = new Card(14, "Diamonds", "Ace of Diamonds", "♦");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);
    testCards.push_back(card7);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 464);
}

TEST(HandRankTests, hasRoyalFlushTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card2 = new Card(10, "Diamonds", "Ten of Diamonds", "♦");
    Card* card3 = new Card(11, "Diamonds", "Jack of Diamonds", "♦");
    Card* card4 = new Card(12, "Diamonds", "Queen of Diamonds", "♦");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(13, "Diamonds", "King of Diamonds", "♦");
    Card* card7 = new Card(14, "Diamonds", "Ace of Diamonds", "♦");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6,card7};
    
    testHand->calculateStrength(communityCards);
    
    ASSERT_EQ(testHand->getStrength(), 464);
}

// Hand Test Suite

TEST(handTests, emptyHandTest)
{
  Hand* testHand = new Hand();

  vector<string> cards;
  EXPECT_EQ(testHand->getCardNames(), cards);
  delete testHand;
}

TEST(handTests, handConstructorTest) {
  Card* jack = new Card(11, "Spades", "Jack of Spades", "♠");
  Card* queen = new Card(12, "Heart", "Queen of Hearts", "♥");
  vector<Card*> jackQueen = {jack, queen};



  Hand *testHand = new Hand(jackQueen);

  EXPECT_EQ(testHand->getCard(0), jack);
  EXPECT_EQ(testHand->getCard(1), queen);
  delete testHand;
}

TEST(handTests, getHandFilledHandTest)
{
  Hand* testHand = new Hand();
  
  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(2, "Spades", "Two of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> cards = {card1, card2};
  EXPECT_EQ(testHand->getHand(), cards);
  delete testHand;
}

TEST(handTests, expectDeathMaxHandTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
  
  testHand->addCard(card1);
  testHand->addCard(card2);


  Card* overflowCard = new Card(5, "Hearts", "Five of Hearts", "♥");

  EXPECT_DEATH(testHand->addCard(overflowCard), "Tried adding card to a hand of 2 cards, which is the max");
  delete testHand;
}

TEST(handTests, ThreeCardHandNameTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  // test->Hand
  vector<string> cards;
  cards.push_back(card1->getName());
  cards.push_back(card2->getName());

  EXPECT_EQ(testHand->getCardNames(), cards);
  delete testHand;
}

TEST(handTests, clearHandTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> cards;

  testHand->clearHand();

  EXPECT_EQ(testHand->getHand(), cards);
  delete testHand;
}

TEST(handTests, getStrengthTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(10, "Spades", "Ten of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> emptyCommunityCards;

  testHand->calculateStrength(emptyCommunityCards);
  EXPECT_EQ(testHand->getStrength(), 10);
  EXPECT_EQ(testHand->getComboName(), "High Card");

  delete testHand;
}

TEST(handTests, getPairTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(10, "Spades", "Ten of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> communityCards;
  Card* card3 = new Card(11, "Diamonds", "Jack of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Three of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Queen of Hearts", "♥");
  Card* card7 = new Card(7, "Hearts", "Seven of Hearts", "♥");

  communityCards.push_back(card3);
  communityCards.push_back(card4);
  communityCards.push_back(card5);
  communityCards.push_back(card6);
  communityCards.push_back(card7);

  testHand->calculateStrength(communityCards);
  EXPECT_EQ(testHand->getStrength(), 53);
  EXPECT_EQ(testHand->getComboName(), "Pair");

  delete testHand;
}


TEST(handTests, getTwoPairTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(10, "Spades", "Ten of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> communityCards;
  Card* card3 = new Card(11, "Diamonds", "Jack of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Three of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Queen of Hearts", "♥");
  Card* card7 = new Card(10, "Hearts", "Ten of Hearts", "♥");

  communityCards.push_back(card3);
  communityCards.push_back(card4);
  communityCards.push_back(card5);
  communityCards.push_back(card6);
  communityCards.push_back(card7);

  testHand->calculateStrength(communityCards);
  EXPECT_EQ(testHand->getStrength(), 110);
  EXPECT_EQ(testHand->getComboName(), "Two Pair");

  delete testHand;
}

// RoundHandler Test Suite

TEST(roundHandlerTests, startRoundTest)
{
    
    ifstream testInput("tests/testInputs/startRoundTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\n"
    );

    vector<Player*> expectedWinners{testPlayer1, testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Kevin");
    EXPECT_EQ(winners.at(1)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(roundHandlerTests, startRoundFoldTest)
{
    
    ifstream testInput("tests/testInputs/startRoundFoldTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has folded!\n");

    vector<Player*> expectedWinners{testPlayer1};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Kevin");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(roundHandlerTests, startEarlyRoundFoldTest)
{
    
    ifstream testInput("tests/testInputs/startRoundEarlyFoldTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has folded!\n");

    vector<Player*> expectedWinners{testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(roundHandlerTests, startLateRoundFoldTest)
{
    
    ifstream testInput("tests/testInputs/startRoundLateFoldTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has folded!\n");

    vector<Player*> expectedWinners{testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(roundHandlerTests, startRoundRaiseTest)
{
    
    ifstream testInput("tests/testInputs/startRoundRaiseTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nWhat would you like to raise your bet to?\nNew highest bet: 525\n0\nJason has raise to 525\nThe current pot amount is 550.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 550\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 0 chips\nPot: 1000\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 1000.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 0 chips\nPot: 1000\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 0 chips\nPot: 1000\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 1000.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 0 chips\nPot: 1000\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 0 chips\nPot: 1000\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 1000.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 0 chips\nPot: 1000\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\n");

    vector<Player*> expectedWinners{testPlayer1, testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Kevin");
    EXPECT_EQ(winners.at(1)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}

// Game Handler Test Suite

TEST(GameHandlerTests, AddPlayerIndividualTest) {
    GameHandler* gameHandler = new GameHandler();

    gameHandler->addPlayer("chloe", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "chloe");
    delete gameHandler;
}

TEST(GameHandlerTests, AddMultiplePlayersTest) {
    GameHandler* gameHandler = new GameHandler();

    gameHandler->addPlayer("chloe", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "chloe");

    gameHandler->addPlayer("kevin", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "kevin");

    gameHandler->addPlayer("jason", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "jason");
    delete gameHandler;
}

TEST(GameHandlerTests, AddPlayerOverLimitTest) {
    GameHandler* gameHandler = new GameHandler();

    gameHandler->addPlayer("chloe", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "chloe");

    gameHandler->addPlayer("kevin", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "kevin");

    gameHandler->addPlayer("jason", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "jason");

    gameHandler->addPlayer("david", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "david");

    gameHandler->addPlayer("emily", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "emily");

    gameHandler->addPlayer("nagi", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "nagi");

    gameHandler->addPlayer("gojo", false);
    ASSERT_EQ(gameHandler->getPlayerList().back()->getName(), "gojo");

    ASSERT_DEATH(gameHandler->addPlayer("gency", false), "Seven players maximum");
    delete gameHandler;
}
TEST(GameHandlerTests, BotGameTest) {
    ifstream testInput ("tests/testInputs/BotGameTestInput.txt");
    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    ostringstream out;
    GameHandler* gameHandler = new GameHandler();

    // gameHandler->addPlayer("chloe", false);
    // gameHandler->addPlayer("Kevin Bot", true);

    // EXPECT_EQ(gameHandler->settings->getNumPlayers(), 2);
    // EXPECT_EQ(gameHandler->playerList->back()->getName(), "Bot Kevin");
    // EXPECT_EQ(gameHandler->playerList->front()->getName(), "chloe");

    gameHandler->runGame(testInput, out);
    // gameHandler->gameSetup(testInput, out, true);
    // cout << out.str() << endl;
    EXPECT_EQ(out.str(), "-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\nEnter player username: \nBot Kevin has called!\nThe current pot amount is 100.\n\nkevin's turn!\nEnter anything to continue\nkevin, it's your turn!\nYou have 950 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA5 |     \n| 7 |     | J |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nkevin has folded!\nBot Kevin won 100 chips with a High Card!\nRound 1 complete!\nWould you like to continue playing?\n1. yes\n2. no\n-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\n");

    delete gameHandler;
    // EXPECT_EQ(out.str(),
    // "-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\nEnter player username: \nBot Kevin has called!\nThe current pot amount is 100.\n\nkevin's turn!\nEnter anything to continue\nkevin, it's your turn!\nYou have 950 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA5 |     | \xE2\x99\xA6 |     \n| 8 |     | 7 |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nkevin has folded!\nBot Kevin won 100 chips with a High Card!\nRound 1 complete!\nWould you like to continue playing?\n1. yes\n2. no\n-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\n");
 
}

TEST(GameHandlerTests, ChangeNumberOfPlayers) {
    ostringstream out;
    GameHandler* gameHandler = new GameHandler();
    // simulate user input 
    ifstream testInput("tests/testInputs/settingsNumPlayersTest.txt");
    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;

    gameHandler->settingsMenu(testInput, out);
    // gameHandler->runGame(testInput, out);
    
    EXPECT_EQ(out.str(),
    "-------------- SETTINGS -----------------\n"
    "1) Change player count\n"
    "2) Change starting chips\n"
    "3) Change big blind amount\n"
    "4) Change small blind amount\n"
    "5) Change number of rounds\n"
    "q) Save and exit\n"
    "----------------------------------------\n"
    "2 to 7 players allowed\n"
    "Enter number of players: \n"
    "-------------- SETTINGS -----------------\n"
    "1) Change player count\n"
    "2) Change starting chips\n"
    "3) Change big blind amount\n"
    "4) Change small blind amount\n"
    "5) Change number of rounds\n"
    "q) Save and exit\n"
    "----------------------------------------\n");
    EXPECT_EQ(gameHandler->getSettings()->getNumPlayers(), 3);

    delete gameHandler;
}

TEST(GameHandlerTests, ruleDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/ruleDisplayTestInput.txt");
  ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;

  gameHandler->rulesMenu(testInput, out);
  EXPECT_EQ(out.str(),
  "\nOverview: \nEach player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. \n*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. \nThe objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards\n\nTexas Hold' em - in depth: \nAt the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will be \nthe small blind, then the player to their left will be the big blind, which is double the value of the small blind. 2 hole cards will be dealt to each player. \nThe starting player may now chooute to fold, call or raise. \n   fold: discard hand and put no more chips in the pot\n   call: add the call amount to the pot\n   raise: increase the call amount for the current round\nFollowing this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player \nhas folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. \nEach player will again chooute to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again chooute \nto fold, call or raise.Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised.\nAt this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest \nranked combination wins the pot.\nIf players tie, the highest hole card that isn't a part of their best hand is used to decide the winner.\nq) back to menu \n");
  
  delete gameHandler;
}

TEST(GameHandlerTests, cardRankingDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/cardRankDisplayTestInput.txt");
  ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;

  
  gameHandler->cardRankingMenu(testInput, out);
  EXPECT_EQ(out.str(),
  "The card rankings are displayed below, from weakest to strongest: \n2\n3\n4\n5\n6\n7\n8\n9\n10\nJ (jack)\nQ (queen)\nK (king)\nA (ace)\n* Note that in Texas Hold' em, all suits are equally ranked\nq) back to menu \n");

  delete gameHandler;
}

TEST(GameHandlerTests, cardComboDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/cardComboDisplayTestInput.txt");
  ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
  gameHandler->cardComboMenu(testInput, out);
  EXPECT_EQ(out.str(),
  " ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | royal flush: straight flush from 10 to Ace.\n| 10 ||  J ||  Q ||  K ||  A |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | straight flush: straight, but all cards are the same suit.\n|  5 ||  6 ||  7 ||  8 ||  9 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA7  || \xE2\x99\xA2  | four of a kind: four of the same card, highest value wins in a tie.\n|  A ||  A ||  A ||  A ||  2 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA7  || \xE2\x99\xA2  | full house: 3 of a kind + 2 of a kind, highest 3 of a kind wins in a tie.\n|  A ||  A ||  A ||  K ||  K |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | flush: 5 cards of the same suit, highest card wins in a tie.\n|  2 ||  4 ||  6 ||  8 ||  K |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | straight: 5 cards in order but not of the same suit.\n|  5 ||  6 ||  7 ||  8 ||  9 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | three of a kind: 3 of a kind, highest card wins in a tie.\n|  A ||  A ||  A ||  2 ||  7 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | two pair: 2 sets of pairs.\n|  K ||  K ||  Q ||  Q ||  J |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | pair: 2 of a kind, highest card wins in a tie.\n|  A ||  A ||  9 ||  8 ||  7 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | high card: no combination, only a single high ranked card\n|  A ||  8 ||  6 ||  4 ||  2 |\n ----  ----  ----  ----  ----\nq) back to menu \n");

  delete gameHandler;
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
