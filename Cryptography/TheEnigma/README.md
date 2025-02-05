# The Enigma 

### Challenge Description
Our linguistic encryption department has developed a cutting-edge encryption algorithm and used it to conceal the flag. To showcase their work, they’ve made the tool available for anyone to encrypt their own messages. Give it a try and see if you can uncover the flag… though they claim it’s nearly impossible! Good luck ;)


### Analysing the Encoding process
After connecting to the netcat process provided you are greated with a string that looks like a base64 encoded string. `MUZTI227HE4XC4DUOM2HI2DJPV3W223FN54HW4JTGJPWWMDBL54DG===`

If we put it into a b64 decoder we get gibberish. If you look closer though you will figure out that the string only contains Uppercase characters, hinting at a possible b32 encoding. Decoding it we get `e34k_99qpts4thi}wmkeox{q32_k0a_x3`


We can find two braces ( '{}' ) but they are not in the expected location, so we suspect it is rotated.

We can then rotate it back and get the string `wmkeox{q32_k0a_x3e34k_99qpts4thi}` 

This looks like a very simple substitution cipher, to figure out the substitution table we can use the input allowed by the executable. We can give input for each alphabet or to make it quicker we can give multiple at the same time as `abbcccdddd` with different number of occurences to find out the pattern quicker. 

The mapping is as follows:
`{'A', 'M'}, {'B', 'Q'}, {'C', 'X'}, {'D', 'T'}, {'E', 'O'}, {'F', 'J'}, {'G', 'Y'}, {'H', 'N'}, {'I', 'P'}, {'J', 'Z'},
        {'K', 'B'}, {'L', 'S'}, {'M', 'V'}, {'N', 'D'}, {'O', 'F'}, {'P', 'W'}, {'Q', 'C'}, {'R', 'K'}, {'S', 'E'}, {'T', 'A'},
        {'U', 'L'}, {'V', 'H'}, {'W', 'U'}, {'X', 'G'}, {'Y', 'R'}, {'Z', 'I'},
        {'a', 'm'}, {'b', 'q'}, {'c', 'x'}, {'d', 't'}, {'e', 'o'}, {'f', 'j'}, {'g', 'y'}, {'h', 'n'}, {'i', 'p'}, {'j', 'z'},
        {'k', 'b'}, {'l', 's'}, {'m', 'v'}, {'n', 'd'}, {'o', 'f'}, {'p', 'w'}, {'q', 'c'}, {'r', 'k'}, {'s', 'e'}, {'t', 'a'},
        {'u', 'l'}, {'v', 'h'}, {'w', 'u'}, {'x', 'g'}, {'y', 'r'}, {'z', 'i'}`

We can get the flag as: `parsec{b32_r0t_c3s34r_99bidl4dvz}`
