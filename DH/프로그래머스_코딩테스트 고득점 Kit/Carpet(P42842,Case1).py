

def solution(brown, yellow):
  
    answer = find_add_case(find_multiple_case(yellow), brown)
    
    return answer


def find_multiple_case(number) :

    y = 1
    answer = []

    while y <= number / y :
        if number % y == 0 :
            x = number // y
            answer.append([x, y])
        y = y + 1

    return answer


def find_add_case (grid, number) :

    answer = []

    for g in grid :

        x = g[0] + 2
        y = g[1] + 2

        if (x + y) * 2 - 4 == number :
            answer += [x, y]

    return answer
