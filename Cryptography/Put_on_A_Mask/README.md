# Put On A Mask

### Challenge Description 

There's an application rumored to contain the "Secrets of Life" — a treasure trove of knowledge. However, access to these secrets is tightly guarded by a Certificate Authority (C.A.), which only trusts a select few to grant access.

But the C.A. has refused to recognize you. Undeterred, you’ve managed to intercept their communications, believing that somewhere within those messages lies the key to unlocking the truth. However, this was all in vain.... Or was it??

### Analysing the packet capture

We can take a look at the traffic and realize that there is some traffic to the IP address 192.168.1.111. However it seems very unstructured. It is in hexadecimal and not very intuitive. This looks something like sending a file with its content as a hex. We can gather the file from the capture using `follow TCP stream` on the first packet. Convert the data to raw and save it to a file. Now the question arises what is the extension of the file. Well the header usually contains the file type, so opening it using a hex editor and comparing with well known formats we can know it is a `.jpeg` image. Saving it as such we can see some digital signature based information but no flag. In typical forensic format we can try steghide to find hidden details from image using command `steghide extract -sf target.jpeg`. This extracts a file which contains a private key.

### Building a Certificate

We now have to build a certificate mimiking as if we are trusted by the CA this is done by the hinted mechanism of digitally signing a certificate. For this we can build certificate using the program `build_cert.py` in the dir.
This has to be then submitted to the netcat instance in a format without newline characters.

This will allow you to get the flag. 

Flag: `parsec{S1gn0f4Ph0ny_1239938123}`