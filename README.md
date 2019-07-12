# deckmeistering
SR5 deck building

This is my deck building formula.

Ratings cost (X*(X+1)/2 * 1000).

Device Rating and Program slots are two different varibles. (Customizable)

Both however cost X^2 * 3000

Additionally I impose a tax to represent gathering various parts, wires, RAM, etc. 

The Tax depends on the deck.

The cost is the Sum of the Attributes * ((Device Rating + Programs-2)/2 * 500.

If the Tax is 0, because DR and P are both 1, it defaults to cost 125.
