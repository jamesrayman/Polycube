#pragma once

#include <vector>

class DancingChain;

class DancingLink {
private:
    DancingChain& chain;

    int indexUp, indexDown, indexLeft, indexRight;
    bool isActive;
public:
    const int col, row;
    int data;

    DancingLink () = delete;
    DancingLink (const DancingLink&);
    DancingLink (DancingChain&, int, int, int);

    bool active () const;
    
    void deactivate ();
    void reactivate ();

    int up () const;
    int down () const;
    int left () const;
    int right () const;

    bool operator== (const DancingLink&) const;
    bool operator!= (const DancingLink&) const;
};

class DancingChain {
private:
    DancingLink term;
    std::vector<DancingLink> cols;
    std::vector<std::vector<DancingLink>> links;
    int colsActive;
    
    std::vector<int> history;
public:
    DancingChain ();
    DancingChain (const DancingChain&);
    DancingChain (const std::vector<std::vector<char>>&);

    void undo ();
    void batchUndo ();
    void startUndoBatch ();

    void deactivate (int, int);

    int up (int, int) const;
    int down (int, int) const;
    int left (int, int) const;
    int right (int, int) const;

    int mostConstrained () const;
    int size () const;

    int front () const;
    bool inRange (int) const;

    DancingLink& operator[] (int);
};
