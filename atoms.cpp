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
    double m; // mass (Da)
    int n, l, m_l; // principal, orbital, magnetic quantum numbers

public:
    Atom(int z, int m, int n, int l, int m_l) : 
        z(z), m(m), n(n), l(l), m_l(m_l) {}

    coords get_coords() {return this->R;}
    int get_z() {return this->z;}
};

class Grid {
public:
    int nx, ny, nz; // number of pts along x, y, z axes
    double h; // grid spacing value (in Bohr)

    Grid (int nx, int ny, int nz, double h) 
        : nx(nx), ny(ny), nz(nz), h(h) {}

    // inline improves performance
    inline size_t index(int i, int j, int k) const {
        return static_cast<size_t>(i * ny * nz + j * nz + k);
    } // what this do?

    inline size_t total_points() const {
        return static_cast<size_t>(nx * ny * nz);
    }

    inline double dV() const {
        return h * h * h; // discrete vol element
    }
}

class Wavefn{
private:
    vector<double> psi; // flattened array
    double E; // eigenvalue
    double occupancy; // 0.0, 1.0, 2.0
public:
    explicit Wavefn(size_t grid_size)
        : psi(grid_size, 0.0), energy(0.0), occupancy(0.0) {} // not sure how to initialize

    void normalize(double dV) {
        // renormalized the wavefunction using
        // val = norm = sqrt(sum_lmn{|psi|^2 * h^3})
        
        double norm_sq{};
        for ( double val : psi ) norm_sq += val * val * dV;
        
        if ( norm_sq > 1e-14 ) { // why 1e-14??
            double inv_norm = 1.0 / std::sqrt(norm_sq);
            for ( double& val : psi ) val *= inv_norm;
        }
    }
};

// i.e. does quantum mech solution to TISE and HF convergence use
// the same grid structure??? 
class Sys {
private:
    vector<Atom> atoms;
    int e_tot;
    int num_spat_orbs;
    vector<Wavefn> orbitals;

public:
    Sys(vector<Atom> atoms, int e_tot, const Grid& grid)
        : atoms(std::move(atoms)), e_tot(e_tot)
    {
        // only closed-shell / single electron configs for now
        num_spat_orbs = (e_tot + 1) / 2;
        orbitals.reserve(num_spat_orbs);
        
        for ( size_t i{}; i < num_spat_orbs; i++ ) {
            orbitals.emplace_back(grid.total_points());
        } // What does this do?
    }

    float get_V(coords r) {
        // returns V_nuc at a point r
        float v{};
        for ( atom : this->atoms ) {
            float dist{}; // should be |r - atom.get_coords|
            // probably easier to implement via some matrix algebra library
            v -= atom.get_z() * e * e / dist; 
            // implement edge case for dist = 0
        }
    } // what would we use this for?
}

