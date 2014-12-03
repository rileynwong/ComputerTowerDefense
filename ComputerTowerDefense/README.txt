Project: Computer Tower Defense
Names: Samy Lanka and Nancy Wong

Compiling: 'make'
Running: 'make run'

Features:
- Read in path from a text file (for now it is path.txt)
- You can buy and place towers throughout the game
- Checks to make sure you don't place towers on top of other towers or in the path (and if you do, reprompts for new coordinates)
- Checks to make sure you have enough money before buying tower
- Towers shoot projectiles in specified direction with a range of 2 units
- Projectiles will kill a bug when they collide
- Projectiles will go away if they run into another tower
- Projectiles will go away if they go their max distance without colliding with a bug or they reach the end of the board
- Constant wave of bugs going along path
- Killing a bug makes them go away from the game board and gives you money
- Bug reaching the end of the path means you lose

Who did waht:
- Nancy: Game Display
	- gamescreen
	- main
	- Drawing the board, taking input, making the game run and updating the state every time the user gave input
- Samy: Game Logic
	- board
	- tower
	- projectile
	- bug
	- The game design and logic, holding the game state, reading in the path from a file