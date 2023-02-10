# Architecture 


## Components of this project

* Monomer
    * Properties
        * Current Position (x,y,z)
        * Previous Position (x,y,z)
        * Diameter : Max distance of local interaction
        * Energy : 
    * Methods
        * Update
        * GetBack

* Polymer
    * Properties
        * Array of Monomers
        * number of monomers
    * Methods
        * Add Monomer
        * Potential between monomers
        * Move ()

* Fields
    * Properties
        * Array of Polymers
        * Number of Polymers
    * Methods
        * Potential between polymers (polymer i, polymer j)
        * Add Polymer (polymer)
        * Move ()

* Output
