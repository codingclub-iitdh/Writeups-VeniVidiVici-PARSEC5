# Cryptography/1
This is the README for Cryptography/1.
Psuedo Random Number Generator:
	- Flag: parsec{N0t50Rand0mAft3r4ll_8612649722}
	- Procedure: There is a packet capture where there are base64 encoded messages in form of DNS, trying to replicate DNS tunnelling. The domains are of format <b64string>.redherring.com. These contain hints to the algorithm used and the parameters used in it. Using this algo and params the random number is generated. This rand number is used as key for the encryption of the message/flag, which can be found in a http message to the same IP Address.
