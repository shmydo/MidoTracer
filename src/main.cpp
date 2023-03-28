#include <iostream>
#include "MainGame.h"
#include "test_tuple.h"

void runTests(){
    Mido::test_tuple_all();
}

int main(int argc, char **argv)
{
    // run tests
    runTests();

    Mido::MainGame mainGame;
    mainGame.run();

    return 0;
}
