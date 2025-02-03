# The Tale of Pinocchio - Reverse Engineering
Pinocchio always seems to find himself in the most troublesome of situations. 
Every time he tells a tall tale, his nose grows, but he never learns. Can you see through his lies and tell us the truth?

![challenge.gif](/files/6a9007f01986b98c7e180a3b17c7a4b6/challenge.gif)

FLAG: parsec{l135_dec31t_ch34t_c3$1!49kAp}

## Challenge Overview

In this challenge, we are tasked with analyzing a GIF file named `challenge.gif`. The objective is to uncover a hidden flag that has been cleverly concealed within the GIF's structure. 

## Analyzing the GIF

Upon inspection, we discover that `challenge.gif` displays 5 frames. Based on the GIF itself and the hint given by the riddle (mentioning pinocchio and ASCII characters), the challenge might lie in the way the frames are separated within the GIF file.

### Technical Breakdown of GIF File Structure

1. **GIF File Structure**: GIF (Graphics Interchange Format) files are composed of a series of frames, each defined by an **Image Descriptor**. These frames are separated by a **Graphics Control Extension (GCE)**, which provides essential information about how each frame should be displayed, including disposal methods, delay times, and transparency settings.

2. **Frame Separation**: In a standard GIF file, frames are separated by a specific byte sequence. The separation is typically managed through the use of the GCE, which indicates the beginning of a new frame. This structure allows for the proper sequencing and display of animated GIFs.

3. **Graphics Control Extension (GCE)**: The GCE is identified by the byte sequence `0x21 0xF9`. This extension is crucial for identifying where a GCE block begins for each frame.

4. **End Of File (EOF)**: The end of a GIF file is marked by the byte sequence `0x3B`, which signifies the termination of the file.

### Analysing the hex

Searching for the hex pattern `21 F9` using `hexeditor` (also in `challenge-gif.hex`), we see that there is one pattern that exists close to a string of ASCII characters AAABBBCCC...
Interestingly, this GCE block is the last one. Even more interesting is that the `21 F9` is preceded by a `3B`, which is also the EOF character for a GIF. This might confuse most image software and therefore the last frame/GCE block might be entirely skipped because of the EOF character being encountered. To resolve the issue, we change the `3B` into a null character `00`, and then reopen the GIF. We see that an extra frame with the flag is displayed.