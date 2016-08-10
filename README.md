# Wolf3d

<i>Cool</i> Wolfenstein made in C with Epitech custom graphic lib : [LibLapin](http://liblapin.readthedocs.io/fr/latest/index.html)
    
Features :
----------
    Small fake 3d Video game made in C, "segfault proof"
    You can change map when you want ingame
    Live Minmap
    Slow Motion mode
    You can change FOV ingame
    A small red cross is located in the middle of the screen and you can remove it
    Disco / LSD mode with nice color effects
    Ambient sound
    Shoot animations and sound
    You can add block to the map and minmap update instantly
    Easy to make custom map

Controls
----------
    ZQSD = Move
    T = Change Map
    M = SlowMotion mode
    A/E = Change FOV
    C = Show Cross
    B = Disco (bonus) mode
    SPACE = Fire
    Return = Place Block
Custom maps
----------

You can make your own map easily<br>
A map is juste a .ini file which respect these rules :

    -Must have this line first :
    [level]
    Then you have to provide 5 informations :
    - name="name of the map"
    - size"Width * Height"
    - width="Wdth"
    - height="Height"
    - data="0","1","0" ... (the map)
    
How to fill the data ?

    You can fill it with :
    42 = Start
    0 = Void
    1 / 3 / = Wall (different colors)
    8 = Exit
There is map sample in maps folder
![Pushswap](https://raw.githubusercontent.com/ethanquix/ressources/master/pict/wolf.png)

Installation
----------
    git clone https://github.com/ethanquix/Wolf3d.git
    cd Wolf3d
    ./wolf3d [map.ini]
    :warning: You cant "make re" because you don't have liblapin installed on your computer
Usage
----------

    ./wolf3d [map.ini]
    Tests map can be found in maps directory
    
> [dimitriwyzlic.com](http://dimitriwyzlic.com) &nbsp;&middot;&nbsp;
> GitHub [@ethanquix](https://github.com/ethanquix) &nbsp;&middot;&nbsp;
> Linkedin [Dimitri Wyzlic](www.linkedin.com/in/dimitriwyzlic)
