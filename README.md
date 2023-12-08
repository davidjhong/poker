# Poker
 
Authors: [Kevin He](https://github.com/kevinhehee/) [Jason An](https://github.com/jasonan18/)
[David Hong](https://github.com/davidjhong)
[Chloe Tang](https://github.com/chloetang085)



## Project Description
 * We believe that translating the physicality of a card game into a program will be an interesting challenge, but also fun to code.  Dealing with the logic behind hand combinations and determining the winner and rankings will be an exciting challenge.
 * We will be using C++ for the backend of this project and CMake to build it.  The program will be in the CLI.
### Input/Output
 * Command line interface with cin and cout
 * Users will type in responses based on scenario
 * input: current hand of each player, number of chips, scores, number of chip bet, check / fold / raise,
 * output: player's cards (hands), declaration of winner, current chip amount per player, current pot amount, middle cards, ASCII art for visual representation of cards
### Features
 * Poker (texas holdem)
   * Uses a standard 52-card deck
   * General gameplay
     * 2 to 7 players
     * Each player starts with a select number of chips, chosen by the user. eg. the user wants everyone to start with 500 chips, everyone starts with 500 chips.
     * Each player receives two random cards from the deck and there will be five random cards in the community cards, which are hidden at first.  They are not allowed to view other players' cards but are able to see the cards in the community hand when they are revealed later.
       * A "hand" is the current pair of cards that a player has and this hand can be used along with the cards in the community hand to create a combination of cards.
       * The strength of the cards are rated with these rules: [Poker Hand Rating](https://www.primedope.com/official-poker-hands-ranking-chart/)
     * Two consecutive players each round of the poker start as the "big blind" and "little blind".  The big blind must enter a select number of chips, which is initially chosen by the user at the beginning of the game, and the small blind must enter half of that amount.
     * The round starts and in consecutive order, each player gets to decide whether they "call", "raise, "check", or "fold".
       * "Call" is to match the highest entry that another player has bet.  They must call, raise, or fold if another player has bet more chips than them.
       * "Fold" is when a player chooses to abandon what they have already bet and exit the round, losing the possibility of winning the entire pot.
       * "Raise" is to increase the highest entry that another player has bet, causing all other players to make the decision to match that bet(call), increase that bet(raise), or exit the round(fold).
       * "Check" is when a player has already bet the same amount as the highest bet and they choose to pass their turn and not raise the bet amount.
     * After each player has gotten their chance to call, raise, check, or fold, three of the community cards are revealed.
     * Each player gets to decide their choice of calling, raising, checking, or folding again.
     * One more community card is revealed.
     * Each player makes their final choice of calling, raising, checking, or folding.
     * The last community card is revealed.
     * Players can now choose to either reveal their hand or not show their hand
       * If a player reveals their hand, they are "in the running" to win the pot
       * If a player chooses not to reveal their hand, they exit the pot.
     * The player with the strongest hand wins the pot and receives all the chips in the pot.
     * A new round starts and play again until one person has all the chips in the game, or when players choose to exit the game.
  
   
## User Interface Specification

### Navigation Diagram
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/0f54a2e8-a31c-453c-aaf3-db04cd0e659d)

### Screen Layouts
Below are the representations of the stages of what the poker game will look like. It begins with the start menu, alongside what the settings screen would look like. Then, when a game is started, the players' names will be entered. The players' hands will be shown next to the pot, their balance, what their best combination is, and also the choice to call, raise, check, or fold. It will transition into the next player's turn, and the betting phases will go until the entire community hand is shown. At the end, the player's hands are compared to see whose combination is best and they will win the pot.
![Untitled presentation](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/979e9950-bd27-4d80-825e-9f3d6f849a8e)
![Untitled presentation (1)](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/9a60326a-cf03-4772-9796-72b719510778)
![Untitled presentation (2)](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/4b1b520b-7e06-4dbc-955b-7b413b12a0ca)
![Untitled presentation (3)](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/72a7d275-2835-46b0-b6de-8290e2a8542b)

## Class Diagram
The class diagram includes all the classes required to make the Poker game. GameHandler is essentially the start menu and will have options leading to the use of every other class. RoundHandler specifically takes use of the Pot, Player, and Deck classes, as they are subject to change every round. For each player's hand, there will also be a combination comparator to give the user an idea of whether they will win or not. There will be a bot class that inherits from Player. The Deck class is made up of the Card class which holds the suit and rank of each card. Display will take care of outputting everything.
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/f180b8bb-d792-43a2-82e7-c4a43ebe2d68)


## Class Diagram Updates
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/660d742a-9c57-437f-bf13-e1d11d5eec4d)

There was an update in the Hand class, which expanded upon the functions in Hand class so that Player class was separated from the Hand class to follow the single responsibility principle.  Rather than have a function in the Player class that handles the current Hand, the player class will store a Hand object that contains the cards within the player's Hand.  Then, the Hand can call its own functions that regarding the details in its own class.  This helped make the code more readable it separated the functions of the Hand class from the functions of the Player class, which was unclear at first.

One more update was with the Combination Comparator class, which has been converted into handRank class. handRank class now also follows the single responsibility principle, reflecting its own functions to compute the final rank instead of inheriting the functions from Hand class. This helped to identify the handRank class more thoroughly and readable, and made the class's purpose more clear as it was not definitive before. 

There are other functions being added to the Player and Pot classes in order to ensure they are compatible and work together. For instance, when players wish to raise, there needs to be something in order to keep track of what the highest bet in the current round is. Thus there is the addition of the int highestBet that will do that job. And also a clearPot() function to help the Roundhandler make sure that pot is reset to 0 every round.

The Display class functions were updated to reflect more similarly to what the screen layout looks like (shown above), with prompts for the players' turns as well as their cards and the community cards. In essence, it can now output players' hands followed by revealed community cards and unrevealed community cards. It outputs everything else in between turns, after the round and can now also output round history which shows the previous rounds played, their winners and their winning combos. 

The Bot class was also added to introduce a feature for single players to play against a bot. It returns a randomized number that corresponds to the action call or fold. This is an extra feature that enhances the user experience. 

The Utility class was added for the clearScreen() function that could clear the terminal in between players' turns so it is overall more tidy and usable. It also ensures that players cannot see other players' cards when it's their turn. 

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 ![1](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/bed5d283-0554-400e-b91a-4c46c88155c2)
 ![2](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/85fd85e8-bd02-40e8-b3ab-4bd87c44a656)
 ![3](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/22415770-5a64-44c6-afb0-d2a19457693f)
 ![4](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/b2f657f8-6f6c-45cf-a064-ab2541a5807c)
 ![5](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/02b84d85-8c0c-435b-9fc4-fe60835fba91)
 ![6](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/324a3a0a-39af-49b2-abfd-33b984c4b110)
 ![7](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/0f5b6cc7-c8b2-47ca-94f1-4325614fc084)
 ![8](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/f3774e93-34b0-49be-85f2-521bf563d908)
 ![9](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/5ace449b-f171-453f-8774-d504be3cb92d)
 ![10](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/60768753/68b243bc-125e-4c4b-8790-7b77ad299bf3)

 ## Installation/Usage
Requires g++ compiler

Installation:
```
cmake .
make poker
```

Usage:
```
./bin/poker
```

Instructions:

To save your game progress, after running ./bin/poker, start playing the game. 

After the round ends, you will be prompted the following: 

![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/3ee7cfb9-8441-4424-a705-d93612eda9e7)

From here, enter '3' and you will be prompted to enter a name for game progress to save: 

![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/fc30e0cd-8b05-41ca-95fd-f86cb7adf8d0)

Then you will be able to see your saved files in savefiles directory (/savefiles): 

![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/71929826-6d69-43df-993c-5dd4b84f0330)

Next time you run ./bin/poker again, if you want to continue playing from the last game choose the "Load From Save" option and enter the savefile name: 

![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/f51fbdf8-119e-47a3-b0f4-fbf1a5422ec6)


You will be able to play from the last game: 

![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/1d424bcd-e606-426e-ba1a-9297b3fbb006)

If you want to transfer a saved game to another computer, copy the content of the file in /savefiles you made to another computer's /savefiles: 

![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/88b050ea-763e-4ee7-98d6-8d6ab279ab01)

--> Copy the content in 'test', create a new file in /savefiles for another computer, and copy and paste the content in there. You will be able to load the new saved file when running the game.




 ## Testing
In the development of this project, we utilized Google Test for testing and verification of the functionalities of our game.  To check our code coverage, we used Gcov.  We were able to reach about 90% code coverage, however, due to the innate randomness of Poker, some portions of the code were not directly testable. To handle this, we used specified seeds in our tests to ensure consistency and examine different game scenarios.
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/49098da6-6c1a-4444-a45f-fb3c9be1ba7d)
In addition, we used Valgrind to confirm that there were no memory leaks within our program.  Shown below is Valgrind confirming that there are no memory leaks after testing through six rounds of Poker.
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/7ae84daf-8cd1-4a4d-9fd0-fc4fa087a274)


