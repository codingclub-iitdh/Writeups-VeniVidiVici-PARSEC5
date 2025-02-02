# OSINT/1
This is the README for OSINT/1.

FLAG: parsec{+48501666264_41_91_polna}

## Challenge Overview

In this challenge, we are tasked with finding out the phone number of a restaurant, the price of Sphaghetti Carbonara in the restaurant, the number of the building of the restaurant and the name of the bus stop near the restaurant. We are given `violin.mp3`, an audio file that supposedly contains a recording of a violin player in the restaurant. We are also told that the restaurant had a very homely feel with outdoor eating and hammocks to sit on.

## Analyzing the audio

Upon inspection, we discover that violin.mp3 also has a small robotic voice in the background (specifically, on the left audio channel).
This robotic voice seems to repeat a few numbers along with the word 'Oblique' on a radio-sounding device.
A bit of research suggests that this is a numbers station.

### Technical Breakdown of GIF File Structure

1. Specifically, the numbers station that is being recorded here is E11 (ENIGMA naming convention), also known as the 'Oblique' numbers station.
2. The sample audio over at https://priyom.org/number-stations/english/e11/ seems to confirm this fact.
3. Digging deeper, we see that it is the English mode of the Polish 11 operator. https://priyom.org/number-stations/operators/polish-11
4. The location is 	52°25'46"N 20°52'53"E (Warsaw, Poland).
5. Location: google.com/maps/place/52°25'46.0"N+20°52'53.0"E. Zooming out a bit, we see that "La Trattoria Marcello & Giulia" is a pizza place located nearby on the same road. The pictures also indicate that this pizza place contains hammocks and outdoor seating, confirming the place in question. 

### Constructing the flag, 

1. The phone number available on both Google Reviews, Street View and Restaurant Guru is +48501666264.
2. The price of Sphagetti Carbonara is 41.00 (41 exculding decimal) zloty.
3. The number of the building is 91.
4. The name of the bus stop beside it is Polna.