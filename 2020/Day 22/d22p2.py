input = open("d22_in.txt").read()
decks = input.split('\n\n')
p1_deck = []
p2_deck = []

for card in decks[0].split('\n'):
    p1_deck.append(int(card))
for card in decks[1].split('\n'):
    p2_deck.append(int(card))

def hash_create(deck):
    out = []
    for card in deck:
        if 1 <= card and card <= 25:
            out.append(chr(card + 64))
        else:
            out.append(chr(card + 96 - 25))
    return ''.join(out)

def score(deck):
    out = 0
    s = len(deck)
    for i in range(s):
        out += (s - i) * deck[i]
    return out


game_no = 0
def game(p1, p2):
    
    global game_no
    game_no += 1
    #print(game_no)

    played_states_p1 = []
    played_states_p2 = []
    cnt = 0
    while len(p1) > 0 and len(p2) > 0:
        
        

        if hash_create(p1) in played_states_p1:
            return (1,[],[])
        if hash_create(p2) in played_states_p2:
            return (1,[],[])
        
        played_states_p1.append(hash_create(p1))
        played_states_p2.append(hash_create(p2))

        tmp1 = p1[0]
        tmp2 = p2[0]

        p1.remove(tmp1)
        p2.remove(tmp2)

        if len(p1) >= tmp1 and len(p2) >= tmp2:
            winner, d1, d2 = game(p1[0:tmp1],p2[0:tmp2])
            if winner == 1:
                p1.append(tmp1)
                p1.append(tmp2)
            else:
                p2.append(tmp2)
                p2.append(tmp1)
        else:
            if tmp1 > tmp2:
                p1.append(tmp1)
                p1.append(tmp2)
            else:
                p2.append(tmp2)
                p2.append(tmp1)
        
        cnt += 1
        #print(cnt)

    if len(p1) == 0:
        return (2,p1,p2)
    else:
        return (1,p1,p2)

winner, d1, d2 = game(p1_deck,p2_deck)

print(winner, d1, d2)

if winner == 1:
    print(score(d1))
else:
    print(score(d2))