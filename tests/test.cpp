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

// Player Test Suite

TEST(playerTests, playerConstructorTest) {
  Player* testPlayer = new Player("Jason", 100);
  EXPECT_EQ(testPlayer->getBalance(), 100);
  EXPECT_EQ(testPlayer->getName(), "Jason");
}

TEST(playerTests, playerBalanceTest) {
  Player* testPlayer = new Player("Jason", 1000);

  testPlayer->setBalance(800);
  EXPECT_EQ(testPlayer->getBalance(), 800);

  testPlayer->addToBalance(500);
  EXPECT_EQ(testPlayer->getBalance(), 1300);
}

TEST(playerTests, playerHandConstructorTest) {
  Player* testPlayer = new Player("Kevin", 0);
  EXPECT_EQ(testPlayer->getBalance(), 0);
  EXPECT_EQ(testPlayer->getHand()->getStrength(), 0);
}

TEST(playerTests, isPlayingTest) {
  Player* testPlayer = new Player("Kevin", 0);
  EXPECT_TRUE(testPlayer->getIsPlaying());

  testPlayer->setIsPlaying(false);
  EXPECT_FALSE(testPlayer->getIsPlaying());
}

TEST(playerTests, currentBetTests) {
  Player* testPlayer = new Player("Kevin", 500);

  EXPECT_EQ(testPlayer->getBalance(), 500);
  EXPECT_EQ(testPlayer->getCurrentBet(), 0);
  
  testPlayer->setCurrentBet(250);
  EXPECT_EQ(testPlayer->getCurrentBet(), 250);

  testPlayer->clearCurrentBet();
  EXPECT_EQ(testPlayer->getCurrentBet(), 0);
  
}

// Card Test Suite

TEST(CardTests, typicalCardTest) {
  Card* testCard = new Card(3, "Spades", "Three of Spades", "♠");

  EXPECT_EQ(testCard->getRank(), 3);
  EXPECT_EQ(testCard->getSuit(), "Spades");
  EXPECT_EQ(testCard->getName(), "Three of Spades");
}

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
    Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 9);
}


TEST(HandRankTests, hasPairTest) {

    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 9);
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


// Pot Test Suite

TEST(PotTest, addToPotTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);
  testPot->addToPot(100);
  EXPECT_EQ(testPot->getPot(), 100);
}

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


// Hand Test Suite

TEST(handTests, emptyHandTest)
{
  Hand* testHand = new Hand();

  vector<string> cards;
  EXPECT_EQ(testHand->getCardNames(), cards);
}

TEST(handTests, handConstructorTest) {
  Card* jack = new Card(11, "Spades", "Jack of Spades", "♠");
  Card* queen = new Card(12, "Heart", "Queen of Hearts", "♥");
  vector<Card*> jackQueen = {jack, queen};



  Hand *testHand = new Hand(jackQueen);

  EXPECT_EQ(testHand->getCard(0), jack);
  EXPECT_EQ(testHand->getCard(1), queen);
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
}

TEST(handTests, expectDeathMaxHandTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
  
  testHand->addCard(card1);
  testHand->addCard(card2);


  Card* overflowCard = new Card(5, "Hearts", "Five of Hearts", "♥");

  // EXPECT_DEATH(testHand->addCard(overflowCard), "Tried adding card to a hand of 2 cards, which is the max");
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
}

TEST(settingsTest, setGetPlayersTest)
{
  Settings* testSettings = new Settings();

  testSettings->setNumPlayers(4);
  EXPECT_EQ(testSettings->getNumPlayers(), 4);
}

TEST(settingsTest, tooLittlePlayersTest)
{
  Settings* testSettings = new Settings();

  unsigned int playerOverflow = 1;
  EXPECT_DEATH(testSettings->setNumPlayers(playerOverflow), "Tried setting to less than 2 players");
}

TEST(settingsTest, tooManyPlayersTest)
{
  Settings* testSettings = new Settings();

  unsigned int playerOverflow = 8;
  EXPECT_DEATH(testSettings->setNumPlayers(playerOverflow), "Tried setting to more than 7 players");
}

TEST(settingsTest, setGetStartingChipsTest)
{
  Settings* testSettings = new Settings();

  testSettings->setStartingChips(40000);
  EXPECT_EQ(testSettings->getStartingChips(), 40000);
}

TEST(settingsTest, tooManyStartingChipsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_DEATH(testSettings->setStartingChips(50001), "Only up to 50000 starting chips");
}

TEST(settingsTest, tooLittleStartingChipsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_DEATH(testSettings->setStartingChips(0), "Must have at least one starting chip");
}

// Round Handler Test Suite

// TEST(roundHandlerTests, callTest)
// {
//   ostream os;
//   vector<Player*> testPlayers = {new Player("Kevin", 200), new Player("Jason", 300)};
//   // Player* testPlayer1 = new Player("Kevin", 200);
//   // Player* testPlayer2 = new Player("Jason", 300);

//   RoundHandler* testHandler = new RoundHandler(os, testPlayers);

//   // testHandler->
// }


// DISPLAY TESTS


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

    " ----\n"
    "| ♠ |\n"
    "| A |\n"
    " ----\n"
    "Community cards:"
    " ----\n"
    "| ♠ |\n"
    "| 2 |\n"
    " ----\n"
    "1. call\n"
    "2. raise\n"
    "3. check\n"
    "4. fold\n");
}

TEST(displayTest, displayMenuTest)
{
  ostringstream out; 
  Display display; 
  display.displayMenu(out);
  EXPECT_EQ(out.str(),
    "-------------- START MENU -----------------\n" 
    "1) Start game\n"
    "2) Settings\n" 
    "3) Rules\n" 
    "4) Card rankings\n" 
    "5) Card combinations\n"
    "q) Quit\n"
    "Enter an option\n"
    "-------------------------------------------\n");
}

TEST(displayTest, displayBetweenTurnsTest)
{
  ostringstream out;
  Display* displayTurns = new Display();
  Player* player = new Player();
  player->setName("chloe");
  displayTurns->displayBetweenTurns(out, player);
  EXPECT_EQ(out.str(),
    "chloe's turn\n"
    "Enter 1 to continue\n");
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

// COMBO NAME TEST

// TEST(handTests, getComboNameTest)
// {
//   Hand* hand = new Hand();
//   vector<Card*> &communityCards;

//   Card* card1 = new Card(3, "Spades", "Three of Spades");
//   Card* card2 = new Card(5, "Spades", "Five of Spades");
//   Card* card3 = new Card(10, "Spades", "Ten of Spades");

//   hand->addCard(card1);
//   hand->addCard(card2);
//   hand->addCard(card3);

//   hand->calculateStrength(communityCards);
//   EXPECT_EQ(hand->getComboName(), "High Card");

// }


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
