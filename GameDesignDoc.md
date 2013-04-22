#Alien Invasion Game Design Document
##CSCI 102, PA 5

###Five Things:
  1. Coin
    * Player earns points by collecting coins.
    * Coins randomly appear on screen and do not move.
    * Coins look like gold coins.
![alt text](images/coin.png "Coin")
  2. Money Bag
    * Player will be temporarily unaffected by every item except for coins.
    * Money bags randomly move around screen.
    * Money bags look like sacks of money.
![alt text](images/money-bag.png "Money Bag")
  3. Alien
    * Alien kills player when they collide.
    * Aliens move in a straight, horizontal line.
    * Aliens look like an evil looking alien, along the lines of the picture below.
![alt text](images/alien.jpg "Alien")
  4. Doctor
    * Player gains a life after colliding with doctor.
    * Doctor bounces off top and bottom of screen, so he always appears to be moving diagonally.
    * Doctor looks like a doctor in a space suit. The image below does not have a space suit, but the doctor will.
![alt text](images/doctor.jpg "Doctor")
  5. Space Turtle
    * Slows down every part of game except for the player when hit.
    * Space turtle crawls along the bottom of the screen.
    * Space turtle looks like a turtle in a space suit.
![alt text](images/space_turtle.gif "Space Turtle")

###Game Play
Player uses keyboard to play game. The up arrow moves the player up. The down arrow moves the player down. The player will use a combination of mouse and keyboard inputs to perform actions such as starting the game and entering a name.

###Scoring
The score goes up by a point every time a coin is collected. This happens when the player and coin collids. The score cannot go down.

###Player Lives
Players start the game with three lives. After colliding with the Alien, the player loses a life. After colliding with the Doctor, the player gains a life. The player dies, or the game ends, when the player has lost all lives.

###User Interface Layout
  * Start button
    - If the game is paused, continues the game.
    - If the game is not paused, starts a new game, as long as a name has been entered in the name line edit.
  * Pause button
    - Pauses the game if a game is being played.
  * Quit button
    - Quits the game application.
  * Name entry box and label
    - A line edit where the user can enter their name.
    - Entering a name is required to start the game.
  * Help box and label.
    - Displays instructions and what each of the five items do.
  * Game output box
    -Displays the user's name, number of lives, points, and errors.
  * Game play scene
    - Game is actually implemented, played, and displayed here. This is under all the previous items.
 ![alt text](images/layout.JPG "Layout")
 
    
    

