input = open("d19_in.txt").read()
input = input.split('\n\n')

rules = input[0].split('\n')
messages = input[1].split('\n')

cr42 = ['abaababb', 'abaaabbb', 'ababbbbb', 'ababaabb', 'abaaaaab', 'abaabaab', 'abaabbab', 'ababbaab', 'abbbabbb', 'abbaaabb', 'abbababb', 'abbbaabb', 'abbbaaab', 'abbaabab', 'abbbabab', 'aabbabbb', 'aabaaabb', 'aabababb', 'aabbaabb', 'aaaaaabb', 'aaabaabb', 'aaabbabb', 'aaaaabbb', 'aaaabbbb', 'aaababbb', 'aaabbbbb', 'aaaabaab', 'aaaaaaab', 'aababaab', 'aabbbaab', 'aabaabab', 'aababbab', 'aaabaaaa', 'aaabbaaa', 'aaabaaba', 'aaababba', 'aaabbaba', 'aaaaaaba', 'aabbaaaa', 'aabbabaa', 'aabbbbaa', 'aabbbaba', 'aababbaa', 'aabaaaaa', 'abaaabba', 'abaabbba', 'abababba', 'ababbbba', 'ababbaba', 'abaaaaba', 'abbaaaba', 'abbababa', 'abbbaaba', 'abbbbaba', 'abbabbaa', 'abbbbbaa', 'abbaaaaa', 'abbabaaa', 'abbbaaaa', 'abbbbaaa', 'abababaa', 'abaaaaaa', 'abaabaaa', 'ababaaaa', 'babaaaaa', 'bababaaa', 'bababbaa', 'babbaaaa', 'babbabaa', 'babbbbaa', 'baaabaaa', 'baabaaaa', 'baababaa', 'baabbbaa', 'babababa', 'babbaaba', 'babbabba', 'babbbbba', 'baaaabba', 'baaabbba', 'baababba', 'baabbbba', 'bbbaaaba', 'bbbababa', 'bbbabbba', 'bbbbaaba', 'bbbbabba', 'bbbbbbba', 'bbbaabaa', 'bbbbabaa', 'bbbaaaaa', 'bbbabaaa', 'bbbbaaaa', 'bbabbaaa', 'bbabbbaa', 'bbababaa', 'bbababba', 'bbaabaaa', 'bbaababa', 'bbaabbaa', 'bbaaaaaa', 'bbaababb', 'bbaabbbb', 'bbaaabab', 'bbabbabb', 'bbabbbbb', 'bbababab', 'bbbaabab', 'bbbababb', 'bbbabaab', 'bbbbaabb', 'bbbbbabb', 'babaabbb', 'babaaabb', 'bababaab', 'bababbab', 'babbbbbb', 'babbbaab', 'baaaaaab', 'baaabaab', 'baaabbab', 'baababab', 'baabbbab', 'baabaabb', 'baabbabb', 'baabbbbb', 'baaaabbb', 'baaabbbb']
cr31 = ['baaaabab', 'baaaaabb', 'baaababb', 'baabaaab', 'baabbaab', 'baababbb', 'babbaaab', 'babbabab', 'babbbbab', 'babaabab', 'babaaaab', 'babbaabb', 'babbabbb', 'babbbabb', 'babababb', 'bababbbb', 'bbaabbab', 'bbabbbab', 'bbaaaaab', 'bbaabaab', 'bbabaaab', 'bbabbaab', 'bbaaabbb', 'bbaaaabb', 'bbababbb', 'bbabaabb', 'bbbaaaab', 'bbbaaabb', 'bbbaabbb', 'bbbabbab', 'bbbabbbb', 'bbbbabbb', 'bbbbbbbb', 'bbbbaaab', 'bbbbabab', 'bbbbbaab', 'bbbbbbab', 'bbaaabaa', 'baaaabaa', 'babaabaa', 'bbbabbaa', 'baaabbaa', 'bbbbbbaa', 'baabbaaa', 'babbbaaa', 'baaaaaaa', 'bbbbbaaa', 'bbabaaaa', 'bbabaaba', 'bbabbaba', 'bbabbbba', 'bbaaaaba', 'bbaaabba', 'bbaabbba', 'bbbbbaba', 'bbbaabba', 'babbbaba', 'babaaaba', 'babaabba', 'bababbba', 'baaaaaba', 'baaababa', 'baabaaba', 'baabbaba', 'abbbbaab', 'abbbbbab', 'abbaaaab', 'abbabaab', 'abbabbab', 'abbaabbb', 'abbabbbb', 'abbbbabb', 'abbbbbbb', 'abaaabab', 'abababab', 'ababbbab', 'ababaaab', 'abababbb', 'abaabbbb', 'ababbabb', 'abaaaabb', 'aabbabab', 'aabbbbab', 'aaaaabab', 'aaaabbab', 'aaababab', 'aaabbbab', 'aabaaaab', 'aabbaaab', 'aaabaaab', 'aaabbaab', 'aaaababb', 'aabaabbb', 'aababbbb', 'aabbbabb', 'aabbbbbb', 'aaaabaaa', 'aaaaaaaa', 'aababaaa', 'aabbbaaa', 'aaabbbaa', 'aaaabbaa', 'aaaaabaa', 'aaababaa', 'aabaabaa', 'abbaabaa', 'abbbabaa', 'abaaabaa', 'abaabbaa', 'ababbaaa', 'ababbbaa', 'abaababa', 'aaaababa', 'aabababa', 'aabaaaba', 'aabbaaba', 'ababaaba', 'abbaabba', 'abbabbba', 'abbbabba', 'abbbbbba', 'aaaaabba', 'aabaabba', 'aabbabba', 'aaaabbba', 'aaabbbba', 'aababbba', 'aabbbbba']

def match_rule(msg):
    if not len(msg) % 8 == 0:
        return False
    tmp = []
    switched = False
    cnt42 = 0
    cnt31 = 0
    for i in range(len(msg)):
        cur_substr = ''.join(tmp)
        if i > 0 and i%8 == 0:
            if switched == False:
                if cur_substr in cr42:
                    cnt42 += 1
                elif cur_substr in cr31:
                    cnt31 += 1
                    switched = True
                else:
                    return False
            else:
                if cur_substr in cr31:
                    cnt31 += 1
                else:
                    return False
            tmp = []
        tmp.append(msg[i])
    
    cur_substr = ''.join(tmp)
    if switched == False:
        if cur_substr in cr42:
            cnt42 += 1
        elif cur_substr in cr31:
            cnt31 += 1
            switched = True
        else:
            return False
    else:
        if cur_substr in cr31:
            cnt31 += 1
        else:
            return False

    if cnt42 > cnt31 and cnt42 > 0 and cnt31 > 0:
        return True
    else:
        return False    
cnt = 0

for message in messages:
    if match_rule(message):
        cnt += 1

print(cnt)