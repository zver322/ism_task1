import cython
import numpy
import time

@cython.boundscheck(False)
@cython.wraparound(False)
cdef quadratic_form(double[:, ::1] A, double [:] x):
    cdef Py_ssize_t n = A.shape[0]
    cdef double result = 0.0
    for i in range(n):
        for j in range(n):
            result += A[i, j] * x[i] * x[j]
    return result

@cython.boundscheck(False)
@cython.wraparound(False)
def benchmark(double[:, ::1] A, double [:] x, int nrepeat):
    cdef double start = time.time()
    cdef double result = 0.0
    for i in range(nrepeat):
        result = quadratic_form(A, x)
    cdef double end = time.time()
    cdef double duration_s = end - start
    cdef double ms_per_run = duration_s * 1000 / nrepeat
    return {"result": result, "btime": ms_per_run}
