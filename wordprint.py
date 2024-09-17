import time,string
from random import randint

target = "hello world"
letters = string.ascii_lowercase + " "
result = ""
for letter in target:
    while True:
        i = letters[randint(0,26)]
        print(result + i)
        if (i == letter):
            result += i
            break
        time.sleep(0.01)