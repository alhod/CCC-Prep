word = list(input(''))
ana = list(input(''))
remain = []
num_ast = 0
for i in ana:
    if i == '*':
        num_ast += 1
    elif i in word:
        word.remove(i)

if len(word) == num_ast:
    print('A')
else:
    print('N')
        
    