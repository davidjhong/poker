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
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/d93dbc78-6a24-4ad4-8864-e423ce038475)

![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/98fc0369-a62d-4660-be56-23cdbbf0815a)

## Class Diagram
The class diagram includes all the classes required to make the Poker game. GameHandler is essentially the start menu and will have options leading to the use of every other class. RoundHandler specifically takes use of the Pot, Player, and Deck classes, as they are subject to change every round. For each player's hand, there will also be a combination comparator to give the user an idea of whether they will win or not. There will be a bot class that inherits from Player. The Deck class is made up of the Card class which holds the suit and rank of each card. Display will take care of outputting everything.
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/112353499/f180b8bb-d792-43a2-82e7-c4a43ebe2d68)


## Class Diagram Updates
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/1668717c-0399-450c-a9aa-dce33f59bc9f)
The new diagram includes the creation of the MenuHandler class which improves the design of project by following the single-responsibility principle.  Originally, the GameHandler class handled all the menu functionality, which was very different from the rest of the class.  Instead, the MenuHandler class now takes control of the menu functionality and deals with the new additions to it, adhering to the open-closed principle.

The creation of the SettingsHandler changes the design to help follow the single responsibility principle by changing the responsibility to editing the settings class to the SettingsHandler class.  This helps separate the responsibility of changing the settings to the SettingsHandler class and keeps the Settings class's responsibility to store the different settings that the game will use. 

Another update was with the Hand class, which expanded upon the functions in Hand class so that Player class was separated from the Hand class to follow the single responsibility principle.  Rather than have a function in the Player class that handles the current Hand, the player class will store a Hand object that contains the cards within the player's Hand.  Then, the Hand can call its own functions that regarding the details in its own class.  This helped make the code more readable it separated the functions of the Hand class from the functions of the Player class, which was unclear at first.


>  
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
