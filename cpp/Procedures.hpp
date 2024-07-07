#ifndef PROCEDURES_HPP
#define PROCEDURES_HPP

class SpaceCraft;  // Forward declaration

class Procedures {
    public:
        Procedures() {}
        ~Procedures() {}

        void moveP(SpaceCraft& craft);
        void orbit(SpaceCraft& craft);
        void teleport(SpaceCraft& craft);
        void ride(SpaceCraft& craft);
};

#endif
