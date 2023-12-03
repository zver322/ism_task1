import numpy as np
import cython_quadratic_form

n = int(input())

# Reading matrix A
a = np.zeros((n, n))
for i in range(n):
    row = input().split(" ")
    for j in range(n):
        a[i, j] = float(row[j])

# Reading vector x
x = np.zeros(n)
input_vector = input().split(" ")
for i in range(n):
    x[i] = float(input_vector[i])

bench_result = cython_quadratic_form.benchmark(a, x, 1000)

print(f"Dimension: {n}\nTiming: {bench_result['btime']} ms\nAnswer = {bench_result['result']}")