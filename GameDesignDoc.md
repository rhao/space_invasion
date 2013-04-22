# Game Design Document
This is a place holder for your game design document. You are advised to write your document in [Markdown](http://daringfireball.net/projects/markdown/) and the following section will show you how to write a document using Markdown markup.

Alternativley, you can write your document in plain text if you wish.

----

## Markdown
Markdown is a human-readable structured plain text format that is used to convert text into HTML. GitHub automatically renders Markdown into HTML.

This is a crash course on how to use Markdown. The following section will show you the plain text used to generate the document shown in the rendering section.

### Code

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
```

----

### Rendering
This section shows the rendering of the plain text above.

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")






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
![alt text](space_turtle.gif "Space Turtle")

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
  * Name entry box
    - A line edit where the user can enter their name.
    - Entering a name is required to start the game.
  * Help box
    - Displays instructions and what each of the five items do.
  * Game output box
    -Displays the user's name, number of lives, and points.
  * Game play scene
    - Game is actually implemented, played, and displayed here.
    
    
    

