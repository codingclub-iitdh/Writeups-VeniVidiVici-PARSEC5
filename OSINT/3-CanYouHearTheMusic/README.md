# Can You Hear the Music - OSINT
On a trip, we discovered a restaurant where we heard an incredible violinist playing his heart out while we relaxed on a hammock, soaking in the cozy, homely atmosphere. As we chilled out, we enjoyed a delicious plate of Spaghetti Carbonara. We even have a recording from that day, but unfortunately, we don’t remember where the restaurant was.

Your task is to find the following details about the restaurant:
- Its phone number
- The price of Spaghetti Carbonara
- The building number of the restaurant
- The name of the nearest bus stop

The flag format is: `parsec{<Phno>_<PriceOfDish>_<BuildingNo>_<NearestBusStop>}`

Note:
* The phone number aforementioned should contain the country code. (Ex: If the number 1234567890 is from India it should be represented as +911234567890)
* Price Of Dish mentioned should be given in the local currency with only the number without any additional characters.
* Building No should be provided as a number without any additional characters
* Bus stop name should contain **one word**, if the Stop's name contains the name of the town, exclude it in the submission


FLAG: parsec{+48501666264_41_91_polna}

## Challenge Overview

In this challenge, we are tasked with finding out 
 - the phone number of a restaurant, 
 - the price of Sphaghetti Carbonara in the restaurant, 
 - the number of the building of the restaurant and the name of the bus stop near the restaurant. 
 
We are given `violin-1.mp3`, an audio file that supposedly contains a recording of a violin player in the restaurant. We are also told that the restaurant had a very homely feel with outdoor eating and hammocks to sit on.

## Analyzing the audio

Upon inspection, we discover that violin.mp3 also has a small robotic voice in the background (specifically, on the left audio channel).
A hint given also suggests that its some kind of broadcast.
This robotic voice seems to repeat a few numbers along with the word 'Oblique' on a radio-sounding device.
This might be a numbers station.

### Numbers Station

1. Searching up "Oblique" numbers station, we find one that has a transmitter in Poland.
2. Specifically, the numbers station that is being played here is E11 (by ENIGMA naming convention), also known as the 'Oblique' numbers station.
3. The sample audio over at https://priyom.org/number-stations/english/e11/ seems to confirm this fact.
4. Digging deeper, we see that it is the English mode of the Polish 11 operator. https://priyom.org/number-stations/operators/polish-11
5. The location is 	52°25'46"N 20°52'53"E (Warsaw, Poland).
6. Location: https://google.com/maps/place/52°25'46.0"N+20°52'53.0"E
7. Zooming out a bit, we see that "La Trattoria Marcello & Giulia" is a pizza place located nearby on the same road. The pictures also indicate that this pizza place contains hammocks and outdoor seating, confirming the place in question. 

### Constructing the flag, 

1. The phone number available on both Google Reviews, Street View and Restaurant Guru is +48501666264.
2. The price of Sphagetti Carbonara is 41.00 (41 exculding decimal) zloty.
3. The number of the building is 91.
4. The name of the bus stop beside it is Polna.
