input = open("d22_in.txt").read()
decks = input.split('\n\n')
p1_deck = []
p2_deck = []

for card in decks[0].split('\n'):
    p1_deck.append(int(card))
for card in decks[1].split('\n'):
    p2_deck.append(int(card))

def score(deck):
    out = 0
    s = len(deck)
    for i in range(s):
        out += (s - i) * deck[i]
    return out

def game(p1, p2):
    cnt = 0
    while len(p1) > 0 and len(p2) > 0:
        if p1[0] > p2[0]:
            tmp1 = p1[0]
            tmp2 = p2[0]
            p1.remove(tmp1)
            p2.remove(tmp2)
            p1.append(tmp1)
            p1.append(tmp2)
        else:
            tmp1 = p1[0]
            tmp2 = p2[0]
            p1.remove(tmp1)
            p2.remove(tmp2)
            p2.append(tmp2)
            p2.append(tmp1)
        cnt += 1
    if len(p1) == 0:
        return (2,p1,p2)
    else:
        return (1,p1,p2)

winner, d1, d2 = game(p1_deck,p2_deck)

if winner == 1:
    print(score(d1))
else:
    print(score(d2))