import random

modeldeck = []
for i in range(4):
    for j in range(13):
        modeldeck.append((i,j))


nohearts = 0
for i in range(1000000000):
    drawn_spade = False
    drawn_heart = False
    sofar = 0
    deck = modeldeck[:]
    while (not drawn_spade):
        index = random.randint(0,len(deck)-1)
        card = deck[index]
        deck.pop(index)
        if (card[0] == 0):
            drawn_heart = True
        if (card[0] == 3):
            drawn_spade = True
        sofar -= 1
    if (not drawn_heart): 
        nohearts += 1

print(nohearts/1000000000)

