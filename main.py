import numpy as np

def generate_vector_and_matrix(n):
    # Генерируем вектор и матрицу с числами двойной точности
    vector = np.random.rand(n)
    matrix = np.random.rand(n, n)

    return vector, matrix

def write_to_file(n, matrix, vector, filename):
    # Записываем данные в текстовый файл
    with open(filename, 'w') as file:
        # Записываем размерность
        file.write(f"{n}\n")

        # Записываем матрицу
        for row in matrix:
            file.write(" ".join(map(str, row)) + "\n")

        # Записываем вектор
        file.write(" ".join(map(str, vector)))


# Задаем массив размерностей n
n_array = [10000, 100000, 150000, 200000]

for n in n_array:
    # Генерируем вектор и матрицу
    vector, matrix = generate_vector_and_matrix(n)
    # Записываем данные в файл
    filename = f"sample_{n}.txt"  # Имя файла для записи
    write_to_file(n, matrix, vector, filename)
    print(f"Данные успешно записаны в файл {filename}.")
