struct Medicine {
    std::string name;
    int hours = 0;
    int minutes = 0;
    int years = 0;
};

struct OpenedMedicine {
    std::string name;
    int openTimestamp = 0;
    int endTimestamp = 0;
};

extern const char* allFileName;
extern const char* openedFileName;

void inputAllMedicine();
std::vector<Medicine*> readAllMedicine();
void showAllMedicine(std::vector<Medicine*>);
void inputOpenedMedicine(int);
std::vector<OpenedMedicine*> readOpenedMedicine();
void showOpenedMedicine(std::vector<OpenedMedicine*>);
void calculateExpirationDates(std::vector<Medicine*>&, std::vector<OpenedMedicine*>&);
void removeExpired(int, std::vector<Medicine*>&, std::vector<OpenedMedicine*>&);
void resaveMedicine(std::vector<Medicine*>&, std::vector<OpenedMedicine*>&);
void inputTimeDate(int&, int&, int&, int&, int&, int&);