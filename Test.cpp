
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good snowman code") {

    CHECK(snowman(11114411)==string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(33233124) == string("   _\n  /_\\\n (o_O) \n/(] [)>\n (   )\n"));
    CHECK(snowman(22333124) == string("  ___\n .....\n (O.O) \n/(] [)>\n (   )\n"));
}

TEST_CASE("check hat") {
    CHECK(snowman(11114411) ==string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(21114411) == string("  ___\n .....\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(31114411) == string("   _\n  /_\\\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(41114411) == string("  ___\n (_*_)\n (.,.) \n ( : ) \n ( : )\n"));
}

TEST_CASE("check nose") {
    CHECK(snowman(11114411) == string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(12114411) == string(" _===_\n (...) \n ( : ) \n ( : )\n"));
    CHECK(snowman(13114411) == string(" _===_\n (._.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(14114411) == string(" _===_\n (. .) \n ( : ) \n ( : )\n"));
}

TEST_CASE("check left eye") {
    CHECK(snowman(11114411) == string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11214411) == string(" _===_\n (o,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11314411) == string(" _===_\n (O,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11414411) == string(" _===_\n (-,.) \n ( : ) \n ( : )\n"));
}

TEST_CASE("check right eye") {
    CHECK(snowman(11114411) == string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11124411) == string(" _===_\n (.,o) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11134411) == string(" _===_\n (.,O) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11144411) == string(" _===_\n (.,-) \n ( : ) \n ( : )\n"));
}


TEST_CASE("check left arm") {
    CHECK(snowman(11111411) == string(" _===_\n (.,.) \n<( : ) \n ( : )\n"));
    CHECK(snowman(11112411) == string(" _===_\n\\(.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11113411) == string(" _===_\n (.,.) \n/( : ) \n ( : )\n"));
    CHECK(snowman(11114411) == string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
}

TEST_CASE("check right arm") {
    CHECK(snowman(11114111) == string(" _===_\n (.,.) \n ( : )>\n ( : )\n"));
    CHECK(snowman(11114211) == string(" _===_\n (.,.)/\n ( : ) \n ( : )\n"));
    CHECK(snowman(11114311) == string(" _===_\n (.,.) \n ( : )\\\n ( : )\n"));
    CHECK(snowman(11114411) == string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
}

TEST_CASE("check torso") {
    CHECK(snowman(11114411) == string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11114421) == string(" _===_\n (.,.) \n (] [) \n ( : )\n"));
    CHECK(snowman(11114431) == string(" _===_\n (.,.) \n (> <) \n ( : )\n"));
    CHECK(snowman(11114441) == string(" _===_\n (.,.) \n (   ) \n ( : )\n"));
}

TEST_CASE("check base") {
    CHECK(snowman(11114411) == string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(11114412) == string(" _===_\n (.,.) \n ( : ) \n (" ")\n"));
    CHECK(snowman(11114413) == string(" _===_\n (.,.) \n ( : ) \n (___)\n"));
    CHECK(snowman(11114414) == string(" _===_\n (.,.) \n ( : ) \n (   )\n"));
}


TEST_CASE("Negative numbers") {
    CHECK_THROWS(snowman(-23341121));                                     
    CHECK_THROWS(snowman(-12344112)); 
}

TEST_CASE("Not enough characters") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(145322));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1));
    
}

TEST_CASE("Too many characters") {
     CHECK_THROWS(snowman(1234334321));
     CHECK_THROWS(snowman(1112415571));
    
}

TEST_CASE("Invalid characters") {

    //for hat
    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(61111111));

     //for nose
    CHECK_THROWS(snowman(17111111));
    CHECK_THROWS(snowman(18111111));

    //for left eye
    CHECK_THROWS(snowman(11511111));
    CHECK_THROWS(snowman(11611111));

    //for right eye
    CHECK_THROWS(snowman(11101111));
    CHECK_THROWS(snowman(11161111));

    //for left arm
    CHECK_THROWS(snowman(11117111));
    CHECK_THROWS(snowman(11119111));

    //for right arm
    CHECK_THROWS(snowman(11111911));
    CHECK_THROWS(snowman(11111011));

    //for torso
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111181));

    //for base
    CHECK_THROWS(snowman(11111118));
    CHECK_THROWS(snowman(11111110));
}





