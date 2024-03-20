# Introduction to 42's so_long
![](https://github.com/jellysg/core/blob/main/02_so_long/img/img1.gif)  
and thanks for the fish(???)

#### Mandatory features
- WASD to move the player
- Should not be able to move into walls
- View has to be 2D (top-down or profile)
- Game doesn't have to be in real-time
- Collect all coins before escaping  
![](https://github.com/jellysg/core/blob/main/02_so_long/img/img3.gif)  

#### Bonus features
- Lose upon touching an enemy patrol
- Sprites have animations
- Movement count is shown directly on screen  
![](https://github.com/jellysg/core/blob/main/02_so_long/img/img2.gif)  


#### Compiling

After cloning, make sure you are in ./core/02_so_long/ directory, then make:
```
make
```

To test the game, run the following:
```
./so_long ./maps/(map name).ber
```
  

# Tutorial: Getting started on so_long
#### Disclaimer:
My structs are not optimized. Due to unoptimized linking, I have to make pointless frees before malloc. This is not only unnecessary line bloat, but also makes it harder to understand when reviewing the source code.  
For this I apologize for the messy linking and extra frees here and there, they were mostly a band-aid to passing valgrind and speed up the submission overall. It could definitely be done better and will revisit this when I have more time in the future.  
  
**This project has heavy focus on memory manipulation.**
  

## Short introduction to MiniLibX:
[MiniLibX (MLX)](https://harm-smits.github.io/42docs/libs/minilibx) is a beginner-friendly API for C, used mainly for a window system called [X11](https://tronche.com/gui/x/xlib/).  

### Installing MLX:
Install MLX by either downloading it directly from the project page or this command:
```
git clone https://github.com/42Paris/minilibx-linux.git mlx
```

### Dependencies:
MLX (and X11 itself) depends on certain packages to carry out some functions. They can be installed with the following command:
```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Makefile additions:
These are some of the additions to your Makefile to ensure the X11 and MLX files are accessible:
```
...
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
...
```

# Core MLX functions for so_long:
- mlx_init  
Initializes the mlx library before anything else.
- mlx_new_window  
Creates a new window instance.
- mlx_hook  
"Hooks" or registers events onto the window or mlx pointer.
- mlx_loop  
Loops across the mlx pointer, registering the hooks in the same order they are called.
- mlx_xpm_file_to_image  
Converts XPM to a viewable image on an mlx pointer.
- mlx_put_image_to_window  
Puts... image.. to window.. I don't know how else to explain this.  
  
The following have to be called **in the same order** or there will be memory leaks:  
- mlx_destroy_image  
Frees image stored in 'mlx_xpm_file_to_image' pointers.
- mlx_destroy_window  
Frees the window instance.
- mlx_destroy_display  
Frees mlx.  
(Note: This frees the mlx functions but you still have to free your own mlx pointer!)

