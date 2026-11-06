// Starter file for atomic objects

struct coords{
    float x, y, z;
};

// todo: figure out how to encode orbitals of atoms from Z
// is it even realistic to do this from first principles? esp.
// for d, f orbitals? It's gonna be difficult to model relativistic
// effects which I know nothing about!

class Atom {
private:
    coords R; // atomic coords (on what scale? pm?)
    int z; // atomic number

public:
    Atom(int atom_num) : z(atom_num) {}
};

