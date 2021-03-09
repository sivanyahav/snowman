
#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>

using namespace std;


//constant
enum parts
{
    ZERO,HAT, NOSE, LEFT_EYE, RIGHT_EYE, LEFT_ARM, RIGHT_ARM, TORSO, BASE 
};

const int types=5, sizeOfInput = 8;
const char minDig='1', maxDig='4';

const array<std::string,types> hats={"", "_===_", " ___\n .....", "  _\n  /_\\"," ___\n (_*_)"};
const array<std::string,types> noses={"", ",", ".", "_",""};
const array<std::string,types> leftEyes={"", ".", "o", "O","-"};
const array<std::string,types> rightEyes={"", ".", "o", "O","-"};
const array<std::string,types>leftArmTops={""," ","\\"," "," "};
const array<std::string,types> leftArms={"","<"," ","/"," "};
const array<std::string,types> rightArmTops={""," ","/"," "," "};
const array<std::string,types> rightArms={"",">"," ","\\"," "};
const array<std::string,types> torsos={"", " : ", "] [", "> <","   "};
const array<std::string,types>bases={"", " : ", "" "", "___","   "};


//This function checks the integrity of the input
void checkDigits(int num){

    //Check that the length of the number is equal to 8
    string numToString= std::to_string(num);
    int numOfDigits= numToString.length();
    if(numOfDigits != sizeOfInput){
        throw std::out_of_range("The length must be 8\n");
    }

    //Check that the character range is greater than 1 and less than 4
    for(int i=0; i<numOfDigits; i++){
        if(numToString[i]< minDig || numToString[i]>maxDig){
            throw std::out_of_range("The characters must be between 1 and 4\n");
        }
    }

}

//This function returns an array in which each cell represents the type of organ you want
array<int,sizeOfInput+1> getDigits(int num){
    array<int,sizeOfInput+1> arr={};
    arr[0]=0;
    const int base=10;
            
    for(int i=sizeOfInput; i>0; i--){
        arr[i]=num%base;
        num/=base;
    }
    return arr;
}

//Functions that build the parts of the snowman 

string buildBase(const int baseType){
    return " ("+bases[baseType]+")";
}

string buildTorso(const int leftArmType, const int torsoType, const int rightArmType){
    return ""+leftArms[leftArmType]+"("+torsos[torsoType]+")"+rightArms[rightArmType];
}

string buildFace(const int leftArmTopType, const int leftEyeType, const int noseType, const int rightEyeType, const int rightArmType){
    return ""+leftArmTops[leftArmTopType]+"("+leftEyes[leftEyeType]+noses[noseType]+rightEyes[rightEyeType]+")"+rightArmTops[rightArmType];
}

string buildHat(const int hatType){
    return " "+hats[hatType];
}

/**
 * We build the snowman in the following way:
 * Level 1: hat
 * Level 2: face
 * Level 3: torso
 * Level 4: base
 **/
string buildSnowman(array<int,sizeOfInput+1> arr){

    string hat=buildHat(arr[HAT]);
    string face=buildFace(arr[LEFT_ARM], arr[LEFT_EYE], arr[NOSE], arr[RIGHT_EYE], arr[RIGHT_ARM]);
    string torso=buildTorso(arr[LEFT_ARM], arr[TORSO], arr[RIGHT_ARM]);
    string base=buildBase(arr[BASE]);
 
    return ""+hat+"\n"+face+"\n"+torso+"\n"+base+"\n";
}


namespace ariel {

    string snowman(int str){      

        checkDigits(str);
        array<int,sizeOfInput+1> Digits = getDigits(str);
        return buildSnowman(Digits);

    }  

}
