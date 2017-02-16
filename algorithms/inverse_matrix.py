from copy import deepcopy

import sys


def words():
    """
    stdin генератор
    """
    for line in sys.stdin:
        for word in line.split():
            yield word


def new_empty_matrix(n):
    """
    Создание новой матрицы
    """
    return [x[:] for x in [[0.0] * n] * n]


def invert(matrix):
    """
    Инвертирует матрицу X с помощью алгоритма Жордана-Гаусса
    Приводим матрицу к еденичной.
    """
    matrix = deepcopy(matrix)

    rows = len(matrix)
    cols = len(matrix[0])

    # получаем еденичную матрицу и конкатенируем ее
    identity = make_identity(rows, cols)
    for i in range(0, rows):
        matrix[i] += identity[i]
    print(matrix)
    i = 0
    for j in range(0, cols):
        print("On col {0} and row {1}".format(j, i))
        zero_sum, first_non_zero = check_for_all_zeros(matrix, i, j)
        # Если все нули - увеличиваем столбец
        if zero_sum == 0:
            if j == cols:
                return matrix
            raise Exception("Matrix is singular.")
        # Если X[i][j] == 0, и под ним не нулевое значение, поменянем две строки
        if first_non_zero != i:
            matrix = swap_row(matrix, i, first_non_zero)
        # Поделить X[i] на X[i][j] чтобы сделать X[i][j] равной 1
        matrix[i] = [m / matrix[i][j] for m in matrix[i]]

        for q in range(0, rows):
            if q != i:
                scaled_row = [matrix[q][j] * m for m in matrix[i]]
                matrix[q] = [matrix[q][m] - scaled_row[m] for m in range(0, len(scaled_row))]
        if i == rows or j == cols:
            break
        i += 1

    for i in range(0, rows):
        matrix[i] = matrix[i][cols:len(matrix[i])]

    return matrix


def check_for_all_zeros(X, i, j):
    """
    Проверяет матрицу X на наличие только нулей в строке i в столбце j
    X - матрица
    i - строка
    j - столбец
    returns -
        zero_sum - количество не нулевых позиций
        first_non_zero - индекс первого не нулевого элемента
    """
    non_zeros = []
    first_non_zero = -1
    for m in range(i, len(X)):
        non_zero = X[m][j] != 0
        non_zeros.append(non_zero)
        if first_non_zero == -1 and non_zero:
            first_non_zero = m
    zero_sum = sum(non_zeros)
    return zero_sum, first_non_zero


def swap_row(matrix, i, p):
    """
    меняет строку i и p местами в матрице matrix
    """
    matrix[p], matrix[i] = matrix[i], matrix[p]
    return matrix


def make_identity(r, c):
    """
    создает матрицу индентичности
    """
    identity = []
    for i in range(0, r):
        row = []
        for j in range(0, c):
            elem = 0
            if i == j:
                elem = 1
            row.append(elem)
        identity.append(row)
    return identity


def main():
    w = words()

    print('Введите размер матрицы: ')
    n = int(next(w))
    mat_a = new_empty_matrix(n)
    for i in range(n):
        for j in range(n):
            mat_a[i][j] = float(next(w))
    print("\n".join(str(mat_a).split('[')))
    result = invert(mat_a)

    print('\n----------------------')
    [print(row) for row in result]

if __name__ == '__main__':
    make_identity(6,7)
    print(invert([[1,3], [3,1]]))
    main()
