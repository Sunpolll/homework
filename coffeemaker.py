class Coffee_Order:
    def __init__(self, coffee:str, milk_level:int, sweet_level:int, size:str):
        self._coffee = coffee
        self._milk_level = milk_level
        self._sweet_level = sweet_level
        self._size = size
    def make_coffee(self):
        recipe_list = Menu
        storage = My_Storage
        menu_name = self._coffee + '_' + self._size
        recipe = recipe_list.get_recipe(menu_name)
        coffee_bean = 5
        water = recipe.get_water()
        milk = recipe.set_milk(self._milk_level)
        sugar = recipe.set_sugar(self._sweet_level)
        price = recipe.get_price()

        status = storage.coffee_making_storage_check(coffee_bean, milk, water, sugar, self._size)
        if status == True:
            print(f'Here is your coffee. Total price is {price}')
            print('Thank you. Wish our coffee make you a good day :)')
            return 'done'
        else: 
            print('We\'re sorry for our mistake.')
            return 'failed'

class Coffee_recipe_list:
    def __init__(self):
        self._menu = {}
    def add_recipe(self, recipe):
        self._menu[recipe.get_name()] = recipe
    def delete_recipe(self, recipe):
        self._menu.pop(recipe.get_name)
    def get_recipe(self, recipe):
        return self._menu[recipe]

class Coffee_recipe:
    def __init__(self,name:str, coffee_bean:int, milk:int, water:int, sugar:int, price:int):
        self._name = name
        self._coffee_bean = coffee_bean
        self._milk = milk
        self._water = water
        self._sugar = sugar
        self._price = price
    def get_water(self):
        return self._water
    def get_name(self):
        return self._name    
    def set_milk(self,level):
        return self._milk*level/50
    def set_sugar(self,level):
        return self._sugar*level/50
    def get_price(self):
        return self._price
    
class Storages:
    def __init__(self, coffee_bean:int, milk:int, water:int, sugar:int, small_cup:int, big_cup:int):
        self._coffee_bean = coffee_bean
        self._milk = milk
        self._water = water
        self._sugar = sugar
        self._small_cup = small_cup
        self._big_cup = big_cup
    def stocking(self, stuff:str, amount:int):
        if stuff == "coffee_bean":
            self._coffee_bean += amount
            print(f"Total coffee bean amount: {self._coffee_bean} grams")
        elif stuff == "milk":
            self._milk += amount
            print(f"Total milk amount: {self._milk} ml")
        elif stuff == "water":
            self._water += amount
            print(f"Total water amount: {self._water} ml")
        elif stuff == "sugar":
            self._sugar += amount
            print(f"Total sugar amount: {self._sugar} gram")
        elif stuff == "small_cup":
            self._small_cup += amount
            print(f"Total small cup amount: {self._small_cup} cup")
        elif stuff == "big_cup":
            self._big_cup += amount
            print(f"Total big cup amount: {self._big_cup} cup")
        else:
            print("Invalid input")
    def use(self, coffee_bean:int, milk:int, water:int, sugar:int, cup_size:int):
        self._coffee_bean -= coffee_bean
        self._milk -= milk
        self._water -= water
        self._sugar -= sugar
        if cup_size == 'small': self._small_cup -= 1
        elif cup_size == 'big': self._big_cup -= 1
    
    def coffee_making_storage_check(self, coffee_bean:int, milk:int, water:int, sugar:int, cup_size:str):
        if self._coffee_bean < coffee_bean:
            print(f"Not enough coffee bean")
            return False
        elif self._milk < milk:
            print(f"Not enough milk")
            return False
        elif self._water < water:
            print(f"Not enough water")
            return False
        elif self._sugar < sugar:
            print(f"Not enough sugar")
            return False
        elif cup_size == 'small' and self._small_cup < 1:
            print(f"Not enough small cup")
            return False
        elif cup_size == 'big' and self._big_cup < 1:
            print(f"Not enough big cup")
            return False
        else:
            print(f"All ingredients check passed. Your coffee is on the way")
            self.use(coffee_bean, milk, water, sugar, cup_size)
            return True
    def check_stock(self):
        print(f"Total coffee bean amount: {self._coffee_bean} grams")
        print(f"Total milk amount: {self._milk} ml")
        print(f"Total water amount: {self._water} ml")
        print(f"Total sugar amount: {self._sugar} gram")
        print(f"Total small cup amount: {self._small_cup} cup")
        print(f"Total big cup amount: {self._big_cup} cup")

My_Storage = Storages(coffee_bean = 10, milk = 100, water = 100, sugar = 100, small_cup = 5, big_cup = 5)
Menu = Coffee_recipe_list()
SAmericano = Coffee_recipe(name = 'americano_small', coffee_bean = 3, milk = 20, water = 20, sugar = 20, price = 20)
BAmericano = Coffee_recipe(name = 'americano_big', coffee_bean = 5, milk = 30, water = 30, sugar = 30, price = 30)
SEspresso = Coffee_recipe(name = 'espresso_small', coffee_bean = 3, milk = 20, water = 20, sugar = 20, price = 20)
BEspresso = Coffee_recipe(name = 'espresso_big', coffee_bean = 5, milk = 30, water = 30, sugar = 30, price = 30)
Menu.add_recipe(SAmericano)
Menu.add_recipe(BAmericano)
Menu.add_recipe(SEspresso)
Menu.add_recipe(BEspresso)
# new_order = Coffee_Order("americano", 50, 50, "small")

# order = new_order.make_coffee()
# My_Storage.check_stock()
# print(order)
status = input("Would you like a coffee ? (yes/no) :")
while status == 'yes':
    coffee = input("Coffee (Americano / Espresso) :").lower()
    while coffee not in ["americano", "espresso"]: coffee = input("Coffee (Americano / Espresso) :").lower()
    milk_level = int(input("Milk level (0% / 25% / 50% (original) / 75% / 100%) :"))
    sweet_level = int(input("Sweet level (0% / 25% / 50% (original) / 75% / 100%) :"))
    size = input("Size (small / big) :")
    print("We have recieved your order")
    new_order = Coffee_Order(coffee, milk_level, sweet_level, size)
    order = new_order.make_coffee()
    My_Storage.check_stock()
    if order == 'done': status = input("Would you like to order another cup ? (yes/no) :")
    else: status = input("Would you like to make a new order ? (yes/no) :")