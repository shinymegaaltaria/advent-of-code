input = open("d21_in.txt").read()
foods = input.split('\n')

allergen_lookup = {}
ingredient_lookup = {}

'''
all_allergens = {}
all_ingredients = {}

def common_element(a,b):
    output = []
    for elem in a:
        if elem in b:
            output.append(elem)
    return output

for food in foods:
    explode = food.split(' : ')
    ingredients = explode[0].split(' ')
    allergens = explode[1].split(',')
    
    for allergen in allergens:
        if allergen in all_allergens:
            all_allergens[allergen].append(ingredients)
        else:
            all_allergens[allergen] = [ingredients]


for key in all_allergens:
    common_ingredient = all_allergens[key][0]
    for food in all_allergens[key]:
        common_ingredient = common_element(common_ingredient,food)
    print(key, common_ingredient)
'''

allergen_lookup['wheat'] = 'zbhp'
ingredient_lookup['zbhp'] = 'wheat'

allergen_lookup['dairy'] = 'fsr'
ingredient_lookup['fsr'] = 'dairy'

allergen_lookup['shellfish'] = 'ndnlm'
ingredient_lookup['ndnlm'] = 'shellfish'

allergen_lookup['fish'] = 'skrxt'
ingredient_lookup['skrxt'] = 'fish'

allergen_lookup['soy'] = 'xcljh'
ingredient_lookup['xcljh'] = 'soy'

allergen_lookup['nuts'] = 'lqbcg'
ingredient_lookup['lqbcg'] = 'nuts'

allergen_lookup['sesame'] = 'dvjrrkv'
ingredient_lookup['dvjrrkv'] = 'sesame'

allergen_lookup['peanuts'] = 'mgbv'
ingredient_lookup['mgbv'] = 'peanuts'

tmp = []
for key in allergen_lookup:
    tmp.append(key)

print(sorted(tmp))
ans = []
for elem in sorted(tmp):
    ans.append(allergen_lookup[elem])

print(','.join(ans))