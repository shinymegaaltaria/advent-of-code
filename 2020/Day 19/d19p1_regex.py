import re

input = open("d19_test.txt").read()
input = input.split('\n\n')

rules = input[0].split('\n')
messages = input[1].split('\n')

parsed_rules = {}
cached_results = {}

for rule in rules:
    explode = rule.split(':')
    parsed_rules[int(explode[0])] = []
    tmp_explode = explode[1].split(' | ')
    for subrule in tmp_explode:
        cur_req = []
        sub_rules = subrule.split(' ')
        for req in sub_rules:
            if not req == '':
                if req.isdigit():
                    cur_req.append(int(req))
                else:
                    cur_req.append(req[1])
        parsed_rules[int(explode[0])].append(cur_req)

'''
for key in parsed_rules:
    print(key, parsed_rules[key])
'''

def match_rule(rule_no:int, msg:str):
    if msg in cached_results[rule_no]:
        return True
    else:
        return False

cnt = 0

def expand(rule_no):
    #print("debug: expand rule {}".format(rule_no))
    output = []

    cases_result = []
    for case in parsed_rules[rule_no]:
        #print(case)
        case_result = []
        for subcase in case:
            if type(subcase) == int:
                if subcase in cached_results:
                    #print("debug: skip rule {}".format(subcase))
                    case_result.append(cached_results[subcase])
                else:
                    subcase_result = expand(subcase)
                    case_result.append(subcase_result)
                    cached_results[subcase] = subcase_result
            else:
                case_result.append(subcase)
        
        case_product = []
        for elem in case_result:
            case_product.append('['+''.join(elem)+']')
        cases_result.append('('+''.join(case_product)+')')

    for i in range(len(cases_result)):
        for elem in cases_result[i]:
            output.append(''.join(elem))

    cached_results[rule_no] = output
    return '['+''.join(cached_results[rule_no])+']'

target = expand(0)
print(target)

pattern = re.compile(target)

'''for key in cached_results:
    print(key, cached_results[key])
'''

for message in messages:
    if pattern.match(message):
        cnt += 1

print(cnt)