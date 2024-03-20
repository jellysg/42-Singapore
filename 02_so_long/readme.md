## so_long
![](https://github.com/jellysg/core/blob/main/02_so_long/img/img1.gif)  
and thanks for the fish(???)

#### Compiling

After cloning, make sure you are in ./core/02_so_long/ directory, then make:
```
make
```

To test the game, run the following:
```
./so_long ./maps/(map name).ber
```

## Compile with the following to test, this main.c works with any GNL file
#### Do note that this is a very simple test, refer to Tripouille or fsoares for optimized tests
```
cc -Wall -Wextra -Werror *e.c *ls.c main.c
```

## Run the test case
```
./a.out
```

## You can change the BUFFER_SIZE in get_next_line.h to check other sizes
