# Game Design Document for "The Sky Is Falling"

## Overview
> The "Sky Is Falling" will be a `qt` based game where the user controls a farmer and tries to dogde 5 different falling animals, which will all `move` differently.
> The user accumulates a different amount of points for every animal dodged. The user has two lives, and the game will end after both lives are lost. The game gets faster and faster as time goes on.

## Moving Objects
> 
> + **1.** `Farmer`
> + ![alt text](http://www.econedlink.org/lessons/images_lessons/267_farmer1.jpg "Farmer")
>    - The user controls the farmer by moving him left or right in order to dodge the falling animals. User controls the farmer with the keyboard. The farmer has 2 lives.
> + **2.** `Turtle`
> + ![alt text](http://aux.iconpedia.net/uploads/192463869.png "Turtle")
>    - The turtle is the slowest falling animal and is worth 1 point if dodged. It has no special movements.
> + **3.** `Donkey`
> + ![alt text](http://icons.iconarchive.com/icons/turbomilk/animals/256/donkey-icon.png "Donkey")
>    - The donkey is the second slowest animal and is worth 1 point if dodged. It takes frequent breaks when it gets tired and stops momentarily.
> + **4.** `Fox`
> + ![alt text](http://osx.wdfiles.com/local--files/icon:cunning-fox/Cunning-Fox.png "Fox")
>    - The fox runs at moderate speed and is worth 2 points. It's special function is the ability to move backwards for short intervals. 
> + **5.** `Gazelle`
> + ![alt text](http://www.iconshock.com/img_jpg/SUPERVISTA/animals/jpg/128/gazelle_icon.jpg "Gazelle")
>    - The gazelle runs quickly and is worth 2 points. It's special function is the ability to left and right. 
> + **6.** `Cheetah`
> + ![alt text](http://www.iconshock.com/img_jpg/SUNNYDAY/animals/jpg/128/cheetah_icon.jpg "Cheetah")
>    - The cheetah is the fastest animal and is worth 3 points. It's special function is to sprint for short intervals. 

## User Gameplay
> **Purpose**: The user will control the farmer with keyboard strokes and try to avoid the falling animals. The user can only move the farmer left and right. It is simple gameplay controls that will make the game simpler to play for the user. I eventually plan to add power ups to the game so there will be a keyboard stroke added to use the powerup.

## Scoring & Lives
> + **1.** `Score` - The user will get points for dodging different types of animals. No points can ever be reducted from the player. The player gets 1 point for dodging turtles and donkeys, 2 points for foxes and gazelles, and 3 points for cheetahs. The points will be displayed in a separate window that will also display the user's name, number of lives, and start, pause, and quit buttons.
> + **2.** `Lives` - The user gets two lives to spare if he gets hit by a falling animal. All types of animals that aren't dodged make the user lose 1 live. After both lives are lost, the game ends and the scoring gets stopped, where the user can choose to quit or restart the game.
> 
###MyList Class
> **Purpose**: a *templated* dynamic array-based `class` that stores all `User` objects
#####Member Data
> + **1.** `capacity` - int of the capacity of the list
> + **2.** `size` - the current size of the List
> + **3.** `data` - a templated array of data that the list holds
>        
#####Methods
> + **1.** Constructor - sets the size of the list to 0
> + **2.** `operator[](int index)` - overrides allowing users to use `[]` instead of `.at()`
> + **3.** `push_back(T n)` - a void function that adds a variable to the back element of the list and increments size
> + **4.** `size()` - returns the current integer size of the list
> + **5.** `at(int loc)` - returns the element of the list that is passed as an integer parameter 
> + **6.** `remove(T val)` - removes a specific value in the list that is passed as a parameter and decrements size by 1 and moves all elements forward to replace that removed element
> 
###GMLReader Class
> **Purpose**: Parse the GML file and read in raw node/vertex and edge data
#####Member Data
> + **1.** None
>         
#####Methods
> + **1.** `static bool read(const char *fn, std::vector<std::string>& nodes, std::vector<std::string>& edges)` - reads in a file and stores the node/edge data in two separate `string vectors`
> 
###GMLWriter Class
> **Purpose**: outputs `User` data (and their friendship connections) in node and edge formats.
#####Member Data
> + **1.** None
>          
#####Methods
> + **1.** `void write(char* f, MyList<User*> &list)` - writes data in node/edge format to a file by taking in a file and a list of users as parameters
> 

## Global Data/Functions
> + **1.** I have a `const int DEFAULT_CAPACITY` in class `MyList` that is used in the constructor to always set the number of elements allowed in the list to whatever that variable is

## High-level Architecture
> The most interaction is between the `User` class and `MyList` class. MyList acts as a better form of a vector that can be used in other classes.
> In User class there is a an instance of MyList to hold the friend IDs. MyList is especially useful because it is templated and can be used with many different
> types of variables. I have created my own algorithms to parse the input gml and command files by using `stringstream` and `getline`. They are used to get attributes
> of a user and add that user to the MyList of users. All the interactivity between adding and removing friends is done through the `MyList<int> friendsID` member variable of User class.


## User Interface
> I would like to add a GUI later on but currently I dont have one. The way users interact with the program is that they input three command line arguments: 
> the input GML file that has the User data in node format and friend connections in edge format, a text file that will have commands to add or remove two Users,
>, and an output GML file they name that will output the Users and their attributes in node format as well as their newly made connections from my algorithm parsing the command
> file (that will be in edge format).

##Test Cases
> + I plan to test all cases that could break my program. I have created error messages if the input GML file or command file isn't read, as well as if the names in the command file 
> don't match User's names in the input GML file or if it doesnt start with an a or r(add or remove friends).
> + I will test cases where the input GML file is not name correctly, when the command file is not named correctly, when the names in the command file are wrong, or when the lines in the command file don't start with an a or r.
> + Some test cases that could break my program that haven't been tested for is if the name is more or less than two words (I.e. Richard Phillips). Also if the node/edge data is not formatted correctly I will not be able to parse it correctly.
> Also, if there are extra random characters in either the GML input file or command file, my algorithm won't be able to parse it correctly.
> + For functions like `read(const char *fn, std::vector<std::string>& nodes, std::vector<std::string>& edges)` I would pass in different filenames but the only one that would work is the filename that is in the folder of the run file.
> Also for the function `write(char* f, MyList<User*> &list)` I'd have to pass the file that was named in `int main()` or else I couldn't output the gml file.
