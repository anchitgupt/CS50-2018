// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // checks for numerator 1
   if(fraction[0] == '1')
   {
       // checks for denominator 8
        if(fraction[2] == '8')
        {
            return 1;
        }
        else
        // checks for denominator 4
        if(fraction[2] == '4')
        {
            return 2;
        }
        // checks for denominator 2
        if(fraction[2] == '2')
        {
            return 4;
        }
        else
         return 0;
   }
   // checks for denominator 8 and numerator 3
   else if(fraction[0] == '3' && fraction[2] == '8'){
        return 3;
   }
   else{
       return 0;
   }

   return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // node caontains Values of pure tones like A, B, C ....
    // acc contains the accidental nodes
    // oct contains which octet they lie in
    char node, acc, oct;
    // checks for pure tone or accidental tone
    if(strlen(note) == 3){
        node= note[0];
        acc = note[1];
        oct = note[2];
    }
    else{
        node= note[0];
        oct = note[1];
    }

    // intial vlaue of the frequency
    double f= 0.0;

    // calculation for the 4th octet pure tone values
    if(node == 'C'){
        f = 440.0 / pow(2.0, (9.0/12.0));
    }
    else
    if(node == 'D'){
        f = 440.0 / pow(2.0, (7.0/12.0));
    }
    else
    if(node == 'E'){
        f = 440.0 / pow(2.0, (5.0/12.0));
    }
    else
    if(node == 'F'){
        f = 440.0 / pow(2.0, (4/12.0));
    }
    else
    if(node == 'G'){
        f = 440.0 / pow(2.0, (2.0/12.0));
    }
    else
    if(node == 'A'){
      /**
        *Given default value of Octet 4 value i.e. A4 frequency
        *
        */
        f = 440.0;
    }
    else
    if(node == 'B'){
        f = 440.0 * pow(2.0, (2.0/12.0));
    }
    else
    return 0;
    // getting the octet value i.e ASCII to integer
    int o =  oct - 48;
    // getting tone for the given octet
    // if octet is less than 4
    if(o > 4){
        for(int i=0;i < o-4 ; i++)
            f *= 2.0;
    }
    else
    // if octet is greater than than 4
    if(o < 4){
        for(int i=0;i < 4-o ; i++)
            f /= 2.0;
    }

    // getting the value of accidental tone if inputted
    if(strlen(note) == 3)
    {
        if(acc == 'b')
        {
            f /= pow(2.0,(1.0/12.0));
        }
        else
        if(acc == '#')
        {
            f *= pow(2.0,(1.0/12.0));
        }
        else
            return 0;
    }
    int final = round(f);
    return final;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s, ""))
        return false;

        return true;
}
