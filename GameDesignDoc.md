# Game Design Document for "The Sky Is Falling"

## Overview
> The "Sky Is Falling" will be a `qt` based game where the user controls a farmer and tries to dogde 5 different falling animals, which will all `move` differently.
> The user accumulates a different amount of points for every animal dodged. The user has two lives, and the game will end after both lives are lost.

## Objects
> 
> + **1.** ![alt text](http://us.123rf.com/400wm/400/400/chudtsankov/chudtsankov1106/chudtsankov110600074/9681562-lucky-farmer-man-carrying-a-rake.jpg "Farmer")
>    - The user controls the farmer by moving him left or right in order to dodge the falling animals. 
> + **2.** Parse the `strings` containing node and edge data to create `User` objects and store them in `MyList`class.
> + **3.** Use `GMLWriter` class to output `User` objects and their friend connections.
> + **4.** Process a command file that specifies `Friend` additions and removals.
> + **5.** Write the resulting social network to a new GML file.
> + **6.** Software should handle any error's like incorrect file inputs, User inputs, or friend additions/removals.


## Classes
###User Class
> **Purpose**: Stores all the personal information of the `User` as well as friend connections
#####Member Data
> + **1.** `name`- stores the name of User
> + **2.** `age`- stores the age of User
> + **3.** `zip`- stores zipcode of User
> + **4.** `id`- stores the ID of User
> + **5.** `IDfriends`- MyList of ids of friends
>        
#####Methods
> + **1.** `Constructor` - initializes `name`, `age`, `zip`, and `id` of the User by taking all of them as parameters. Also calls MyList constructor of the variable friendlist
> + **2.** `getName()` - returns the string name of User
> + **3.** `getAge()` - returns the integer age of User
> + **4.** `getID()` - returns the integer ID of User
> + **5.** `getZIP()` - returns the integer zip code of User
> + **6.** `addFriends(int i)` - adds another User's id to the list IDfriends through a paramter
> + **7.** `MyList<int>& friendsIDs()` - returns the whole list of IDfriends
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
