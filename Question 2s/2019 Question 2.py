fx, fy, top_left_x, top_left_y, bottom_left_x, bottom_left_y = input('').split(' ')
fx, fy, top_left_x, top_left_y, bottom_left_x, bottom_left_y = int(fx), int(fy), int(top_left_x), int(top_left_y), int(bottom_left_x), int(bottom_left_y)

if top_left_x <= fx <= bottom_left_x:
    # Case 1. Do fy-top_left_y, fy-bottom_left_y, find smallest, and that is the longest length rope
    length = min([fy-top_left_y, fy-bottom_left_y])
    if length < 0:
        length = length * -1
    print(format(length, '.3f'))

elif top_left_y <= fy <= bottom_left_y:
    # Case 1. Do fx-top_left_x, fx-bottom_left_x, find smallest, and that is the longest length rope
    length = min([fx-top_left_x, fx-bottom_left_x])
    if length < 0:
        length = length * -1
    print(format(length, '.3f'))

else:
    # Case 2. Find corners: (top_left_x, top_left_y), (top_left_x, bottom_left_y), (bottom_left_x, top_left_y), (bottom_left_x, bottom_left_y)
    # Use a2 + b2 = c2 to find best length
    corners = [(top_left_x, top_left_y), (top_left_x, bottom_left_y), (bottom_left_x, top_left_y), (bottom_left_x, bottom_left_y)]
    
    lengths = []

    for i in corners:
        lengths.append(((fx-i[0])**2 + (fy-i[1])**2)**(1/2))
    
    length = min(lengths)
    if length < 0:
        length = length * -1

    print(format(length, '.3f'))