#pragma once
#include <iostream>
#include "Picture.h"
#include "Brush.h"
#include "ColorBrush.h"
#include "ColorPatternBrush.h"

int main()
{
    string s1[] =
    {
        ".OO.",
        "O..O",
        "O..O",
        ".OO.",
    };
    string s2[] =
    {
        "          _____          ",
        "         /\\    \\         ",
        "        /::\\    \\        ",
        "       /::::\\    \\       ",
        "      /::::::\\    \\      ",
        "     /:::/\\:::\\    \\     ",
        "    /:::/__\\:::\\    \\    ",
        "   /::::\\   \\:::\\    \\   ",
        "  /::::::\\   \\:::\\    \\  ",
        " /:::/\\:::\\   \\:::\\____\\ ",
        "/:::/  \\:::\\   \\:::|    |",
        "\\::/   |::::\\  /:::|____|",
        " \\/____|:::::\\/:::/    / ",
        "       |:::::::::/    /  ",
        "       |::|\\::::/    /   ",
        "       |::| \\::/____/    ",
        "       |::|  ~|          ",
        "       |::|   |          ",
        "       \\::|   |          ",
        "        \\:|   |          ",
        "         \\|___|          "
    };
    string s3[] =
    {
        "______  _____  _____ ___  ___",
        "|  _  \\|  _  ||  _  ||  \\/  |",
        "| | | || | | || | | || .  . |",
        "| | | || | | || | | || |\\/| |",
        "| |/ / \\ \\_/ /\\ \\_/ /| |  | |",
        "|___/   \\___/  \\___/ \\_|  |_/"
    };

    string s4[] =
    {
        "XOXOXOXO",
        "OXOXOXOX",
        "XOXOXOXO",
        "OXOXOXOX",
        "XOXOXOXO",
        "OXOXOXOX",
        "XOXOXOXO",
        "OXOXOXOX"
    };

    string s5[] =
    {
        "                      ,*(/,...           .*/(###(/*         ",
        "              *((/(@@%((#######%&@@(*%@%#((#########%&@(    ",
        "       .#&&%%%&@@&#####%%%#####%&&%%######%&&@@@&%#######@& ",
        "   .&%#&@&%(///#&&%#&@%###%&@&%%##%%%##%&&@&%#######@@#####&",
        " ,&@%,.,,.         .#&%#&@@@&#*.        ,/%@%#&@%######%####",
        ".&.(@@@@@@@&          .%@#,(@@@@(            *&%#%&%########",
        "#.(@@* *@@@@/         (%,@@@@@@@@@*             *%&%########",
        "# (@@@&@@@@@,        *% %@@, ,@@@@/               ./&#######",
        ",% .%@@@@(,         /@& *@@@@@@@@#             #@###########",
        " (&&@%##((##(#%@@%##(%@@, .*/*.            .#@##%&##########",
        "   /&@@@@@@@@&%#########@&@@%(*....,*/%&@&##%@@#############",
        "  .@@%####################&@&&#######&@@@&##################",
        " /@##%&&&@&&&&&&&&&%%#######################################",
        " /&#(((((###############%%@@@@&%############################",
        "  #@#(&@@(((((((#####%&@@@&%#((((#%&@@&#####################",
        "    (@##@&(((############%%%%%%%&@@&#((((#@&################",
        "     @##&@#((#############%#%%%%%%%%%&@@#((@%###############",
        "    .@%(&@#(((###############%%#%%%%%%%%@((@%###############",
        "    .@%(&@#(((((############%%%%#%%%%%%@%(%@################",
        "    .@%(&@#(((((((###############%##@&((&@&#################",
        "    .@#(@@#(((((((((##############@&((%@####################",
        "    .@#(@&(((((((((((((((######&@%(#&@######################",
        "    ,@#(&@@%%(((((((((((((#%@&#((&@&######################@@",
        "    .@%((((##%&@@@@@@&@&#(((#%@@&#######################@&  "
    };

    cout << "***** Part 1 - (2 points) *****" << endl << endl;

    Picture p1(4, s1, "Small circle");
    Picture p2(21, s2, "3D letter R");
    Picture p3(6, s3, "DOOM Logo");
    Picture p4(p1);
    Picture p5 = p3;
    
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    cout << p5 << endl;

    cout << "***** Part 2 - (2 points) *****" << endl << endl;

    Brush b1("Regular brush", p1);
    Brush b2("Another regular brush", p2);
    Brush b3("Yet another regular brush", p3);
    
    cout << b1;
    b1.paint();
    cout << endl;
    
    cout << b2;
    b2.paint();
    cout << endl;
    
    cout << b3;
    b3.paint();
    cout << endl;

    cout << "***** Part 3 - (1 points) *****" << endl << endl;

    ColorBrush cb1("Cyan brush", 6, p1);
    ColorBrush cb2("Green brush", 2, p2);
    ColorBrush cb3("Red brush", 1, p3);
    ColorBrush cb4("Another cyan brush", cb1.getColor(), p2);
    
    cout << cb1;
    cb1.paint();
    cout << endl;
    
    cout << cb2;
    cb2.paint();
    cout << endl;
    
    cout << cb3;
    cb3.paint();
    cout << endl;
    
    cout << cb4;
    cb4.paint();
    cout << endl;

    cout << "***** Part 4 - (3 points) *****" << endl << endl;

    ColorPatternBrush cpb1("White-green brush", 7, cb2.getColor(), 1, 1, p1);
    ColorPatternBrush cpb2("Green-magenta brush", cpb1.getAlternateColor(), 5, 2, 3, p2);
    ColorPatternBrush cpb3("Red-blue brush", cb3.getColor(), 4, 29, 29, p3);
    ColorPatternBrush cpb4("Cyan brush with blue bits", cb1.getColor(), cpb3.getAlternateColor(), 6, 1, p2);
    
    cout << cpb1;
    cpb1.paint();
    cout << endl;
    
    cout << cpb2;
    cpb2.paint();
    cout << endl;
    
    cout << cpb3;
    cpb3.paint();
    cout << endl;
    
    cout << cpb4;
    cpb4.paint();
    cout << endl;
    
    Picture p6(8, s4, "Checkerboard");
    Picture p7(24, s5, "Poggers");
    
    b1.setPicture(p6);
    cout << b1;
    b1.paint();
    cout << endl;
    
    cb2.setPicture(p7);
    cout << cb2;
    cb2.paint();
    cout << endl;
    
    cpb1.setPicture(p2);
    cout << cpb1;
    cpb1.paint();
    cout << endl;
}