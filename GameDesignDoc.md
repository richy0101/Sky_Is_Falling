# Game Design Document for "The Sky Is Falling"

## Overview
> The "Sky Is Falling" will be a `qt` based game where the user controls a farmer and tries to dogde 5 different falling animals, which will all `move` differently.
> The user accumulates a different amount of points for every animal dodged. The user has three lives, and the game will end after both lives are lost. The game gets faster and faster as time goes on.

## Moving Objects
> 
> + **1.** `Farmer`
> + ![alt text](http://www.econedlink.org/lessons/images_lessons/267_farmer1.jpg "Farmer")
>    - The user controls the farmer by moving him left or right in order to dodge the falling animals. User controls the farmer with the keyboard. The farmer has 2 lives.
> + **2.** `Turtle`
> + ![alt text](http://www.designdownloader.com/item/pngs/Sea_Turtle_t005/Sea_Turtle_t005-20120619174148-00001.png "Turtle")
>    - The turtle is the slowest falling animal and is worth 10 points if dodged. The turtle moves normally and doesn't have any special `move` function.
> + **3.** `Donkey`
> + ![alt text](http://icons.iconarchive.com/icons/turbomilk/animals/256/donkey-icon.png "Donkey")
>    - The donkey is the second slowest animal and is worth 20 points if dodged. Donkeys sometime take breaks and will stay in the same position for on `move`.
> + **4.** `Fox`
> + ![alt text](http://osx.wdfiles.com/local--files/icon:cunning-fox/Cunning-Fox.png "Fox")
>    - The fox runs at moderate speed and is worth 30 points. The fox is cunning and can move backwards and random times.
> + **5.** `Gazelle`
> + ![alt text](http://www.iconshock.com/img_jpg/SUPERVISTA/animals/jpg/128/gazelle_icon.jpg "Gazelle")
>    - The gazelle runs quickly and is worth 40 points. The gazelle is able to move left and right randomly, not just in a straight line downwards.
> + **6.** `Cheetah`
> + ![alt text](http://www.iconshock.com/img_jpg/SUNNYDAY/animals/jpg/128/cheetah_icon.jpg "Cheetah")
>    - The cheetah is the fastest running animal and is worth 50 points. The cheetah is swift and at random times can sprint downwards for a `move`.
> + **6.** `Rabbit`
> + ![alt text](http://icongal.com/gallery/image/40628/rabbit_bunny_easter_easter_eggs.png "Cheetah")
>    - The rabbit is patient and waits to move. It will randomly move after long pauses, but the move will be a great leap. It also tracks the farmer and will move in the direction of him. The rabbit is worth 60 points.
> + **6.** `Wolf`
> + ![alt text](http://www.designdownloader.com/item/pngs/Wolf_t004/Wolf_t004-20120728103808-00001.png "Cheetah")
>    - The wolf has the ability to make long jumps to the left, right, or downwards. It is fast when it leaps and is worth 70 points. 

## User Gameplay
> **Purpose**: The user will control the farmer with keyboard strokes and try to avoid the falling animals. The user can only move the farmer left and right. It is simple gameplay controls that will make the game simpler to play for the user. I eventually plan to add power ups to the game so there will be a keyboard stroke added to use the powerup.

## Scoring & Lives
> + **1.** `Score` - The user will get points for dodging different types of animals. No points can ever be reducted from the player. The player gets 10 poinst for dodging turtles, 20 for donkeys, 30 for foxes, 40 for gazelles, 50 for cheetahs, 60 for rabbits, and 70 for wolfs. The points will be displayed in a separate window that will also display the number of lives, and start, pause, and quit buttons.
>     - `High Score`- The game keeps track of every game played and what the highest score ever was. See if you can beat the high score of all this game's history!
> + **2.** `Lives` - The user gets two lives to spare if he gets hit by a falling animal. All types of animals that aren't dodged make the user lose 1 live. After all three lives are lost, the game ends and the scoring gets stopped, where the user can choose to quit or restart the game.
> 

## Game & User Interface
> + ![alt text](http://i.imgur.com/KMttarR.jpg "Hand Drawn Interface")
>  **Overview** There are two windows, one main window where the game is shown, and one menu window, where the widgets to control the game are located.
> +  **1.** `Game Window`
>     - As time progresses different animals will start to fall randomly at the top of the screen. It progresses from the slowest, the turtle, to the fastest, the cheetah. As time goes on all the animal's speed increase at a constant rate to make the game harder for the user.
>     - User controls the farmer to dodge all the animals that are falling. One life of the two given will be taken away if the farmer touches a falling animal. The user accumulates a different amount of points per animal dodged.
>     - Animal objects are created as the fall from the top of the screen and are deleted at the end of the window when they have completely fallen. There is no set number of animals that can be on the field but animals are created at random time intervals.
> + **2.** `Menu Window` inside `Game Window`
>     - Displays the user's current `level`, `score`, `highscore`, and the user's current `lives` at the top of the window.
>     - Displays three buttons: `start`,`pause`,`quit`
>          * `start` button- when pressed the game starts, either at the beginning of the game when the game is preset to pause (timer is off) or when the game is paused.
>          * `pause` button- when pressed the game pauses by pausing the timer.
>          * `quit` button- when pressed the game force quits.


