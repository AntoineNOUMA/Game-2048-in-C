# Game-2048-in-C

Technical documentation

• The functions of this project have been grouped into five groups:

- The functions useful for the management of the terminal
- The functions useful for the management of the menu
- The functions useful for the management of the game
- The functions useful for the management of the boxes
- The functions useful for the motion management

• All prototypes of these functions are defined in the file myHeader.h

• The prototype of this header is included in each ".c" file with the command #include "myHeader.h" to include all the functions we will use in these files

• To compile the program, enter the following commands in your shell:

- gcc main.c  fonctionsGestionCases.c fonctionsGestionMenu.c fonctionsGestionMouvements.c fonctionsGestionPartie.c fonctionsGestionTerminal.c -o 2048 	- ./2048


User ManualGame rule: The game starts with a grid of 16 squares (modifiable in the options) and initialized with two values ​​2 or 4, the goal is to collide the powers of two in order to sum them to arrive at the value 2048 .

In this program, you can:
- Play
- Save
- Load
- Complete the game
- Show scoreboard
- Show options
	O Change the maximum value to be reached to win, here 2048
	O Change the size of the grid, here 4 x 4