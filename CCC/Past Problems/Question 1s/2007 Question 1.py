num_of_participants = input('')
dates = []
birthdays = []
for i in range(0, int(num_of_participants)):
    dates.append(input(''))
for i in dates:
    year, month, day = i.split(' ')
    birthdays.append((int(year), int(month), int(day)))
vote_year = 2007
vote_month = 2
vote_day = 27
for i in birthdays:
    if i[0] + 18 < vote_year:
        print('Yes')
    elif i[0] + 18 == vote_year:
        if i[1] < vote_month:
            print('Yes')
        elif i[1] == vote_month:
            if i[2] <= vote_day:
                print('Yes')
            else:
                print('No')
        else:
            print('No')
    else:
        print('No')