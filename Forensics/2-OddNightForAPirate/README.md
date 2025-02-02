# Odd Night For a Pirate - Forensics
The Marines have captured an infamous pirate group. The marines were hoping to find all the treasures they have stolen, however they were dissapointed to find meagre treasure and a very small disk. The Pirate leader in his last moments declares that the disk contains the key to finding his treasure and releases a copy of the disk image to everyone. Your job is to find what is hidden in plain sight, not everyone is capable of seeing past the evident photos, prove you are the best pirate of them all.

FLAG: `parsec{th3_m00n_d035_h1d3_4_l0t_i53pJ9v503}`

### Analysing the disk

Looking at the disk, it contains an ext4 file system with a lot of images.

Let us try to see the history of the disk. 

### File Recovery

Recovering file using `photorec`, we see a jpg file. 

The text in it says: `"sail, sail! sail to the uncharted seas and find the hidden treasure."`

Analysing its metadata using `exiftool`, we see the file contains a Make field as `"https://steghide.sourceforge.net/"`.

Looks like they are hinting at steganography. Applying `steghide` on the same image with no password, we get the text in `whisper.txt` 

`whisper.txt` contains the following text: `"when the ghosts in the uncharted ask you to reveal the key to the secrets, whisper to them the beautiful place you see here"`.

Very interesting. The places in the photos depict Belgium, But this looks like a dead end? What do ghosts mean? What is the uncharted?

### Revisiting the disk

Going back to our disk analysis, we see that there is some unallocated space at the end. Maybe the uncharted space was a reference to this. 

Using `testdisk`, we see that it is also a ext4 filesystem. Again, we recover files from there which seem to be a copy of some files from the main partition. Maybe these were the "ghosts", that seemed to not exist until we recovered them. Strange...

But something is off, one of the files `fireplace.jpg` is named in a different fashion from the others. checking the file modification times of all images using `exiftool`, we see TWO of them are modified in 2025 (`including fireplace.jpg`) while all others are modified last in 2013.

Using `steghide` again to extract the text from `fireplace.jpg`, we see that they require a password.

Using the hint from earlier, and a bit of bruteforcing, we crack the right password "`belgium`".

We recover `luna.txt`.

`luna.txt` contains a riddle about Luna. `"Oh Luna, keeper of secrets in the night sky, your light reveals what shadows conceal"`. This hints at the moon!

Applying `steghide` again on `{date}-Moon-Sign.jpg`, we recover `flag.txt` which contains the flag.