#include <iostream>
#include <cmath>
#include "OpenABF.hpp"

int main(int argc) {

// Alias algorithms for convenience
using ABF = OpenABF::ABFPlusPlus<float>;
using LSCM = OpenABF::AngleBasedLSCM<float, ABF::Mesh>;

// Make a triangular pyramid mesh
auto mesh = ABF::Mesh::New();
mesh->insert_vertex(0, 0, 0);
mesh->insert_vertex(2, 0, 0);
mesh->insert_vertex(1, std::sqrt(3), 0);
mesh->insert_vertex(1, std::sqrt(3) / 3, 1);

mesh->insert_face(0, 3, 1);
mesh->insert_face(0, 2, 3);
mesh->insert_face(2, 1, 3);

// Print original coordinates
for (const auto& v : mesh->vertices()) {
    std::cout << v->idx << ": " << v->pos << std::endl;
}

// Compute parameterized angles
ABF::Compute(mesh);

// Compute mesh parameterization from angles
LSCM::Compute(mesh);

// Print new coordinates
for (const auto& v : mesh->vertices()) {
    std::cout << v->idx << ": " << v->pos << std::endl;
}
}
