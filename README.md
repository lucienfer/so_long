# so_long

<p align="center">:information_source: A small 2D Game made using the MiniLibX Graphics Library - Textures, sprites and tiles included. </p>

## Index
* [What is so_long?](#what-is-so_long)
* [Requirements](#requirements)
* [How does it work?](#how-does-it-work)
	* [Maps](#maps)	
	* [Controls](#controls)

<h2 align="center" id="what-is-so_long"> What is so_long? </h2>

The fifth project at 42 programming school.
It's the first graphical project in the Cursus, we can choose between 3 options - FdF, Fractol and so_long - that in general
cover different areas, but all 3 are graphical projects. The so_long consists of a top-down game, which we code from scratch using
the MiniLibx graphical library. It involves a series of validations from the map that is passed as argument,
checks to prevent memoy leaks, the game engineering, managing windows, events, sprites and maps.
	
<h2 align="center" id="requirements"> Requirements </h2>

<p  align="center"> :warning: The project must be written in accordance with the <a href="https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf" target="_blank">Norm</a> </p>
The Norm  is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core by default, and
to any project where it's specified. These are some of them:

    Each function must be maximum 25 lines, not counting the function's own curly brackets.
    
    Each line must be at most 80 columns wide, comments included.
    
    A function can take 4 named parameters maximum.
    
    You can't declare more than 5 variables per function.
    
    You're not allowed to use: for , do...while , switch , case ,  goto  ,
    ternary operators such as `?' and VLAs - Variable Length Arrays.
  The norminette (as we call the norm at 42) is in python and open source.
  
  Its repository is available at https://github.com/42School/norminette.
    
<h2 align="center" id="how-does-it-work"> How does it work? </h2>

You'll be able to play once you install the <a href="https://github.com/42Paris/minilibx-linux">MiniLibx</a> features or if you're using one of the machines at 42.

To play, first compile the project with make:

	make
	
In case you wanna play the bonus version:

	make bonus
	
So, run ./so_long followed by the map:
	
	./so_long maps/big.ber	

For bonus:
	
	./better_so_long maps/big.ber
	
<h3 id="maps" align="center"> Maps </h3>   
You can parse any kind of map, as long as it respects the below rules:

The map must be a .ber file.

And can only contain these characters:
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| 1         |   Wall   |
| C	        | Coin |
| E	        |   Exit  |
| P         |   Player  |      
| 0         |   Floor     |
    
For bonus there's an extra character - which makes you lose once touch it.
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| M         |  Enemies  |


The map must be rectangular and surrounded by walls '1'.

The map must contain at least one exit, one collectible, and one starting position.

Check some examples in the folder /assets/maps.
	
As in maps/big.ber:

<img src="https://user-images.githubusercontent.com/81205527/163024984-1ff511c1-17d2-4eef-8d97-90cc8a884c73.png">
	
<h3 id="controls" align="center"> Controls </h3>   
    
| KEY |	OBJECT   |
| --------- | ---------- |
| W or ⬆️        |    Move up   |
| A	or ⬅️        |    Move left |
| S	or ⬇️     |    Move down   |
| D or ➡️       |   Move para right|      
| Q or Esc      |   Close the game     | 
    
    
Use WASD or arrow keys to move.
	
	
After getting all the coin bags, the exit opens and you can escape downstairs.
	
You can close the game by Clicking on the red cross on the window’s frame, or pressing Q or Esc.
