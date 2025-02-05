# A Collector's Dream

### Challenge Description
My friend was showing off his collection of VHS tapes and other rare memorabilia when I stumbled upon something intriguing—an exclusive, limited-edition collectible. Curious, I started looking it up online and came across another similar card from the same collection. 

Now, I need your help to identify the legendary player on the VHS cover, figure out how many of these were produced, and determine the exact set number of the card I found.

The flag should follow the format of: `parsec{<PlayerName>_<SetsProduced>_<SetNo>}`
Note:
* Player name must be firstnamelastname with no spaces and contains only lowercase characters.

## Reverse Searching For the Collection


### Finding the Player
The collection has what seems to be a card and cover of a VHS tape. The VHS tape has the player with a jersey of some team `Rockies`. In the card you can barely make out that it is `Colorado`.

Now that we have figured out the team, we can narrow down our search. Reverse searching the image doesn't give fruitful results. Using the 1995 season we can search for some images of the team and get a better image.

Going through the highlights we can find a compilation of 30 years containing images of Colorado Rockies at [Medium](https://rockies.mlblogs.com/30-years-of-baseball-in-the-rockies-photo-archive-b88926803533). Here we can find a few better quality images of the person on the cover. Reverse searching these will lead you to the player's name on many articles.

### Finding the card
The card contains some kind of card which has inscription `Opening day Coors Field`. If we reverse search this image, we are led to an ebay link where they have advertised it as `Phone cards`. Searching 1995 Colorado Rockies phone cards collectors edition, we can find a X.com post. Opening it up we can find the original source with the number of copies and copy number on it.

Flag: `parsec{donbaylor_5000_214}`