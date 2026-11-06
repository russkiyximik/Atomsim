// Starter file for atomic objects
#include <vector.h>

// fundamental quantum physical constants
const INT e {1};
const INT m_e {1};

struct coords{
    float x, y, z;
};


// todo: figure out how to encode orbitals of atoms from Z
// is it even realistic to do this from first principles? esp.
// for d, f orbitals? It's gonna be difficult to model relativistic
// effects which I know nothing about!

// todo: should i use the library eigen for coordinates & quantum states?
// apparently it is good for matrix algebra


class Wavefn{
private:
    vector<vector<vector<float>>> pts; // 3D
public:
    Wavefn() {} // not sure how to initialize

    void renormalize(float val) {
        // renormalized the wavefunction using
        // val = norm = sqrt(sum_lmn{|psi|^2 * h^3})
        // loop through each val of this->pts to renormalize by 1/val
    }
};

class Electron {
private:
    // wavefunction representation
    Wavefn psi_r;
    bool spin; // 1 - up, 0 - down
public:
    // methods
    // getter for position/momentum???
};

class Atom {
private:
    coords R; // atomic coords (on what scale? pm?)
    int z; // atomic number
    int m; // mass (Da)
    int n, l, m_l; // principal, orbital, magnetic quantum numbers

public:
    Atom(int z, int m, int n, int l, int m_l) : 
        z(z), m(m), n(n), l(l), m_l(m_l) {}

    coords get_coords() {return this->R;}
    int get_z() {return this->z;}
};

// should grid representation be the same for step 1 vs after?
// i.e. does quantum mech solution to TISE and HF convergence use
// the same grid structure??? 
class Grid {
private:
    vector<Atom> atoms;
    vector<Wavefn> wavefns; // is this an accurate physical 
    // representation of a molecular system??
    // should Grid and Molecular System be separate objects?
public:
    float get_V(coords r) {
        // returns V_nuc at a point r
        float v{};
        for ( atom : this->atoms ) {
            float dist{}; // should be |r - atom.get_coords|
            // probably easier to implement via some matrix algebra library
            v -= atom.get_z() * e * e / dist; 
            // implement edge case for dist = 0
            // what constant(s) to use?
        }
    }
}

