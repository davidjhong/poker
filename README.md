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
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/d93dbc78-6a24-4ad4-8864-e423ce038475)
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/98fc0369-a62d-4660-be56-23cdbbf0815a)

## Class Diagram
![image](https://github.com/cs100/final-project-khe035-dhong050-jan058-ctang085/assets/53993828/6f91de1a-e260-4b38-8580-98c8119d7c90)
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
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
 
