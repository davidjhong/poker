



class Settings
{
    private:
        unsigned int numPlayers;
        unsigned int startingChips;
        unsigned int bigBlindAmt;
        unsigned int littleBlindAmt;
        unsigned int numOfRounds;
    public:
        Settings();

        unsigned int getNumPlayers() const;
        unsigned int getStartingChips() const;
        unsigned int getBigBlindAmt() const;
        unsigned int getLittleBlindAmt() const;
        unsigned int getNumOfRounds() const;

        void setNumPlayers(unsigned int);
        void setStartingChips(unsigned int);
        void setBigBlindAmt(unsigned int);
        void setLittleBlindAmt(unsigned int);
        void setNumOfRounds(unsigned int);
};
        
