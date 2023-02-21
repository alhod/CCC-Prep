lines = int(input(''))
sentences = []
for i in range(0, lines):
    sentences.append(input(''))

eng = 0
fre = 0

for sen in sentences:
    eng += [i.lower() for i in sen].count('t')
    fre += [i.lower() for i in sen].count('s')

if eng > fre:
    print('English')
else:
    print('French')