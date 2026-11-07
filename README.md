# Atomsim

This is a personal project to implement a molecular simulation environment!

## Roadmap

I will implement this in multiple stages, subject to change.

1. First principles
    - Atomic objects in molecular systems
    - Start with n<=2 atoms for simplicity. Can work my way up (including d, f orbitals) later
    - Quantum states & descriptions
    - Other physical descriptions
2. Model H, H2+, He+
    - Use analytical TISE as ground-truth
    - Diagonalize sparse matrix H psi_i = e_i psi_i
    - Conjugate Gradient or Lanczos method
3. Implement SCF procedure
4. Implement HF
5. Run a single point calculation
    - Implement AIMD!!
6. Look into DFT
    - Implement AIMD using DFT
7. Run a geometric relaxation


Reach ideas:
- Beyond closed-shell / single-electron configs