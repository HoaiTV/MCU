class Person:
    # ATTRIBUTE
    name = "HELLO WORLD ";
    age = 22;
    male = True
    # METHOD
    def setName(self, name):
        self.name = name
    
    def getName(self):
        return self.name
    
    def setAge(self, age):
        self.age = age
    
    def getAge(self):
        return self.age
    
    def setMale(self, male):
        self.male = male
    
    def getMale(self):
        return self.male

# instance
person = Person()
# properties
print(person.name) # HELLO WORLD
print(person.age) # 22
print(person.male) # True
# methods
person.setName("aliba ba")
print(person.getName()) # ALIBABA

person.setAge(22)
print(person.getAge()) # 22 

person.setMale(False)
print(person.getMale()) # False
