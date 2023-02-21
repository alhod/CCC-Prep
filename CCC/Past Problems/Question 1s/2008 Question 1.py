cities = []
while True:
    temp = input('')
    city_temperature = temp.split(' ')
    city_temperature[1] = int(city_temperature[1])
    cities.append((city_temperature[1], city_temperature[0]))
    if city_temperature[0] == 'Waterloo':
        break

cities.sort()
print(cities[0][1])