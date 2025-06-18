
import numpy as np
from scipy.linalg import lu




# Original matrix
A = np.array([
    [0, 2, 1],
    [1, 1, 1],
    [2, 1, 0]
], dtype=float)

# Perform LU decomposition with partial pivoting
P, L, U = lu(A)

# Display the results
print("Matrix A:")
print(A)

print("\nPermutation matrix P:")
print(P)

print("\nLower triangular matrix L:")
print(L)

print("\nUpper triangular matrix U:")
print(U)

# Verify that PA = LU
PA = P @ A
LU = L @ U

print("\nPA:")
print(PA)

print("\nLU:")
print(LU)

print("\nVerification (PA ≈ LU):", np.allclose(PA, LU))
