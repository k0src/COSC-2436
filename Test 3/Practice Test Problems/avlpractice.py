import random

insertions = random.randint(5, 50)
removals = random.randint(0, 20)

insert_numbers = random.sample(range(101), insertions)
remove_numbers = random.sample(insert_numbers, removals)

print("Insertions: ", insert_numbers)
print("Removals: ", remove_numbers)