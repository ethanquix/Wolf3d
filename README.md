# Pushswap

<i>Fast</i> sorting algorithm who can <b>ONLY</b> use restricted moves.
    
What is Pushswap ?
----------
    The game is made of two lists of numbers named l_a and l_b. At the beginning, l_b is
    empty and l_a contains a certain amount of positive or negative numbers (no duplicates).
    The goal of the game is to make it so that l_a contains the same numbers but sorted in
    an ascending order.
    To do so, you only have the following operations at your disposal:
    • sa : swaps the first 2 elements of l_a
    (does nothing if there aren’t enough elements).
    • sb : swaps the first 2 elements of l_b
    (does nothing if there aren’t enough elements).
    • ss : sa and sb at the same time.
    • pa : takes the first element of l_b and puts it in the first position in l_a.
    (does nothing if l_b is empty).
    • pb : takes the first element of l_a and puts it in the first position in l_b.
    (does nothing if l_a is empty).
    • ra : rotates l_a
    (towards the start, the first element becomes the last one).
    • rb : rotates l_b
    (towards the start, the first element becomes the last one).
    • rr : ra and rb at the same time.
    • rra : rotates l_a
    (towards the end, the last element becomes the first one).
    • rrb : rotates l_b
    (towards the end, the last element becomes the first one).
    • rrr : rra and rrb at the same time.

Featuring
----------

    (test.pl) pearl program to test pushswap
    Really fast alorithm, combination of 2 algorithm : Radix sort and Fusion sort
    Can sort 50,000 numbers in less than 0,5 seconds !
![Pushswap](https://raw.githubusercontent.com/ethanquix/ressources/master/gif/pushswap.gif)

Installation
----------
    git clone https://github.com/ethanquix/Pushswap.git
    cd Pushswap
    make re
Usage
----------

    ./push_swap [number1] [number2] ...
  You can also execute <i>test.pl</i> which test my pushswap for 50, 500, 5000 and 50000 numbers and verify output
  
    $ test.pl && tail trace/trace.txt
    
  :warning: It takes a loong time (~5 to 10 minutes)
  
  There is files containing random numbers located in "tests" folder, you can use them like that to see how fast my pushswap is :
  
    $ time ./push_swap `cat tests/test50000` > /dev/null

> [dimitriwyzlic.com](http://dimitriwyzlic.com) &nbsp;&middot;&nbsp;
> GitHub [@ethanquix](https://github.com/ethanquix) &nbsp;&middot;&nbsp;
> Linkedin [Dimitri Wyzlic](www.linkedin.com/in/dimitriwyzlic)
