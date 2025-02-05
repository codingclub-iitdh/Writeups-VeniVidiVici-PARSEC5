# Pattern In Increasing Entropy

### Challenge Description

A crime syndicate has just been captured. However, just before their capture, they sent a message to their partner in crime containing a crucial secret. Fortunately, the police were tapping the network, but they are now stuck, unable to find any clues. Can you help them uncover the elusive secret?

### Analysing the Wireshark Network Capture

The wireshark capture contains a lot of requests for some very popular websites and their respective DNS requests and responses. However, one domain might catch your eye. `redherring.com` which is often used to denote something out of place, like a clue. Looking closely at the requests we can realize that the criminals were contacting using DNS tunelling. The subdomain of redherring seems like a base64 string.

If we b64 decode the string we get something interesting. The first contains `algo:LCG`, looking up LCG you will find it is a psuedo random number generator using a seed. The second contains the time generated.
Given the title and the unusual inclusion of timestamp one can figure out that the timestamp is possibly the seed for the generator. The other parameters of the algorithm are followed hence forth giving a hint to the likelihood of the seed being the timestamp.

Keeping the IP of the other party in mind, we can filter out the traffic. We find there is also a HTTP POST request. Looking at the body of the request we find something that resembles the cipher text.

> [!NOTE]
> Due to the existing cipher being hard to decrypt due to ambiguous padding, we replaced the cipher in the hints.

Now we can decrypt the flag with the program dec.py found in this directory.

You will get the flag: `parsec{N0t50Rand0mAft3r4ll_8612649722}`
